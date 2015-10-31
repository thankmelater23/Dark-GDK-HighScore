#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class HighScorers
{
public:
	char *name;
	int score;
	//int recize = sizeof(name) + sizeof(int);
	int record;

};

char name[20];
int  score = 7;
bool newScoreBool;
vector<HighScorers> currentScorer(10);
HighScorers newScore;
int recize = sizeof(char [15]) + sizeof(int);
int record;


int main(int argc, char *argv)
{
	newScore.score = score;

	char filename[] = "HighScore.txt";

	
	fstream fbin(filename, ios::binary | ios::in | ios:: out);

	if(fbin)
	{
		cout << endl << filename << " opened";
	}
	else//Creates HighScore File
	{
		ofstream file(filename);
		cout << endl << filename << " High Score File is not created\n";
		system("PAUSE");
		system("cls");
		cout << "Creating HighScore File\n\n";
		system("pause");

		fstream fbin(filename, ios::binary | ios::in | ios:: out);
		int z = 0;
		for(vector<HighScorers>::iterator i = currentScorer.begin(); i < currentScorer.end(); ++i)
		{
		i->score = 5 + z;
		i->name = "No Name";
		fbin.seekp(z * recize);
		fbin.write(i->name, 20);
		fbin.write(reinterpret_cast<char*>(&i->score),  sizeof(int));
		z++;
		}

	}

	for(vector<HighScorers>::iterator i = currentScorer.begin(); i < currentScorer.end(); ++i)
	{
		if(newScore.score > i->score && newScoreBool != true)
		{
			currentScorer.pop_back();
			cout << "New High Score!!!\n\nEnter in name: ";
			cin.getline(newScore.name, 30);
			currentScorer.push_back(newScore);
			newScoreBool = true;
		}
	}

	if(newScoreBool == true)
	{
		int j = 0;

		for(vector<HighScorers>::iterator i = currentScorer.begin(); i < currentScorer.end(); ++i)
		{
			fbin.seekp(j * recize);
			fbin.write(i->name, 20);
			fbin.write(reinterpret_cast<char*>(&i->score),  sizeof(int));
			j++;
		}
	}
	
	for(int i = 0; i < 10; i++)
	{

			fbin.seekp(i * recize);
			fbin.read(name, 20);
			fbin.read(reinterpret_cast<char*>(&score),  sizeof(int));

			cout << i + 1 << "\t";
			cout << name << "\t\t\t\t";
			cout << score << endl << endl;
	}

	system("PAUSE");

	fbin.close();
}