/*This is a quiz to test a subject matter experts knowledge of Cyber Security*/
//Pre-processor statements
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

// structure to store info for questions
struct questionInfo
{
	//Char arrays to store question options and answers
	char questionString[1000];
	char* options[4];
	char answer[500];
};
//dec of function to initialize questions, takes array of type questionInfo as parameter
void initialize(struct questionInfo question[]);
//Main function of program
int main()
{
	struct questionInfo question[13]; // declare array
	int wrongAttempts = 0, points = 0, questionNum = 0, choice = 0, select = 0; // declare variables for counting
	time_t initialTime; // object for time calculation
	initialize(question); //initializes question array
	while (points != 10 && wrongAttempts != 3 && choice != -1) // while loop that continues questions until points 10, wrong attempts 3, or exit code -1
	{
		//print strigs that give player information 
		printf("You can exit the quiz by pressing -1\n");
		printf("Your Points: %d\n", points);
		printf("Wrong attempts: %d\n\n", wrongAttempts);
		printf("Q%d: %s\n\n", questionNum + 1, question[questionNum].questionString);
		for (int i = 0; i < 4; i++) // for loop to display options
		{
			printf("Option %d: %s\n", i + 1, question[questionNum].options[i]);
		}
		//prompt user to select option
		printf("\nSelect one option number= ");
		initialTime = time(NULL);
		scanf("%d", &choice);
		//stop timer and calculate time taken by user to input
		time_t timeTakenForInput = (double)(time(NULL) - initialTime);
		//loop to ensure choice is within parameters of -1, or < 4
		while (choice < -1 || choice > 4)
		{
			printf("\nPlease choose from options available only: ");
			initialTime = time(NULL);
			scanf("%d", &choice);
			time_t timeTakenForInput = (double)(time(NULL) - initialTime);
		}
		//exit loop if enters -1
		if (choice == -1)
			break;
		system("cls"); // clear console
		if (strcmp(question[questionNum].options[choice - 1], question[questionNum].answer) == 0 && timeTakenForInput <= 10) // if answer stored in option selected matches correct answer and time taken < 10 add point
		{
			points++;
			printf("Your answer was correct. ");
		}
		else if (strcmp(question[questionNum].options[choice - 1], question[questionNum].answer) != 0 && timeTakenForInput <= 10) // if answer does not match and time taken <10 count wrong attempt
		{
			wrongAttempts++;
			printf("Your answer was wrong. ");
		}
		else if (timeTakenForInput > 10) // if time taken for input >10 count as wrong attempt
		{
			wrongAttempts++;
			printf("Your answer is counted wrong because you took more than 60 seconds. ");
		}
		// loop to move to next question or exit quiz, string to display points and wrong attempts
		questionNum++;
		printf("\nTotal Points: %d\n", points);
		printf("Wrong attempts: %d\n\n", wrongAttempts);
		printf("Press 1 to show next question\nPress 2 to exit the quiz\nYour choice: ");
		scanf("%d", &select);
		while (select != 1 && select != 2)
		{
			printf("\nPlease choose correct option !!\n\nPress 1 to show next question\nPress 2 to exit the quiz\nYour choice: ");
			scanf("%d", &select);
		}
		if (select == 2)
			break;
		system("cls");
	}
	printf("\nEnd of quiz !!!\n");
	printf("Total Points: %d\n", points);
	printf("Wrong attempts: %d\n\n", wrongAttempts);
	return 0;
}
//definition of function which initializes question array
void initialize(struct questionInfo question[])
{
	strcpy(question[0].questionString, "Software designed to prevent, detect and eradicate malicious software, such as a virus?");
	strcpy(question[0].answer, "Anti-Malware Software");
	question[0].options[0] = "Anti-Phishing Software";
	question[0].options[1] = "Anti-Malware Software";
	question[0].options[2] = "Bloat ware";
	question[0].options[3] = "none of these";

	strcpy(question[1].questionString, "What is A network of computers infected with malicious software and controlled without the owners knowledge?");
	strcpy(question[1].answer, "Botnet");
	question[1].options[0] = "Attack Stack";
	question[1].options[1] = "Malicious Network";
	question[1].options[2] = "Botnet";
	question[1].options[3] = "None of these";

	strcpy(question[2].questionString, "An attempt to disrupt a network/business/organisation by issuing more requests than a system is able to cope with, it can be performed with malicious intent or as a protest?");
	strcpy(question[2].answer, "Denial Of Service");
	question[2].options[0] = "Denial Of Service";
	question[2].options[1] = "Evil Twin Attack";
	question[2].options[2] = "Backdoor";
	question[2].options[3] = "None of these";

	strcpy(question[3].questionString, "A method that is used to attempt to ensure data security by use of encrypted (secret) code?");
	strcpy(question[3].answer, "Encryption");
	question[3].options[0] = "Data Lock";
	question[3].options[1] = "Encryption";
	question[3].options[2] = "Decryption";
	question[3].options[3] = "All of the above";

	strcpy(question[4].questionString, "Software that is designed to protect a computer system/network from unauthorised access and intrusion?");
	strcpy(question[4].answer, "Firewall");
	question[4].options[0] = "File Protection Protocol";
	question[4].options[1] = "Cyber Space";
	question[4].options[2] = "Firewall";
	question[4].options[3] = "all of the above";

	strcpy(question[5].questionString, "The national environment in which communications over computer network occurs?");
	strcpy(question[5].answer, "Cyber Space");
	question[5].options[0] = "Cyber Space";
	question[5].options[1] = "internet";
	question[5].options[2] = "Dark Web";
	question[5].options[3] = "None of these";

	strcpy(question[6].questionString, "Exploiting an employee at a company to gain access to their network is an example of ?");
	strcpy(question[6].answer, "Social Engineering");
	question[6].options[0] = "Physical Security Exploit";
	question[6].options[1] = "Social Engineering";
	question[6].options[2] = "Man in the Middle Attack";
	question[6].options[3] = "Newzeland";

	strcpy(question[7].questionString, "Attacker relays and alters communications between two parties who believe they are communicating with eachother?");
	strcpy(question[7].answer, "Man in the Middle Attack");
	question[7].options[0] = "Evil Twin";
	question[7].options[1] = "DDOS";
	question[7].options[2] = "Man in the Middle Attack";
	question[7].options[3] = "All of the above";

	strcpy(question[8].questionString, "A feature or defect of a computer system that allows surreptitious unauthorized access to data?");
	strcpy(question[8].answer, "Backdoor");
	question[8].options[0] = "Backdoor";
	question[8].options[1] = "loop hole";
	question[8].options[2] = "SQL injection";
	question[8].options[3] = "Daffodil";

	strcpy(question[9].questionString, "network point that acts as an entrance to another network?");
	strcpy(question[9].answer, "Gateway");
	question[9].options[0] = "Point of entry";
	question[9].options[1] = "Gateway";
	question[9].options[2] = "Backdoor";
	question[9].options[3] = "None of the above";

	strcpy(question[10].questionString, "local or restricted communicatioins network?");
	strcpy(question[10].answer, "Intranet");
	question[10].options[0] = "Intranet";
	question[10].options[1] = "Internet";
	question[10].options[2] = "Proxy Server";
	question[10].options[3] = "None of these";

	strcpy(question[11].questionString, "Type of surveillance software that has capability to record keystrokes?");
	strcpy(question[11].answer, "Keylogger");
	question[11].options[0] = "Malware";
	question[11].options[1] = "Ransomware";
	question[11].options[2] = "Keylogger";
	question[11].options[3] = "All of the above";

	strcpy(question[12].questionString, "Type of malware attack in which the attacker locks and encrypts the victims data?");
	strcpy(question[12].answer, "Ransomware");
	question[12].options[0] = "Ransomware";
	question[12].options[1] = "Encrypt Malware";
	question[12].options[2] = "Keylogger";
	question[12].options[3] = "None of these";
}
