#include <iostream>
using namespace std;
class Student {
public:
    
    string name;
    string surname;
    int* mark = new int[5];
    double avg_mark() {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += mark[i];
        }
        return sum / 5;
    }
};
class Group: public Student{
public:
    Group(int n) {
        student = new Student[40];
        count = n;
    };
   
    Student* student;
    int count;
    void Sort(Student student[]) {
        int n = count-2;
        for (int k = 0; k < count; k++) {
            for (int i = 0; i <= n; i++) {
                if (student[i].avg_mark() < student[i + 1].avg_mark()) {
                    Student temp;
                    temp = student[i];
                    student[i] = student[i + 1];
                    student[i + 1] = temp;
                }
            }
            n--;
        }
    }
    void Rate() {
        for (int i = 0; i < count; i++) {
            cout << student[i].name << endl;
            cout << student[i].surname << endl;
            cout << student[i].avg_mark() << endl;
        }
    }
    friend void Input() {}
    void Adding() {
        count += 1;
        cin >> student[count-1].name;
        cin >> student[count-1].surname;
        for (int k = 0; k < 5; k++) {
            cin >> student[count-1].mark[k];
        }
    }
    void Delete(int k) {
        for (int i = k - 1; i < count; ++i)
        {
            student[i] = student[i + 1];
        }
        count--;
    }
};
void Input(Student student[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Input information about" << " " << i + 1 << " student:" << endl;
        cin >> student[i].name;
        cin >> student[i].surname;
        for (int k = 0; k < 5; k++) {
            cin >> student[i].mark[k];
        }
    }
}


int main(){
    int amount;
    int number;
    cin >> n;

    Group A(amount);
    Input(A.student,A.count);
    A.Sort(A.student);
    A.Rate();

    A.Adding();
    A.Sort(A.student);
    A.Rate();

    cin >> number;
    A.Delete(number);
    A.Sort(A.student);
    A.Rate();
}

