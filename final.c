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
int input(char ch[], int l, int cb_x, int cb_y);
void move(char ch[], char c, int cb_x, int cb_y, int n);
void set(char ch[], char c, int p);
void add(char ch[], char c, int cb_x, int cb_y, int l);
void rem(char ch[], int x, int y, int l);
int getl(char s[], int lim);

//output functions
void printc(char a[], int l);
void printb(int b[], int n);
int rcpy(char f[], char t[], int c, int cb_x, int cb_y);

//program functions
void x_in_b(int b[], int n);
int init_b(int b[], int n);

int main(){

  int ms[TABS];
  char fb[MAXF], ib[MAXL], ob[MAXL];
  int  x[3], y[3], z[3], t[3];
  int i, c;
  
  ms[0] = init_b(ms, TABS);
  init_b(t, 3);
  init_b(x, 3);
  init_b(y, 3);
  init_b(z, 3);
  i = 0;
  
  while(ms[0]){

    if(!i)
      ++i;

    printf("Cycle Count: %d\n", i);
    printf("BIT-VAL going in: %d\n", ms[i]);
    if(!ms[i]&&i<2){
      printf("Entering Output Handling\n");

      if(!ms[4]){
	printf("Output to screen\n");
	/*ouput_buffer is for screen*/
	printc(ob, t[i-i]);
      }else{
	
	printf("Output to buffer\n");
	/*output_buffer is for buffer*/
	rcpy(ob, fb, c, x[i-i], y[i-i]); 
      }
      
      printf("Setting Bits to Input\n");
      x_in_b(ms, i);
    } else if(ms[i]&&i<2){

      if(ms[4]){
	printf("<Enter Command to Apply: "kill" to exit>\n");
	printf("<CB_X:%d CB_Y:%d 
      } else {
	printf("<Enter a Statement: Ctrl-D to exit>\n");
	//input
      }

      
      printf("Entering Input Handling\n");
      if(!ms[2] && !ms[3]){
	
	printf("Buff_Bits set to OB\n");
	/*a buffer is inputted into ob
	  use bit s_handler or ms[4]
	  if (!x)
	  input is copied to ob
	  else
	  reference value from fb is copied into ob
	  -this is using a cmd, so the principle is
	  if s_handler == true || (ms[4]) 
	  then we know that input contains a command not a statement
	 */
	if(!ms[4]){
	 
	  printf("Input Being Copied To OB\n");
	  rcpy(ib, ob, c, x[i-i], y[i-i]);
	} else {
	  
	}

	printf("Setting Bits to Input\n");
	x_in_b(ms, 3);
      }else if(!ms[2] && ms[3]){
		 printf("Input into Input buffer\n");
	/*
	  outputting INTO the input_buffer, is based on the sequence that
	  what has been loaded in will then be sent to another buffer, ethier fb or bb
	  for the base test of the routine it will be implictly the fb, later based on s_handler 
	  we will also be able to send data into the back buffer IF NOT S_HANDLER BIT input for command
	*/

       
	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else if(ms[2] && !ms[3]){
		 printf("Input into the Front-Buffer\n");
	/*
	  inputting INTO front_buffer, comes in a few different ways that will need to be handled
	  
	 */
	rcpy(ob, fb, c, x[i+i], y[i+i]);
	
	x_in_b(ms, 3);
      }else if(ms[2] && ms[3]){
		 printf("Input into the Back-Buffer\n");
	/*This block will be for the back_buffer
	  -The back buffer will be used to move data from front_buffer
	  if it is required that it not have commands applied to it
	  *basically: this; is, a. rough description
	 */
	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else {
	printf("/tERROR: Outside OF RANGE Which is technically impossible...\nSo why are you here...\n Exiting...\n\n");
	break;
      }
      ++i;
      x_in_b(ms, i);
    } else {
      printf("Cycling bits: %d\n", i);
      if(ms[4] && i>=TABS-1)
	break;

      if(i>=TABS-1){
	i=0;//reset counter when of bit array length is reached 
	x_in_b(ms, 4);//turn on or off s_handler for next cycle to perform subsequent handling
	
      }
      /* Handle bits is is:input state; and os:output state; later implement after the base routine is down*/
	 
	++i;
    }

  }
}

int input(char ch[], int l, int cx, int cy){
  int i = 0;
  char line[MAXL];
  
  while(i = getl(line, MAXL) > 0)
    
    
    ;
  return i;
}

int getl(char ch[], int lim){
  int c, i;

  for(i=0;i<lim-1&&(c=getchar())!=EOF; ++i){
    ch[i] = c;
    ++i;
  }
}


//prints a bit-array
void printb(int a[], int n){
  for(int i = 0; i < n; ++i)
    printf("\t%d", a[i]);
  printf("\n");
}

//prints a char-array
void printc(char a[], int len){
  for(int i = 0; i < len; ++i)
    printf("%c", a[i]);
  printf("\n");
}

 
  /*
    rcpy: reference copy function; used to copy a buffer into another buffer while allowing for referencing
    via a char o:option, and locations cb_x:current buffer char in line, and cb_y:current buffer line
    
    cb_y is used to count '\n'
    cb_x is used to count chars in line
    
    options: i or r
    i = insert at x,y 
    r = is replace at x,y till '\0' is read
   */
int rcpy(char f[], char t[], int o, int cb_x, int cb_y){
  int i=O;
  while((t[i]=f[i])!='\0')
    ++i;
}


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
void move(char ch[], char c, int cb_x, int cb_y, int n){

}

  /*set state b[x] based on char to polarity p*/
  //char b[]: the bit array that needs a value to be changed
  /*char c: character to say which state param needs changing
    e:entab; structure text output to entab OR detab
    f:foldline; fold lines to a defined values
    r:comments; state of comments when outputing data
    d:debug; test inputted statements for syntaxtical correctness
    t:trail; trailing blanks in the lines
  */


void set(char b[], char c, int p){

}


  /*add current input statement into ch[] based on c at cx, cy at l of input statement */
  //char ch[]: buff in which we are going to add the input text to
  //char c: the character defining insert text at location or replace text at location
  //int cx: character in line to add at
  //int cy: line in fule to add at
  //int l:length of input statement to be added
void add(char ch[], char c, int cb_x, int cb_y, int l){

}

void rem(char ch[], int cb_x, int cb_y, int l){
  /* Replace from location x,y > len of ch[] with everything that follows after l*/

}

/*Functions for bit operations*/
void x_in_b(int b[], int p){
  b[p] = !b[p];
}

int init_b(int b[], int n){
  int i = O;
    for(i = O; i < n; ++i)
      b[i] = O;
    if(b[0])
      return O;
    else
      return I;
}
