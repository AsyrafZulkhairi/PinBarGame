/* AUTHOR & PROGRAMMER = AGENT 037
   DATE =   28 ZULKAEDAH 1435, 23 SEPTEMBER 2014
   VERSION = 1.7
   PURPOSE = MAEN GAME TEKA NOMBOR
   WHAT'S NEW = 1.UBAH CARA DISPLAY HIGHSCORE, DISPLAY NAMES DULU BARU TOTALGUESS.
   				2.TAMBAH INVALID BILE USER INPUT NAME (MAX LETTER 19, MIN 1).
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void GenerateNum(int []);
void GetWord(char [],int[]);
void DisplayNum(int []);
int CheckRepeatedNum(int []);
void CheckPinBar(int [],int []);
void ConvertToNumber(char [],int []);
void DisplayHighscores(void);
void Instruction(void);
void Credits(void);
void line1(void);
void ReadHighScoreFile();
void WriteHighScoreFile();
char names[11][20]={"NIL","NIL","NIL","NIL","NIL","NIL","NIL","NIL","NIL","NIL","NIL"};//Tak perlu initialize NIL pun takpe, tapi saje buat nak kasi file nampak x pelik
int highscores[11]={100,100,100,100,100,100,100,100,100,100,100};
int totalguess,win,resign;
int main()
{	system("title PinBar game v1.7 by AGENT 037");
	char word1[5];
	int number[4],guess[4];
	int opt,invalid;
	ReadHighScoreFile();
	do{
	system("color 71");system("cls");puts("Choose Option:");
	line1();puts("1=Play\n2=Highscores\n3=Instruction(How to play)\n4=Credits\n5=Exit");
	line1();printf("Option:");
	scanf("%d",&opt);system("cls");
	if(opt==1)
	{GenerateNum(number);totalguess=0;win=0;resign=0;
	 puts("\nEnter 'X' pada bile2 mase kalau nak resign.\nGood Luck!");
	 system("pause");system("cls");
	 do{
	 	do{
			GetWord(word1,number);
			if(resign==1)
			   break;
			ConvertToNumber(word1,guess);
			invalid=CheckRepeatedNum(guess);
       	  }while(invalid==1);
       	  if(resign==1)
       	     break;
	 	CheckPinBar(number,guess);
	 }while(win!=1);
	 DisplayHighscores();
	}
	else if(opt==2)
		DisplayHighscores();
	else if(opt==3)
		Instruction();
	else if(opt==4)
		Credits();
	else if(opt==5)
		break;//Kalau return 0; ganti break; ni pun boleh, dah try
	}while(1);
	 return 0;
}
void CheckPinBar(int ans[],int guess[])
{int i,j,bar=0,pin=0;
 for(i=0;i<4;i++)
 {for(j=0;j<4;j++)
  {if(guess[j]==ans[i])
     {if(j==i)
        bar++;
      else
        pin++;
     }
  }
 }
 totalguess++;
 printf("\t\t\t\t");
 DisplayNum(guess);
 printf("= %d BAR, %d PIN\tRound:%d\n",bar,pin,totalguess);
 if(bar==4)
    {puts("Congratulation! you guessed the number!");system("color f1");win=1;
     printf("Enter your name:");gets(names[10]);
     while(strlen(names[10])>19)//<<--Baru
     {puts("Invalid. Maximum number of letters is 19. Please try again.");printf("Enter your name:");gets(names[10]);
     }
     while(strlen(names[10])<1)//<<--Baru = Kalau user tak input ape2, pastu tekan enter, jadi invalid.
     {puts("Invalid. Minimum number of letters is 1. Please try again.");printf("Enter your name:");gets(names[10]);
     }
	 highscores[10]=totalguess;
    }
}
void DisplayHighscores(void)
{int i,j,tempscore;char tempname[20];
 for(j=0;j<10;j++)
 {for(i=0;i<10;i++)
 {if(highscores[i]>highscores[i+1])
     {tempscore=highscores[i];strcpy(tempname,names[i]);
      highscores[i]=highscores[i+1];strcpy(names[i],names[i+1]);
      highscores[i+1]=tempscore;strcpy(names[i+1],tempname);
     }
 }
 }
 WriteHighScoreFile();
 puts("\n\t\t<<<<<<<<<<--TOP 10 HIGHSCORES-->>>>>>>>>>\n");
 puts("\tRANKING\t\t\tNAMES\t\t\tTOTAL GUESS");//<<--What's New no. 1
 puts("\t-------\t\t\t-----\t\t\t-----------");
 for(i=0;i<10;i++)
 {if(highscores[i]!=100)
  printf("\t   %-2d\t\t       %-20s\t%6d\n",i+1,names[i],highscores[i]);
 }
 puts("\n\n\n");system("pause");
}
void GetWord(char word[],int num[])
{int i;
 do{printf("Enter number:");i=0;
 	fflush(stdin);
 	gets(word);
 	if(strcmp(word,"showme")==0)
 	{DisplayNum(num);printf("\n");continue;
 	}
 	if(strcmpi(word,"x")==0)
 	{resign=1;printf("The number is ");DisplayNum(num);
	 printf("\n");system("pause");break;
 	}
 	if(strlen(word)!=4)
 	   {puts("Invalid!");continue;
 	   }
 	for(i=0;i<4;i++)
 	{if(isdigit(word[i])==0)
 	    {puts("Invalid!");break;}
 	}
 	
   }while(i<4);
}
void DisplayNum(int num[])
{int i,j;
 for(i=0;i<4;i++)
	{printf("%d",num[i]);
	}
}
int CheckRepeatedNum(int num[])
{int i,j,invalid=0;
 for(i=0;i<3;i++)
 {for(j=i+1;j<4;j++)
  {if(num[i]==num[j])
      {invalid=1;break;
      }
  }
  if(invalid==1)
     {puts("Invalid! ade nombor berulang");break;
     }
 }
 return invalid;
}
void ConvertToNumber(char word[],int num[])
{int i;
 for(i=0;i<4;i++)
	{
	 switch(word[i])
	 {case '0':num[i]=0;break;
	  case '1':num[i]=1;break;
	  case '2':num[i]=2;break;
	  case '3':num[i]=3;break;
	  case '4':num[i]=4;break;
	  case '5':num[i]=5;break;
	  case '6':num[i]=6;break;
	  case '7':num[i]=7;break;
	  case '8':num[i]=8;break;
	  case '9':num[i]=9;break;
	 }
	}
}
void GenerateNum(int num[4])
{int i,j;srand(time(NULL));
 for(i=0;i<4;i++)
 {do{num[i]=rand()%(10);
 	 for(j=i-1;j>=0;j--)
 	 {if(num[i]==num[j])
 	     break;
 	 }
    }while(j>=0);
 }
}
void Instruction(void)
{int lang;
 do{
 system("cls");
 puts("Select Language:");line1();puts("1=Bahasa Melayu\n2=English\n3=[Back]");line1();printf("Language:");
 scanf("%d",&lang);system("cls");
 if(lang==1)
 	{puts("PinBar game adalah game teka 4-digit nombor.");
 	 puts("Nombor tersebut mesti terdiri daripada 4 nombor berlainan.\nJadi, tiada nombor seperti 1123 atau 1231 atau 1213");
 	 puts("\t(Sebab nombor tersebut ade nombor berulang,1)");
 	 puts("\nBile anda meneka nombor, anda akan diberitahu bilangan PIN dan BAR.");
 	 puts("\tPIN = bilangan nombor yang padan TAPI berada di tempat yang salah");
 	 puts("\tBAR = bilangan nombor yang padan DAN berada di tempat yang betul");
 	 puts("Jadi, sasaran tertinggi game ini adalah untuk memperoleh 4-BAR.\n");
 	}
 else if(lang==2)
 	{puts("PinBar game is a 4-digit number guessing game.");
 	 puts("The number must consist of 4 different number.\nSo, there is no number such 1123 or 1231 or 1213");
 	 puts("\t(because the 4-digit number have repeated number,1)");
 	 puts("\nWhen you guess the number, you will be informed of how many PIN and BAR.");
 	 puts("\tPIN = amount of number that is match BUT at wrong place");
 	 puts("\tBAR = amount of number that is match AND at right place");
 	 puts("So, the ultimate goal of this game is to achieve 4-BAR.\n");
 	}
 else if(lang==3)
 	break;
 system("pause");
 }while(1);return;
}
void Credits(void)
{	puts("\n");
	puts("                                THIS PINBAR                        ");
	puts("                              GAME WAS KINDLY                      ");
	puts("                                CREATED BY:                        ");
	puts("\n");
	puts("         000000 000000 000000 00   00 000000  000000 000000 000000 ");
	puts("         000000 000000 000000 00   00 000000  00  00 000000 000000 ");
	puts("         00  00 00     00     000  00   00    00  00     00     00 ");
	puts("         000000 00 000 000000 0000 00   00    00  00 000000     00 ");
	puts("         000000 00 000 000000 00 0000   00    00  00 000000     00 ");
	puts("         00  00 00  00 00     00  000   00    00  00     00     00 ");
	puts("         00  00 000000 000000 00   00   00    000000 000000     00 ");
	puts("         00  00 000000 000000 00   00   00    000000 000000     00 ");
	puts("\n");
	puts("                             YOU'RE WELCOME!!!                      ");
	puts("\n\n");
	system("pause");
}
void line1(void)
{puts("******************************");
}
void ReadHighScoreFile()
{int i=0;
 FILE*HS;
 
 if((HS=fopen("Highscore.dat","r")) == NULL )//Kalau file Highscore.dat tiada, program akan buat baru
 	HS=fopen("Highscore.dat","w");
 else
 {fscanf(HS,"%s%d",names[i],&highscores[i]);
  while(!feof(HS))
  {i++;
   fscanf(HS,"%s%d",names[i],&highscores[i]);
  }
  fclose(HS);
 }
}
void WriteHighScoreFile()
{int i=0;FILE*HS;
 
 HS=fopen("Highscore.dat","w");
 do{ fprintf(HS,"%s %d\n",names[i],highscores[i]);i++;
    }while(i<10);
 fclose(HS);
}
