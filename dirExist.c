 #include <stdio.h>
  #include <dirent.h>

  int main(int argc, char **argv) {

        char path[20]="\logfile1.txt";
        FILE *fp;
        fp=fopen(path,"w");
          fprintf(fp,"fhgsf");
         fclose(fp);


        /* if the given directory doesn't exists */
        return 0;
  }
