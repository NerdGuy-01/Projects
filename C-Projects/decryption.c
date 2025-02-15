#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "encrypted_data.txt"

void encryptPwd(char *pwd, char *encPwd) {
    char key = 'S';
    int len = strlen(pwd);
    for (int i = 0; i < len; i++) {
        encPwd[i] = pwd[i] ^ key;
    }
    encPwd[len] = '\0';
}

void decryptCaesar(char *text, int shift) {
    shift = shift % 26;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + (26 - shift)) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + (26 - shift)) % 26;
        }
    }
}

void decryptXOR(char *text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] ^= key;
    }
}

void readFile(char *pwd, char *data, int *method, int *shift) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }
    fscanf(file, "%d\n", method);
    fscanf(file, "%d\n", shift);
    fgets(pwd, 50, file);
    fgets(data, 1024, file);
    fclose(file);
    
    pwd[strcspn(pwd, "\n")] = '\0';
    data[strcspn(data, "\n")] = '\0';
}

int main() {
    char data[1024], storedPwd[50], userPwd[50], encUserPwd[50];
    char key = 'K';
    int shift, method;

    readFile(storedPwd, data, &method, &shift);
    
    printf("Enter password: ");
    scanf("%49s", userPwd);
    encryptPwd(userPwd, encUserPwd);
    
    if (strcmp(encUserPwd, storedPwd) != 0) {
        printf("Incorrect password!\n");
        return 1;
    }
    
    if (method == 1) {
        decryptCaesar(data, shift);
    } else if (method == 2) {
        decryptXOR(data, key);
    } else {
        printf("Invalid encryption method!\n");
        return 1;
    }
    
    printf("Decrypted Data:\n%s\n", data);
    return 0;
}
