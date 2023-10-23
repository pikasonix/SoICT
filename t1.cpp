#include <stdio.h>
#include <string.h>


int main()
{
   const char haystack[20] = "VietJackTeam";
   const char needle[10] = "Team";
   char *ret;

   ret = strstr(haystack, needle);

   printf("Chuoi con la: %s\n", ret);
   
   return(0);
}
