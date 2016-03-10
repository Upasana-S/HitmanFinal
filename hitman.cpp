#include <iostream>

#include <stdio.h>

#include<conio.h>
# include<time.h>

# include<string.h>
#include <cstdlib>

# define length  17
# define breadth  17


using namespace std;


/*void swap(char b[length][breadth], char c[length][breadth]);
void move(char b[length][breadth]);
void glider(char b[length][breadth]);

void draw(char b[length][breadth]);*/

void glider(char b[length][breadth]){
   for(int i=0; i<length;i++)
        {for(int j=0;j<breadth;j++)
            {if(i==0||i==length-1)
                {b[i][j]='-';}
            else if(j==0||j==breadth-1)
                {b[i][j]='|';}
            else
                {b[i][j]='.';}
            }
            
            

}
    
    
          /*  int x, y;
           x=rand()%7+rand()%3+2;
			y=rand()%7+rand()%4+2 ;
            
       b[x][y]= b[x-1][y+1]=b[x-1][y+2]=b[x][y+3]=b[x+1][y+1]=b[x+1][y+2]='H';*/
            
}



void draw(char b[length][breadth]){
	system("cls")  ;
	
    cout<<"   ";
    for(int k=0; k<breadth-1; k++)
    if(k<10)
     cout<< k<<"  ";
    else
     cout<< k<<" ";
    cout << endl; 
    char c='A';
    for (int i=0; i<length;i++){
     if(i>0&&i<length-1)
       {cout<<c<<"  ";
         c++;
       }
      else if(i==0)cout<< "O" <<"  " ;
      else cout<<"   ";
       
        for(int j=0;j<breadth;j++){
            cout<<b[i][j]<<"  ";
        }
        cout <<endl<< endl;
        
       
    }
   
}





void move(char b[length][breadth]){
    int y;
    char x;
	TOP:
    cout<<"where would you like to move?(eg. A 1)"; 

    cin>> x>> y;
    x=toupper(x);
    
    int xx= x-64;
    if (xx==6){
    	cout<< "Hint: to continue to the next generation\n without adding hitmen\n enter O 0";
    	getch();
    }
    if((xx>=0 ||xx<16)&& y>=0&&y<=15)
    {if(b[xx][y]=='.')
    	b[xx][y]='H';
    }
    else{cout<<" invalid input. try again\n";
    		getch();
    		goto TOP;
    }	
 
     	
     }


    /*Pre: The life configuration exiss and the x and yumn of the living cell are passed to the function*/
    /*Post: The number of living neigbours of the cells is returned*/

void swap(char b[length][breadth], int i , int j,int &n){
 n=0;
            if(b[i][j+1]=='H')
                n++;
            if(b[i][j-1]=='H')
                n++;
            if(b[i+1][j]=='H')
                n++;    
            if(b[i-1][j]=='H')
                n++;
            if(b[i+1][j+1]=='H')
                n++;
            if(b[i-1][j+1]=='H')
                n++;
            if(b[i-1][j-1]=='H')
                n++;
            if(b[i+1][j-1]=='H')
                n++;
             if( b[i][j+1]=='T')
                n++;
            if( b[i][j+-1]=='T')
                n++;
            if( b[i+1][j]=='T')
                n++;    
            if( b[i-1][j]=='T')
                n++;
            if( b[i+1][j+1]=='T')
                n++;
            if( b[i-1][j+1]=='T')
                n++;
            if(b[i-1][j-1]=='T')
                n++;
            if(b[i+1][j-1]=='T')
                n++;      
             cout<< "  "<< n<<'\t'; 
                
   
    
    }



void update(char b[length][breadth])
{ 
    /*Pre: The life object contains a configuration*/
    /*Post: The updated configuration is now ready*/
    int i,j, n ;
   
    char new_grid[length+2][breadth+2];

    for(i=1;i<=length-2;i++)
    { 
    for(j=1;j<=breadth-2;j++)
    {
    		swap(b,i,j,n);
    		
    if((n==3||n==2)&&(b[i][j]=='H'||b[i][j]=='T')	)
    {new_grid[i][j]=b[i][j];
    }
    else if(n==3&&b[i][j]=='.')
    {new_grid[i][j]='h';
    
    }
    else if(n==3&&b[i][j]=='h')
    {new_grid[i][j]='H';
    
    }
    else if((n>=4||n<=2) && (b[i][j]!='H'||b[i][j]!='T'))
    {new_grid[i][j]='.';
    }
    
		}
	
	}
    
    	
  for(i=1;i<length-2;i++)
    {
        for(j=1;j<breadth-2;j++)
        {
            b[i][j]= new_grid[i][j];
        }
    }
 
     
	 
}
 
    



void instructions(void){
 cout<< "\n INSTRUCTIONS\n ============\n\nHITMAN is an adaptation of John Conway's Game of Life \n and follows the same rules: \n if a cell(H,T or\'.\') has  less than two alive neighbours it  will die\n" ;
  cout<<"\nYou and youe allies are representedon the grid as Hs";
  cout<< "\n The targets are shown as Ts,";
  cout<<" and all potential recrits are \'.\'s";
  
  cout<<"Recruits in training will be represented with hs and will gain experience the longer they survive and the closer they are to the action.";
  
  cout<< "\nAny cell with more than 3 neighbours, will also die";
  cout<<"\n A cell with 2 or 3 neighbours will survive to the next generation";
  cout<<"\nA  dead 	cell with exactly 3 neighbours  will become alive";

  cout<<"\n Press any key to go back";
}


void intro(void){
cout <<"welcome to HITMAN!!\n .You are a trained assassin and are seeking to spread your\"knowledge\" to people everywhere.\n You will start solo and be assigned a target,\n your aim is to \"take care\"  of said target\n while also trying to scout for talent \n by following the rules of the gang:\nyou and your squad will move such that any one of you has a maximum of 3 \nand a minimium of 2 neighbours,inclusive ofthe targets but not innocent bystanders n (however you have to accept that along the way you will lose some men, and \nif you play your cards right you could even gain new men, \neven an army!)\n \nyou can take the target out solo or \nin a four way shootout but if you \ngo in with 2 or 3 men you might come out with none.\nThe most important rule of all is to stay in your homeground, \nleave your area and you will die\n BE WARNED AND GOOD LUCK.\n ";
cout<< "Press k to start,or press i for more information and instructions\n\n";
}

void outro(void){
	cout<<"\nYou've got skills!!\n You are now ready to take on any target,\n no matter the time or the place\n , keep going and you could be the next\n Unabomber\n Keep spreading the love!";}


void win(int no,double seconds, int l){
	cout<<"you win!!\n  ";
cout<<"\n You finished in "<< no<<" moves and "<< seconds <<" seconds\n";
 




switch(l)
{
	case 1: if(no>4){cout<< "you could do better though, the designer finished in 4 moves and 11 seconds\n";}
			else if(no==4){cout <<"you took just as many moves as the designer\n";}
				
				else{cout<<"you beat the designer!!\n";}

			 if( seconds<11)cout<<"You were faster than the designer!!\n";break;
	case 2: if(no>4){cout<< "you could do better though, the designer finished in 4 moves and 18 seconds\n";}
				else if(no==4){cout <<"you took just as many moves as the designer\n";}
				
					else{cout<<"you beat the designer!!\n";}

			if( seconds<18)cout<<"You were faster than the designer!!";break;
	case 3: 
				if(no>4){cout<< "you could do better though, the designer finished in 4 moves and 15 seconds\n";}
				else if(no==4){cout <<"you took just as many moves as the designer\n";}
				
					else{cout<<"you beat the designer!!\n";}
			if( seconds<15)cout<<"You were faster than the designer!!";break;
}
}
void levels( char b[length][breadth],char c[length][breadth]){
	
	
	int x,y,l=0;
char ch;
do{
l++;
if (l==4){break;
}
system("cls")  ;

cout<<"Level " <<l<<":";
getch();


glider(b);
x=rand()%3+rand()%3+1;
y=rand()%3+rand()%3+1 ;


getch();
switch(l){
	case 3: x+=2;
			b[x][y]=b[x+1][y]=b[x][y-1]=b[x-1][y+1]=b[x-1][y]='T'; break;
	case 2: y++;
			b[x][y]= b[x-1][y+1]=b[x-1][y+2]=b[x][y+3]=b[x+1][y+1]=b[x+1][y+2]='T';break;
	case 1:b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]='T'; break;
}
draw(b);
time_t start = time(0);


int no=1,n=0;
do{
 		draw(b);
 		move(b);
 		draw(b);
 
 		update(b);
 		draw(b);
 		
 		no++;
}while(b[x][y]=='T'||b[x+1][y]=='T'|| b[x][y+1]=='T'|| b[x+1][y+1]=='T'||b[x-1][y+1]=='T'||b[x-1][y+2]=='T'||b[x][y+3]=='T');
double seconds= difftime( time(0), start);
win(no,seconds,l);
cout<<"\nready for the next level? : Y/N";
cin>>ch;
ch=toupper(ch);
if(ch!='N'&& ch!='Y')
{cout<<"Imma take that as a yes. =P";
getch();
}

}while(ch!='N');
system("cls")  ;
if(l<4){cout<<"Thank you for playing!! Hope you had fun";}
else {outro();
}
}

   
 


int main() 
{char b[length][breadth],i, c[length][breadth] ;

intro();





cin>>i;
if (i=='i'){
    instructions();


 
 getch();
system("cls")  ;
}
levels(b,c);
  return 0;
}       



    
     
    
    


