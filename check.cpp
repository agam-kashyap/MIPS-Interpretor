#include<bits/stdc++.h>

using namespace std;
int main()
{
	vector<string> OurOutput;
	vector<string> Expected;

	ifstream ourfile("output.txt");
	if(ourfile.is_open())
	{
		string line;
		while( getline(ourfile,line))
		{
			OurOutput.push_back(line);
		}
		ourfile.close();
	}
	else cout << "Unable to open 1" << endl ;

	// for(int i=0;i<OurOutput.size();i++) {cout << OurOutput[i] << endl;}

	ifstream expFile("online.txt");
	if(expFile.is_open())
	{
		string line;
		while(getline(expFile,line))
		{
			Expected.push_back(line);
		}
	}
	else cout << "Unable to open 2" << endl;

	// for(int i=0;i<Expected.size();i++) {cout << Expected[i] << endl;}

	if(OurOutput.size() != Expected.size())
	{
		cout << "Files are not same";
	}
	else
	{
		int x=1;
		for(int i=0;i<OurOutput.size();i++)
		{
			if(OurOutput[i] == Expected[i])
				cout << "Line number " << x << " is same." << endl;
			else
				cout << "Line number " << x << " is not same"<< endl;

			x++;
			
			// sleep(1);
		}
	}
}