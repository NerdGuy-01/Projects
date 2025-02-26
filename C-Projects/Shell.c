// A Custom Command Line shell 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>  
#include <windows.h>

#define LINE 1024
#define ARGS 64  // Fixed typo: AGRS -> ARGS

int main() {
    char command[LINE];
    char *args[ARGS];  // Fixed typo: agrs -> args
    FILE *file;
    file = fopen("file.txt", "w");
    if(file == NULL) {
        printf("Error!! File is not opening.");
        return 1;  // Added return to handle error
    }
    
    while(1) {  // Moved the loop to the beginning for better flow
        printf("myshell$ ");  // Added space after prompt
        fflush(stdout); // Removes Buffer
        
        if(fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }
        
        fprintf(file, "%s", command);
        
        // Remove newline from command if present
        size_t len = strlen(command);
        if(len > 0 && command[len-1] == '\n') {
            command[len-1] = '\0';
        }
        
        // Check for exit command
        if(strcmp(command, "Exit") == 0 || strcmp(command, "exit") == 0) {
            printf("Program ended\n");
            break;  // Changed to break instead of closing file here
        }
        
        if(strlen(command) == 0) {  // Fixed typo: stlen -> strlen
            continue;
        }
        
        // Parsing the string into tokens
        int i = 0;
        char *token = strtok(command, " \t");  // Added space as delimiter
        while(token != NULL && i < ARGS-1) {  // Fixed typo: ARGS instead of AGRS
            args[i++] = token;
            token = strtok(NULL, " \t\n");  // Added space as delimiter
        }
        args[i] = NULL;
        
        // Convert args array to a single command string 
        char cmdstring[LINE] = "";
        for(int j = 0; args[j] != NULL; j++) {  // Fixed syntax: removed comma, added semicolon
            strcat(cmdstring, args[j]);
            strcat(cmdstring, " ");  // Added space between arguments
        }
        
        // Create a windows process
        STARTUPINFO si = {0}; 
        PROCESS_INFORMATION pi = {0}; 
        si.cb = sizeof(si); 


         char fullCommand[LINE + 10] = "cmd.exe /c ";
        strcat(fullCommand, cmdstring);
        
        if(!CreateProcess(NULL, cmdstring, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            printf("Error!! Unable to execute command: %s\n", cmdstring);
            DWORD error = GetLastError();
            printf("Error code: %lu\n", error);
        }
        else {
            // Wait for process to complete 
            WaitForSingleObject(pi.hProcess, INFINITE);     
                 CloseHandle(pi.hProcess); 
            CloseHandle(pi.hThread); 
        }
    }
    
    fclose(file);
    return 0;
}