#include <iostream>
using namespace std;

class pointType
{
protected:
    double xCoordinate;
    double yCoordinate;

public:
    pointType() {}
    pointType(double x, double y) : xCoordinate(x), yCoordinate(y) {}
    void setCoordinates();
    void displayCoordinates() const;
    double getX();
    double getY();
};

void pointType::setCoordinates()
{
    cout << "enter x coordinate : ";
    cin >> xCoordinate;
    cout << "enter y coordinate : ";
    cin >> yCoordinate;
}
void pointType::displayCoordinates() const
{
    cout << "x coordinate is : " << xCoordinate << "\n\n";
    cout << "y coordinate is : " << yCoordinate;
}
double pointType::getX()
{
    return xCoordinate;
}
double pointType::getY()
{
    return yCoordinate;
}

int main()
{
    unsigned int option;
    pointType pt;
    double x, y;

    do
    {
        cout << "1 set coordinates\n";
        cout << "2 display coordinates\n";
        cout << "3 get x coordinate\n";
        cout << "4 get y coordinate\n";
        cout << "5 exit program\n";
        cout << "enter a number in above options : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "set coordinates\n\n";
            pt.setCoordinates();
            cout << "\n\n\n";
            break;
        case 2:
            cout << "displaying x-y plane coordinates\n";
            pt.displayCoordinates();
            cout << "\n\n\n";
            break;
        case 3:
            cout << "getting x coordinate\n\n";
            x = pt.getX();
            cout << "x coordinate of the plane is : " << x << "\n\n";
            break;
        case 4:
            cout << "getting y coordinate\n\n";
            x = pt.getY();
            cout << "y coordinate of the plane is : " << x << "\n\n";
            break;
        default:
            cout << "SORRY!\nINVALID OPTION\n\n";
            break;
        }
    } while (option != 5);
}