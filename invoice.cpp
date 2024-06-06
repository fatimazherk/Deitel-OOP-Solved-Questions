// 3.13 (Invoice Class) Create a class called Invoice that a hardware store might use to represent
// an invoice for an item sold at the store. An Invoice should include four data members—a part num-
// ber (type string), a part description (type string), a quantity of the item being purchased (type
// int) and a price per item (type int).  Your class
// should have a constructor that initializes the four data members. Provide a set and a get function for
// each data member. In addition, provide a member function named getInvoiceAmount that calcu-
// lates the invoice amount (i.e., multiplies the quantity by the price per item), then returns the
// amount as an int value. If the quantity is not positive, it should be set to 0. If the price per item is
// not positive, it should be set to 0. Write a test program that demonstrates class Invoice’s capabilities.
#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    // Constructor
    Invoice(string pn, string pd, int q, int pp)
        : partNumber(pn), partDescription(pd), quantity(q), pricePerItem(pp) {
        // Ensure the quantity and price per item are non-negative
        if (quantity < 0) 
        quantity = 0;
        if (pricePerItem < 0) 
        pricePerItem = 0;
    }

    // Setters
    void setPartNumber(string pn) {
        partNumber = pn;
    }

    void setPartDescription(string pd) {
        partDescription = pd;
    }

    void setQuantity(int q) {
        quantity = (q < 0) ? 0 : q;
    }

    void setPricePerItem(int pp) {
        pricePerItem = (pp < 0) ? 0 : pp;
    }

    // Getters
    string getPartNumber() const {
        return partNumber;
    }

    string getPartDescription() const {
        return partDescription;
    }

    int getQuantity() const {
        return quantity;
    }

    int getPricePerItem() const {
        return pricePerItem;
    }

    // Function to calculate the invoice amount
    int getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    // Create an Invoice object
    Invoice invoice("gtr-003", "sleek red two-wheeler bike", 3, 4000);

    // Display the details
    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per Item: " << invoice.getPricePerItem() << endl;
    cout << "Invoice Amount: " << invoice.getInvoiceAmount() << endl;

    // Modify the quantity and price to demonstrate the setter methods and invoice calculation
    invoice.setQuantity(2);  
    invoice.setPricePerItem(2000);  
    cout<<endl<<"Invoice Amount: "<< invoice.getInvoiceAmount()<<endl;

    return 0;
}
