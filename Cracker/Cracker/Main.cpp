#include <iostream>
#include <string>

using namespace std;

string crackTheText(string text, int& count);

int main() {
	while (1) {
		string text;
		string generatedText;
		int count = 0;

		cout << "Enter test text" << endl;
		getline(cin, text);

		cout << "Starting the crack" << endl;
		generatedText = crackTheText(text, count);
		if (generatedText == "") {
			cout << "text is longer than 7, cant solve" << endl;
			return 0;
		}
		cout << "Cracked. . ." << endl;
		cout << "Your text is " << generatedText << endl;
		cout << "Took " << count << " loop" << endl;
	}
	return 0;
}

string crackTheText(string text, int& count) {
	char typeOfCase[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	int sizeOfCase = sizeof(typeOfCase) / sizeof(typeOfCase[0]);

	string generatedText = "";
	char temp1, temp2, temp3, temp4, temp5, temp6, temp7;
	int length = 1;
	int y = 0;
	int x = 0;
	int n = 0;
	int m = 0;
	int k = 0;
	int j = 0;

	generatedText = "";
	goto LOOP1;
	// first text
	for (y = 0; y < sizeOfCase; y++) {
		temp1 = typeOfCase[y];

		// second text
		for (x = 0; x < sizeOfCase; x++) {
			temp2 = typeOfCase[x];

			// third text
			for (n = 0; n < sizeOfCase; n++) {
				temp3 = typeOfCase[n];

				// forth text
				for (m = 0; m < sizeOfCase; m++) {
					temp4 = typeOfCase[m];

					// fifth text
					for (k = 0; k < sizeOfCase; k++) {
						temp5 = typeOfCase[k];

						// 6th text 
						for (j = 0; j < sizeOfCase; j++) {
							temp6 = typeOfCase[j];

							// 7th text
							LOOP1:
							for (int i = 0; i < sizeOfCase; i++) {
								temp7 = typeOfCase[i];
								switch (length) {
								case 1:
									generatedText = temp7;
									break;
								case 2:
									generatedText = string() + temp6 + temp7;
									break;
								case 3:
									generatedText = string() + temp5 + temp6 + temp7;
									break;
								case 4:
									generatedText = string() + temp4 + temp5 + temp6 + temp7;
									break;
								case 5:
									generatedText = string() + temp3 + temp4 + temp5 + temp6 + temp7;
									break;
								case 6:
									generatedText = string() + temp2 + temp3 + temp4 + temp5 + temp6 + temp7;
									break;
								case 7:
									generatedText = string() + temp1 + temp2 + temp3 + temp4 + temp5 + temp6 + temp7;
									break;
								default:
									goto END;
									break;
								}

								if (generatedText == text) {
									return generatedText;
								}
								count++;
							}
							if (length == 1)
								length++;
						}
						if (length == 2)
							length++;
					}
					if (length == 3)
						length++;
				}
				if (length == 4)
					length++;
 			}
			if (length == 5)
				length++;
		}
		if (length == 6)
			length++;
	}
	

	END:
	return generatedText;
}