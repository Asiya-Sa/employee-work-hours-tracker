#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// function to print the table
void printTable (string days[], string employees[], int hoursWorked[][5],int numOfEmp)
{
    // Set the width for formatting
    const int columnWidth = 10;

    // Print the table header
    cout << setw(columnWidth) << "Employee";
    for (int i = 0; i < 5; ++i) {
        cout << setw(columnWidth) << days[i];
    }
    cout << endl;

    // Print the table content
    for (int emp= 0; emp< numOfEmp; ++emp) {
        cout << setw(columnWidth) << employees[emp];
        for (int day = 0; day < 5; ++day) {
            cout << setw(columnWidth) << hoursWorked[emp][day] ;
        }
        cout << endl;
        
    }

}

int main() {
	
	
    int numEmployees = 4;
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu"};

    string employees[20] = {"Noura", "Aziz", "Deem", "Omar"};
    int hoursWorked[20][5] = {
        {8, 7, 7, 5, 9},  // Noura hours for Sun to Thu
        {9, 9, 10, 12, 5},  // Aziz hours for Sun to Thu
        {6, 10, 11, 10, 9},  // Deem hours for Sun to Thu
        {8, 11, 5, 8, 12}   // Omar hours for Sun to Thu
    };
    printTable(days, employees, hoursWorked,numEmployees);
cout<<endl;  
  
// change the table hours less than 6 
int row, col;
for (row=0; row<numEmployees; row++) {
for (col=0; col<5; col++) {

// modifying working hours to 6 hours

if(hoursWorked[row][col]<6){
hoursWorked[row][col]=6;

// printing the name of employee and the day of the week for employees whose hours were modified

cout<<"The hours for "<<employees [row]<<" on "<<days[col]<< " was changed to be 6 \n";}
}}

// displaying the table after the change
cout<<endl;
cout<<"        ";
for (int i=0; i<5; i++) {
cout<<days[i]<<"\t";
}
cout<<endl;
for (int row=0; row<numEmployees; row++){
cout<<employees[row]<<"\t";
for (col=0; col<5; col++)
cout<<hoursWorked[row][col]<<"\t";
cout<<endl;
}

// calculating the highest and lowest hours of the week
int maxTotalHours = 0;
int maxDayIndex=0;
// Find the day with the highest total working hours
for (int day = 0; day < 5; ++day) {
    int totalHours = 0;
    for (int emp= 0;emp< numEmployees; ++emp) {
        totalHours += hoursWorked[emp][day];
    }
    if (totalHours > maxTotalHours) {
        maxTotalHours = totalHours;
        maxDayIndex = day;
    }
    
}
int minTotalHours = 0; // Initialize with the maximum possible value
int minDayIndex = 0;

// Find the day with the lowest total working hours
for (int day = 0; day < 5; ++day) {
    int totalHours = 0;
    for (int emp = 0; emp < numEmployees; ++emp) {
        totalHours += hoursWorked[emp][day];
    }
    if (totalHours < minTotalHours) {
        minTotalHours = totalHours;
        minDayIndex = day;
    }
}

// Print the days with the and highest lowest total working hours
cout<<endl;
cout << "The Day with the highest total working hours: " << days[maxDayIndex] << endl;
// Print the day with the lowest total working hours
cout << "The Day with the lowest total working hours: " << days[minDayIndex] << endl;

while (true){
    int number;
    cout<<endl;
    // print menu of three options
    cout<<"Choose one of the following options\n1. Add a new Employee.\n2. Enquire about an Employee.\n3. Exit"<<endl;
    cin>>number;
    
    // if the input number is one
    if (number==1){
   
  cout << "Enter the name of the new employee: ";
    cin >> employees[numEmployees];

    cout << "Enter the number of hours for each day separated by a space: ";
    for (int day = 0; day < 5; ++day) {
        cin >> hoursWorked[numEmployees][day];
    }
    numEmployees++;

    printTable(days, employees, hoursWorked, numEmployees);}
    
    // if the input number is two
    else if (number==2) {
    // ask about employee
    string nameEmp;
    cout<<"Enter employee name: ";
    cin>>nameEmp;
    int i=0;
    while (i<nameEmp.length()){
        nameEmp[i]= tolower(nameEmp[i]);
        ++i;
    }
    
    bool found=false;
    int nm=-1;
    int chek=0;
    while ( chek <numEmployees) {
     string lowerName = employees[chek];
     int j=0;
        while (j<lowerName.length()) {
            lowerName[j] = tolower(lowerName[j]);
            ++j;
        }

        if (nameEmp == lowerName) {
            found = true;
            nm = chek;
            break;
        }
        ++chek;
    }
    if (found) {
    	
        // the total of weekly hours
        int workhours=0;
        for (int a=0; a<5; a++){
        workhours=workhours+hoursWorked [nm][a];}
        
        // the day of the highest working working hours 
        int maxH=hoursWorked[nm][0];
        int maxD=0;
        for(int b=1; b<5; b++){
		if (hoursWorked[nm][b]>maxH){
                maxH=hoursWorked[nm][b];
                maxD=b;
            }
        }
        // Calculation of employee salary
        
       int totalsalary = 0;
       for (int day = 0; day < 5; ++day) {
        int Dailysalary;
        
        if (hoursWorked[nm][day] <= 9) {
        Dailysalary = hoursWorked[nm][day] * 100;}
  else {
        Dailysalary = 9 * 100 + (hoursWorked[nm][day] - 9) * 200; }
        
    totalsalary += Dailysalary;
   }
        
    // print the information about the chooosen employee
    cout<<"Employee "<<employees[nm]<<" has worked "<<workhours<<" hours in the week."<<endl;
    cout<<"The day that "<<employees[nm]<<" has the highest working hours is "<<days[maxD]<<endl
 <<employees[nm]<<" Salary: "<<totalsalary<<" SAR in the week."<<endl;;
    }
    else 
    cout<<"Sorry, employee does not exist"<<endl;
}
//// if the input number is three
   else if (number==3){
    cout<<"Thank you for using our system.";
      break;}}

    return 0;
}
