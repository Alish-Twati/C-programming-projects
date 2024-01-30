#include <stdio.h>
#include <string.h>
void encrypt(const char* input, const char* output)
{
    // Open input file in read mode
    FILE*inFile=fopen(input,"r");
    // Open output file in write mode
    FILE*outFile=fopen(output,"w");
    // Check if file opening was successful
    if (inFile==NULL || outFile==NULL)
    {
        // Print error message
        printf("Error opening the given input files!\n");
        return;  // Return from the function
    }

    int ch;
    // Read each character from input file until end of file
    while ((ch=fgetc(inFile))!=EOF)
    {
         // Encrypt the character by adding 100 to its ASCII value
        ch=ch+100;
        // Write the encrypted character to the output file
        fputc(ch,outFile);
    }

    // Close the input file
    fclose(inFile);
    // Close the output file
    fclose(outFile);
    // Print success message
    printf("The given file '%s' encrypted successfully to '%s'!\n", input, output);
}

void decrypt(const char* input, const char* output)
{
     // Open input file in read mode
    FILE*inFile=fopen(input,"r");
    // Open output file in write mode
    FILE*outFile=fopen(output,"w");

    // Check if file opening was successful
    if (inFile==NULL || outFile==NULL)
    {
        // Print error message
        printf("Error opening the given input files!\n");
        return;  // Return from the function
    }

    int ch;
    // Read each character from input file until end of file
    while ((ch=fgetc(inFile))!=EOF)
    {
        // Decrypt the character by subtracting 100 from its ASCII value
        ch=ch-100;
        // Write the decrypted character to the output file
        fputc(ch,outFile);
    }

    // Close the input file
    fclose(inFile);
    // Close the output file
    fclose(outFile);
    // Print success message
    printf("The given file '%s' decrypted successfully to '%s'!\n", input, output);
}

int main()
{
    char input[30];
    char output[30];
    int choice;

    printf("Welcome to the file encryption and decryption program.\n");
    printf("Enter the name of the input file to open: ");
    // Read the input file name from the user
    scanf("%s",input);

    printf("Enter the name of the output file to create: ");
    // Read the output file name from the user
    scanf("%s",output);
    // Check if the output file name is the same as the input file name
    if (strcmp(input,output) == 0)
    {
        printf("Error: The input and output file names cannot be the same.\n");
        printf("Enter any different file names for output.\n");
        return 0;  // Return from the program
    }

    printf("\nChoose an option:\n");
    printf("1. Encrypt the file.\n");
    printf("2. Decrypt the file.\n");
    printf("Enter your choice (1 or 2): ");
    // Read the user's choice
    scanf("%d",&choice);

    if (choice==1)
    {
        // Call the encrypt function
        encrypt(input, output);
    }
    else if (choice==2)
    {
        // Call the decrypt function
        decrypt(input, output);
    }
    else
    {
        // Print error message for invalid choice
        printf("Invalid choice!\n");
    }

    return 0;
}

