#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "encrypted_data.txt"

void encryptPwd(char *pwd, char *encPwd) {
    char key = 'S'; // Simple XOR encryption key for Password 
    int len = strlen(pwd);
    for (int i = 0; i < len; i++) {
        encPwd[i] = pwd[i] ^ key;
    }
    encPwd[len] = '\0';
}

void encryptCaesar(char *text, int shift) {
    shift = shift % 26;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        }
    }
}

void encryptXOR(char *text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] ^= key;
    }
}

void writeFile(char *pwd, char *data, int method, int shift) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%d\n", method);
    fprintf(file, "%d\n", shift);
    fprintf(file, "%s\n", pwd);
    fprintf(file, "%s\n", data);
    fclose(file);
}

int main() {
    char data[1024], password[50], encPassword[50];
    char key = 'K';
    int shift, method;

    printf("Set a password: ");
    scanf("%49s", password);
    encryptPwd(password, encPassword);

    printf("Enter text to store: ");
    getchar();
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Select encryption method (1: Caesar Cipher, 2: XOR): ");
    scanf("%d", &method);

    if (method == 1 || strcmp(method,"Caeser Cipher")==0) {
        printf("Enter shift value for Caesar Cipher: ");
        scanf("%d", &shift);
        encryptCaesar(data, shift);
    } else if (method == 2 || strcmp(method,"XOR")) {
        shift = 0; // No shift needed for XOR
        encryptXOR(data, key);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    writeFile(encPassword, data, method, shift);
    printf("Data saved successfully!\n");
    return 0;
}
