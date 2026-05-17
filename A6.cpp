#include <iostream>
using namespace std;

int main()
{
    string symptom;
    
    cout << "Enter symptom: ";
    getline(cin, symptom);

    if (symptom == "fever")
        cout << "Possible illness: Viral Fever";
    else if (symptom == "cough")
        cout << "Possible illness: Cold";
    else if (symptom == "headache")
        cout << "Possible illness: Migraine";
    else if (symptom == "stomach pain")
        cout << "Possible illness: Gastritis";
    else
        cout << "Consult doctor for proper diagnosis";

    return 0;
}
