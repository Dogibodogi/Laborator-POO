#include "Functii.h"
#include "student.h"
int CompareNames(student s1, student s2) {
    int a = 0;
    int b = 0;
    while (s1.GetName()[a] != '\0')
        a++;
    while (s2.GetName()[b] != '\0')
        b++;
    if (a > b)
        a = b;
    for (int i = 0; i < a; i++)
    {
        if (s1.GetName()[i] > s2.GetName()[i])
            return 1;
        if (s1.GetName()[i] < s2.GetName()[i])
            return -1;
    }

    return 0;
}
int CompareMathematicsGrades(student s1, student s2) {
    if (s1.GetMathGrade() > s2.GetMathGrade())
        return 1;
    if (s1.GetMathGrade() < s2.GetMathGrade())
        return -1;
    return 0;
}
int CompareEnglishGrades(student s1, student s2) {
    if (s1.GetEnglishGrade() > s2.GetEnglishGrade())
        return 1;
    if (s1.GetEnglishGrade() < s2.GetEnglishGrade())
        return -1;
    return 0;
}
int CompareHistoryGrades(student s1, student s2) {
    if (s1.GetHistoryGrade() > s2.GetHistoryGrade())
        return 1;
    if (s1.GetHistoryGrade() < s2.GetHistoryGrade())
        return -1;
    return 0;
}
int CompareAverageGrades(student s1, student s2) {
    if (s1.RetrieveAverageGrade() > s2.RetrieveAverageGrade())
        return 1;
    if (s1.RetrieveAverageGrade() < s2.RetrieveAverageGrade())
        return -1;
    return 0;
}