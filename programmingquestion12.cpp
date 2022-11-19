// QUESTION NUMBER 12 PROGRAMMING EXERCISE CHAPTER 13
#include <iostream>
using namespace std;

class personType
{
    string firstName;
    string lastName;

public:
    personType() {}
    personType(string fName, string lName)
    {

        firstName = fName;
        lastName = lName;
    };
    void setName();
    void print() const;
    string getFirstName();
    string getLastName();
};
void personType::setName()
{
    cout << "enter first name : ";
    cin >> firstName;
    cout << "enter last name : ";
    cin >> lastName;
}

string personType::getFirstName()
{

    return firstName;
}
string personType::getLastName()
{
    return lastName;
}

void personType::print() const
{
    cout << "first name : " << firstName << "\n";
    cout << "last name : " << lastName << "\n";
}
class doctorType : public personType
{
    string doc_spaciality;

public:
    doctorType() {}
    doctorType(string firstName, string LastName, string dp) : doc_spaciality(dp), personType(firstName, LastName) {}
    void setDocSpaciality();
    void dispDocSpaciality();
};

void doctorType::setDocSpaciality()
{
    cout << "enter the doctor spaciality : ";
    getline(cin, doc_spaciality);
}
void doctorType::dispDocSpaciality()
{

    cout << "doctor is : " << doc_spaciality << "\n";
}

class dateType
{
    int dDay, dMonth, dYear, number;

public:
    dateType() {}
    dateType(unsigned int d, unsigned int m, unsigned int y) : dDay(d), dMonth(m), dYear(y) {}
    void setDate();
    void dispDate();
    void setDay();
    void setMonth();
    void setYear();
    int getDay() const;
    int getMonth() const;
    int getyear() const;
};
void dateType::setDate()
{
    cout << "enter the date : ";
    cin >> dDay;
    if (dDay > 0 && dDay < 31)
    {
        cout << "enter the month : ";
        cin >> dMonth;
        if (dMonth > 0 && dMonth <= 12)
        {
            cout << "enter the year : ";
            cin >> dYear;
        }
        else
        {
            cout << "sorry!\ninvalid Month\n";
        }
    }
    else
    {
        cout << "sorry!\ninvalid date\n";
    }
}
void dateType::setYear()
{
    cout << "enter the Year : ";
    cin >> dYear;
}
int dateType::getDay() const
{
    return dDay;
}
int dateType::getMonth() const
{
    return dMonth;
}
int dateType::getyear() const
{
    return dYear;
}

void dateType::dispDate()
{
    cout << dDay << "-" << dMonth << "-" << dYear << "\n";
}

class patientType : public personType
{
    unsigned int patientID, age, DOB, DOA, DOD;
    string attending_doc_name;
    dateType dType;
    doctorType docType;

public:
    patientType() {}
    patientType(unsigned int patientid, unsigned int a, unsigned int dob, unsigned int doa, unsigned int dod, string docName, string fname, string lname) : patientID(patientid), age(a), DOB(dob), DOA(doa), DOD(dod), attending_doc_name(docName), personType(fname, lname) {}
    void setPatientData();
    void dispPatientData();
};
void patientType::setPatientData()
{
    personType::setName();
    cout << "enter patient ID : ";
    cin >> patientID;
    cout << "enter patient date of birth : \n";
    dType.setDate();
    cout << "enter patient Date of addmission in hospital : \n";
    dType.setDate();
    cout << "enter patient Date of discharge form hospital : \n";
    dType.setDate();
    cin.ignore(10, '\n');
    cout << "enter patient attending doctor name : ";
    getline(cin, attending_doc_name);
    docType.setDocSpaciality();
}
void patientType::dispPatientData()
{
    personType::print();
    cout << " patient ID :  " << patientID << "\n";
    cout << " patient age :  ";
    dType.dispDate();
    cout << " patient date of birth  :";
    dType.dispDate();
    cout << " patient date of addmission in hospital :  ";
    dType.dispDate();
    cout << " patien date of discharge from hospital :  ";
    dType.dispDate();
    cout << " patient attending doctor name :  " << attending_doc_name << "\n";
    cout << " doctor credantials : \n";
    docType.dispDocSpaciality();
}

class billType : public patientType
{
    float patient_hospital_charges, madicine_charges;
    unsigned int doc_fee, room_charges;

public:
    billType() {}
    billType(float phc, float mc, unsigned int df, unsigned int rc, unsigned int patientid, unsigned int a, unsigned int dob, unsigned int doa, unsigned int dod, string docName, string fname, string lname) : patient_hospital_charges(phc), madicine_charges(mc), doc_fee(df), room_charges(rc), patientType(patientid, a, dob, doa, dod, docName, fname, lname) {}
    void setBill();
    void dispBill();
};
void billType::setBill()
{
    patientType::setPatientData();
    cout << "enter doctor fee : ";
    cin >> doc_fee;
    cout << "enter the patient hospital charges : ";
    cin >> patient_hospital_charges;
    cout << "enter patient madicine charges  : ";
    cin >> madicine_charges;
    cout << "enter the room charges : ";
    cin >> room_charges;
}
void billType::dispBill()
{
    patientType::dispPatientData();
    cout << "doctor fee : " << doc_fee << "\n";
    cout << "hospital charges : " << patient_hospital_charges << "\n";
    cout << "madicine charges : " << madicine_charges << "\n";
    cout << "patient room charges : " << room_charges << "\n";
}

int main()
{
    billType bType;
    unsigned int option;
    do
    {
        cout << "\n\n\n1 set patient Bil \n";
        cout << "2 display patient Bill \n";
        cout << "3 terminate program \n";
        cout << "enter an option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\n\n";
            bType.setBill();
            cout << "\n\n";
            break;
        case 2:
            cout << "\n\n";
            bType.dispBill();
            cout << "\n\n";
            break;
        case 3:
            cout << "\n\n";
            cout << "program is terminated \n";
            exit(0);
            break;
        default:
            cout << "SORRY!\nINVALID ENTERY \n";
            break;
        }

    } while (option != 3);

    return 0;
}