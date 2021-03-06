#include <iostream>
#include "Circles_func.cpp"

using namespace std;

int main(int argc, char *argv[])
{	
	try {
		if (argc != 2) {
			throw "Error in arguments. To run use circles.exe input_file.txt";
		}

		// file -> vector
		vector<Сircle> circles;
		if (!file_read(argv[1], circles)) {
			throw 1;
		}

		// searching answers and sort by id
		vector<unsigned int> answer;
		answer = find_circle(circles);
		sort(answer.begin(), answer.end());

		// output of answer
		if (answer.size() == 0) {
			cout << "Not found" << endl;
		}
		else {
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << endl;
			}
		}

		circles.clear();
		circles.shrink_to_fit();
	}

	catch (const char *error) {
		cout << error << endl;
		return 1;
	}
	catch (...) {
		cout << "Unexpected exit from the program." << endl;
		return 1;
	}

    return 0;
}
