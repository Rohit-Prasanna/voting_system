#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct voter_information
{
    char aadhar[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *space,*start=NULL;
node *search(char x[],char y[],char z[],node *,int *);
node *voter_insert(node *);
node *main_logs(node *);
 void admin();
 void winner();
 	void exi();
 	void voting();
 	void not_again();
 	void stop();
 	void show();


int count=0,R=3,vote=0;
int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;
int main()
{
	while(1){

    system("cls");
    printf("\n\n\n");
    printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");

    printf("\t           ***************************************************        \n\n\n\n\n");
    printf("        \t\t *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");
    int BB;

    scanf("%d",&BB);
    if(BB==1)
    {
      start=  main_logs(start);
    }

}
    return 0;
}

node *main_logs(node *start)
{
    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR VOTE ENTRY     \n");
    Sleep(300);
    printf("        \t\t\t2. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("        \t\t\t3. FOR WINNER         \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    Sleep(500);
    printf("    \t ********So Plz Enter********\n\n\n");
    int T;
    scanf("%d",&T);
    if(T==1)
    {
       start= voter_insert(start);
    }
    if(T==2)
    {
      admin();
    }
    if(T==3)
    {
      winner();
    }
    if(T!=1||T!=2||T!=3)
    {
    	main_logs(start);
	}


    return start;
}
node* create_node(char aadhar[], char name[], char birth_date[]) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->aadhar, aadhar);
    strcpy(new_node->name, name);
    strcpy(new_node->birth_date, birth_date);
    new_node->next = NULL;
    return new_node;
}

node* voter_insert(node* start) {
    int R = 3;
    int UNIVERSAL = 0;
    int* z = &UNIVERSAL;
    node* temp;
    char name[50], birth_date[15], aadhar[20];
    system("cls");
    printf("\n\n\n\n");
    printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    Sleep(300);
    printf("\t\t\t ID YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n", R);
    Sleep(300);
    printf("\t\tPlease \n");
    Sleep(300);
    printf("\t\t\tEnter your AADHAR ID number: ");
    gets(aadhar);
    gets(aadhar);
    printf("\t\t\tEnter Your NAME: ");
    gets(name);
    printf("\t\t\tEnter Your BIRTH DATE in dd-mm-yyyy format: ");
    gets(birth_date);

    FILE* file;
    char filename[] = "voters.txt";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        stop();
        return start;
    }

    int found = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %[^\n]%*c %s", aadhar, name, birth_date);
        temp = create_node(aadhar, name, birth_date);
        if (search(temp->aadhar, temp->name, temp->birth_date, start, z) != NULL) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        if (UNIVERSAL == 0) {
            voting();
        }
        else {
            not_again();
        }
    }
    else {
        R--;
        if (R == 0) {
            stop();
        }
        else {
            printf("\n\n\n\n");
            printf("\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
            Sleep(300);
            printf("\t\t\tPlz Re-Enter\n\n");
            Sleep(300);
            system("pause");
            start = voter_insert(start);
        }
    }

    return start;
}

void voting() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n");
    Sleep(300);

    FILE* file;
    char filename[] = "candidates.txt";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        getch();
        return;
    }

    char line[100];
    int count = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("\t\t\t %d. %s", count, line);
        count++;
    }
    fclose(file);

    printf("\n\t\t\t Plzz, \n");
    printf("\t\t\t Enter Your Choice \n");
    int choice;
    scanf("%d", &choice);
    getchar();  // Consume the newline character

    // Update the vote count based on the user's choice
    file = fopen("vote_count.txt", "r+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        getch();
        return;
    }
    int i;
    for (i = 1; i <= choice; i++) {
        fgets(line, sizeof(line), file);
        if (i == choice) {
            char candidateName[100];
            int voteCount;
            sscanf(line, " %[^:]:%d", candidateName, &voteCount);  // Include a space before the format specifier to skip leading whitespace
            fseek(file, -strlen(line), SEEK_CUR);  // Move the file pointer back to the beginning of the line
            fprintf(file, "%s:%d\n", candidateName + 1, voteCount + 1);  // Increment the vote count and skip the first character of the candidate name
            fclose(file);
            break;
        }
    }
    fclose(file);

    printf("\n\n**************************THANK YOU***************************\n\n");
    printf("Press any key to exit...");
    getch();
}







void admin() {
    printf("\n\n\n");

    int choice;
    printf("\n\n\n");
    printf("\t\t\tEnter Your Password To Unlock The Admin Panel\n\n");
    scanf("%d", &choice);
    if (choice == 1234) {
        int adminChoice;
        printf("\n\n\n");
        printf("\t\t\t1. ADD CANDIDATE\n");
        printf("\t\t\t2. SHOW RESULTS\n");
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                addCandidate();
                break;
            case 2:
                show();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } else {
        printf("Wrong Password\n");
    }
}

void addCandidate() {
    FILE* candidatesFile;
    FILE* voteCountFile;
    char candidatesFilename[] = "candidates.txt";
    char voteCountFilename[] = "vote_count.txt";
    candidatesFile = fopen(candidatesFilename, "a");
    voteCountFile = fopen(voteCountFilename, "a");
    if (candidatesFile == NULL || voteCountFile == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char name[50];
    char symbol[50];

    printf("Enter the candidate's name: ");
    scanf(" %[^\n]", name);

    printf("Enter the candidate's symbol: ");
    scanf(" %[^\n]", symbol);

    fprintf(candidatesFile, "%s - %s\n", name, symbol);
    fprintf(voteCountFile, "%s:0\n", name);  // Initialize vote count to 0
    fclose(candidatesFile);
    fclose(voteCountFile);

    printf("Candidate added successfully.\n");
}

struct Candidate {
    char name[100];
    char symbol[100];
    int votes;
};



// Function to read and display the vote count from the text file
void readVoteCount() {
    FILE* file;
    char filename[] = "vote_count.txt";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}


// Function to display the current vote count
void show(struct Candidate candidates[], int numCandidates) {
    system("cls");

    printf("\n\n\n\n");
    printf("Present Vote Count :\n\n");
    Sleep(500);

    readVoteCount();

    Sleep(500);

    printf("\n\n**************************THANK YOU***************************\n\n");
    printf("Press any key to exit...");
    getch();
}


void winner(struct Candidate candidates[], int numCandidates) {
    system("cls");
    printf("\n\n\n\n");

    FILE* file;
    char filename[] = "vote_count.txt";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        getch();
        main_logs(start);
        return;
    }

    int maxVotes = 0;
    char winnerName[100];
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        char candidateName[100];
        int voteCount;
        sscanf(line, "%[^:]:%d", candidateName, &voteCount);

        if (voteCount > maxVotes) {
            maxVotes = voteCount;
            strcpy(winnerName, candidateName);
        }
    }

    fclose(file);

    if (maxVotes > 0) {
        printf("\t\t\tThe present Winner is %s and they have got %d votes\n\n\n\n", winnerName, maxVotes);
    } else {
        printf("\t\t\tNo winner found. There are no candidates.\n\n\n\n");
    }

    printf("\t\t\t\tEnter any key to return to the main log\n\n");
    getch();
    main_logs(start);
}


   void stop()
   {
       system("cls");

       printf("\n\n\n\n");
       printf("\t\t\t (:-SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW -:) \n\n\n");
       Sleep(500);
       printf("\t\t\t Plz try again After A few Moment\n\n\n");
       Sleep(500);
       printf("\t\t\t * * *Thank You* * *  \n\n\n");
       Sleep(500);
       printf("press any key");
       getch();

   }

  void not_again(struct Candidate candidates[], int numCandidates) {
    int A;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n");
    Sleep(300);
    printf("\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n");
    Sleep(300);
    printf("\t\t\t If You want to see the present winner, Enter One(1); otherwise, enter any other key for Main Logs\n\n");
    Sleep(300);

    scanf("%d", &A);
    if (A == 1) {
        winner(candidates, numCandidates);
    } else {
        main_logs(start);
    }
}


   void exi()
   {
       system("cls");

       printf("\n\n\n\n\n");
       Sleep(500);
       printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
       Sleep(1000);
       printf("\t\t\t * * *Thank You For Using This ONLINE PLATFORM For VOTING* * *  \n\n\n");
       Sleep(1000);
       exit(0);
   }
node *search(char x[],char y[],char z[],node *start,int *Y)
{
	 *Y=0;
  node *t,*space;
  if(start==NULL)
  {
      space=(node*)malloc(sizeof(node));
     strcpy(space->aadhar,x);
     strcpy(space->name,y);
     strcpy(space->birth_date,z);

      start=space;
      space->next=NULL;

  }
  else
  {
      t=start;
      while(t!=NULL)
       {
          if((strcmp(t->aadhar,x)==0&& strcmp(t->name,y)==0 &&strcmp(t->birth_date,z)==0))
          {
          	*Y=1;

          	break;
          }
              t=t->next;
    	}

          if(*Y==0)
          {

          	space=(node*)malloc(sizeof(node));

       		strcpy(space->aadhar,x);

       		strcpy(space->name,y);

       		strcpy(space->birth_date,z);
	        t=space;
    	    space->next=NULL;

    	}
  }
  return start;
 }

