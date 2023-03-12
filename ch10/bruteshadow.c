#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char* argv[] ) {

  FILE *fd1, *fd2;
  char *str1, *str2;
  char *salt, *hash, *key, *key1;
  char buf[30], word[100], pass[300];
  
  if (argc != 3) {

    fprintf(stderr, "Usage: %s <file shadow> <file dict>\n", argv[0]);
    exit(-1);
  }

  str1 = (char*) malloc(300);
  //str2 = (char*) malloc(100);

  // открываем файл с зашифрованными паролями
  fd1 = fopen(argv[1], "r");
  
  fprintf(stderr, "Please, wait...\n");
  
  // читаем в цикле каждую строчку файла    
  while( fgets(str1, 300, fd1) != NULL)
  {
    str2 = strstr(str1, "$6$"); // ищем в строке символы $1$

    if (str2 != NULL) // и если находим, то 
    {
      // выделяем зашифрованный пароль
      key = strtok(str2, ":"); 
      snprintf(pass, sizeof(pass), "%s", key);    
      printf ("pass=%s (%ld)\n", pass, strlen(pass));
    
      // выделяем salt в зашифрованном пароле
      strtok(key, "$");    
      salt = strtok(NULL, "$");
      hash = strtok(NULL, "\0"); // эту операцию можно не делать

      // формируем salt в виде $1$salt$    
      snprintf(buf, sizeof(buf), "$6$%s$", salt);        
    
      // открываем файл словаря
      //fd2 = fopen("/usr/share/dict/words", "r"); 
      fd2 = fopen( argv[2], "r" ); 

      // читаем в цикле каждое слово из словаря
      while( fgets(word, 100, fd2) != NULL)
      {
        // удаляем символ новой строки
    	(&word[ strlen(word)] )[-1] = '\0';
	
	    // вычисляем новый зашифрованный пароль
        key1 = crypt(word, buf);

	    // сравниваем зашифрованные пароли

        if (!strncmp(key1, pass, strlen(key1))) {

            printf("OK! Password: %s\n\n", word);
	        break;
        }
      }

    
      fclose(fd2);

    }
  }

  fclose(fd1);
  free(str1);

  return 0;
}