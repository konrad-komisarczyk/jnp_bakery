#include "bakery.h"

#include <iostream>

using namespace std;

int main() {
    cout << "PI = " << PI << endl << endl;
    CherryPie<int, 1> cherryPie(1);
    cout << cherryPie.getArea() << endl;
    cout << cherryPie.getStock() << endl;

    ApplePie<int, 1, double> applePie(2, 21.37);
    cout << applePie.getArea() << endl;
    cout << applePie.getPrice() << endl;
    cout << "initial stock: " << applePie.getStock() << endl;
//    applePie.sell();
//    cout << applePie.getStock() << endl;


    CherryPie<int, 2> cherryPie2(2);
    Bakery<double, int, 100, ApplePie<int, 1, double>, CherryPie<int, 1>, CherryPie<int, 2>> bakery(applePie, cherryPie, cherryPie2);
    cout << "profits: " << bakery.getProfits() << endl;
    cout << "stock: " << bakery.getProductStock<decltype(applePie)>() << endl;
    bakery.sell<ApplePie<int, 1, double>>();
    cout << "profits: " << bakery.getProfits() << endl;
    bakery.sell<ApplePie<int, 1, double>>();
    cout << "stock: " << bakery.getProductStock<decltype(applePie)>() << endl;
    cout << "profits: " << bakery.getProfits() << endl;
    bakery.sell<ApplePie<int, 1, double>>();
    cout << "profits: " << bakery.getProfits() << endl;
    bakery.sell<ApplePie<int, 1, double>>();
    cout << "profits: " << bakery.getProfits() << endl;

    ApplePie<int, 1, float> applePie2(2, 21.37);
    Bakery<float, int, 100, ApplePie<int, 1, float>, CherryPie<int, 1>> bakery2(applePie2, cherryPie);

}