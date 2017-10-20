#include <stdio.h>

#define TABS 8
#define WRAP 64
#define MAXL 512
#define MAXF 262144
#define O 0
#define I 1

int input(char ch[], int l, int cb_x, int cb_y);
void move(char ch[], char c, int cb_x, int cb_y, int n);
void set(char ch[], char c, int p);
void add(char ch[], char c, int cb_x, int cb_y, int l);
void rem(char ch[], int x, int y, int l);
int getl(char s[], int lim);

void printc(char a[], int l);
void printb(int b[], int n);
int rcpy(char f[], char t[], int c, int cb_x, int cb_y);

void x_in_b(int b[], int n);
int init_b(int b[], int n);

int main(){

  int ms[TABS];
  char  ib[MAXL], ob[MAXL], fb[MAXF], bb[MAXF];
  int  x[3], y[3], z[3], t[3];
  int cx, cy, cz, ct, lc;
  int i, c;
  
  ms[0] = init_b(ms, TABS);
  init_b(t, 3);
  init_b(x, 3);
  init_b(y, 3);
  init_b(z, 3);
  i = 0;

  cx = cy = cz = ct = lc = 0;
  
  while(ms[0]){
    
    if(!i){
      printf("I cannot be 0, setting to 1\n");
      ++i;
    }
        
    printf("Intra-Cycle Count: %d\n", i);

    if(!ms[i]&&i<2){
      printf("Entering Output Handling\n");

      printf("S_Handler bit checking: %d\n", ms[4]);
      if(!ms[4]){
	printf("Output to screen:\n %s\n", ob);
      }else{
	
	printf("Output to buffer\n");
	rcpy(ob, fb, c, x[i-i], y[i-i]); 
      }
      
      x_in_b(ms, i);
    } else if(ms[i]&&i<2){
   
      printf("Buffer to Input into: ");	
      printf("<%d,%d>\n", ms[2], ms[3]);
      if(ms[4]){
	printf("<Enter Command to Apply: 'kill' to exit>\n");
	printf("<CB_X:%d CB_Y:%d CB_Z:%d CB_T:%d>:\n", cx, cy, cz, ct);
	cz = input(ib, z[i], x[i], y[i]);
      } else {
	printf("<Enter a Statement: Ctrl-D to exit>\n");
	cz = input(ib, z[i], x[i], y[i]);
      }

      
      printf("Entering Input Handling\n");
      if(!ms[2] && !ms[3]){
	
	printf("Buff_Bits set to OB\n");
	if(!ms[4]){
	 	
	  printf("Input Being Copied To OB\n");
	  rcpy(ib, ob, 0, 0, 0);
	} else {
	  
	}

	printf("Setting Input Buffer to: i_buff\n");
	x_in_b(ms, 3);
      }else if(!ms[2] && ms[3]){

	printf("Input into Input buffer\n");
	
	printf("Setting Input Buffer to: f_buff\n");
	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else if(ms[2] && !ms[3]){
	
	printf("Input into the Front-Buffer\n");
	rcpy(ob, fb, c, x[i+i], y[i+i]);
	printf("Setting Input Buffer to: b_buff\n");
	x_in_b(ms, 3);
      }else if(ms[2] && ms[3]){
	
	printf("Input into the Back-Buffer\n");
	
	printf("Setting Input Buffer to: o_buff\n");
	x_in_b(ms, 2);
	x_in_b(ms, 3);
      }else {
	printf("/tERROR: Outside OF RANGE Which is technically impossible...\nSo why are you here...\n Exiting...\n\n");
	break;
      }
      x_in_b(ms, 1);
      x_in_b(ms, 4);
      ++i;
    } else {

      if(i>=TABS-1){
	
	printf("Resetting Cycle Counter:\n");
	i=0;
      }
      ++i;
    }
  }
}

int input(char ch[], int l, int cx, int cy){
  int i = 0;
  char line[MAXL];

  printf("Entering input loop, in function input()\n");
  while(i = getl(line, MAXL) > 0){
    printf("Handling, input read by line\n");
    ++cy;

    rcpy(line, ch, 0, 0, 0);
  }
  return i;
}

int getl(char ch[], int lim){
  int c, i;

  for(i=0;i<lim-1&&(c=getchar())!=EOF && c != '\n'; ++i){
    ch[i] = c;
    if(c == '\n'){
      ch[i] = c;
      ++i;
    }
  }
  ch[i] = '\0';
  return i;
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
    
    cb_y is used to count lines'\n'
    cb_x is used to count chars in line
    
    options: i or r
    i = insert at x,y till 
    r = is replace at x,y till '\0' is read
   */
int rcpy(char f[], char t[], int o, int cb_x, int cb_y){
  int i=O;
  while((t[i] = f[i]) !='\0'){
    ++i;
    }
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
