#include <SFML/Graphics.hpp>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace sf;
namespace mp = boost::multiprecision;

//typedef mp::cpp_dec_float_100 FLOAT;
typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
//typedef mp::cpp_int INT;

FLOAT clac(int NUM) {
    FLOAT A, MINPI, MAXPI;

    MINPI = 0;
    MAXPI = 0;

    for (int i = 1; i <= NUM - 1; ++i) {
        A = (FLOAT(NUM) * FLOAT(NUM)) - (FLOAT(i) * FLOAT(i));
        MINPI += mp::sqrt(A);
    }
    MINPI = FLOAT(4) / (FLOAT(NUM) * FLOAT(NUM)) * MINPI;

    return MINPI;
}

int main () {
    int NUM;

    cout << "please enter number. " << endl;

    cin >> NUM;

    RenderWindow window(VideoMode(600, 600), "archimedes");

    int sides = NUM;
    const float radius = 300.0f;
    ConvexShape polygon;
    polygon.setPointCount(sides);

    for (int i = 0; i < sides; ++i) { 
        float angle = i * 2 * M_PI / sides - M_PI / 2;
        polygon.setPoint(i, sf::Vector2f(radius * cos(angle), radius * sin(angle))); 
    }

    polygon.setPosition(300, 300);
    polygon.setFillColor(Color::White);

    while (window.isOpen()) { 
        Event event; 
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); 
        }
        window.clear();
        window.draw(polygon); 
        window.display();
    }

    cout << setprecision(numeric_limits<decltype(clac(NUM))>::digits10 + 1) << clac(NUM) << endl;
    //cout << setprecision(200) << PI << endl;
    return 0; 
}
