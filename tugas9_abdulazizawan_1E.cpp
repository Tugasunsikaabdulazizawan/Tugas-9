#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SimpleList {
private:
    vector<string> items;

public:
    void addItem(const string& item) {
        items.push_back(item);
        cout << "Item '" << item << "' added." << endl;
    }

    void readItems() const {
        if (items.empty()) {
            cout << "No items in the list." << endl;
            return;
        }
        cout << "Items in the list:" << endl;
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void deleteItem(int index) {
        if (index < 1 || index > items.size()) {
            cout << "Invalid index. No item deleted." << endl;
            return;
        }
        cout << "Item '" << items[index - 1] << "' deleted." << endl;
        items.erase(items.begin() + (index - 1));
    }
};

int main() {
    SimpleList list;
    int choice;
    string item;
    int index;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Read Items" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                cin.ignore();
                getline(cin, item);
                list.addItem(item);
                break;

            case 2:
                list.readItems();
                break;

            case 3:
                cout << "Enter index of item to delete: ";
                cin >> index;
                list.deleteItem(index);
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
