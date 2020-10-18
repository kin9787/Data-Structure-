#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>  
using namespace std;

int tutorID = 1;

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
	int tutorID;
	string tutorFirstName;
	string tutorLastName;
	struct Date datejoined, dateTerminated;
	double hourlyPayRate;
	struct TuitionCenter center;
	struct Subject teachSub;
	string phoneNumber;
	string tutorAddress;
	int rating;
}; struct Tutor tutorDetails[100];

/*initialize the data*/

void initialize_data() {
	tutorDetails[0].tutorID = 1; tutorDetails[0].tutorFirstName = "A"; tutorDetails[0].tutorLastName = "CHANGJI";
	tutorDetails[0].datejoined.dd = 23; tutorDetails[0].datejoined.mm = 4; tutorDetails[0].datejoined.yyyy = 1999;
	tutorDetails[0].hourlyPayRate = 40; tutorDetails[0].center.tuitionCenterCode = 1002; tutorDetails[0].center.tuitionCenterName = "Alpha";
	tutorDetails[0].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[0].teachSub.subjectCode = 2001;
	tutorDetails[0].teachSub.subjectName = "Mal"; tutorDetails[0].phoneNumber = "60134020303";
	tutorDetails[0].tutorAddress = "99,Kuala Lumpur 2, 43200"; tutorDetails[0].rating = 4;
	tutorDetails[1].tutorID = 7; tutorDetails[1].tutorFirstName = "B"; tutorDetails[1].tutorLastName = "Lao";
	tutorDetails[1].datejoined.dd = 23; tutorDetails[1].datejoined.mm = 4; tutorDetails[1].datejoined.yyyy = 1999;
	tutorDetails[1].hourlyPayRate = 40; tutorDetails[1].center.tuitionCenterCode = 1001; tutorDetails[1].center.tuitionCenterName = "Alpha";
	tutorDetails[1].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[1].teachSub.subjectCode = 2001;
	tutorDetails[1].teachSub.subjectName = "Chinese"; tutorDetails[1].phoneNumber = "60134020100";
	tutorDetails[1].tutorAddress = "32, Medan  3, 54200"; tutorDetails[1].rating = 5;
	tutorDetails[2].tutorID = 3; tutorDetails[2].tutorFirstName = "C"; tutorDetails[2].tutorLastName = "Chen";
	tutorDetails[2].datejoined.dd = 23; tutorDetails[2].datejoined.mm = 4; tutorDetails[2].datejoined.yyyy = 1999;
	tutorDetails[2].hourlyPayRate = 40; tutorDetails[2].center.tuitionCenterCode = 1003; tutorDetails[2].center.tuitionCenterName = "Alpha";
	tutorDetails[2].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[2].teachSub.subjectCode = 2001;
	tutorDetails[2].teachSub.subjectName = "Chinese"; tutorDetails[2].phoneNumber = "60134070303";
	tutorDetails[2].tutorAddress = "42, Medan Kurau 2, 14000"; tutorDetails[2].rating = 2;
	tutorDetails[3].tutorID = 2; tutorDetails[3].tutorFirstName = "D"; tutorDetails[3].tutorLastName = "Yang";
	tutorDetails[3].datejoined.dd = 23; tutorDetails[3].datejoined.mm = 4; tutorDetails[3].datejoined.yyyy = 1999;
	tutorDetails[3].hourlyPayRate = 40; tutorDetails[3].center.tuitionCenterCode = 1005; tutorDetails[3].center.tuitionCenterName = "Alpha";
	tutorDetails[3].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[3].teachSub.subjectCode = 2001;
	tutorDetails[3].teachSub.subjectName = "Chinese"; tutorDetails[3].phoneNumber = "60124020303";
	tutorDetails[3].tutorAddress = "32, Tmn Kincala 2, 53200"; tutorDetails[3].rating = 1;
	tutorDetails[4].tutorID = 5; tutorDetails[4].tutorFirstName = "E"; tutorDetails[4].tutorLastName = "Lee";
	tutorDetails[4].datejoined.dd = 23; tutorDetails[4].datejoined.mm = 4; tutorDetails[4].datejoined.yyyy = 1999;
	tutorDetails[4].hourlyPayRate = 40; tutorDetails[4].center.tuitionCenterCode = 1004; tutorDetails[4].center.tuitionCenterName = "Alpha";
	tutorDetails[4].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[4].teachSub.subjectCode = 2001;
	tutorDetails[4].teachSub.subjectName = "Chinese"; tutorDetails[4].phoneNumber = "60174020303";
	tutorDetails[4].tutorAddress = "21, Tmn Mahkota 2, 43200"; tutorDetails[4].rating = 1;
	tutorDetails[5].tutorID = 6; tutorDetails[5].tutorFirstName = "F"; tutorDetails[5].tutorLastName = "Lao";
	tutorDetails[5].datejoined.dd = 23; tutorDetails[5].datejoined.mm = 4; tutorDetails[5].datejoined.yyyy = 1999;
	tutorDetails[5].hourlyPayRate = 40; tutorDetails[5].center.tuitionCenterCode = 1003; tutorDetails[5].center.tuitionCenterName = "Alpha";
	tutorDetails[5].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[5].teachSub.subjectCode = 2001;
	tutorDetails[5].teachSub.subjectName = "Chinese"; tutorDetails[5].phoneNumber = "0124020303";
	tutorDetails[5].tutorAddress = "22, Medan Kincha, 23000"; tutorDetails[5].rating = 5;
	tutorDetails[6].tutorID = 4; tutorDetails[6].tutorFirstName = "G"; tutorDetails[6].tutorLastName = "Yao";
	tutorDetails[6].datejoined.dd = 23; tutorDetails[6].datejoined.mm = 4; tutorDetails[6].datejoined.yyyy = 1999;
	tutorDetails[6].hourlyPayRate = 40; tutorDetails[6].center.tuitionCenterCode = 1005; tutorDetails[6].center.tuitionCenterName = "Alpha";
	tutorDetails[6].center.tuitionCenterLocation = "Bukit Bintang"; tutorDetails[6].teachSub.subjectCode = 2001;
	tutorDetails[6].teachSub.subjectName = "Chinese"; tutorDetails[6].phoneNumber = "0134020304";
	tutorDetails[6].tutorAddress = "2, Cheras 2, 14000"; tutorDetails[6].rating = 2;
	tutorID = 8;
}

/*function that checks whether the list is empty or full*/
int check_vacant_slot() {
	int i = 0; int emptySlot = 0; int vacantSlot = 0;
	/*perform 100 times counting*/
	while (i < 100) {
		/*check if the tutor id in index is NULL*/
		if (tutorDetails[i].tutorID != NULL) {
			vacantSlot++; //increment vacant slot
		}
		else {
			emptySlot++; //increment empty slot
		}
		i++;
	}
	if (vacantSlot == 0) {
		return 1; //if vacantSlot is empty, it will return 1 meaning the array is empty
	}
	else if (emptySlot == 0) {
		return 2; //if emptySlot is empty, it will return 1 meaning the array is full
	}
	else {
		return 3;
	}
}

/*merge algorithm for merging splited array*/
void merge(int l, int m, int r, int choice) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	struct Tutor L[50], R[50];
	for (i = 0; i < n1; i++) {
		L[i] = tutorDetails[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = tutorDetails[m + 1 + j];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	switch (choice) {
	case 1:
		while (i < n1 && j < n2)
		{
			if (L[i].tutorID <= R[j].tutorID)
			{
				tutorDetails[k] = L[i];
				i++;
			}
			else
			{
				tutorDetails[k] = R[j];
				j++;
			}
			k++;
		}
		break;
	case 2:
		while (i < n1 && j < n2)
		{
			if (L[i].center.tuitionCenterCode <= R[j].center.tuitionCenterCode)
			{
				tutorDetails[k] = L[i];
				i++;
			}
			else
			{
				tutorDetails[k] = R[j];
				j++;
			}
			k++;
		}
		break;
	case 3:
		while (i < n1 && j < n2)
		{
			if (L[i].hourlyPayRate <= R[j].hourlyPayRate)
			{
				tutorDetails[k] = L[i];
				i++;
			}
			else
			{
				tutorDetails[k] = R[j];
				j++;
			}
			k++;
		}
		break;
	case 4:
		while (i < n1 && j < n2)
		{
			if (L[i].rating <= R[j].rating)
			{
				tutorDetails[k] = L[i];
				i++;
			}
			else
			{
				tutorDetails[k] = R[j];
				j++;
			}
			k++;
		}
		break;
	}

	while (i < n1)
	{
		tutorDetails[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		tutorDetails[k] = R[j];
		j++;
		k++;
	}
	


}

/*merge sort algorithm for sorting the array*/
void mergeSort(int l, int r, int choice)

{	/*check if left l is greater than right r*/
	if (l < r) 
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(l, m,choice); //call merge sort function
		mergeSort(m + 1, r, choice); //call merge sort function

		merge(l, m, r, choice); //call merge function
	}
}

/*binary search algorithm to search tutor ID*/
int binarySearch(int, int, int);

/*exponential search algorithm to search tutor ID*/
int exponential_search(int n, int tutID) {

	/*check whether given id is at first location*/
	if (tutorDetails[0].tutorID == tutID) {
		return 0;
	}
	int i = 1;
	/*find the range for binary search by doubling the i*/
	while (i < n && tutorDetails[i].tutorID <= tutID) {
		i = i * 2;
	}

	return binarySearch(i / 2, min(i, n), tutID); //call binary search for the found range
}

/*binary search algorithm to search tutor ID*/
int binarySearch(int left, int right, int tutID) {
	if (right >= left)
	{
		int mid = left + (right - left) / 2; //calculation for middle
		if (tutorDetails[mid].tutorID == tutID)  //if the tutor id in the middle index then return
			return mid;
		else if (tutorDetails[mid].tutorID > tutID) //if the tutor id in the middle index is greater than the given tutor ID
			return binarySearch(left, mid - 1, tutID); //put middle - 1 as the int r in the binary search 
		else
			return binarySearch(mid + 1, right, tutID); //put middle + 1 as the int l in the binary search
	}
	return -1; //reached element is not present in array
}

/*enter new details of the tutor into newnode*/
void enterDetails(int i) {
	int choice; char seperator;
	cout << "\t|      ENTER TUTOR DETAILS MENU      |" << endl;
	cout << "	Generated Tutor ID                  : " << tutorID << endl; // print generated tutor ID
	cout << "	Please enter Tutor Name             : ";
	cin >> tutorDetails[i].tutorFirstName;
	cout << "	Please enter The Last Name of Tutor : ";
	cin >> tutorDetails[i].tutorLastName;
	cout << "	Please enter Tutor Date Joined      : " <<endl;
	cout << "	Format (DD/MM/YYYY)                 : ";
	cin >> tutorDetails[i].datejoined.dd; cin >> seperator;
	cin >> tutorDetails[i].datejoined.mm; cin >> seperator;
	cin >> tutorDetails[i].datejoined.yyyy;
	cout << "	Please enter Hourly Pay Rate (40-80): ";
hourInsert:
	cin >> tutorDetails[i].hourlyPayRate;
	/*check whether given hourly pay rate input is valid 40 to 80*/
	if (tutorDetails[i].hourlyPayRate < 40 || tutorDetails[i].hourlyPayRate > 80) {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT   : ";
		goto hourInsert;  //it will go to the hourInsert location if given input is not valid which is (40-80)
	}
	cout << "	Please select Tuition Center        : " << endl;
	cout << "	1. Bukit Bintang " << endl << "	2. Bukit Jalil" << endl << "	3. Puchong" << endl;
	cout << "	4. Cheras" << endl <<"	5. Kepong" << endl << "\tPlease insert choice (1-5) : " ;
error:
	cin >> choice;
	/*check whether given choice input is valid 1 to 5*/
	switch (choice) {
	case 1:
		tutorDetails[i].center.tuitionCenterCode = 1001;
		tutorDetails[i].center.tuitionCenterName = "Alpha";
		tutorDetails[i].center.tuitionCenterLocation = "Bukit Bintang";
		break;
	case 2:
		tutorDetails[i].center.tuitionCenterCode = 1002;
		tutorDetails[i].center.tuitionCenterName = "Beta";
		tutorDetails[i].center.tuitionCenterLocation = "Bukit Jalil";
		break;
	case 3:
		tutorDetails[i].center.tuitionCenterCode = 1003;
		tutorDetails[i].center.tuitionCenterName = "Omega";
		tutorDetails[i].center.tuitionCenterLocation = "Puchong";
		break;
	case 4:
		tutorDetails[i].center.tuitionCenterCode = 1004;
		tutorDetails[i].center.tuitionCenterName = "Lamda";
		tutorDetails[i].center.tuitionCenterLocation = "Cheras";
		break;
	case 5:
		tutorDetails[i].center.tuitionCenterCode = 1005;
		tutorDetails[i].center.tuitionCenterName = "Super";
		tutorDetails[i].center.tuitionCenterLocation = "Kepong";
		break;
	default:
		cout << "\tWRONG SELECTION, PLEASE TRY AGAIN! " << endl << "\t";
		goto error; //it will go to the error location if given input is not 1 to 5
	}
	cout <<  "	Please select Subject Taught        : "<< endl;
	cout << "	1. Chinese " << endl << "	2. Malay" << endl << "	3. English" << endl;
	cout << "	4. Mathematics" << endl << "	5. Science" << endl << "\tPlease insert choice (1-5) : ";
error1:
	cin >> choice;
	/*check whether given choice input is valid 1 to 5*/
	switch (choice) {
	case 1:
		tutorDetails[i].teachSub.subjectCode = 2001;
		tutorDetails[i].teachSub.subjectName = "Chinese";
		break;
	case 2:
		tutorDetails[i].teachSub.subjectCode = 2002;
		tutorDetails[i].teachSub.subjectName = "Malay";
		break;
	case 3:
		tutorDetails[i].teachSub.subjectCode = 2003;
		tutorDetails[i].teachSub.subjectName = "English";
		break;
	case 4:
		tutorDetails[i].teachSub.subjectCode = 2004;
		tutorDetails[i].teachSub.subjectName = "Mathematics";
		break;
	case 5:
		tutorDetails[i].teachSub.subjectCode = 2005;
		tutorDetails[i].teachSub.subjectName = "Science";
		break;
	default:
		cout << "\tWRONG SELECTION, PLEASE TRY AGAIN!" << endl << "\t";
		goto error1; //it will go to the error1 location if given input is not 1 to 5
		break;
	}
	cout << "	Please enter Phone Number           : ";
	cin >> tutorDetails[i].phoneNumber;
	cout << "	Please enter Tutor Address          : ";
	cin.ignore();
	getline(cin, tutorDetails[i].tutorAddress);
	cout  << "	Please enter Tutor Rating     (1-5) : ";
ratingInsert:
	cin >> tutorDetails[i].rating;
	/*check whether given choice input is valid 1 to 5*/
	if (tutorDetails[i].rating < 1 || tutorDetails[i].rating >5) {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT   : ";
		goto ratingInsert;
	}
	Sleep(2000); //wait 2 seconds
	cout << endl <<"\t*****     Entered Details Successful     *****";
	Sleep(2000); system("CLS"); //wait 2 seconds and clear the screen
}

/*add tutor details in the empty slot*/
int addTutorDetails() {
	int i = 1;
	/*check whether the first element in array is empty*/
	if (tutorDetails[0].tutorID == NULL) {
		tutorDetails[0].tutorID = tutorID; 
		enterDetails(0); //call enter details with the first index passed to the enter details function
		tutorID = tutorID + 1;
		return 0;
	}
	else {
		/*find the index of the empty element*/
		for (i < 100; i; i++) {
			/*check whether the element in index is empty*/
			if (tutorDetails[i].tutorID != NULL) {
				continue;
			}
			else {
				tutorDetails[i].tutorID = tutorID;
				enterDetails(i);
				tutorID = tutorID + 1;
				break;
			}
		}
	}
	return 1;
}

/*displaying all the tutoir details in an ascending order*/
void display_ascending(int lastIndex) {
	system("CLS");
	/*formating for the title for details of tutor*/
	cout << "\t| TUTOR DETAILS |" << endl << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; cout << setw(14) << "|DATE JOINED|";
	cout << setw(18) << "|DATE TERMINATED|"; cout << setw(6) << "|PAY|" ; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	int i = 0;
	/*while index is lesser or equals to last index display tutor details*/
	while (i <= lastIndex) {
		/*check if tutor ID in the index is not null*/
		if (tutorDetails[i].tutorID != NULL) {
			cout << "\t" << setw(6) << tutorDetails[i].tutorID << setw(14) << tutorDetails[i].tutorFirstName << setw(13) << tutorDetails[i].tutorLastName << setw(7);
			cout << tutorDetails[i].datejoined.dd << "/" << tutorDetails[i].datejoined.mm << "/" << tutorDetails[i].datejoined.yyyy << setw(10);
			cout << tutorDetails[i].dateTerminated.dd << "/" << tutorDetails[i].dateTerminated.mm << "/" << tutorDetails[i].dateTerminated.yyyy << setw(11);
			cout << tutorDetails[i].hourlyPayRate << setw(10) << tutorDetails[i].center.tuitionCenterCode << setw(21) << tutorDetails[i].center.tuitionCenterLocation;
			cout << setw(11) << tutorDetails[i].center.tuitionCenterName;
			cout << setw(12) << tutorDetails[i].teachSub.subjectCode << setw(13) << tutorDetails[i].teachSub.subjectName;
			cout << setw(17) << tutorDetails[i].phoneNumber << setw(30) << tutorDetails[i].tutorAddress;
			cout << setw(10) << tutorDetails[i].rating;
			cout << endl;
		}
		i++;
	}
	/*press enter to leave the current function*/
	cout << "	PRESS ENTER TO LEAVE ......" << endl;
	cout << "	"; cin.get();
	if (cin.get() == '\n') {
		cout << "	EXITING BACK TO MAIN MENU	" << endl;
		Sleep(2000);
		system("CLS");
	}
}

/*displaying all the tutoir details in an descending order*/
void display_descending(int lastIndex) {
	system("CLS");
	/*formating for the title for details of tutor*/
	cout << "\t| TUTOR DETAILS |" << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; cout << setw(14) << "|DATE JOINED|";
	cout << setw(18) << "|DATE TERMINATED|"; cout << setw(6) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	int i = lastIndex;
	/*while index is greater or equals 0 display tutor details*/
	while (i >= 0) {
		if (tutorDetails[i].tutorID != NULL) {
			cout << "\t" << setw(6) << tutorDetails[i].tutorID << setw(14) << tutorDetails[i].tutorFirstName << setw(13) << tutorDetails[i].tutorLastName << setw(7);
			cout << tutorDetails[i].datejoined.dd << "/" << tutorDetails[i].datejoined.mm << "/" << tutorDetails[i].datejoined.yyyy << setw(10);
			cout << tutorDetails[i].dateTerminated.dd << "/" << tutorDetails[i].dateTerminated.mm << "/" << tutorDetails[i].dateTerminated.yyyy << setw(11);
			cout << tutorDetails[i].hourlyPayRate << setw(10) << tutorDetails[i].center.tuitionCenterCode << setw(21) << tutorDetails[i].center.tuitionCenterLocation;
			cout << setw(11) << tutorDetails[i].center.tuitionCenterName;
			cout << setw(12) << tutorDetails[i].teachSub.subjectCode << setw(13) << tutorDetails[i].teachSub.subjectName;
			cout << setw(17) << tutorDetails[i].phoneNumber << setw(30) << tutorDetails[i].tutorAddress;
			cout << setw(10) << tutorDetails[i].rating;
			cout << endl;
		}
		i--;
	}
	/*press enter to leave the current function*/
	cout << "	PRESS ENTER TO LEAVE ......" << endl;
	cout << "	"; cin.get();
	if (cin.get() == '\n') {
		cout << "	EXITING BACK TO MAIN MENU	" << endl;
		Sleep(2000);
		system("CLS");
	}
}

/*menu for choosing the orientation that user wants to display*/
void display_orientation() {
	int choice; int i = 0; int arraySize = 0;
	cout << "\tHOW WOULD YOU LIKE TO DISPLAY IT?" << endl;
	cout << "\t1. ASCENDING ORDER" << endl;
	cout << "\t2. DESCENDING ORDER" << endl;
	cout << "\t3. EXIT BACK TO MAIN MENU"<< endl;
	while (tutorDetails[i].tutorID != NULL) {
		arraySize++;
		i++;
	}
error:
	cout << "\t";
	cin >> choice;
	switch (choice) {
	case 1:
		display_ascending(arraySize-1); //call display ascending function and pass in the last index
		break;
	case 2:
		display_descending(arraySize-1); //call display descending function and pass in the last index
		break;
	case 3:
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait 3 seconds
		system("CLS"); //clear the screen
		return;
	default:
		cout << "	INPUT IS NOT VALID PLEASE TRY AGAIN !";
		goto error;
	} //go to error location
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
		while (tutorDetails[i].tutorID != NULL) {
			arraySize++;
			i++;
		}
		mergeSort(0, arraySize - 1, choice); //call the merge sort function and pass the first & last index and choice to the function
		display_orientation(); //call display orientation function
	}
	else if (choice == 5) {
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear screen
	}
	else {
		cout << "\tPLEASE TRY AGAIN WITH VALID INPUT";
		Sleep(2000); //wait for 2 seconds
		goto error; //go to the error location
	}
}

/*menu for deleting the tutor*/
void delete_tutor_details(int index, int lastIndex) {
	char seperator; int dayOfContract;
	/*display the tutor details of the searched tutor*/
	cout << "\t| TUTOR DETAILS |" << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|" << setw(14) << "|DATE JOINED|" << endl;
	cout << "\t" << setw(6) << tutorDetails[index].tutorID << setw(13) << tutorDetails[index].tutorFirstName << setw(14) << tutorDetails[index].tutorLastName << setw(7);
	cout << tutorDetails[index].datejoined.dd << "/" << tutorDetails[index].datejoined.mm << "/" << tutorDetails[index].datejoined.yyyy << "\t" << endl;
	cout << "\t WHAT IS THE TEMINATION DATE OF THE USER? (DD/MM/YYY) : ";
	cin >> tutorDetails[index].dateTerminated.dd; cin >> seperator; //ask for the termination date of the tutor
	cin >> tutorDetails[index].dateTerminated.mm; cin >> seperator;
	cin >> tutorDetails[index].dateTerminated.yyyy;
	dayOfContract = (tutorDetails[index].dateTerminated.dd + tutorDetails[index].dateTerminated.mm * 30 + tutorDetails[index].dateTerminated.yyyy * 365) -
		(tutorDetails[index].datejoined.dd + tutorDetails[index].datejoined.mm * 30 + tutorDetails[index].datejoined.yyyy * 365); //calculate the days by subtracting the date terminated with the date joined in days
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
		cout << "\t" << setw(6) << tutorDetails[index].tutorID << setw(14) << tutorDetails[index].tutorFirstName << setw(13) << tutorDetails[index].tutorLastName << setw(7);
		cout << tutorDetails[index].datejoined.dd << "/" << tutorDetails[index].datejoined.mm << "/" << tutorDetails[index].datejoined.yyyy << setw(10);
		cout << tutorDetails[index].dateTerminated.dd << "/" << tutorDetails[index].dateTerminated.mm << "/" << tutorDetails[index].dateTerminated.yyyy << setw(11);
		cout << tutorDetails[index].hourlyPayRate << setw(10) << tutorDetails[index].center.tuitionCenterCode << setw(21) << tutorDetails[index].center.tuitionCenterLocation;
		cout << setw(11) << tutorDetails[index].center.tuitionCenterName;
		cout << setw(12) << tutorDetails[index].teachSub.subjectCode << setw(13) << tutorDetails[index].teachSub.subjectName;
		cout << setw(17) << tutorDetails[index].phoneNumber << setw(30) << tutorDetails[index].tutorAddress;
		cout << setw(10) << tutorDetails[index].rating;
		cout << endl << endl;
	error:
		cout << "\tARE YOU SURE THIS IS THE RECORD YOU WANT TO DELETE? (Y/N) : ";
		cin >> choice;
		if (toupper(choice) == 'Y') {
			cout << "\t PERFORMING DELETION........"; Sleep(3000);
			/*check if the current index is the last index*/
			if (lastIndex == index) {
				/*perform deletion*/
				tutorDetails[lastIndex].tutorID = NULL;  tutorDetails[lastIndex].tutorFirstName = ""; tutorDetails[lastIndex].tutorLastName = "";
				tutorDetails[lastIndex].datejoined.dd = NULL; tutorDetails[lastIndex].datejoined.mm = NULL; tutorDetails[lastIndex].datejoined.yyyy = NULL;
				tutorDetails[lastIndex].dateTerminated.dd = NULL; tutorDetails[lastIndex].dateTerminated.mm = NULL; tutorDetails[lastIndex].dateTerminated.yyyy = NULL;
				tutorDetails[lastIndex].hourlyPayRate = NULL; tutorDetails[lastIndex].center.tuitionCenterCode = NULL;  tutorDetails[lastIndex].center.tuitionCenterLocation = "";
				tutorDetails[lastIndex].center.tuitionCenterName = ""; tutorDetails[lastIndex].teachSub.subjectCode = NULL; tutorDetails[lastIndex].teachSub.subjectName = "";
				tutorDetails[lastIndex].phoneNumber = ""; tutorDetails[lastIndex].tutorAddress = "";  tutorDetails[lastIndex].rating = NULL;
			}
			else {
				/*perform deletion and move next element into previous element*/
				for (index; index < lastIndex; index++) {
					tutorDetails[index].tutorID = tutorDetails[index + 1].tutorID; tutorDetails[index].tutorFirstName = tutorDetails[index + 1].tutorFirstName;
					tutorDetails[index].tutorLastName = tutorDetails[index + 1].tutorLastName; tutorDetails[index].datejoined.dd = tutorDetails[index + 1].datejoined.dd;
					tutorDetails[index].datejoined.mm = tutorDetails[index + 1].datejoined.mm; tutorDetails[index].datejoined.yyyy = tutorDetails[index + 1].datejoined.yyyy;
					tutorDetails[index].dateTerminated.dd = tutorDetails[index + 1].dateTerminated.dd; tutorDetails[index].dateTerminated.mm = tutorDetails[index + 1].dateTerminated.mm;
					tutorDetails[index].dateTerminated.yyyy = tutorDetails[index + 1].dateTerminated.yyyy; tutorDetails[index].hourlyPayRate = tutorDetails[index + 1].hourlyPayRate;
					tutorDetails[index].center.tuitionCenterCode = tutorDetails[index + 1].center.tuitionCenterCode; tutorDetails[index].center.tuitionCenterLocation = tutorDetails[index + 1].center.tuitionCenterLocation;
					tutorDetails[index].center.tuitionCenterName = tutorDetails[index + 1].center.tuitionCenterName; tutorDetails[index].teachSub.subjectCode = tutorDetails[index + 1].teachSub.subjectCode;
					tutorDetails[index].teachSub.subjectName = tutorDetails[index + 1].teachSub.subjectName; tutorDetails[index].phoneNumber = tutorDetails[index + 1].phoneNumber;
					tutorDetails[index].tutorAddress = tutorDetails[index + 1].tutorAddress; tutorDetails[index].rating = tutorDetails[index + 1].rating;
				}
				/*deleting the last element*/
				tutorDetails[lastIndex].tutorID = NULL;  tutorDetails[lastIndex].tutorFirstName = ""; tutorDetails[lastIndex].tutorLastName = "";
				tutorDetails[lastIndex].datejoined.dd = NULL; tutorDetails[lastIndex].datejoined.mm = NULL; tutorDetails[lastIndex].datejoined.yyyy = NULL;
				tutorDetails[lastIndex].dateTerminated.dd = NULL; tutorDetails[lastIndex].dateTerminated.mm = NULL; tutorDetails[lastIndex].dateTerminated.yyyy = NULL;
				tutorDetails[lastIndex].hourlyPayRate = NULL; tutorDetails[lastIndex].center.tuitionCenterCode = NULL;  tutorDetails[lastIndex].center.tuitionCenterLocation = "";
				tutorDetails[lastIndex].center.tuitionCenterName = ""; tutorDetails[lastIndex].teachSub.subjectCode = NULL; tutorDetails[lastIndex].teachSub.subjectName = "";
				tutorDetails[lastIndex].phoneNumber = ""; tutorDetails[lastIndex].tutorAddress = "";  tutorDetails[lastIndex].rating = NULL;
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
			goto error; //go to error location
		}
	}
	else {
		cout << "\tTERMINATION DATE IS NOT OVER 60 DAYS!" << endl << endl;
		cout << "\tDELETE EXECUTION DENIED" << endl;
		cout << "	*****      RETURNING TO MAIN MENU      *****";
		Sleep(3000); //wait for 3 seconds
		system("CLS"); //clear the screen
		return;
	}

}


/*modify tutor details*/
void modify_tutor_details(int index) {
	int choice;
	string address, phoneNumber;
	char confirm; char choiceConfirm;
	system("CLS"); //clear the screen
	/*display the details of the tutor that to be modified*/
	cout << "\t| MODIFY TUTOR MENU |" << endl;
	cout << "\t" << setw(4); cout << "|TUTOR ID|"; cout << setw(13) << "|FIRST NAME|"; cout << setw(12) << "|LAST NAME|"; 
	cout << setw(6) << "|PAY|"; cout << setw(14) << "|CENTRE CODE|"; cout << setw(18) << "|CENTRE LOCATION|"; cout << setw(14) << "|CENTRE NAME|";
	cout << setw(11) << "|SUB CODE|"; cout << setw(11) << "|SUB NAME|"; cout << setw(15) << "|PHONE NUM|"; cout << setw(21) << "|ADDRESS|"; cout << setw(23) << "|RATINGS|" << endl;
	cout << "\t"<<setw(6) << tutorDetails[index].tutorID << setw(13) << tutorDetails[index].tutorFirstName << setw(13) << tutorDetails[index].tutorLastName << setw(8);
	cout << tutorDetails[index].hourlyPayRate << setw(10) << tutorDetails[index].center.tuitionCenterCode << setw(21) << tutorDetails[index].center.tuitionCenterLocation;
	cout << setw(12) << tutorDetails[index].center.tuitionCenterName;
	cout << setw(12) << tutorDetails[index].teachSub.subjectCode << setw(13) << tutorDetails[index].teachSub.subjectName;
	cout << setw(16) << tutorDetails[index].phoneNumber << setw(30) << tutorDetails[index].tutorAddress;
	cout << setw(10) << tutorDetails[index].rating;
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
				tutorDetails[index].phoneNumber = phoneNumber;
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
				tutorDetails[index].tutorAddress = address;
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
		cout << "\tPLEASE TRY AGAIN !" << endl<<endl;
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
	/*calculate array size*/
	while (tutorDetails[i].tutorID != NULL) {
		arraySize++;
		i++;
	}
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
		r = exponential_search(arraySize, x); //perform exponential search with the array size and given input
		if (r == -1) {
			cout << "\tTHERE IS NO SUCH RECORD!!!" << endl;
			cout << "	*****      RETURNING TO MODIFY MENU      *****";
			Sleep(3000); //wait for 3 sefcond
			system("CLS"); //clear the screen
			goto modifymenu; //goto modifymenu location
		}
		else {
			modify_tutor_details(r); //call the modify function
			break;
		}

	case 2:
		cout << "\tPLEASE ENTER THE TUTOR ID YOU WANT TO SEARCH : "; cin >> x;
		r = exponential_search(arraySize, x); //perform exponential search with the array size and given input
		if (r == -1) {
			cout << "\tTHERE IS NO SUCH RECORD!!!" << endl;
			cout << "	*****      RETURNING TO MODIFY MENU      *****";
			Sleep(3000); //wait for 3 sefcond
			system("CLS"); //clear the screen
			goto modifymenu; //goto modifymenu location
		}
		else {
			delete_tutor_details(r, arraySize - 1); //call the delete function
			break;
		}
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
int generate_report_menu() {
	int i = 0; int emptySlot = 0; int vacantSlot = 0; int random;
	/*perform 100 times of calculation*/
	while (i < 100) {
		/*check if tutor id in selected index is NULL*/
		if (tutorDetails[i].tutorID != NULL) {
			vacantSlot++; //increment vacantSlot
		}
		else {
			emptySlot++; //increment emptySlot
		}
		i++;
	}
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
	return vacantSlot;
}

int main() {
	initialize_data();
mainmenu:
	int choice; int check; int i = 0; int arraySize = 0;
	char exitChoice;
	/*display the main menu of the system*/
	cout << "\t|   WELCOME TO TUTOR MANAGEMENT SYSTEM!   |" << endl << endl << endl;
	cout << "\t|  1. ADD A TUTOR RECORD                  |" << endl;
	cout << "\t|  2. DISPLAY TUTOR RECORD                |" << endl;
	cout << "\t|  3. MODIFY TUTOR RECORD                 |" << endl;
	cout << "\t|  4. GENERATE REPORT                     |" << endl;
	cout << "\t|  5. EXIT                                |" << endl;
	cout << "\t|         PLEASE ENTER A CHOICE !         |" << endl << "\t";
	/*calculate array size*/
	while (tutorDetails[i].tutorID != NULL) {
		arraySize++;
		i++;
	}
	cin >> choice;
	/*check the user choices*/
	switch (choice) {
	case 1:
		check = check_vacant_slot();//call check function and set the value to check
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
		check = check_vacant_slot();//call check function and set the value to check
		/*check whether the check variable is 1 2 or 3, 1 meaning empty, 2 being full*/
		if (check == 1) {
			cout <<	"\tCURRENTLY THERE'S NO RECORDS OF TUTOR, PLEASE ADD NEW TUTOR "<< endl;
			Sleep(3000); //wait for 3 seconds
			cout << "	*****      RETURNING TO MAIN MENU      *****";
			Sleep(2000); //wait for 2 seconds
			system("CLS"); //clear the screen
			goto mainmenu; //go to mainmenu location
		}
		else {
			system("CLS"); //clear the screen
			display_tutor_menu();//call the display tutor function
			goto mainmenu; //go to mainmenu location
		}
		break;
	case 3:
		check = check_vacant_slot();//call check function and set the value to check
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
			mergeSort(0,arraySize - 1,1); //perform mergeSort by tutor ID
			modify_tutor_menu(); //call modify tutor function
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
			cout << "	*****          EXITING PROGRAM          *****";
			Sleep(3000); //wait for 3 seconds
			exit; //exit the program
		}
		else {
			cout << "	*****      RETURNING TO MAIN MENU      *****";
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

