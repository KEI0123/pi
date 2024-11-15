#include <SFML/Graphics.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <vector>
#include <random>

using namespace std;
using namespace sf;
namespace mp = boost::multiprecision;

typedef mp::cpp_dec_float_100 FLOAT;
//typedef mp::number<mp::cpp_dec_float<5000>> FLOAT;
//typedef mp::cpp_int INT;

constexpr long Loop = 1000;

constexpr int NUM_LINE = 12;
constexpr int LINE_SPACING = 60;
constexpr int WIN_WIDTH = LINE_SPACING * (NUM_LINE + 1);
constexpr int WIN_HEIGHT = LINE_SPACING * (NUM_LINE + 1);
constexpr int MAG = LINE_SPACING / 2;

random_device rand_gen;
mt19937 engine(rand_gen());

class LineDrawer
{
public:
    LineDrawer(int numLines, int lineSpacing, int lineLength) {
        for (int i = 0; i < numLines; ++i)
        {
            float yOffset = (i - 1) * lineSpacing + lineSpacing;
            lines.push_back(Vertex(Vector2f(lineSpacing, lineSpacing + yOffset), Color::Black));
            lines.push_back(Vertex(Vector2f(0 + lineLength - lineSpacing, lineSpacing + yOffset), Color::Black));
        }
    }

    void drawLines(RenderWindow& window) {
        window.draw(&lines[0], lines.size(), Lines);
    }

private:
    vector<Vertex> lines;
};

class Needle
{
public:
    Needle(float mid_posx, float mid_posy, float nposx, float nposy, int colvalue) {
        if (colvalue == 1){
            ndl.push_back(Vertex(Vector2f(mid_posx, mid_posy), Color::Red));
            ndl.push_back(Vertex(Vector2f(nposx, nposy), Color::Red));
        }
        else {
            ndl.push_back(Vertex(Vector2f(mid_posx, mid_posy), Color::Black));
            ndl.push_back(Vertex(Vector2f(nposx, nposy), Color::Black));
        }
    }

    void drawNeedle(RenderWindow& window) {
        window.draw(&ndl[0], ndl.size(), Lines);
    }
private:
    vector<Vertex> ndl;
};

bool touch(double miny, double maxy) {
    for (int i = 0; i < 12; ++i) {
        if (i * 2 >= miny && i * 2 <= maxy)
            return true;
    }
    return false;
}

int main()
{
    uniform_real_distribution<long double> dist(0, 22);
    uniform_real_distribution<long double> dists(0, 1);

    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Buffon's needle");

    vector<Needle> needles;
    int colvalue = 0;
    long long cou = 0;
    for (int i = 0; i < Loop; ++i) {
        double mid_posy = dist(engine);
        double mid_posx = dist(engine);

        double hposy = dists(engine);
        double hposx = dists(engine);
        double lposy = dists(engine);
        double lposx = dists(engine);
    
        double y = hposy - lposy;
        double x = hposx - lposx;

        double sin = y / sqrt(x * x + y * y);
        double cos = x / sqrt(x * x + y * y);

        sin += mid_posy;
        cos += mid_posx;

        double maxy = max(mid_posy, sin);
        double miny = min(mid_posy, sin);

        if (touch(miny, maxy)) {
            colvalue = 1;
            cou++;
        }

        needles.emplace_back(float(mid_posx * MAG) + LINE_SPACING, float(mid_posy * MAG) + LINE_SPACING, float(cos * MAG) + LINE_SPACING, float(sin * MAG) + LINE_SPACING, colvalue);
        colvalue = 0;
    }

    if (cou != 0) {
        FLOAT PI = FLOAT(Loop) / FLOAT(cou);
        cout << setprecision(numeric_limits<decltype(PI)>::digits10 + 1) << PI << endl;
    }
    else
        cout << "Agein" << endl;

    LineDrawer lineDrawer(NUM_LINE, LINE_SPACING, WIN_WIDTH);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        lineDrawer.drawLines(window);
        for (auto& needle : needles) {
            needle.drawNeedle(window);
        }
        window.display();
    }

    return 0;
}
