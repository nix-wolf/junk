#include <stdio.h>

/* INPUT function: Called int main() branch main-state[1] if
   IN "DMK":~ input: main|root; main-state[1], int
   -this reads a function named input, used in main or the root sequence of the program, a location in the bit array associated to this function that it will modify willingly, the return type in which that handles the associated bit array.

   -in otherwords we can define in one like this fundemental sequence
   int input();

   tn main(){
   int main-state[SIZE];
   
   main-state[0] = init(n<this>);

   while(main-state[i] != SIZE && m-state[0]){
   
   if(mstate[1]){
     
     ms[1] = input()||fn
   }else{
   
     ms[1] = fX()||fn-1;
   }
   
   }
   
   Usage: read in a <statement> then read in cmds to be proformed on the <statement> then return whether or not input will re-run in next iteration of the program.

   variables
   char bu[]
   - bu = buffer: this is the line buffer that the primary state is read into; this is then modified and or compressed into smaller statements to be stored in a file buffer. The buffer doesnt have to be a line buffer but for example purposes we use the line for the first input. but when we are inputting into a file buffer after handling we will also use the same function.
   char bbu[]
   - bbu = back buffer: 
   int len[] 

   int x
   
   int y
   



*/
int input(char bu[], char bbu[], int len[], int x, int y);

int main(){
  /*MS variable: defined in main(); on initilize, int 
    IN DMK:~ ms: main; init, int
             ms: main;  val, int: TABS; int, 8
    -this reads: that ms in main is defined at start of the function main OR at the point of initialization of main and its a integer variable. since next we see that it is an array of ints and we are going to define a Variable TABS to equal eight and say that ms is going to be that in length.
    
    -in otherwords this would define this if written alone
    #define TABS 8

    main(){
    int ms[8] || ms[TABS];

    }

    -to further extend the arguments in DMK we also add this

    ms: main; is, main-state bits
    -this reads: ms in main function is the main fucntions state bit container.
    
    -this then would give the while loop in the code with a handlable exit status
    *
    while(ms[0]){
    
    }
    *
    
    -bits
      this means that we are handling only true and false values from this container, in otherwords we are using it to contain state data of the progress of something
    -"-state" 
      the -state appendage onto a function name or variable name says that we are using this to state information about the progress of the ladder named variable. in this case again is referencing the main function of the program.
    -"; is,"
     semi colen seperator from the second reference to the third, saying that is means that this rooted definition IE ms: the value prior to colon within reference to the value prior to semi colon, equals the reference value and association of the right hand side or the seperated values after the comma.

    -ontop of this definition we also have a definable set that can be processed in some way

    ms: main; 0, stateOfMain 
              1, polarityOfMain
	      2, bufferReference
	      3, bufferPolarity
	      4, stateHandler
	      5, !DEF
	      6, !DEF
	      7, extra
    -this read:
    that each value store at N position has a refereneable name that is for users to understand what each state value is used for
    stateOfMain: is used to enter the main while loop as well as is used to kill the program at anytime where all that is required is that ms[0] be switched and the program closes.
    polarityOfMain: is a reference but to determine whether the program is in an input-state or a output-state. This is because in any given program fundementally it will always be in a transition from reading input and outputting a response based of that input. So when a state bit set is being applied and we remove the objective content of this example and application the first two positions will always be used for the same purpose while the rest are basiclly all defined as ++n[ex] which contains the statement !DEF or not defined. which is is ever read will just be ignored kind of like a null read but a value that can be read and handled and changed as is a defnitive value
    bufferRef & bufferPol: 
    -this is slightly different the the first two in the sense that numberone it is subjective to this program and objectively describing buffers for storing our input, which is some ways in the end may not be as subjectively different than any other program when this is scaled up or down or expanded which would then simply that the objectivity is really the only thing that will change from application of the structure and framework that is being proposed here.
    ms[2]: 0; front-buffer, type
           1; back-buffer, type
    ms[3]: 0; line-buffer, type
           1; file-buffer, type

	   which is extended to these reads when cycling
	   n & n+1: 0 0; front line buffer
	            0 1; front file buffer
                    1 0; back line buffer
		    1 1; back file buffer

		    -I think it is important to note that I am planning on making it so that the back bufferes are only defined and used within functions and don't residuelly reside on the system. but if needs be should be able to be setup and passed into the next function that can use them. fundementally that means that they will be defined and then handled and restored in the front buffers, passed inout the next state put back into the new back buffers then rehandled modified then re-qritten to the front buffers.
    stateHandler:
        ms[4] = state-handler
	"-handler"
   */
  int ms[TABS = 8];
  
  int ios[TABS];
}
