//Project 2: Book store analysis program
// Zayd Haque
// 10/15/2016

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function prototypes

void findHighestRow(int[][6], int, int[]); 
void findHighestCol(int[][6], int, int[]); 
void findLowestRow(int[][6], int,  int []); 
void findLowestCol(int[][6], int, int[]); 
void findTotalRow(int[][6], int, int []);
void findTotalCol(int[][6], int, int[]);
void sortArrayRow(int[], int, string []);
void sortArrayCol(int[], int, string []);
int searchArray(int[][6], int,int, int);
int findTotalSales(int[][6], int);

int main(){
	

	int bookSales[12][6]; // 2D array for months and book type
	string months[12] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	string subjects[6] = {"MATH", "CS", "PHY", "CHEM", "BIO", "GEO"};
	string unsMonths[12] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" }; // this keeps the months in unsorted order
	string unsSubjects[6] = { "MATH", "CS", "PHY", "CHEM", "BIO", "GEO" }; // keeps the subjects unsorted order 
	int totalRow[12]; // array to hold totals of each row 
	int totalCol[6]; // array to hold totals of each col
	int highRow[12]; // array to hold the highest of the row
	int highCol[6]; // array to hold the highest of the col
	int lowRow[12]; // array to hold the lowest of the row 
	int lowCol[6]; // array to hold the highest of the col
	int totalSales;  // total sales
	

	cout << "Welcome to the Book Store Sales Analysis Program!" << endl;
	cout << "Lets begin ......." << endl;
	cout << endl;

	ifstream inFile;
	inFile.open("sale.dat"); // getting input from file

	for (int i = 0; i < 12; i++){

	
		for (int j = 0; j < 6; j++){

			inFile >> bookSales[i][j];

		} // close bracket for inner loop

	} // outer loop ended


	// calls to the functions
	findHighestRow(bookSales, 12, highRow); // CHECKED
	findHighestCol(bookSales, 12, highCol); // CHECKED
	findLowestRow(bookSales, 12, lowRow); // CHECKED
	findLowestCol(bookSales, 12, lowCol); // CHECKED
	findTotalRow(bookSales, 12, totalRow); // CHECKED
	findTotalCol(bookSales, 12, totalCol); // CHECKED

	totalSales = findTotalSales(bookSales, 12); // CHECKED



	cout<< " MONTH" << "\t";

	for (int count = 0; count < 6; count++){


		cout << subjects[count] << " \t";
	}

	cout << "TOTAL" << " \t" << " HIGH" << " \t" << "LOW";

	cout << endl;

	for (int i = 0; i < 12; i++){

			cout << months[i] << " \t ";

		for (int j = 0; j < 6; j++){
			
			cout << bookSales[i][j] << "\t";

		} // inner loop ended
		cout << totalRow[i] << "\t" << highRow[i] << "\t" << lowRow[i];
		cout << endl;
	} // outer loop ended
	cout << "----------------------------------------------------" << endl;
	cout << "TOTAL ";
	for (int count = 0; count < 6; count++){

		cout << " \t " << totalCol[count];

	}
	
	cout << endl;

	cout << "HIGH ";
	for (int count = 0; count < 6; count++){

		cout << " \t " << highCol[count];

	}

	cout << endl;
	
	cout << "LOW ";
	for (int count = 0; count < 6; count++){

		cout << " \t " << lowCol[count];

	}

	cout << endl;

	cout << "The total sales is: " << totalSales << endl;
	
	cout << "------------------------------------------------------" << endl;


	// sort and search below

	sortArrayRow(totalRow,12, months);
	cout << "----------------------------------" << endl;
	sortArrayCol(totalCol, 6 , subjects);


	// search prompts and call below

	
	string subject, month;
	int subNum, monNum; // holds the int values of the subject and month
	cout << "----------------------------------" << endl;
	
	do{
		
		cout << "Please enter the month(1st 3 letters & use all uppercase) or Enter -1 to exit: " << endl;
		cin >> month;
		cout << endl;
		if (month != "-1"){
			cout << "Enter subject(enter how it is in the table heading & use all uppercase) or Enter -1 to exit: " << endl;
			cin >> subject;
			cout << endl;

		

		for (int i = 0; i < 12; i++){

			if (month == unsMonths[i]){

				monNum = i;


			}
		
		}

		for (int j = 0; j < 6; j++){

			if (subject == unsSubjects[j]){

				subNum = j;


			}

		}
		
		
	cout << "The total sale is " << searchArray(bookSales, 12,monNum , subNum) << endl;


}
	

	} while (month != "-1");

	

	cout << endl;

	cout << "bye!" << endl;



	inFile.close();


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// *************** functions below *************
//			- findHighest for row and col
//			- findLowest for row and col
//			- findTotal for row, col, and totalSales
//			- sortArray
//			- searchArray
// *********************************************

void findHighestRow(int sales[][6], int rows, int hiRow[12]){

	for (int i = 0; i < 12; i++){

		hiRow[i] = sales[i][0];

		for (int j = 0; j < 6; ++j){

			if (sales[i][j] > hiRow[i]){

				hiRow[i] = sales[i][j];


			} // end of if stat.


		} // inner loop ended



	} // outer loop ended


}

void findHighestCol(int sales[][6], int rows, int hiCol[6]){


	for (int j = 0; j < 6; ++j){
		
		hiCol[j] = sales[0][j];

			for(int i = 0; i < 12; ++i){

				if (sales[i][j] > hiCol[j]){

					hiCol[j] = sales[i][j];

				} // end of if stat.


			} // inner loop ended


	} // outer loop ended
	

}
void findLowestCol(int sales[][6], int rows, int lowCol[6]){

	for (int j = 0; j < 6; ++j){

		lowCol[j] = sales[0][j];

		for (int i = 0; i < 12; ++i){

			if (sales[i][j] < lowCol[j]){

				lowCol[j] = sales[i][j];

			} // end of if stat.


		} // inner loop ended


	} // outer loop ended


	
}
void findLowestRow(int sales[][6], int rows, int lowRow[12]){




	for (int i = 0; i < 12; i++){

		lowRow[i] = sales[i][0];

		for (int j = 0; j < 6; ++j){

			if (sales[i][j] < lowRow[i]){

				lowRow[i] = sales[i][j];


			} // end of if stat.


		} // inner loop ended



	} // outer loop ended




}

void findTotalRow(int sales[][6], int rows, int totRow[12]){


	for (int i = 0; i < rows; ++i){
		totRow[i] = 0;

		for (int j = 0; j < 6; ++j){

			totRow[i] += sales[i][j];


		} // inner loop ended

	} // outer loop
	


}

void findTotalCol(int sales[][6], int rows, int totCol[6]){

	for (int j = 0; j < 6; ++j){

		totCol[j] = 0;

		for (int i = 0; i < 12; ++i){

			totCol[j] += sales[i][j];


		} // inner loop ended


	} // outer loop ended


	
}

void sortArrayRow(int array[], int size, string months[]){

	bool swap;
	int temp;
	string tempM;

	do{
		swap = false;
		for (int count = 0; count < (size - 1); count++){

			if (array[count] < array[count + 1] ){
				
				tempM = months[count];
				months[count] = months[count + 1];
				months[count + 1] = tempM;

				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}


		} 
	}  while (swap);

	cout << "Sorting months in descending order of total sale: " << endl;
	

		for (int i = 0; i < 12; i++){

			cout << months[i] << " " <<  array[i] << " " << endl;

		}

}

int searchArray(int sales[][6], int rows, int month, int subject){
	
	

	
	

	for (int i = 0; i < rows; i++){

		if (i == month){

			for (int j = 0; j < 6; j++){


				if (j == subject) {

					return sales[i][j];




				}

				
			}

		}

		

	}
	
	return -1;


}
void sortArrayCol(int array[], int size, string subs[]){



	bool swap;
	int temp;
	string tempS;

	do{
		swap = false;
		for (int count = 0; count < (size - 1); count++){

			if (array[count] < array[count + 1]){

				tempS = subs[count];
				subs[count] = subs[count + 1];
				subs[count + 1] = tempS;

				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}


		}
	} while (swap);

	cout << "Sorting categories in descending order of total sale: " << endl;


	for (int i = 0; i < 6; i++){

		cout << subs[i] << " " <<  array[i] << " " << endl;

	}


}
int findTotalSales(int sales[][6], int rows){

	int total = 0;

	for (int i = 0; i < rows; i++){


		for (int j = 0; j < 6; j++){

			total += sales[i][j];



		}


	}





	return total;
}