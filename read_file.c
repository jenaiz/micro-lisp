#include <stdio.h>

int main(int argc, char** argv){
  
  FILE *source;
  char buf[1000];

  if (argc == 2) {
    printf("Reading source file... %s\n", argv[1]);
    source = fopen(argv[1],"r");
  } else {
    printf("ERROR: Add a source file to the compiler.\n");
    return 1;
  }
  
  if (!source) {
    return 1;
  }

  while (fgets(buf, 1000, source) != NULL) {
    printf("%s", buf);
  }    

  fclose(source);
  return 0;
}
