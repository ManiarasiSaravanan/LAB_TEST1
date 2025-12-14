#include <iostream>
#include <iomanip>
using namespace std;

//(a) getPrice using array
double getPrice(int roomType)
{
    double prices[3] = { 150.00, 200.00, 300.00 };

    if (roomType >= 1 && roomType <= 3)
        return prices[roomType - 1];
    else
        return 0.0;
}

//(b)calculateDiscount
double calculateDiscount(double subtotal, int night) {
    double discount = 0.0;
    if (night >= 3 && night<= 5) {
        discount = subtotal * 0.05;
    }
    else if (night> 5) {
        discount = subtotal * 0.10;
    }
    return discount;
}

//(c)computeAmounts
void computeAmounts(int nights, double pricePerNight,double& subtotal, double& discount, double& afterDiscount){
    subtotal = pricePerNight * nights;
    discount = calculateDiscount(subtotal, nights);
    afterDiscount = subtotal - discount;
}

//(d)promoCode
double applyPromo(char promoCode, double subtotal) {
    if (promoCode == 'Y' || promoCode == 'y')
        return subtotal * 0.05;   // 5% promo discount
    else
        return 0;
}

//(e)displayMessage
void displayMessage(double finalTotal) {
    if (finalTotal > 1200)
        cout << "VIP CUSTOMER: You are eligible for free airport pickup!\n";
    else if (finalTotal < 300)
        cout << "Enjoy your vacation!\n";
    else
        cout << "Thank you for booking with FTMK Grand Hotel.\n";
}

//(f)displaySummary
void displaySummary(double pricePerNight, int nights,
    double subtotal, double discount,
    double finalTotal)
{
    cout << "\n------------------ BOOKING SUMMARY ------------------\n\n";

    cout << fixed << setprecision(2);

    cout << "Price per Night   : RM" << pricePerNight << endl;
    cout << "Nights Stayed     : " << nights << endl;
    cout << "Subtotal          : RM" << subtotal << endl;
    cout << "Discount          : RM" << discount << endl;

    cout << "------------------------------------------------------\n";
    cout << "Final Total       : RM" << finalTotal << endl;
    cout << "------------------------------------------------------\n\n";
}


int main() {
    int roomType, nights;
    double pricePerNight = 0, subtotal = 0, discount = 0, finalTotal = 0;
    double grandTotal = 0.0;
    char promo;
    char again;

   
    cout << "=====================================================\n";
    cout << "           FTMK GRAND HOTEL BOOKING SYSTEM\n";
    cout << "=====================================================\n\n";
    do {


        cout << "1. Standard Room  - RM150.00 per night\n";
        cout << "2. Deluxe Room    - RM200.00 per night\n";
        cout << "3. Suite Room     - RM300.00 per night\n";

        cout << "Enter room type (1-3): ";
        cin >> roomType;

        if (roomType < 1 || roomType > 3) {
            cout << "Invalid room type! Program terminated.\n";
            return 0;
        }

        //getPrice
        pricePerNight = getPrice(roomType);

        cout << "Enter number of nights: ";
        cin >> nights;

        if (nights <= 0) {
            cout << "Invalid number of nights! Program terminated.\n";
            return 0;
        }


        // Display selected room
        if (roomType == 1) {
            cout << "\nYou selected Standard Room.\n";
        }
        else if (roomType == 2) {
            cout << "\nYou selected Deluxe Room.\n";
        }

        else cout << "\nYou selected Suite Room.\n";

        // Calculate subtotal
        subtotal = pricePerNight * nights;

        //calculateDiscount
        subtotal = pricePerNight * nights;
        discount = calculateDiscount(subtotal, nights);
        subtotal -= discount;

        //computeAmounts
        computeAmounts(pricePerNight, nights, subtotal, discount, finalTotal);


        // promoCode
        cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
        cin >> promo;

        double promoDiscount = applyPromo(promo, finalTotal);
        finalTotal -= promoDiscount;

        grandTotal += finalTotal;

        cout << "Do you want to add more booking? (Y/N) ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    displaySummary(pricePerNight, nights, subtotal, discount, finalTotal);

    displayMessage(finalTotal);


    cout << "=====================================================\n";

    cout << "\n================ GRAND TOTAL =================\n";
    cout << "Grand Total for all bookings: RM" << fixed << setprecision(2) << grandTotal << endl;
    cout << "================================================\n";

    return 0;
}
