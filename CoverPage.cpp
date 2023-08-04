#include "CoverPage.h"


CoverPage::CoverPage() {
	current.setCurrentDate();
}

void CoverPage::chCoverPage() {
	string option;
	//Date current;
	//current.setCurrentDate();

		cout << "	    +	     +             +        ++++           +           ++" << endl;
		cout << "	 +     +     +            + +       +    +      +     +      +" << endl;
		cout << "	+       +    +           +++++      +     +    +       +    +" << endl;
		cout << "	 +     +     +          +     +     +    +      +     +      +" << endl;
		cout << "	    +        ++++++    +       +    ++++           +           ++" << endl;


		cout << endl;

		cout << "	******************************************************************" << endl;
		cout << "	*================================================================*" << endl;
		cout << "	*                                               Date: "; current.display(); cout << " *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press 1 to login:                                             *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press 2 to Register:                                          *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*  Press Any Key to Refresh the CoverPage:                       *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	*                                                                *" << endl;
		cout << "	******************************************************************" << endl;
		cout << "	*================================================================*" << endl;
		cout << endl;
		cout << "Your choice : ";
		cin >> option;
		setChoice(option);
		if (choice == "1" || choice == "2") {
			
		}
		else {
			system("CLS");
		}
	

}

void CoverPage::setChoice(string passed) {
	strcpy_s(choice, passed.c_str());
}
char * CoverPage::getChoice() {
	return choice;
}