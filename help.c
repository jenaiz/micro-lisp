#include <stdio.h>

void help();
void help_small();
void unknown();

int main(int argc, char** argv){
  //unknown("hello world");
  //help_small();
  help();
}

void help() {
  printf("Usage: mlisp [switches] [--] [programfile] [arguments]\n");
  printf("-0[octal]       specify record separator (\\0, if no argument)\n");
  printf("-a              autosplit mode with -n or -p (splits $_ into $F)\n");
  printf("-c              check syntax only\n");
  printf("-Cdirectory     cd to directory before executing your script\n");
  printf("-d              set debugging flags (set $DEBUG to true)\n");
  printf("-e 'command'    one line of script. Several -e's allowed. Omit [programfile]\n");
  printf("-Eex[:in]       specify the default external and internal character encodings\n");
  printf("-Fpattern       split() pattern for autosplit (-a)\n");
  printf("-i[extension]   edit ARGV files in place (make backup if extension supplied)\n");
  printf("-Idirectory     specify $LOAD_PATH directory (may be used more than once)\n");
  printf("-l              enable line ending processing\n");
  printf("-n              assume 'while gets(); ... end' loop around your script\n");
  printf("-p              assume loop like -n but print line also like sed\n");
  printf("-rlibrary       require the library before executing your script\n");
  printf("-s              enable some switch parsing for switches after script name\n");
  printf("-S              look for the script using PATH environment variable\n");
  printf("-T[level=1]     turn on tainting checks\n");
  printf("-v              print version number, then turn on verbose mode\n");
  printf("-w              turn warnings on for your script\n");
  printf("-W[level=2]     set warning level; 0=silence, 1=medium, 2=verbose\n");
  printf("-x[directory]   strip off text before #!ruby line and perhaps cd to directory\n");
  printf("-h              show this message, --help for more info\n");
}

void unknown(char* option) {
  printf("Unknown option: %s\n", option);
}

void help_small() {
  printf("usage: mlisp [option] ... [bla bla bla] [arg] ...\n");
  printf("Try `mlisp -h' for more information.\n");
}
