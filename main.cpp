#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <random>

using namespace std;

struct Character {
    string name;
    int stepHeight;
};

int howMuchCanReach(int diff, const vector<Character> &brotherhood) {
    int result = 0;
    for (auto &i: brotherhood) {
        if (i.stepHeight >= diff) {
            result++;
        }
    }
    return result;
}

int main() {
    int N;
    cout << "Vvod N" << endl;
    cin >> N;

    random_device os_seed;
    const unsigned int seed = os_seed();

    mt19937 generator(seed);
    uniform_int_distribution<unsigned int> distribute(0, 6);
//    int obstacles[]{0, 1,6,4,3,5,3};
    int obstacles[N + 1];
    obstacles[0] = 0;
    for (int i = 1; i <= N; i = i + 1) {
        obstacles[i] = distribute(generator);
        cout << obstacles[i] << ' ';
    }
    cout << endl;
    vector<Character> brotherhood{{"Legolas",  7},
                                  {"Frodo",    2},
                                  {"Aragorn",  3},
                                  {"Boromir",  3},
                                  {"Gandalf",  3},
                                  {"Samwise",  2},
                                  {"Peregrin", 2},
                                  {"Meriadoc", 2},
                                  {"Gimli",    1}};

    for (int i = 0; i < N && brotherhood.size() > 1; i = i + 1) {
        int diff = abs(obstacles[i] - obstacles[i + 1]);
        while (brotherhood.size() > 1 && howMuchCanReach(diff, brotherhood) < 2) {
            diff--;
            brotherhood.pop_back();
        }
    }
    if (brotherhood.size() == 1) {
        cout << "Sauron wins";
    } else {
        cout << "Gandalf wins" << endl;
        for (auto &i: brotherhood) {
            cout << i.name << endl;
        }
    }
    return 0;
}




