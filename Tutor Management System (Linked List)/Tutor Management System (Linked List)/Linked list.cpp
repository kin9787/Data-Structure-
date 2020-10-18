#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <iomanip>  
using namespace std;

int choice; int tutorID = 6;


struct TuitionCenter {
	int tuitionCenterCode;
	string tuitionCenterName;
	string tuitionCenterLocation;
};

struct Subject {
	int subjectCode;
	string subjectName;
};

struct Date {
	int dd;
	int mm;
	int yyyy;
};

struct Tutor {
	struct Tutor *previous;
	int tutorID; 
	string tutorFirstName;
	string tutorLastName;
	struct Date*datejoined, *dateTerminated;
	double hourlyPayRate;
	struct TuitionCenter *center;
	struct Subject *teachSub;
	string phoneNumber;
	string tutorAddress;
	int rating;
	struct Tutor *next;
} *start, *newnode, *back, *current, *last;


/*function that checks whether the list is empty or full*/
int check_vacant_slot(Tutor *temp) {
	int emptySlot = 0; int vacantSlot = 0;
	if (start == NULL) {
		return 1; //if the start is empty, it will return 1 meaning the list is empty
	}
	else {
		while (temp != NULL) { // while the pointer is not null continue to tranverse the next pointer
			vacantSlot++; //will increment the vacantSlot
			temp = temp->next;
		}
		emptySlot = 100 - vacantSlot; // calculate empty slots in system
		if (emptySlot == 0) {
			return 2; //if the empty slot is 0, it will return 2 meaning the list is full
		}
		else {
			return 3;
		}
	}
}

/*bubble sort sorting algorithm for sorting the linked list based given choice*/
void bubbleSort(struct Tutor *start, int choice)
{
	int swapped, i;
	struct Tutor *ptr1;
	struct Tutor *lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;
	switch (choice) {
	case 1:
		do {
			swapped = 0;
			ptr1 = start;
			while (ptr1->next != lptr) // while pointer ptr1 is not NULL continue to transverse
			{	
				/*if the given choice is 1 means is sorting by tutorID
				  thus, if current tutor id is greater than the next tutor id
				  then it will continue to swap the positions*/
				if (ptr1->tutorID > ptr1->next->tutorID)
				{
					swap(ptr1->tutorID, ptr1->next->tutorID); swap(ptr1->tutorFirstName, ptr1->next->tutorFirstName);
					swap(ptr1->tutorLastName, ptr1->next->tutorLastName);
					swap(ptr1->datejoined->dd, ptr1->next->datejoined->dd); swap(ptr1->datejoined->mm, ptr1->next->datejoined->mm);
					swap(ptr1->datejoined->yyyy, ptr1->next->datejoined->yyyy);
					swap(ptr1->dateTerminated->dd, ptr1->next->dateTerminated->dd); swap(ptr1->dateTerminated->mm, ptr1->next->dateTerminated->mm);
					swap(ptr1->dateTerminated->yyyy, ptr1->next->dateTerminated->yyyy);
					swap(ptr1->hourlyPayRate, ptr1->next->hourlyPayRate);
					swap(ptr1->center->tuitionCenterCode, ptr1->next->center->tuitionCenterCode);
					swap(ptr1->center->tuitionCenterName, ptr1->next->center->tuitionCenterName);
					swap(ptr1->center->tuitionCenterLocation, ptr1->next->center->tuitionCenterLocation);
					swap(ptr1->teachSub->subjectCode, ptr1->next->teachSub->subjectCode);
					swap(ptr1->teachSub->subjectName, ptr1->next->teachSub->subjectName);
					swap(ptr1->phoneNumber, ptr1->next->phoneNumber); swap(ptr1->tutorAddress, ptr1->next->tutorAddress);
					swap(ptr1->rating, ptr1->next->rating);
					swapped = 1; //set swap = 1 meaning it needs to continue to perform sorting
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped); // if the swap is 0 it will then stop the sort
		break;
	case 2:
		do {
			swapped = 0;
			ptr1 = start;

			while (ptr1->next != lptr) // while pointer ptr1 is not NULL continue to transverse
			{
				/*if the given choice is 2 means is sorting by tuition centre
				thus, if current tuition centre code is greater than the tuition centre code
				then it will continue to swap the positions*/
				if (ptr1->center->tuitionCenterCode > ptr1->next->center->tuitionCenterCode)
				{
					swap(ptr1->tutorID, ptr1->next->tutorID); swap(ptr1->tutorFirstName, ptr1->next->tutorFirstName);
					swap(ptr1->tutorLastName, ptr1->next->tutorLastName);
					swap(ptr1->datejoined->dd, ptr1->next->datejoined->dd); swap(ptr1->datejoined->mm, ptr1->next->datejoined->mm);
					swap(ptr1->datejoined->yyyy, ptr1->next->datejoined->yyyy);
					swap(ptr1->dateTerminated->dd, ptr1->next->dateTerminated->dd); swap(ptr1->dateTerminated->mm, ptr1->next->dateTerminated->mm);
					swap(ptr1->dateTerminated->yyyy, ptr1->next->dateTerminated->yyyy);
					swap(ptr1->hourlyPayRate, ptr1->next->hourlyPayRate);
					swap(ptr1->center->tuitionCenterCode, ptr1->next->center->tuitionCenterCode);
					swap(ptr1->center->tuitionCenterName, ptr1->next->center->tuitionCenterName);
					swap(ptr1->center->tuitionCenterLocation, ptr1->next->center->tuitionCenterLocation);
					swap(ptr1->teachSub->subjectCode, ptr1->next->teachSub->subjectCode);
					swap(ptr1->teachSub->subjectName, ptr1->next->teachSub->subjectName);
					swap(ptr1->phoneNumber, ptr1->next->phoneNumber); swap(ptr1->tutorAddress, ptr1->next->tutorAddress);
					swap(ptr1->rating, ptr1->next->rating);
					swapped = 1; //set swap = 1 meaning it needs to continue to perform sorting
				}
				ptr1 = ptr1->next; 
			}
			lptr = ptr1;
		} while (swapped); // if the swap is 0 it will then stop the sort
		break;
	case 3:
		do {
			swapped = 0;
			ptr1 = start;

			while (ptr1->next != lptr) // while pointer ptr1 is not NULL continue to transverse
			{
				/*if the given choice is 3 means is sorting by hourly pay rate
				thus, if current hourly pay rate is greater than the next hourly pay rate
				then it will continue to swap the positions*/
				if (ptr1->hourlyPayRate > ptr1->next->hourlyPayRate)
				{
					swap(ptr1->tutorID, ptr1->next->tutorID); swap(ptr1->tutorFirstName, ptr1->next->tutorFirstName);
					swap(ptr1->tutorLastName, ptr1->next->tutorLastName);
					swap(ptr1->datejoined->dd, ptr1->next->datejoined->dd); swap(ptr1->datejoined->mm, ptr1->next->datejoined->mm);
					swap(ptr1->datejoined->yyyy, ptr1->next->datejoined->yyyy);
					swap(ptr1->dateTerminated->dd, ptr1->next->dateTerminated->dd); swap(ptr1->dateTerminated->mm, ptr1->next->dateTerminated->mm);
					swap(ptr1->dateTerminated->yyyy, ptr1->next->dateTerminated->yyyy);
					swap(ptr1->hourlyPayRate, ptr1->next->hourlyPayRate);
					swap(ptr1->center->tuitionCenterCode, ptr1->next->center->tuitionCenterCode);
					swap(ptr1->center->tuitionCenterName, ptr1->next->center->tuitionCenterName);
					swap(ptr1->center->tuitionCenterLocation, ptr1->next->center->tuitionCenterLocation);
					swap(ptr1->teachSub->subjectCode, ptr1->next->teachSub->subjectCode);
					swap(ptr1->teachSub->subjectName, ptr1->next->teachSub->subjectName);
					swap(ptr1->phoneNumber, ptr1->next->phoneNumber); swap(ptr1->tutorAddress, ptr1->next->tutorAddress);
					swap(ptr1->rating, ptr1->next->rating);
					swapped = 1; //set swap = 1 meaning it needs to continue to perform sorting
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped); // if the swap is 0 it will then stop the sort
		break;
	case 4:
		do {
			swapped = 0;
			ptr1 = start;

			while (ptr1->next != lptr) // while pointer ptr1 is not NULL continue to transverse
			{
				/*if the given choice is 4 means is sorting by rating
				thus, if current rating is greater than the next rating
				then it will continue to swap the positions*/
				if (ptr1->rating > ptr1->next->rating)
				{
					swap(ptr1->tutorID, ptr1->next->tutorID); swap(ptr1->tutorFirstName, ptr1->next->tutorFirstName);
					swap(ptr1->tutorLastName, ptr1->next->tutorLastName);
					swap(ptr1->datejoined->dd, ptr1->next->datejoined->dd); swap(ptr1->datejoined->mm, ptr1->next->datejoined->mm);
					swap(ptr1->datejoined->yyyy, ptr1->next->datejoined->yyyy);
					swap(ptr1->dateTerminated->dd, ptr1->next->dateTerminated->dd); swap(ptr1->dateTerminated->mm, ptr1->next->dateTerminated->mm);
					swap(ptr1->dateTerminated->yyyy, ptr1->next->dateTerminated->yyyy);
					swap(ptr1->hourlyPayRate, ptr1->next->hourlyPayRate);
					swap(ptr1->center->tuitionCenterCode, ptr1->next->center->tuitionCenterCode);
					swap(ptr1->center->tuitionCenterName, ptr1->next->center->tuitionCenterName);
					swap(ptr1->center->tuitionCenterLocation, ptr1->next->center->tuitionCenterLocation);
					swap(ptr1->teachSub->subjectCode, ptr1->next->teachSub->subjectCode);
					swap(ptr1->teachSub->subjectName, ptr1->next->teachSub->subjectName);
					swap(ptr1->phoneNumber, ptr1->next->phoneNumber); swap(ptr1->tutorAddress, ptr1->next->tutorAddress);
					swap(ptr1->rating, ptr1->next->rating);
					swapped = 1; //set swap = 1 meaning it needs to continue to perform sorting
				}
				ptr1 = ptr1->next;
			}
			lptr = ptr1;
		} while (swapped); // if the swap is 0 it will then stop the sort
		break;
	}
}

/*recursive linear search algorithm searching the pointer that given tutor id is at*/
Tutor *search(Tutor *temp, int tutorID) {
	/*checking the pointer given*/
	if (temp == NULL) // if the given pointer is NULL, return.
	{
		return temp;
	}
	else
	{
		/*checking the whether the tutor id in current link list*/
		if (temp->tutorID == tutorID) //if the current linked list tutor id is the same as the one given by user, return the pointer;
		{
			return temp;
		}
		else {
			search(temp->next, tutorID); // if the tutor ID is not found in the current pointer, perform recursive searching passing the next pointer
		}
	}
}

/*enter new details of the tutor into newnode*/
void enterDetails() {
	int choice; char seperator;
	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0; //set the date terminated = 0/0/0
	cout << "\t|      ENTER TUTOR DETAILS MENU      |" << endl;
	cout << "	Generated Tutor ID                  : " << tutorID << endl; // print generated tutor ID
	cout << "	Please enter Tutor Name             : ";
	cin >> newnode->tutorFirstName;
	cout << "	Please enter The Last Name of Tutor : ";
	cin >> newnode->tutorLastName;
	cout << "	Please enter Tutor Date Joined      : " << endl;
	cout << "	Format (DD/MM/YYYY)                 : ";
	cin >> newnode->datejoined->dd; cin >> seperator;
	cin >> newnode->datejoined->mm; cin >> seperator;
	cin >> newnode->datejoined->yyyy;
	cout << "	Please enter Hourly Pay Rate (40-80): ";
hourInsert:
	cin >> newnode->hourlyPayRate;
	/*check whether given hourly pay rate input is valid 40 to 80*/
	if (newnode->hourlyPayRate < 40 || newnode->hourlyPayRate> 80) {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT   : ";
		goto hourInsert; //it will go to the hourInsert location if given input is not valid which is (40-80)
	}
	cout << "	Please select Tuition Center        : " << endl;
	cout << "	1. Bukit Bintang " << endl << "	2. Bukit Jalil" << endl << "	3. Puchong" << endl;
	cout << "	4. Cheras" << endl << "	5. Kepong" << endl << "\tPlease insert choice (1-5) : ";
error:
	cin >> choice;
	/*check whether given choice input is valid 1 to 5*/
	switch (choice) {
	case 1:
		newnode->center->tuitionCenterCode = 1001;
		newnode->center->tuitionCenterName = "Alpha";
		newnode->center->tuitionCenterLocation = "Bukit Bintang";
		break;
	case 2:
		newnode->center->tuitionCenterCode = 1002;
		newnode->center->tuitionCenterName = "Beta";
		newnode->center->tuitionCenterLocation = "Bukit Jalil";
		break;
	case 3:
		newnode->center->tuitionCenterCode = 1003;
		newnode->center->tuitionCenterName = "Omega";
		newnode->center->tuitionCenterLocation = "Puchong";
		break;
	case 4:
		newnode->center->tuitionCenterCode = 1004;
		newnode->center->tuitionCenterName = "Lamda";
		newnode->center->tuitionCenterLocation = "Cheras";
		break;
	case 5:
		newnode->center->tuitionCenterCode = 1005;
		newnode->center->tuitionCenterName = "Super";
		newnode->center->tuitionCenterLocation = "Kepong";
		break;
	default:
		cout << "\tWRONG SELECTION, PLEASE TRY AGAIN!" << endl << "\t";
		goto error; //it will go to the error location if given input is not 1 to 5
	}
	cout << "	Please select Subject Taught        : " << endl;
	cout << "	1. Chinese " << endl << "	2. Malay" << endl << "	3. English" << endl;
	cout << "	4. Mathematics" << endl << "	5. Science" << endl << "\tPlease insert choice (1-5) : ";
error1:
	cin >> choice;
	/*check whether given choice input is valid 1 to 5*/
	switch (choice) {
	case 1:
		newnode->teachSub->subjectCode = 2001;
		newnode->teachSub->subjectName = "Chinese";
		break;
	case 2:
		newnode->teachSub->subjectCode = 2002;
		newnode->teachSub->subjectName = "Malay";
		break;
	case 3:
		newnode->teachSub->subjectCode = 2003;
		newnode->teachSub->subjectName = "English";
		break;
	case 4:
		newnode->teachSub->subjectCode = 2004;
		newnode->teachSub->subjectName = "Mathematics";
		break;
	case 5:
		newnode->teachSub->subjectCode = 2005;
		newnode->teachSub->subjectName = "Science";
		break;
	default:
		cout << "\tWRONG SELECTION, PLEASE TRY AGAIN!" << endl << "\t";
		goto error1; //it will go to the error1 location if given input is not 1 to 5
		break;
	}
	cout << "	Please enter Phone Number           : ";
	cin >> newnode->phoneNumber;
	cout << "	Please enter Tutor Address          : ";
	cin.ignore();
	getline(cin, newnode->tutorAddress);
	cout << "	Please enter Tutor Rating     (1-5) : ";
ratingInsert:
	cin >> newnode->rating;
	/*check whether given choice input is valid 1 to 5*/
	if (newnode->rating < 1 || newnode->rating >5) {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT   : ";
		goto ratingInsert; //it will go to the ratingInsert if given input is not 1 to 5
	}
	Sleep(2000);
	cout << endl << "\t*****     Entered Details Successful     *****";
	Sleep(2000); system("CLS");
}

/*add tutor details in the end of linked list*/
void addTutorDetails() {
	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = tutorID;
	newnode->next = NULL;
	newnode->previous = NULL;
	/*check whether start of linked list is empty*/
	if (start == NULL) {
		enterDetails(); //enter details into new node
		tutorID = tutorID + 1; //increment the generated tutor ID
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		enterDetails(); //enter details into new node
		tutorID = tutorID + 1; //increment the generated tutor ID
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}
}

/*displaying all the tutoir details in an ascending order*/
void display_ascending() {
	system("CLS");
	/*formating for the title for details of tutor*/
	cout << "\t| TUTOR DETAILS |" << endl << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; cout << setw(14) << "|DATE JOINED|";
	cout << setw(18) << "|DATE TERMINATED|"; cout << setw(6) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	int i = 0;
	current = start; // set current node = start node
	/*while the current node is not null, print all the details of the tutor of the current node*/
	while (current != NULL) {
		cout << "\t" << setw(6) << current->tutorID << setw(14) << current->tutorFirstName << setw(13) << current->tutorLastName << setw(7);
		cout << current->datejoined->dd << "/" << current->datejoined->mm << "/" << current->datejoined->yyyy << setw(10);
		cout << current->dateTerminated->dd << "/" << current->dateTerminated->mm << "/" << current->dateTerminated->yyyy << setw(11);
		cout << current->hourlyPayRate << setw(10) << current->center->tuitionCenterCode << setw(21) << current->center->tuitionCenterLocation;
		cout << setw(11) << current->center->tuitionCenterName;
		cout << setw(12) << current->teachSub->subjectCode << setw(13) << current->teachSub->subjectName;
		cout << setw(17) << current->phoneNumber << setw(30) << current->tutorAddress;
		cout << setw(10) << current->rating;
		cout << endl;
		current = current->next; // set the current node to next node
	}
	/*press enter to leave the current function*/
	cout << "	PRESS ENTER TO LEAVE ......" << endl;
	cout << "	"; cin.get();
	if (cin.get() == '\n') {
		cout << "	EXITING BACK TO MAIN MENU	" << endl;
		Sleep(2000); //wait for 2 seconds
		system("CLS"); //clear the screen
	}
}

/*displaying all the tutoir details in an descending order*/
void display_descending() {
	system("CLS");
	/*formating for the title for details of tutor*/
	cout << "\t| TUTOR DETAILS |" << endl << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; cout << setw(14) << "|DATE JOINED|";
	cout << setw(18) << "|DATE TERMINATED|"; cout << setw(6) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	int i = 0;
	current = last;
	// set current node = last node
	/*while the current node is not null, print all the details of the tutor of the current node*/
	while (current != NULL) {
		cout << "\t" << setw(6) << current->tutorID << setw(14) << current->tutorFirstName << setw(13) << current->tutorLastName << setw(7);
		cout << current->datejoined->dd << "/" << current->datejoined->mm << "/" << current->datejoined->yyyy << setw(10);
		cout << current->dateTerminated->dd << "/" << current->dateTerminated->mm << "/" << current->dateTerminated->yyyy << setw(11);
		cout << current->hourlyPayRate << setw(10) << current->center->tuitionCenterCode << setw(21) << current->center->tuitionCenterLocation;
		cout << setw(11) << current->center->tuitionCenterName;
		cout << setw(12) << current->teachSub->subjectCode << setw(13) << current->teachSub->subjectName;
		cout << setw(17) << current->phoneNumber << setw(30) << current->tutorAddress;
		cout << setw(10) << current->rating;
		cout << endl;
		current = current->previous; // set the current node to previous node
	}
	cout << "	PRESS ENTER TO LEAVE ......" << endl;
	cout << "	"; cin.get();
	/*press enter to leave the current function*/
	if (cin.get() == '\n') {
		cout << "	EXITING BACK TO MAIN MENU	" << endl;
		Sleep(2000);
		system("CLS");
	}
}

/*menu for choosing the orientation that user wants to display*/
void display_orientation() {
	int choice;
	cout << "\tHOW WOULD YOU LIKE TO DISPLAY IT?" << endl;
	cout << "\t1. ASCENDING ORDER" << endl;
	cout << "\t2. DESCENDING ORDER" << endl;
	cout << "\t3. EXIT BACK TO MAIN MENU" << endl;
error:
	cout << "\t";
	cin >> choice;
	switch (choice) {
	case 1:
		display_ascending(); //call display ascending function
		break;
	case 2:
		display_descending(); //call display descending function
		break;
	case 3:
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait 3 seconds
		system("CLS"); //clear the screen
		return;
	default:
		cout << "	INPUT IS NOT VALID PLEASE TRY AGAIN !";
		goto error;
	}
}

/*menu for choosing the elements for sorting*/
void display_tutor_menu() {
	int choice; int i = 0; int arraySize = 0;
	cout << "\t|     CHOOSE WHICH DATA TO SORT BY ?     |" << endl << endl << endl;
	cout << "\t|  1. TUTOR ID                           |" << endl;
	cout << "\t|  2. TUITION CENTRE                     |" << endl;
	cout << "\t|  3. HOURLY WAGE                        |" << endl;
	cout << "\t|  4. TUTOR RATING                       |" << endl;
	cout << "\t|  5. EXIT                               |" << endl;
	cout << "\t|        PLEASE ENTER A CHOICE !         |" << endl << "\t";
error:
	cin >> choice;
	/*check if the choice given is a valid choice*/
	if (choice >= 0 && choice <= 4) {
		bubbleSort(start, choice); //call the bubble sort function and pass the choice to the function
		display_orientation(); //call display orientation function
	}
	else if (choice == 5) {
		cout << "	**      RETURNING TO MAIN MENU      **";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear screen
	}
	else {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT";
		Sleep(2000); //wait for 3 seconds
		goto error; //go to the error location
	}
}

/*deleting the last node/tutor*/
void delete_last_tutor(Tutor *temp) {
	temp = last; //set the current node = last node
	last->previous->next = NULL; //the next pointer for the previous node of the last node will be set to NULL
	last = last->previous; //the last node is now the previous node of the current last node
	delete temp; //delete the current node
}

/*deleting the first node/tutor*/
void delete_first_tutor(Tutor *temp) {
	temp = start; //set the current node = start node
	start->next->previous = NULL; //the next pointer for the previous node of the start node will be set to NULL
	start = start->next; //the start node is now the next node of the current start node
	delete temp; //delete the current node
}

/*menu for deleting the tutor*/
void delete_tutor_details(Tutor *temp) {
	char seperator; int dayOfContract;
	/*display the tutor details of the searched tutor*/
	cout << "\t| TUTOR DETAILS |" << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|" << setw(14) << "|DATE JOINED|" << endl;
	cout << "\t" << setw(6) << temp->tutorID << setw(13) << temp->tutorFirstName << setw(14) << temp->tutorLastName << setw(7);
	cout << temp->datejoined->dd << "/" << temp->datejoined->mm << "/" << temp->datejoined->yyyy << "\t" << endl;
	cout << "\t WHAT IS THE TEMINATION DATE OF THE USER? (DD/MM/YYY) : ";
	cin >> temp->dateTerminated->dd; cin >> seperator; //ask for the termination date of the tutor
	cin >> temp->dateTerminated->mm; cin >> seperator;
	cin >> temp->dateTerminated->yyyy;
	dayOfContract = (temp->dateTerminated->dd + temp->dateTerminated->mm * 30 + temp->dateTerminated->yyyy * 365) -
		(temp->datejoined->dd + temp->datejoined->mm * 30 + temp->datejoined->yyyy * 365); //calculate the days by subtracting the date terminated with the date joined in days
	/*checks whether the day of contract is over 60 days*/
	if (dayOfContract >= 60) {
		char choice;
		system("CLS");
		/*display the tutor details of the searched tutor*/
		cout << "\t| DELETE TUTOR MENU |" << endl;
		cout << "\t| TUTOR DETAILS |" << endl;
		cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; cout << setw(14) << "|DATE JOINED|";
		cout << setw(18) << "|DATE TERMINATED|"; cout << setw(3) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
		cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
		cout << "\t" << setw(6) << temp->tutorID << setw(14) << temp->tutorFirstName << setw(13) << temp->tutorLastName << setw(7);
		cout << temp->datejoined->dd << "/" << temp->datejoined->mm << "/" << temp->datejoined->yyyy << setw(10);
		cout << temp->dateTerminated->dd << "/" << temp->dateTerminated->mm << "/" << temp->dateTerminated->yyyy << setw(11);
		cout << temp->hourlyPayRate << setw(10) << temp->center->tuitionCenterCode << setw(21) << temp->center->tuitionCenterLocation;
		cout << setw(11) << temp->center->tuitionCenterName;
		cout << setw(12) << temp->teachSub->subjectCode << setw(13) << temp->teachSub->subjectName;
		cout << setw(17) << temp->phoneNumber << setw(30) << temp->tutorAddress;
		cout << setw(10) << temp->rating;
		cout << endl << endl;
	error:
		cout << "\tARE YOU SURE THIS IS THE RECORD YOU WANT TO DELETE? (Y/N) : "; //confirmation for deletion
		cin >> choice;
		/*check whether choice is Y or N*/
		if (toupper(choice) == 'Y') {
			cout << "\t PERFORMING DELETION........"; Sleep(3000);
			/*check whether current node is the start or last node*/
			if (temp == start && temp == last) { //current node is the start and last node
				start = NULL; //set start node = NULL
			}
			else if (temp == start) { //current node is the start node
				delete_first_tutor(temp); //call delete first tutor function
			}
			else if (temp == last) { //start node is the start node
				delete_last_tutor(temp); //call delete last tutor function
			}
			else {
				back = temp->previous; //back node is now the previous node of the current node;
				back->next = back->next->next; // the next pointer of the back node is not the next and next pointer of the back node
				temp->next->previous = back; // the pointer next previous of the current node is now the back node
				delete temp; //delete the current node
			}
			cout << endl << endl << "\tSUCCESSFULLY DELETED !" << endl;
			Sleep(3000); //wait for 3 seconds
			cout << "	*****      RETURNING TO MAIN MENU      *****";
			Sleep(3000); //wait for 3 seconds
			system("CLS"); //clear the screen
		}
		else if (toupper(choice) == 'N') {
			cout << "\tPLEASE TRY AGAIN !!!" << endl << endl;
			cout << "	*****      RETURNING TO MAIN MENU      *****";
			Sleep(3000); //wait for 3 seconds
			system("CLS"); //clear the screen
			return;
		}
		else {
			cout << "\tPLEASE INSERT A VALID INPUT!";
			goto error; //go to the error position
		}
	}
	else {
		cout << "\tTERMINATION DATE IS NOT OVER 60 DAYS!" << endl << endl;
		cout << "\tDELETE EXECUTION DENIED" << endl;
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait for 3 seconds
		system("CLS");  //clear the screen
		return;
	}

}

/*modify tutor details*/
void modify_tutor_details(Tutor *temp) {
	int choice;
	string address, phoneNumber;
	char confirm; char choiceConfirm;
	system("CLS"); //clear the screen
	/*display the details of the tutor that to be modified*/
	cout << "\t| MODIFY TUTOR MENU |" << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|";
	cout << setw(6) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	cout << "\t" << setw(6) << temp->tutorID << setw(13) << temp->tutorFirstName << setw(13) << temp->tutorLastName << setw(8);
	cout << temp->hourlyPayRate << setw(10) << temp->center->tuitionCenterCode << setw(21) << temp->center->tuitionCenterLocation;
	cout << setw(12) << temp->center->tuitionCenterName;
	cout << setw(12) << temp->teachSub->subjectCode << setw(13) << temp->teachSub->subjectName;
	cout << setw(16) << temp->phoneNumber << setw(30) << temp->tutorAddress;
	cout << setw(10) << temp->rating;
	cout << endl << endl;
error:
	cout << "\tARE YOU SURE THIS IS THE RECORD YOU WANT TO MODIFY? (Y/N) : ";
	cin >> choiceConfirm;
	/*check if user is to modify this detail*/
	if (toupper(choiceConfirm) == 'Y') {
		cout << "\tWHICH DETAILS WOULD YOU LIKE TO CHANGE?" << endl;
		cout << "\t1. PHONE NUMBER" << endl;
		cout << "\t2. ADDRESS     " << endl;
		cout << "\t3. EXIT BACK TO MAIN MENU" << endl << "\t";
	retry:
		cin >> choice;
		/*check the choice of the user*/
		switch (choice) {
		case 1:
		phoneConfirmation:
			cout << "\tPLEASE INSERT NEW PHONE NUMBER : ";
			cin >> phoneNumber;
			cout << "\tYOU ENTERED THE NUMBER " << phoneNumber << endl;
		wrongInput:
			cout << "\tIS THIS THE PHONE NUMBER YOU WANTED? (Y/N)" << endl << "\t";
			cin >> confirm;
			/*validate if customer had key in the right number*/
			if (toupper(confirm) == 'Y') {
				temp->phoneNumber = phoneNumber; //set the current node phone number to the new number given
				cout << "\tPHONE NUMBER HAD SUCCESSFULLY CHANGED" << endl;
				Sleep(3000); //wait 3 second
				cout << "	*****      RETURNING TO MAIN MENU      *****";
				Sleep(3000); //wait 3 second
				system("CLS"); //clear the screen
				return;
			}
			else if (toupper(confirm) == 'N') {
				cout << "\tINSERT AGAIN " << endl;
				goto phoneConfirmation; //go to phoneConfirmation location
			}
			else {
				cout << "\tWRONG INPUT, PLEASE TRY AGAIN" << endl;
				goto wrongInput; //go to wronmgInput location
			}
			break;
		case 2:
		addressConfirmation:
			cout << "\tPLEASE INSERT ADDRESS : ";
			cin.ignore();
			getline(cin, address);
			cout << "\tYOU ENTERED THE ADDRESS " << address << endl;
		wrongInputA:
			cout << "\tIS THIS THE ADDRESS YOU WANTED? (Y/N)" << endl << "\t";
			cin >> confirm;
			/*validate if customer had key in the right address*/
			if (toupper(confirm) == 'Y') {
				temp->tutorAddress = address;
				cout << "\tADDRESS HAD SUCCESSFULLY CHANGED" << endl;
				Sleep(3000); //wait for 3 seconds
				cout << "	*****      RETURNING TO MAIN MENU      *****";
				Sleep(3000); //wait for 3 seconds
				system("CLS"); //clear the screen
				return;
			}
			else if (toupper(confirm) == 'N') {
				cout << "\tINSERT AGAIN " << endl;
				goto addressConfirmation; //go to addressConfirmation location
			}
			else {
				cout << "\tWRONG INPUT, PLEASE TRY AGAIN" << endl;
				goto wrongInputA; //go to wronginputA location
			}
			break;
		case 3:
			cout << "	*****      RETURNING TO MAIN MENU      *****";
			Sleep(3000); //wait for 3 seconds
			system("CLS");
			break;
		default:
			cout << "\tTHE INPUT IS NOT VALID, PLEASE TRY AGAIN !" << endl;
			goto retry; //go to retry location
		}
	}
	else if (toupper(choiceConfirm) == 'N') {
		cout << "\tPLEASE TRY AGAIN !" << endl << endl;
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear the screen
	}
	else {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT!" << endl;
		Sleep(3000); //wait for 3 seconds
		goto error; //clear the screen
	}

}

/*menu for choosing for modify or delete tutor details*/
void modify_tutor_menu() {
	int choice; int x; int n; int r; int arraySize = 0; int i = 0;
modifymenu:
	cout << "\t|  WELCOME TO MODIFY TUTOR MENU!  |" << endl << endl << endl;
	cout << "\t|  1. MODIFY TUTOR DETAILS        |" << endl;
	cout << "\t|  2. DELETE TUTOR DETAILS        |" << endl;
	cout << "\t|  3. EXIT TO MAIN MENU           |" << endl;
	cout << "\t|     PLEASE ENTER A CHOICE !     |" << endl << "\t";
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "\tPLEASE ENTER THE TUTOR ID YOU WANT TO SEARCH : "; cin >> x;
		current = start;
		current = search(current, x); //find the node of the searched tutor ID
		/*check whether current node is NULL*/
		if (current == NULL) {
			cout << "\tTHERE IS NO SUCH RECORD!!!" << endl;
			cout << "	*****      RETURNING TO MODIFY MENU      *****";
			Sleep(3000); //wait for 3 sefcond
			system("CLS"); //clear the screen
			goto modifymenu; //goto modifymenu location
		}
		else {
			modify_tutor_details(current); //call the modify function
		}
		break;
	case 2:
		cout << "\tPLEASE ENTER THE TUTOR ID YOU WANT TO SEARCH : "; cin >> x;
		current = start;
		current = search(current, x); //find the node of the searched tutor ID
		/*check whether current node is NULL*/
		if (current == NULL) {
			cout << "\tTHERE IS NO SUCH RECORD!!!" << endl;
			cout << "	*****      RETURNING TO MODIFY MENU      *****";
			Sleep(3000);
			system("CLS");
			goto modifymenu;
		}
		else {
			delete_tutor_details(current); //call the delete function
		}
		break;

	case 3:
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear the screen
		break;
	default:
		cout << "	PLEASE ENTER A VALID INPUT";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear the screen
		goto modifymenu;
	}
}

/*menu for generating the number of vacant and empty slots of the system*/
void generate_report_menu() {
	int i = 0; int emptySlot = 0; int vacantSlot = 0; int random;
	/*check whether start node is not NULL*/
	if (start != NULL) {
		/*while the current node is not NULL tranverse*/
		while (current != NULL) {
			vacantSlot++; //increment vacantSlot
			current = current->next;
		}
		emptySlot = 100 - vacantSlot; //calculate empty slot
		/*Display the number of available and vacant slot*/
		cout << "	AVAILABLE SLOT = " << emptySlot << endl;
		cout << "	VACANT SLOT    = " << vacantSlot << endl;
		cout << "	PRESS ENTER TO LEAVE ......" << endl;
		cout << "	"; cin.get();
		/*check enter to leave*/
		if (cin.get() == '\n') {
			cout << "	EXITING BACK TO MAIN MENU	" << endl;
			Sleep(2000); //wait for 2 seconds
			system("CLS"); //clear the screen
		}
	}
	else {
		emptySlot = 100; //set the empty slot = 100 since start node is empty
		cout << "	AVAILABLE SLOT = " << emptySlot << endl;
		cout << "	VACANT SLOT    = " << vacantSlot << endl;
		cout << "	PRESS ENTER TO LEAVE ......" << endl;
		cout << "	"; cin.get();
		if (cin.get() == '\n') {
			cout << "	EXITING BACK TO MAIN MENU	" << endl;
			Sleep(2000); //wait for 2 seconds
			system("CLS"); //clear the screen
		}
	}
}

void initialize_data() {
	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = 1;
	newnode->next = NULL;
	newnode->previous = NULL;

	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0;
	newnode->center->tuitionCenterCode = 1001;
	newnode->center->tuitionCenterName = "Alpha";
	newnode->center->tuitionCenterLocation = "Bukit Bintang";
	newnode->tutorFirstName = "Mark";
	newnode->tutorLastName = "aas";
	newnode->hourlyPayRate = 54;
	newnode->datejoined->dd = 23;
	newnode->datejoined->mm = 2;
	newnode->datejoined->yyyy = 1999;
	newnode->teachSub->subjectCode = 2001;
	newnode->teachSub->subjectName = "Chinese";
	newnode->phoneNumber = "0123455";
	newnode->tutorAddress = "20, Jln Mas, Tmn Mas";
	newnode->rating = 3;

	if (start == NULL) {
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}

	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = 2;
	newnode->next = NULL;
	newnode->previous = NULL;

	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0;
	newnode->center->tuitionCenterCode = 1001;
	newnode->center->tuitionCenterName = "Alpha";
	newnode->center->tuitionCenterLocation = "Bukit Bintang";
	newnode->tutorFirstName = "Loo";
	newnode->tutorLastName = "Jas";
	newnode->hourlyPayRate = 40;
	newnode->datejoined->dd = 12;
	newnode->datejoined->mm = 5;
	newnode->datejoined->yyyy = 2020;
	newnode->teachSub->subjectCode = 2001;
	newnode->teachSub->subjectName = "Malay";
	newnode->phoneNumber = "0123455";
	newnode->tutorAddress = "12, Jln Mas, Tmn Bukit";
	newnode->rating = 2;

	if (start == NULL) {
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}

	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = 3;
	newnode->next = NULL;
	newnode->previous = NULL;

	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0;
	newnode->center->tuitionCenterCode = 1002;
	newnode->center->tuitionCenterName = "Beta";
	newnode->center->tuitionCenterLocation = "Bukit Jalil";
	newnode->tutorFirstName = "Kai";
	newnode->tutorLastName = "Jin";
	newnode->hourlyPayRate = 80;
	newnode->datejoined->dd = 12;
	newnode->datejoined->mm = 1;
	newnode->datejoined->yyyy = 2012;
	newnode->teachSub->subjectCode = 2001;
	newnode->teachSub->subjectName = "Chinese";
	newnode->phoneNumber = "112333";
	newnode->tutorAddress = "20, Jln Mas, Kuala Lumpur";
	newnode->rating = 5;

	if (start == NULL) {
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}

	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = 4;
	newnode->next = NULL;
	newnode->previous = NULL;

	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0;
	newnode->center->tuitionCenterCode = 1004;
	newnode->center->tuitionCenterName = "Lamda";
	newnode->center->tuitionCenterLocation = "Cheras";
	newnode->tutorFirstName = "Lee";
	newnode->tutorLastName = "Jin";
	newnode->hourlyPayRate = 40;
	newnode->datejoined->dd = 20;
	newnode->datejoined->mm = 5;
	newnode->datejoined->yyyy = 2020;
	newnode->teachSub->subjectCode = 2001;
	newnode->teachSub->subjectName = "Chinese";
	newnode->phoneNumber = "0123455";
	newnode->tutorAddress = "20, Jln Mas, Tmn Bukit";
	newnode->rating = 1;

	if (start == NULL) {
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}

	newnode = new Tutor; //creating a new node for the linked list
	newnode->datejoined = new Date;
	newnode->dateTerminated = new Date;
	newnode->center = new TuitionCenter;
	newnode->teachSub = new Subject;
	newnode->tutorID = 5;
	newnode->next = NULL;
	newnode->previous = NULL;

	newnode->dateTerminated->dd = 0; newnode->dateTerminated->mm = 0; newnode->dateTerminated->yyyy = 0;
	newnode->center->tuitionCenterCode = 1004;
	newnode->center->tuitionCenterName = "Lamda";
	newnode->center->tuitionCenterLocation = "Cheras";
	newnode->tutorFirstName = "Ding";
	newnode->tutorLastName = "Hao";
	newnode->hourlyPayRate = 56;
	newnode->datejoined->dd = 30;
	newnode->datejoined->mm = 6;
	newnode->datejoined->yyyy = 2000;
	newnode->teachSub->subjectCode = 2001;
	newnode->teachSub->subjectName = "Indian";
	newnode->phoneNumber = "01888234";
	newnode->tutorAddress = "23, Jln 12, Tmn Jalil";
	newnode->rating = 4;

	if (start == NULL) {
		start = last = newnode; //set the newnode to start node and last node
	}
	else {
		newnode->previous = last; // newnode previous pointer is the previous last node
		last->next = newnode; // previous last node next pointer is now new node
		last = newnode; //set the newnode to the last node
	}

}

int main() {
	initialize_data();
mainmenu:
	int choice; int check; int i = 0; int arraySize = 0;
	char exitChoice;	current = start;
	/*display the main menu of the system*/
	cout << "\t|   WELCOME TO TUTOR MANAGEMENT SYSTEM!   |" << endl << endl << endl;
	cout << "\t|  1. ADD A TUTOR RECORD                  |" << endl;
	cout << "\t|  2. DISPLAY TUTOR RECORD                |" << endl;
	cout << "\t|  3. MODIFY TUTOR RECORD                 |" << endl;
	cout << "\t|  4. GENERATE REPORT                     |" << endl;
	cout << "\t|  5. EXIT                                |" << endl;
	cout << "\t|         PLEASE ENTER A CHOICE !         |" << endl << "\t";
	cin >> choice;
	/*check the user choices*/
	switch (choice) {
	case 1:
		check = check_vacant_slot(current); //call check function and set the value to check
		/*check whether the check variable is 1 2 or 3, 1 meaning empty, 2 being full*/
		if (check == 2) {
			cout << "THERE IS NO AVAILABLE SLOT ";
			Sleep(3000); //wait for 3 seconds
			system("CLS"); //clear the screen
			goto mainmenu; //go to mainmenu location
		}
		else {
			system("CLS"); //clear the screen
			addTutorDetails(); //call the add tutor function
			goto mainmenu; //go to mainmenu location
		}
		break;
	case 2:
		check = check_vacant_slot(current); //call check function and set the value to check
		/*check whether the check variable is 1 2 or 3, 1 meaning empty, 2 being full*/
		if (check == 1) {
			cout << "\tCURRENTLY THERE'S NO RECORDS OF TUTOR, PLEASE ADD NEW TUTOR " << endl;
			Sleep(3000); //wait for 3 seconds
			cout << "	*      RETURNING TO MAIN MENU      *";
			Sleep(2000); //wait for 2 seconds
			system("CLS"); //clear the screen
			goto mainmenu; //go to mainmenu location
		}
		else {
			system("CLS"); //clear the screen
			display_tutor_menu(); //call the display tutor function
			goto mainmenu; //go to mainmenu location
		}
		break;
	case 3:
		check = check_vacant_slot(current); //call check function and set the value to check
		/*check whether the check variable is 1 2 or 3, 1 meaning empty, 2 being full*/
		if (check == 1) {
			cout << "\tCURRENTLY THERE'S NO RECORDS OF TUTOR, PLEASE ADD NEW TUTOR " << endl;
			Sleep(3000); //wait for 3 seconds
			cout << "	*****      RETURNING TO MAIN MENU      *****";
			Sleep(2000); //wait for 2 seconds
			system("CLS"); //clear the screen
			goto mainmenu; //go to mainmenu location
		}
		else {
			system("CLS"); //clear the screen
			bubbleSort(start, 1); //sort the tutor by the tutor ID
			modify_tutor_menu(); // call the modify tutor function
			goto mainmenu; //go to mainmenu location
		}
		break;
	case 4:
		generate_report_menu(); //call the generate report menu
		goto mainmenu; //go to mainmenu location
		break;
	case 5:
		cout << "	ARE YOU SURE YOU WANT TO EXIT ?	(Y/N) " << endl << "\t";
		cin >> exitChoice;
		if (toupper(exitChoice) == 'Y') {
			cout << "	*          EXITING PROGRAM          *";
			Sleep(3000); //wait for 3 seconds
			exit; //exit the program
		}
		else {
			cout << "	*      RETURNING TO MAIN MENU      *";
			Sleep(3000); //wait for 3 seconds
			system("CLS"); //clear the screen
			goto mainmenu; //go to mainmenu location
		}
		break;
	default:
		cout << "Going back to main menu";
		system("CLS"); //clear the screen
		goto mainmenu; //go to mainmenu location
	}
}

	

