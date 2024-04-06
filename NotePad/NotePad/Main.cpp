#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Note {
private:
	string title;
	string text;

public:
	Note(string _title, string _text) : title(_title), text(_text) {}
	string getTitle() { return title; }
	string getText() { return text; }
};

class NotePad {
private:
	vector<Note> notes;
public:
	void addNote(string title, string text) {
		Note newNote(title, text);
		notes.push_back(newNote);
		cout << "Note added successful... \n\n\n";
	}

	void showNotes() {
		vector<Note>::iterator  it;
		for (it = notes.begin(); it != notes.end(); it++) {
			cout << it->getTitle() << endl << it->getText() << endl << endl << endl;
			if (it == notes.end()) {
				break;
			}
		}
	}

	void delNote(string title) {
		vector<Note>::iterator  it;
		for (it = notes.begin(); it != notes.end(); it++) {
			if (title == it->getTitle()) {
				break;
			}
		}

		if (it == notes.end()) {
			cout << "Note has not found...\n\n\n";
		}
		else
		{
			notes.erase(it);
			cout << "Note deleted successful... \n\n\n";
		}
	}
};

int main() {
	NotePad newNote;
	while (true) {
		int choice;
		cout << "**************************************\n";
		cout << "*              NOTEPAD               *\n";
		cout << "**************************************\n";
		cout << "For add Note: 1\n";
		cout << "For show all Notes: 2\n";
		cout << "For delete Note: 3\n";
		cout << "For log out: 4\n";
		cout << "Your choice: ";
		cin >> choice;

		cout << endl << endl;


		switch (choice)
		{
		case 1: {
			string title, text;
			cout << "Please type title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Please type text: ";
			getline(cin, text);
			newNote.addNote(title, text);
			break;
		}
		case 2: {
			newNote.showNotes();
			break;
		}
		case 3: {
			string title;
			cout << "Please type title: ";
			cin.ignore();
			getline(cin, title);
				newNote.delNote(title);
			break;
		}
		case 4: {
			cout << "See you...\n\n\n";
			return 0;
		}
		default:
			cout << "Invalid selection. Please try again.\n\n\n";
			break;
		}
	}

}