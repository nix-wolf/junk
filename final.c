#include <stdio.h>

/* constant variables */
#define TABS 8
#define WRAP 64
#define MAXL 512
#define MAXF 262144
#define O 0
#define I 1

/* function prototypes */
//input functions
int output(char ch[], int cha[], int cx, int cy);
int input(char ch[], int len[], int cx, int cy);
void move(char ch[], char c, int cx, int cy, int n);
void set(char ch[], char c, int p);
void add(char ch[], char c, int cx, int cy, int l);
void remove(char ch[], int x, int y, int l);

//program functions
int getl(char s[], int lim);
void rcpy(char f[], char t[]);
void x_in_b(int b[], int n);
int init_b(int b[], int n);
void printc(char a[], int l);
void printb(int b[], int n);

int main(){

  int ms[TABS];
  char fb[MAXF], ib[MAXL], ob[MAXL];
  int  x[3], y[3], z[3], t[3];
  int i;
  
  ms[0] = init_b(ms, TABS);
  init_b(len, TABS/4);
  init_b(x, TABS/4);
  init_b(y, TABS/4);
  
  i = 0;
  
  while(ms[0]){

    if(!i)
      ++i;

    
    
    if(!ms[i]&&i<2){
      if(!ms[4]){
	/*ouput_buffer is for screen*/
      }else{
	  /*output_buffer is for buffer*/
      }
      x_in_b(ms, i);
    } else if(ms[i]&&i<2){
      
      if(!ms[2] && !ms[3]){
	t[i] = input(ob, MAXL, x[i], y[i]);	
	x_in_b(ms, 3);
      }else if(!ms[2] && ms[3]){
	t[i] = input(ib, MAXL, x[i], y[i]);

	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else if(ms[2] && !ms[3]){
	t[i] = input(fb, MAXF, x[i+i], y[i+i]);
	x_in_b(ms, 3);
      }else if(ms[2] && ms[3]){

	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else {
	printf("/tERROR: Outside OF RANGE Which is technically impossible...\nSo why are you here...\n Exiting...\n\n");
	break;
      }
    
      x_in_b(ms, i);
    } else {
      ++i;
    }
    
  }
}

int input(char ch[], int l, int cx, int cy){
  int i = 0;
  char line[MAXL];
  
  while(i = getl(line, MAXL) > 0)

    
    ;

}

int getl(char ch[], int lim){
  int c, i;

  for(i=0;i<lim-1&&(c=getchar())!=EOF; ++i){
    ch[i] = c;
    ++i;
  }
}
 
void printb(int a[], int n){
  for(int i = 0; i < n; ++i)
    printf("\t%d", a[i]);
  printf("\n");
}

void printc(char a[], int len){
  for(int i = 0; i < len; ++i)
    printf("%c", a[i]);
  printf("\n");
}

void rcpy(char f[], char t[]){
  int i=O;
  while((t[i]=f[i])!='\0')
    ++i;
}

/*Functions for bit operations*/
void x_in_b(int b[], int p){
  b[p] = !b[p];
}

int init_b(int b[], int n){
  int i = O;
  //printf("Setting bit array values to OFF\n");
    for(i = O; i < n; ++i)
      b[i] = O;
    //printf("Returning ON for setting in main state bit\n");
    if(b[0])
      return O;
    else
      return I;
}

void move(char ch[], char c, int cx, int cy, int n){
  /*move read position in buffer based on params*/
  //char ch[]: buffer at which we are changing position of next interaction
  /*char c: character to give us direction
    l:last;previous line, cy-n
    n:next;next line, cy+n
    a:ahead;previous char, cx-n
    b:back;next char,cy+n
  */
  //int cx:current position IN line
  //int cy:current line IN buffer
  //int n: number in which to associate
}

void set(char b[], char c, int p){
  /*set state b[x] based on char to polarity p*/
  //char b[]: the bit array that needs a value to be changed
  /*char c: character to say which state param needs changing
    e:entab; structure text output to entab OR detab
    f:foldline; fold lines to a defined values
    r:comments; state of comments when outputing data
    d:debug; test inputted statements for syntaxtical correctness
    t:trail; trailing blanks in the lines
   */
  
}

void add(char ch[], char c, int cx, int cy, int l){
  /*add current input statement into ch[] based on c at cx, cy at l of input statement */
  //char ch[]: buff in which we are going to add the input text to
  //char c: the character defining insert text at location or replace text at location
  //int cx: character in line to add at
  //int cy: line in fule to add at
  //int l:length of input statement to be added
}

void remove(char ch[], int x, int y, int l){
  /* Replace from location x,y > len of ch[] with everything that follows after l*/

}
