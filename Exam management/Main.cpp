
using namespace std;
#include <iostream>
#include <windows.h>

FILE* accounts;
FILE* exams;
FILE* scores;

//STRUCTURES ----

struct Student_acc
{
	char Username[16];
	char Password[16];
	char First_name[20];
	char Last_name[20];
};
Student_acc S;


struct Teacher_acc
{
	char Username[16];
	char Password[16];
	char First_name[20];
	char Last_name[20];
};
Teacher_acc T;


struct Manager_acc
{
	char Username[16];
	char Password[16];
	char First_name[20];
	char Last_name[20];
};
Manager_acc M;


struct Question
{
	char Description[20][1000];
	char Option1[20][100];
	char Option2[20][100];
	char Option3[20][100];
	char Option4[20][100];
	int Answer[20];
	char Subject[20];
	int Number_of_questions;
	int Point[20];
	int Time;
};
Question Q;


struct Scores
{
	char name[20];
	char family[20];
	char subject[20];
	int score;
};

Scores N;
/*---------------------------------------------------------------------------------*/


//FUNCTIONS ----

int Sign_up();

int Sign_up_teacher();

int Sign_up_student();



void Manager_Sign_In();

int Teacher_Sign_In();

int Student_Sign_In();



int Manager_panel();

int Teacher_panel(char T_name[16], char T_lastname[16]);

int Student_panel(char S_name[16], char S_lastname[16]);



void Student_order();

void Teacher_order();



void Exam_make();

void Exams_info(char name[20], char family[20]);

void Exams_result(char name[16], char lastname[16]);

void Exams_result_manager();





int main()
{
	// MAIN MENU PAGE ---
	system("cls");
	//system("Color F0");
	bool t = true;
	int Menu_key;
	cout << "<<<<<<<<<<<<<<<<<<< W E L C O M E >>>>>>>>>>>>>>>>>>>" << endl << endl;
	cout << ">>>>>>> Exam Management Of Isfahan University <<<<<<<" << endl << endl << endl;
	cout << "          MAIN MENU" << endl;
	cout << "=============================" << endl;
	cout << "[1] Student sign in          " << endl;
	cout << "[2] Teacher sign in          " << endl;
	cout << "[3] Manager sign in          " << endl;
	cout << "[4] sign up                  " << endl;
	cout << "=============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Menu_key;
	while (t)
	{
		switch (Menu_key)
		{
		case 1: Student_Sign_In();
			break;
		case 2: Teacher_Sign_In();
			break;
		case 3: Manager_Sign_In();
			break;
		case 4: Sign_up();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Menu_key;
		}
		}
	}


}



int Sign_up()
{
	bool t = true;
	bool t2 = true;
	int Sign_up_key, Sign_up_key2;
	system("cls");
	cout << "          SIGN UP" << endl;
	cout << "============================" << endl;
	cout << "[1] Student sign up         " << endl;
	cout << "[2] Main menu               " << endl;
	cout << "[ ] To sign up a teacher, you must apply from the manager panel" << endl;
	cout << "============================" << endl;
	cout << "Please press a key..." << endl;
	cin >> Sign_up_key;
	while (t)
	{
		switch (Sign_up_key)
		{

		case 1:
		{
			char Username[16], Password[16], First_name[20], Last_name[20];
			system("cls");
			cout << "      STUDENT SIGN UP" << endl;
			cout << "============================" << endl;
			cout << "Username: ";
			cin >> Username;
			cout << "Password: ";
			cin >> Password;
			cout << "Your first name: ";
			cin >> First_name;
			cout << "Your last name: ";
			cin >> Last_name;
			fopen_s(&accounts, "Student.txt", "rb");
			fread(&S, sizeof(S), 1, accounts);
			while (!feof(accounts))
			{
				if (strcmp(S.Username, Username) == 0)
				{
					fclose(accounts);
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(h, 4);
					cout << "THIS USERNAME ALREADY EXISTS... " << endl;
					SetConsoleTextAttribute(h, 7);
					cout << "============================" << endl;
					cout << "[1] Try again signing up" << endl;
					cout << "[2] Main menu" << endl;
					cout << "============================" << endl;
					cout << "Please enter a number..." << endl;

					cin >> Sign_up_key2;
					while (t2)
					{
						switch (Sign_up_key2)
						{
						case 1: Sign_up();
							break;
						case 2: main();
							break;
							// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
						default:
						{
							HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(h, 4);
							cout << "PLEASE ENTER A VALID NUMBER! " << endl;
							SetConsoleTextAttribute(h, 7);
							cin >> Sign_up_key2;
						}

						}
					}

				}
				fread(&S, sizeof(S), 1, accounts);
			}
			fclose(accounts);
			strcpy_s(S.Username, Username);
			strcpy_s(S.Password, Password);
			strcpy_s(S.First_name, First_name);
			strcpy_s(S.Last_name, Last_name);
			fopen_s(&accounts, "Student.txt", "ab");
			if (!accounts)
			{
				cout << "File was not created...";
				exit(0);
			}
			fwrite(&S, sizeof(S), 1, accounts);

			fclose(accounts);

			t = false;
		};
		break;
		case 2: main();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Sign_up_key;
		}
		}
	}

	return 0;
}



int Sign_up_teacher()
{
	char Username[16], Password[16], First_name[20], Last_name[20];
	int Sign_up_teacher_key;
	bool t = true;
	system("cls");
	cout << "      TEACHER SIGN UP" << endl;
	cout << "============================" << endl;
	cout << "Username: ";
	cin >> Username;
	cout << "Password: ";
	cin >> Password;
	cout << "Your first name: ";
	cin >> First_name;
	cout << "Your last name: ";
	cin >> Last_name;

	fopen_s(&accounts, "Teacher.txt", "a+b");
	fread(&T, sizeof(T), 1, accounts);
	while (!feof(accounts))
	{
		if (strcmp(T.Username, Username) == 0)
		{
			fclose(accounts);
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "THIS USERNAME ALREADY EXISTS... " << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "============================" << endl;
			cout << "[1] Try again signing up" << endl;
			cout << "[2] Manager panel" << endl;
			cout << "============================" << endl;
			cout << "Please enter a number..." << endl;

			cin >> Sign_up_teacher_key;
			while (t)
			{
				switch (Sign_up_teacher_key)
				{
				case 1: Sign_up_teacher();
					break;
				case 2: Manager_panel();
					break;
					// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
				default:
				{
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(h, 4);
					cout << "PLEASE ENTER A VALID NUMBER! " << endl;
					SetConsoleTextAttribute(h, 7);
					cin >> Sign_up_teacher_key;
				}

				}
			}

		}
		fread(&T, sizeof(T), 1, accounts);
	}
	fclose(accounts);
	strcpy_s(T.Username, Username);
	strcpy_s(T.Password, Password);
	strcpy_s(T.First_name, First_name);
	strcpy_s(T.Last_name, Last_name);
	fopen_s(&accounts, "Teacher.txt", "ab");
	if (!accounts)
	{
		cout << "File was not created...";
		exit(0);
	}
	fwrite(&T, sizeof(T), 1, accounts);

	fclose(accounts);
	Manager_panel();
}


int Sign_up_student()
{
	bool t = true;
	bool t2 = true;
	int Sign_up_key, Sign_up_key2;
	system("cls");
	cout << "          SIGN UP" << endl;
	cout << "============================" << endl;
	cout << "[1] Student sign up         " << endl;
	cout << "[2] Manager panel           " << endl;
	cout << "============================" << endl;
	cout << "Please press a key..." << endl;
	cin >> Sign_up_key;
	while (t)
	{
		switch (Sign_up_key)
		{

		case 1:
		{
			char Username[16], Password[16], Last_name[20], First_name[20];
			system("cls");
			cout << "      STUDENT SIGN UP" << endl;
			cout << "============================" << endl;
			cout << "Username: ";
			cin >> Username;
			cout << "Password: ";
			cin >> Password;
			cout << "Your first name: ";
			cin >> First_name;
			cout << "Your last name: ";
			cin >> Last_name;

			fopen_s(&accounts, "Student.txt", "rb");
			fread(&S, sizeof(S), 1, accounts);
			while (!feof(accounts))
			{
				if (strcmp(S.Username, Username) == 0)
				{
					fclose(accounts);
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(h, 4);
					cout << "THIS USERNAME ALREADY EXISTS... " << endl;
					SetConsoleTextAttribute(h, 7);
					cout << "============================" << endl;
					cout << "[1] Try again signing up    " << endl;
					cout << "[2] Manager panel           " << endl;
					cout << "============================" << endl;
					cout << "Please enter a number..." << endl;

					cin >> Sign_up_key2;
					while (t2)
					{
						switch (Sign_up_key2)
						{
						case 1: Sign_up();
							break;
						case 2: Manager_panel();
							break;
							// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
						default:
						{
							HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(h, 4);
							cout << "PLEASE ENTER A VALID NUMBER! " << endl;
							SetConsoleTextAttribute(h, 7);
							cin >> Sign_up_key2;
						}

						}
					}

				}
				fread(&S, sizeof(S), 1, accounts);
			}
			fclose(accounts);
			strcpy_s(S.Username, Username);
			strcpy_s(S.Password, Password);
			strcpy_s(S.First_name, First_name);
			strcpy_s(S.Last_name, Last_name);
			fopen_s(&accounts, "Student.txt", "ab");
			if (!accounts)
			{
				cout << "File was not created...";
				exit(0);
			}
			fwrite(&S, sizeof(S), 1, accounts);

			fclose(accounts);

			t = false;
		};
		break;
		case 2: Manager_panel();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Sign_up_key;
		}
		}
	}
}


void Manager_Sign_In()
{
	bool t = true;
	int Manager_Sign_In_key;
	char Username[16], Password[16];
	system("cls");
	cout << "      MANAGER SIGN IN" << endl;
	cout << "============================" << endl;
	cout << "Username: ";
	cin >> Username;
	cout << "Password: ";
	cin >> Password;

	if ((strcmp(Username, "admin") == 0) && (strcmp(Password, "admin") == 0))
	{
		Manager_panel();
	}

	//IF USERNAME OR PASSWORD IS WRONG ----
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 4);
	cout << "Username or Password is wrong..." << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "============================" << endl;
	cout << "[1] Try again signing in" << endl;
	cout << "[2] Main menu" << endl;
	cout << "============================" << endl;
	cout << "Please enter a number..." << endl;

	cin >> Manager_Sign_In_key;
	while (t)
	{
		switch (Manager_Sign_In_key)
		{
		case 1: Manager_Sign_In();
			break;
		case 2: main();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Manager_Sign_In_key;
		}

		}
	}




}



int Teacher_Sign_In()
{
	int Teacher_Sign_In_key;
	char Username[16], Password[16];
	bool t = true;
	system("cls");
	cout << "      TEACHER SIGN IN" << endl;
	cout << "============================" << endl;
	cout << "Username: ";
	cin >> Username;
	cout << "Password: ";
	cin >> Password;
	fopen_s(&accounts, "Teacher.txt", "rb");
	fread(&T, sizeof(T), 1, accounts);
	while (!feof(accounts))
	{
		if ((strcmp(T.Username, Username) == 0) && (strcmp(T.Password, Password) == 0))
		{
			fclose(accounts);
			Teacher_panel(T.First_name, T.Last_name);
		}
		fread(&T, sizeof(T), 1, accounts);
	}

	//IF USERNAME OR PASSWORD IS WRONG ----
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 4);
	cout << "Username or Password is wrong..." << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "============================" << endl;
	cout << "[1] Try again signing in" << endl;
	cout << "[2] Main menu" << endl;
	cout << "============================" << endl;
	cout << "Please enter a number..." << endl;

	cin >> Teacher_Sign_In_key;
	while (t)
	{
		switch (Teacher_Sign_In_key)
		{
		case 1: Teacher_Sign_In();
			break;
		case 2: main();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Teacher_Sign_In_key;
		}

		}
	}
	return 0;
}



int Student_Sign_In()
{
	int Student_Sign_In_key;
	char Username[16], Password[16];
	bool t = true;
	system("cls");
	cout << "      STUDENT SIGN IN" << endl;
	cout << "============================" << endl;
	cout << "Username: ";
	cin >> Username;
	cout << "Password: ";
	cin >> Password;
	fopen_s(&accounts, "Student.txt", "rb");
	fread(&S, sizeof(S), 1, accounts);
	while (!feof(accounts))
	{
		if ((strcmp(S.Username, Username) == 0) && (strcmp(S.Password, Password) == 0))
		{
			fclose(accounts);
			Student_panel(S.First_name, S.Last_name);
		}
		fread(&S, sizeof(S), 1, accounts);
	}

	//IF USERNAME OR PASSWORD IS WRONG ----
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 4);
	cout << "Username or Password is wrong..." << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "============================" << endl;
	cout << "[1] Try again signing in" << endl;
	cout << "[2] Main menu" << endl;
	cout << "============================" << endl;
	cout << "Please enter a number..." << endl;

	cin >> Student_Sign_In_key;
	while (t)
	{
		switch (Student_Sign_In_key)
		{
		case 1: Student_Sign_In();
			break;
		case 2: main();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Student_Sign_In_key;
		}

		}
	}
	return 0;
}




int Manager_panel()
{
	int Manager_panel_key;
	system("cls");
	cout << "    << MANAGER PANEL >>" << endl;
	cout << "============================" << endl;
	cout << "Welcome back dear " << "Manager" << "." << endl << endl;
	cout << "=============================" << endl;
	cout << "[1] Sign up a new teacher    " << endl;
	cout << "[2] Sign up a new student    " << endl;
	cout << "[3] List of teachers         " << endl;
	cout << "[4] List of students         " << endl;
	cout << "[5] Student scores           " << endl;
	cout << "[6] Log out                  " << endl;
	cout << "=============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Manager_panel_key;

	switch (Manager_panel_key)
	{
	case 1: Sign_up_teacher();
		break;
	case 2: Sign_up_student();
		break;
	case 3: Teacher_order();
		break;
	case 4: Student_order();
		break;
	case 5: Exams_result_manager();
		break;
	case 6: main();
		break;
		// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
	default:
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
		cout << "PLEASE ENTER A VALID NUMBER! " << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> Manager_panel_key;
	}
	}
	return 0;



}



int Teacher_panel(char T_name[16], char T_lastname[16])
{
	int Teacher_panel_key;
	system("cls");
	cout << "     << TEACHER PANEL >>" << endl;
	cout << "============================" << endl;
	cout << "Welcome back dear " << T_name << "." << endl << endl;
	cout << "=============================" << endl;
	cout << "[1] Make a new exam          " << endl;
	cout << "[2] Students scores          " << endl;
	cout << "[3] Log out                  " << endl;
	cout << "=============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Teacher_panel_key;

	switch (Teacher_panel_key)
	{
	case 1: Exam_make();
		break;
		/*case 2: Scores_of_students();
			break;*/
	case 3: main();
		break;
		// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
	/*default:
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
		cout << "PLEASE ENTER A VALID NUMBER! " << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> Teacher_panel_key;
	}*/
	}
	return 0;

}




int Student_panel(char S_name[16], char S_Lastname[16])
{
	int Student_panel_key;
	system("cls");
	cout << "     << STUDENT PANEL >>" << endl;
	cout << "=============================" << endl << endl;
	cout << "WELCOME BACK DEAR " << S_name << "." << endl << endl;
	cout << "=============================" << endl;
	cout << "[1] List of exams            " << endl;
	cout << "[2] Exam results             " << endl;
	cout << "[3] Log out                  " << endl;
	cout << "=============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Student_panel_key;

	switch (Student_panel_key)
	{
	case 1: Exams_info(S_name, S_Lastname);
		break;
	case 2: Exams_result(S_name, S_Lastname);
		break;
	case 3: main();
		break;
		// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
	default:
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
		cout << "PLEASE ENTER A VALID NUMBER! " << endl;
		SetConsoleTextAttribute(h, 7);
		cin >> Student_panel_key;
	}
	}
	return 0;

}

void Student_order()
{
	int Student_order_key;
	bool t = true;
	system("cls");
	int c = 0, i, j;
	char students_family[1000][20];
	char temp[20];
	char students_name[1000][20];
	char temp2[20];
	fopen_s(&accounts, "Student.txt", "rb");
	fread(&S, sizeof(S), 1, accounts);
	while (!feof(accounts))
	{
		c += 1;
		fread(&S, sizeof(S), 1, accounts);
	}
	fclose(accounts);
	fopen_s(&accounts, "Student.txt", "rb");
	fread(&S, sizeof(S), 1, accounts);
	for (i = 0; i < c; i++)
	{
		strcpy_s(students_family[i], S.Last_name);
		strcpy_s(students_name[i], S.First_name);
		fread(&S, sizeof(S), 1, accounts);
	}

	for (j = 0; j < c - 1; j++)
	{
		for (i = 0; i < c - 1 - j; i++)
		{
			if ((strcmp(students_family[i], students_family[i + 1])) > 0)
			{
				strcpy_s(temp, students_family[i]);
				strcpy_s(students_family[i], students_family[i + 1]);
				strcpy_s(students_family[i + 1], temp);

				strcpy_s(temp2, students_name[i]);
				strcpy_s(students_name[i], students_name[i + 1]);
				strcpy_s(students_name[i + 1], temp2);
			}
		}
	}
	fclose(accounts);

	cout << "       STUDENTS LIST" << endl;
	cout << "============================" << endl;
	for (i = 0; i < c; i++)
	{
		cout << "<" << i + 1 << "> " << students_family[i] << " " << students_name[i] << endl;
	}


	cout << endl;
	cout << "============================" << endl;
	cout << "[1] Back to manager panel        " << endl;
	cout << "============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Student_order_key;
	while (t)
	{
		switch (Student_order_key)
		{
		case 1: Manager_panel();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Student_order_key;
		}

		}
	}
}

void Teacher_order()
{
	int Teacher_order_key;
	bool t = true;
	system("cls");
	int c = 0, i, j;
	char Teacher_family[1000][20];
	char temp[20];
	char Teacher_name[1000][20];
	char temp2[20];
	fopen_s(&accounts, "Teacher.txt", "rb");
	fread(&T, sizeof(T), 1, accounts);
	while (!feof(accounts))
	{
		c += 1;
		fread(&T, sizeof(T), 1, accounts);
	}
	fclose(accounts);
	fopen_s(&accounts, "Teacher.txt", "rb");
	fread(&T, sizeof(T), 1, accounts);
	for (i = 0; i < c; i++)
	{
		strcpy_s(Teacher_family[i], T.Last_name);
		strcpy_s(Teacher_name[i], T.First_name);
		fread(&T, sizeof(T), 1, accounts);
	}

	for (j = 0; j < c - 1; j++)
	{
		for (i = 0; i < c - 1 - j; i++)
		{
			if ((strcmp(Teacher_family[i], Teacher_family[i + 1])) > 0)
			{
				strcpy_s(temp, Teacher_family[i]);
				strcpy_s(Teacher_family[i], Teacher_family[i + 1]);
				strcpy_s(Teacher_family[i + 1], temp);

				strcpy_s(temp2, Teacher_name[i]);
				strcpy_s(Teacher_name[i], Teacher_name[i + 1]);
				strcpy_s(Teacher_name[i + 1], temp2);
			}
		}
	}
	fclose(accounts);

	cout << "        TEACHER LIST" << endl;
	cout << "============================" << endl;
	for (i = 0; i < c; i++)
	{
		cout << "<" << i + 1 << "> " << Teacher_family[i] << " " << Teacher_name[i] << endl;
	}


	cout << endl;
	cout << "============================" << endl;
	cout << "[1] Back to manager panel        " << endl;
	cout << "============================" << endl;
	cout << "Please press a key..." << endl;

	cin >> Teacher_order_key;
	while (t)
	{
		switch (Teacher_order_key)
		{
		case 1: Manager_panel();
			break;
			// IF USER DIDNT ENTER A VALID NUMBER, PRINT AN ERROR ----
		default:
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 4);
			cout << "PLEASE ENTER A VALID NUMBER! " << endl;
			SetConsoleTextAttribute(h, 7);
			cin >> Teacher_order_key;
		}

		}
	}
}

void Exam_make()
{


	int Exam_make_key, i;
	bool t = true;
	system("cls");
	cout << "    << MAKE A NEW EXAM >>" << endl;
	cout << "=============================" << endl;
	cout << "Please enter the exmas topic: " << endl;
	cin >> Q.Subject;
	cout << "Please enter the number of your questions: " << endl;
	cin >> Q.Number_of_questions;
	cout << "Please enter the time of your exam in minuts: " << endl;
	cin >> Q.Time;
	cin.ignore();
	for (i = 0; i < Q.Number_of_questions; i++)
	{
		cout << "Please enter the question " << i + 1 << " description: " << endl;
		fgets(Q.Description[i], 1000, stdin);
		cout << "Please enter the Option 1 of question: " << i + 1 << endl;
		fgets(Q.Option1[i], 100, stdin);
		cout << "Please enter the Option 2 of question: " << i + 1 << endl;
		fgets(Q.Option2[i], 100, stdin);
		cout << "Please enter the Option 3 of question: " << i + 1 << endl;
		fgets(Q.Option3[i], 100, stdin);
		cout << "Please enter the Option 4 of question: " << i + 1 << endl;
		fgets(Q.Option4[i], 100, stdin);
		cout << "Please enter the number of the true Option: " << i + 1 << endl;
		cin >> Q.Answer[i];
		cout << "Please enter the point of the question " << i + 1 << ": " << endl;
		cin >> Q.Point[i];
		cin.ignore();
	}
	fopen_s(&exams, "Exam.txt", "a+b");
	fwrite(&Q, sizeof(Q), 1, exams);
	fclose(exams);


}



void Exams_info(char name[20], char family[20])
{
	system("cls");
	cout << "     << LIST OF EXAMS >>" << endl;
	cout << "=============================" << endl;
	int i = 0, Exams_info_key, answer, j, score = 0;
	char exam_name[20];
	bool t = false;
	fopen_s(&exams, "Exam.txt", "rb");
	fread(&Q, sizeof(Q), 1, exams);
	while (!feof(exams))
	{
		cout << "[" << i + 1 << "]" << Q.Subject << " -- Time: " << Q.Time << " Mins" << endl;
		fread(&Q, sizeof(Q), 1, exams);
		i++;
	}
	fclose(exams);
	cout << "=============================" << endl;
	cout << "Please write the exam subject to go to the exam..." << endl;

	fgets(exam_name, 20, stdin);

	fopen_s(&exams, "Exam.txt", "rb");
	fread(&Q, sizeof(Q), 1, exams);
	while (!feof(exams))
	{
		if ((strcmp(exam_name, Q.Subject)) == 0)
		{
			fopen_s(&scores, "Student_scores.txt", "a+b");
			strcmp(N.subject, Q.Subject);
			for (j = 1; j <= Q.Number_of_questions; j++)
			{
				t = true;
				cout << j << "_ " << Q.Description[j] << "  (point " << Q.Point[j] << ")" << endl;
				cout << "[1]" << Q.Option1[j] << endl;
				cout << "[2]" << Q.Option2[j] << endl;
				cout << "[3]" << Q.Option3[j] << endl;
				cout << "[4]" << Q.Option4[j] << endl;
				cout << "Enter the number of your desired option: " << endl << endl;
				cin >> answer;
				if (answer == Q.Answer[j])
				{
					score += Q.Point[j];
				}
			}
		}
		fread(&Q, sizeof(Q), 1, exams);
		i++;
	}
	fclose(exams);

	if (t)
	{
		strcmp(N.name, name);
		strcmp(N.family, family);
		N.score = score;
	}
	fopen_s(&scores, "Student_scores.txt", "a+b");
	fwrite(&N, sizeof(N), 1, scores);
	fclose(scores);
}

void Exams_result(char name[16], char lastname[16])
{
	system("cls");
	cout << "        << SCORES >>" << endl;
	cout << "=============================" << endl;
	fopen_s(&scores, "Student_scores.txt", "rb");
	fread(&N, sizeof(N), 1, scores);
	while (!feof(scores))
	{
		if ((strcmp(name, N.name) == 0) && (strcmp(lastname, N.family) == 0))
		{
			cout << "Score in " << N.subject << " exam: " << N.score << endl;
		}
		fread(&N, sizeof(N), 1, scores);
	}
	fclose(scores);
}

void Exams_result_manager()
{
	system("cls");
	cout << "        << SCORES >>" << endl;
	cout << "=============================" << endl;
	fopen_s(&scores, "Student_scores.txt", "rb");
	fread(&N, sizeof(N), 1, scores);
	while (!feof(scores))
	{
		cout << N.name << " " << N.family << " -- " << "Score in " << N.subject << " exam: " << N.score << endl;

		fread(&N, sizeof(N), 1, scores);
	}
	fclose(scores);
}