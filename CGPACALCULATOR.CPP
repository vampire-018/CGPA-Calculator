#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate GPA
double calculateGPA(const vector<int>& credits, const vector<double>& grades) {
    int totalCredits = 0;
    double totalGradePoints = 0;

    for (size_t i = 0; i < credits.size(); ++i) {
        totalCredits += credits[i];
        totalGradePoints += credits[i] * grades[i];
    }

    return (totalCredits > 0) ? totalGradePoints / totalCredits : 0.0;
}

int main() {
    vector<vector<int>> semesterCredits;
    vector<vector<double>> semesterGrades;

    char choice;
    do {
        int numCourses;
        cout << "Enter the number of courses for this semester: ";
        cin >> numCourses;

        vector<int> credits(numCourses);
        vector<double> grades(numCourses);

        cout << "\n--- Enter Course Information ---" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << "\nCourse " << i + 1 << ":\n";
            cout << "  Credits: ";
            cin >> credits[i];
            cout << "  Grade (e.g., 4.0, 3.5): ";
            cin >> grades[i];
        }

        semesterCredits.push_back(credits);
        semesterGrades.push_back(grades);

        cout << "\nDo you want to enter another semester's grades? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Output table for each semester and calculate semester GPAs
    cout << "\n--- Semester Course Details and GPAs ---" << endl;
    for (size_t i = 0; i < semesterCredits.size(); ++i) {
        cout << "\nSemester " << i + 1 << " Course Details:" << endl;
        cout << "+-----------------+---------+--------+" << endl;
        cout << "| Course          | Credits | Grade  |" << endl;
        cout << "+-----------------+---------+--------+" << endl;

        for (size_t j = 0; j < semesterCredits[i].size(); ++j) {
            cout << "| " << left << setw(15) << "Course " + to_string(j + 1)
                 << "| " << right << setw(7) << semesterCredits[i][j]
                 << "| " << right << setw(6) << fixed << setprecision(2) << semesterGrades[i][j] << " |" << endl;
        }

        cout << "+-----------------+---------+--------+" << endl;

        double semesterGPA = calculateGPA(semesterCredits[i], semesterGrades[i]);
        cout << "| Semester GPA    | " << right << setw(7) << fixed << setprecision(2) << semesterGPA << " |        |" << endl;
        cout << "+-----------------+---------+--------+" << endl;
    }

    // Calculate final CGPA
    vector<int> allCredits;
    vector<double> allGrades;
    for (size_t i = 0; i < semesterCredits.size(); ++i) {
        allCredits.insert(allCredits.end(), semesterCredits[i].begin(), semesterCredits[i].end());
        allGrades.insert(allGrades.end(), semesterGrades[i].begin(), semesterGrades[i].end());
    }

    double finalCGPA = calculateGPA(allCredits, allGrades);

    // Output final CGPA
    cout << "\n--- Final CGPA ---" << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << finalCGPA << endl;

    return 0;
}
