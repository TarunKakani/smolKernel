// all this is doing is clearing the screen and write to it the string my first kernel 
// the video memory declared at the start is the start of video memory pointer in protected mode

// now to understand video memory
// the video memory pointer points at address 0xb8000, the screens text memory is simply a chunk of memory in our address space

// The memory mapped for input/output for the screen starts at 0xb8000 and supports 25 lines, each line contains 80 ascii characters
// each character element in this text memory represents 16 bits (2 bytes)

// the first byte should have the representation of the character as in ASCII.
// the second byte is the attribute-style. this is the formatting of the character including attributes such as color

// example
// to print the character 's' in green color on black background, 
// we will store the character 's' in the first byte of the video memory address
// then the value 0x02 in the second byte (where 0 represents black background and 2 represents green foreground)

// attribute-style address table
// 0 - Black, 1 - Blue, 2 - Green, 3 - Cyan, 4 - Red, 5 - Magenta, 6 - Brown, 7 - Light Grey, 8 - Dark Grey, 9 - Light Blue, 10/a - Light Green, 11/b - Light Cyan, 12/c - Light Red, 13/d - Light Magenta, 14/e - Light Brown, 15/f – White.



void kmain(void){
	const char *str = "my first kernel";
  char *vidptr = (char*)0xb8000; // video memory begins from here
  unsigned int i = 0;
  unsigned int j = 0;

  // the program writes the blank character with 0x07 attribute all over the 80 columns of the 25 lines. This thus clears the screen.
  while(j < 80 * 25 * 2){
    vidptr[j] = ' ';

    // attribute byte light grey on black screen
    vidptr[j+1] = 0x07;
    j = j + 2;
  }

  j = 0;
  
  // this loop will write the string to video memory
  // characters of the null terminated string “my first kernel” are written to the chunk of video memory with each character holding an attribute-byte of 0x07.
  while(str[j] != '\0'){

    // character ascii
    vidptr[i] = str[j];
    
    // give character black bg and light grey fg
    vidptr[i+1] = 0x07;
    ++j;
    i = i + 2;
  }

  return;
}
