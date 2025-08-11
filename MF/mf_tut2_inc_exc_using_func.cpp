#include<iostream>
using namespace std;

int students_in_either(int music, int sports, int intersection) {
    return music + sports - intersection;
}

int students_only_in_sports(int sports, int intersection) {
    return sports - intersection;
}

int students_only_in_music(int music, int intersection) {
    return music - intersection;
}

int students_in_neither(int universal, int music, int sports, int intersection) {
    return universal - (music + sports - intersection);
}

int main() {
    int size_universal = 200;
    int size_sports = 120;
    int size_music = 90;
    int size_intersection = 50;

    cout << "\nStudents in either one club: " << students_in_either(size_music, size_sports, size_intersection);
    cout << "\nStudents only in Sports Club: " << students_only_in_sports(size_sports, size_intersection);
    cout << "\nStudents only in Music Club: " << students_only_in_music(size_music, size_intersection);
    cout << "\nStudents in neither club: " << students_in_neither(size_universal, size_music, size_sports, size_intersection);

    return 0;
}
