#include "lab4_problem3.h"
#include <string>
#include <vector>

Student::Student(string nameStudent) {
    name = nameStudent;
}

Student::Student(string nameStudent, int quizscore) {
    name = nameStudent;
    quizScore.push_back(quizscore);
}

Student::~Student() {
}

void Student::addQuizScore(int score) {
    quizScore.push_back(score);
}

double Student::getAverageScore() {
    if (quizScore.size()==0) return 0;
    double sum = 0;
    for (int i = 0; i < quizScore.size(); i++) sum += quizScore[i];
    return sum / quizScore.size();
}