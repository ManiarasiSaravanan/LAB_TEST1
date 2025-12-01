#include <iostream>
#include <iomanip>
using namespace std;
// (a) getPrice
double getPrice(int roomType) {
    if (roomType == 1)
        return 150.00;
    else if (roomType == 2)
        return 200.00;
    else if (roomType == 3)
        return 300.00;
    else
        return 0.00;
}

int main() {
    int roomType, nights;
    double pricePerNight = 0, subtotal = 0, discount = 0, finalTotal = 0;
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

        cout << "Enter number of nights: ";
        cin >> nights;

        if (nights <= 0) {
            cout << "Invalid number of nights! Program terminated.\n";
            return 0;
        }

        // Room price selection
        if (roomType == 1) {
            pricePerNight = 150;
        }
        else if (roomType == 2) {
            pricePerNight = 200;
        }
        else if (roomType == 3) {
            pricePerNight = 300;
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

        // Long stay discount
        if (nights >= 3 && nights <= 5) {
            discount = subtotal * 0.05;
        }
        else if (nights > 5) {
            discount = subtotal * 0.10;
        }

        subtotal -= discount;

        // Promo code
        cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
        cin >> promo;

        if (promo == 'Y' || promo == 'y') {
            subtotal = subtotal * 0.90; // extra 10% discount
        }

        finalTotal = subtotal;

        cout << "Do you want to add more booking? (Y/N)";
        cin >> again;
    } while (again == 'Y' || again == 'y');

    // DISPLAY SUMMARY
    cout << "\n------------------ BOOKING SUMMARY ------------------\n\n";

    cout << fixed << setprecision(2);

    cout << "Price per Night   : RM" << pricePerNight << endl;
    cout << "Nights Stayed     : " << nights << endl;

    cout << "Subtotal          : RM" << (pricePerNight * nights) << endl;

    if (discount > 0)
        cout << "Discount (" << (discount / (pricePerNight * nights) * 100)
        << "%): RM" << discount << endl;
    else
        cout << "Discount          : RM0.00\n";

    cout << "------------------------------------------------------\n";

    cout << "Final Total       : RM" << finalTotal << endl;

    cout << "------------------------------------------------------\n\n";

    // FINAL MESSAGE
    if (finalTotal > 1200)
        cout << "VIP CUSTOMER: You are eligible for free airport pickup!\n";
    else if (finalTotal < 300)
        cout << "Enjoy your vacation!\n";
    else
        cout << "Thank you for booking with FTMK Grand Hotel.\n";

    cout << "=====================================================\n";

    return 0;
}
