#include <iostream>
#include <fstream>
#include<cmath>
#include<iomanip>
int main()
{
	//file input
	std::ifstream infile;
	infile.open("inMeanSTD");

	int inMeanSTD, inMeanSTD2, inMeanSTD3, inMeanSTD4;

	infile >> inMeanSTD >> inMeanSTD2 >> inMeanSTD3 >> inMeanSTD4;
	std::cout << "Data from the file:" << inMeanSTD << std::endl;

	std::cout << "Data from the file:" << inMeanSTD2 << std::endl;

	std::cout << "Data from the file:" << inMeanSTD3 << std::endl;

	std::cout << "Data from the file:" << inMeanSTD4 << std::endl;

	//Calculate mean for file values
	double fileMean = (inMeanSTD + inMeanSTD2 + inMeanSTD3 + inMeanSTD4) / 4.0;

	//Calulate population standard deviation for file values
	double fileSTDdev = sqrt(
		(pow(inMeanSTD - fileMean, 2) +
			(pow(inMeanSTD2 - fileMean, 2) +
				(pow(inMeanSTD3 - fileMean, 2) +
					(pow(inMeanSTD4 - fileMean, 2)) / 4.0)
				)))
		;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Mean from file: " << fileMean << std::endl;
	std::cout << "Population standard deviation from file: " << fileSTDdev << std::endl;

	//user input
	int user1, user2, user3, user4;

	std::cout << std::endl;
	std::cout << "Enter four integers: ";
	std::cin >> user1 >> user2 >> user3 >> user4;

	std::cout << " User input: " << user1 << std::endl;
	std::cout << " User input: " << user2 << std::endl;
	std::cout << " User input: " << user3 << std::endl;
	std::cout << " User input: " << user4 << std::endl;

	double userMean = (user1 + user2 + user3 + user4) / 4.0;
	//calculate mean for user values
	double userSTDdev = sqrt(
		(pow(user1 - userMean, 2) +
			(pow(user2 - userMean, 2) +
				(pow(user3 - userMean, 2) +
					(pow(user4 - userMean, 2)) / 4.0)
				)))
		;


	std::cout << "Mean: " << userMean << std::endl;
	std::cout << "Population standard deviation:" << userSTDdev << std::endl;

	//file output
	std::ofstream outHAM("outMeanSTD.dat");
	outHAM << std::fixed << std::setprecision(2);

	outHAM << "User input:" << user1 << std::endl;
	outHAM << "User input:" << user2 << std::endl;
	outHAM << "User input:" << user3 << std::endl;
	outHAM << "User input:" << user4 << std::endl;
	outHAM << "Mean: " << userMean << std::endl;
	outHAM << "Population standard deviation: " << userSTDdev << std::endl;
	outHAM.close();


	infile.close();
	outHAM.close();
	return 0;
}