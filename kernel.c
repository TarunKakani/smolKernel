// all this is doing is clearing the screen and write to it the string my first kernel 
// the video memory declared at the start is the start of video memory in protected mode

// now to understand video memory
//

void kmain(void){
	const char *str = "my first kernel";
  char *vidptr = (char*)0xb8000; // video memory begins from here
  unsigned int i = 0;
  unsigned int j = 0;

  // the below loop clears the screen (???)
  while(j < 80 * 25 * 2){
    vidptr[j] = ' ';

    // attribute byte light grey on black screen
    vidptr[j+1] = 0x07;
    j = j + 2;
  }

  j = 0;
  
  // this loop will write the string to video memory
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
