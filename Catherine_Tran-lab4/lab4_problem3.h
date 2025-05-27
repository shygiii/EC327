#ifndef LAB4_PROBLEM3_H
#define LAB4_PROBLEM3_H
#include <string>
#include <vector>
using namespace std;

class Student {
    private:    
        string name;
        vector<int> quizScore;

    public:
        Student(string nameStudent);
        Student(string nameStudent, int quizscore);
        ~Student();
        void addQuizScore(int score);
        double getAverageScore();
};
#endif // LAB4_PROBLEM3_MIDDLE_H