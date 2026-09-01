#include <iostream>
using namespace std;

class Employee {
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    Employee() {
        employeeCount++;
        empId = 1000 + employeeCount;
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 10000;
        isActive = true;
    }


    void setName(const string& n) {
        name = n;
        if (n.empty()) {
            cout << "ERROR: Name cannot be empty." << endl;
            return;
        }
    }

    			void setDepartment(const string& dept) {
    					if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations") {
    							department = dept;
    									} else {
    											cout << "ERROR: '" << dept << "' is not a registered department." << endl;
    										}
    						}

    void setGrade(char g) {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D') {
            grade = g;
        } else {
            cout << "ERROR: Invalid grade '" << g << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000) {
            basicSalary = salary;
        } else {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected." << endl;
        }
    }

    void deactivate() {
        isActive = false;
    }

    int getEmpId() const { return empId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    char getGrade() const { return grade; }
    double getBasicSalary() const { return basicSalary; }
    bool getIsActive() const { return isActive; }


    double computeAllowances() const {
        if (grade == 'A') return basicSalary * 0.40;
        if (grade == 'B') return basicSalary * 0.30;
        if (grade == 'C') return basicSalary * 0.20;
        return basicSalary * 0.10;
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();

        if (gross <= 50000) {
            return 0;
        } else if (gross <= 100000) {
            return (gross - 50000) * 0.10;
        } else {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        cout << "============================================" << endl;
        cout << " EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;
        cout << "Emp ID     : " << empId << endl;
        cout << "Name       : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Grade      : " << grade << endl;
        cout << "Status     : " << (isActive ? "Active" : "Inactive") << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Basic Salary       : Rs. " << basicSalary << endl;
        cout << "Allowances         : Rs. " << computeAllowances() << endl;
        cout << "Gross Salary       : Rs. " << computeGrossSalary() << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Tax Deduction      : Rs. " << computeTax() << endl;
        cout << "Net Salary         : Rs. " << computeNetSalary() << endl;
        cout << "============================================" << endl << endl;
    }

    static int getEmployeeCount() {
        return employeeCount;
    }

    void acceptDetails() {
        string tempName, tempDept;
        char tempGrade;
        double tempSalary;

        cout << "Enter name: ";
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, tempName);
        setName(tempName);

        cout << "Enter department: ";
        cin >> tempDept;
        setDepartment(tempDept);

        cout << "Enter grade: ";
        cin >> tempGrade;
        setGrade(tempGrade);

        cout << "Enter basic salary: ";
        cin >> tempSalary;
        setBasicSalary(tempSalary);
    }
};

int Employee::employeeCount = 0;

int main() {

    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();
    if (!e3->getIsActive()) {
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    }

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}

/*
Bonus - Struct Padding

struct Layout1 { char c1; int i; char c2; };
struct Layout2 { int i; char c1; char c2; };

sizeof(Layout1) comes out bigger than sizeof(Layout2) even though both
have the exact same members. Reason is padding.

1. Why sizes differ:
   In Layout1 the compiler places char c1 (1 byte) first, but int i needs
   to start at a 4-byte boundary, so it inserts 3 padding bytes after c1.
   Then int i takes 4 bytes, then char c2 takes 1 byte, and again padding
   is added at the end so the whole struct size is a multiple of the
   largest member (4 bytes). Total ends up around 12 bytes.

   In Layout2 int i already starts at the beginning so no padding needed
   before it. c1 and c2 (1 byte each) fit right after it, and only little
   padding is needed at the end. Total ends up around 8 bytes.

2. What padding is:
   Padding is extra unused bytes the compiler inserts between or after
   struct members so each member lands on a memory address that matches
   its own size requirement (alignment). CPUs read aligned memory faster,
   so compiler adds this automatically even though we did not ask for it.

3. Why member order matters for packet headers / hardware registers:
   Network packets and hardware register maps must match an exact byte
   layout defined by a protocol or a datasheet. If padding bytes sneak in
   because of bad member ordering, the struct no longer matches the wire
   format or the real register layout, and reading/writing it directly
   will corrupt data or send wrong values. So fields should be ordered
   largest to smallest to reduce padding, or packed structs should be used.
*/
