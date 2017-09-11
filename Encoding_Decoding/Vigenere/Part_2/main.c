#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
RESOURCES:
http://tigger.uic.edu/~jleon/mcs425-s05/handouts/Vigenere-Cipher.pdf
http://rosettacode.org/wiki/Levenshtein_distance


2a) [10] Write 2 functions.
?	The first implements the pseudo-code in lecture 8 to compute the Levenshtein Distance between 2 strings
?	The second performs a Vigenère cipher on an input string, using this prototype:
?	Vigenere( char *szIn, char *szOut, int iOutmax, char *szKey )

2b) [5] Then, for main(),  select a test phrase of at least 8 letters plus 2 more phrases which are similar, and 3 which are very different.  Compute and print the Levenshtein Distances between the test phrase and the other 5.  Then encrypt them all with Vigenere (choose a cipher key of length 4) and compare the distances again. Interpret the results.
*/


void upper_case(char *src);
char* encipher(const char *src, char *key, int is_encode);
int levenshtein(const char *szOne, int iLOne, const char *szTwo, int iLTwo);

char *Vigenere(char *szIn, char *szOut, int iOutmax, char *szKey);
char *Convert_Upper_Case(char *convert);
char *Remove_Spaces(char *convert);

char conversion_state;

char *Star_Wars = "Don't lecture me, Obi-Wan. I see through the lies of the Jedi. ";
char Key[14] = "VIGENERECIPHER";

unsigned int string_length;

int main()
{
	int iConsoleInput = 5; int counter = 0;
	unsigned char ch;
	char *Encode = NULL, *Decode = NULL;
	unsigned char *Decryped_Pointer;
	char pointer_size = strlen(Star_Wars);
	char key[] = "VIGENERECIPHER";
	const char *t1 = "CreativeP";
	const char *s1 = "CrativeVe";
	const char *s2 = "CratinveP";
	const char *n1 = "StringsRrrr";
	const char *n2 = "NawtCommmon";
	const char *n3 = "InCodesTayie";

	printf("\n\n **************************************** \n Assignment Question 2a: \n\n");
	Encode = (char *)malloc(sizeof(char)*pointer_size + 1);
	Decode = (char *)malloc(sizeof(char)*pointer_size + 1);

	Encode[pointer_size] = '\0';
	Decode[pointer_size] = '\0';

	conversion_state = 0;
	printf("\n Unconverted String: %s", Star_Wars);
	Encode = Vigenere(Star_Wars, Encode, pointer_size, Key);

	printf("\n Converted String: %s", Encode);
	conversion_state = 1;
	Decode = Vigenere(Encode, Decode, pointer_size, Key);

	printf("\n Decoded String: %s", Decode);

	printf("\n\n **************************************** \n Assignment Question 2b: \n\n"); 
	printf("levenshtein distance between '%s' and '%s' : %d\n", s1, s2,
		levenshtein(s1, strlen(s1), s2, strlen(s2)));

	printf("levenshtein distance between '%s' and '%s' : %d\n", t1, s1,
		levenshtein(t1, strlen(t1), s1, strlen(s1)));

	printf("levenshtein distance between '%s' and '%s' : %d\n", t1,s2,
		levenshtein(t1, strlen(t1), s2, strlen(s2)));

	printf("levenshtein distance between '%s' and '%s' : %d\n", t1, n1,
		levenshtein(t1, strlen(t1), n1, strlen(n1)));

	printf("levenshtein distance between '%s' and '%s' : %d\n", t1, n2,
		levenshtein(t1, strlen(t1), n2, strlen(n2)));

	printf("levenshtein distance between '%s' and '%s' : %d\n", t1, n3,
		levenshtein(t1, strlen(t1), n3, strlen(n3)));

	return 0;
}

/*
-----------------------------------------------------------------------
--- All Special Chars, spaces and lower case letters must be removed or converted
1 conversion state = decode
0 conversion state = encode
*/
char *Vigenere(char *szIn, char *szOut, int iOutmax, char *szKey){
	int count = 0, length = 0, stringlength = 0, keyCount = 0, keyLength = 0, i = 0;
	char *Upper_Key;
	char *Upper_String;
	char *Upper_String_2;

	stringlength = strlen(szIn);
	keyLength = strlen(szKey);

	Upper_Key = (char *)malloc(sizeof(char)* (keyLength + 1));
	Upper_String = (char *)malloc(sizeof(char)* (stringlength + 1));
	Upper_String_2 = (char *)malloc(sizeof(char)* (stringlength + 1));

	Upper_Key = Convert_Upper_Case(szKey);


	if (conversion_state == 0){
		Upper_String_2 = Convert_Upper_Case(szIn);
		Upper_String = Remove_Spaces(Upper_String_2);
	}

	else
		Upper_String = Convert_Upper_Case(szIn);


	for (count = 0; count < stringlength; count++)
	{
		if (Upper_String[count] == '\0')
			break;

		if (conversion_state == 0)
			Upper_String[count] = 'A' + (((Upper_String[count] - 'A') + (Upper_Key[(count % keyLength)] - 'A')) % 26);

		else
			Upper_String[count] = 'A' + (((Upper_String[count]) - (Upper_Key[(count % keyLength)]) + 26) % 26);
	}

	return Upper_String;
}

//Removes any special chars, spaces etc// 
char *Remove_Spaces(char *convert){
	unsigned int count = 0, i = 0, stringlength = strlen(convert);
	char *Out_String;

	Out_String = (char *)malloc(sizeof(char)* stringlength + 1);

	for (count = 0; count < stringlength; count++){
		if (convert[count] == '\0')
			break;
		// all special chars occur between 0x00->0x40 and 0x7B->0xFF // 
		if (convert[count] < 0x7B && convert[count] > 0x40)
			Out_String[i++] = convert[count];
	}

	Out_String[i] = '\0';// null pad
	//printf("\n\n NEW STRING NO SPACES: %s", Out_String);
	return Out_String;
}

char *Convert_Upper_Case(char *convert){
	char *UC_String;
	char Up_Case;
	unsigned int count = 0;
	unsigned int  stringlength = strlen(convert);
	UC_String = (char *)malloc(sizeof(char)* stringlength + 1);

	//printf("\n LS: %d, \n %s", stringlength, convert); 
	while (*convert != '\0')
	{
		if (*convert == '\0' || count >= stringlength)
			break;

		if (islower(*convert))
		{
			Up_Case = *convert;
			Up_Case -= 0x20;
			*UC_String = Up_Case;
		}

		else
			*UC_String = *convert;

		convert++;
		UC_String++;
		count++;
	}
	UC_String -= count;
	UC_String[count] = '\0';


	return UC_String;
}



/* Code taken without permission from
http://rosettacode.org/wiki/Levenshtein_distance

*/
int levenshtein(const char *szOne, int iLOne, const char *szTwo, int iLTwo)
{
	int a, b, c;

	/* if either string is empty, difference is inserting all chars
	* from the other
	*/
	if (!iLOne) return iLTwo;
	if (!iLTwo) return iLOne;

	// if possible shorten the length of both strings if ends are the same // 
	if (szOne[iLOne] == szTwo[iLOne])
		return levenshtein(szOne, iLOne - 1, szTwo, iLTwo - 1);

	/* Check 3 Cases
	case 1 -  last part of char = on both sides, return to function -1 lenght on both strings
	case 2 -  go through the entire lenght of the first string compare it with 2nd string (which is shrinking)
	case 3 -  go trhough the entire length of the second string compare it with 1st string (which is shrinking)
	*/
	a = levenshtein(szOne, iLOne - 1, szTwo, iLTwo - 1); // shorten string length on both ends 1 & 2
	b = levenshtein(szOne, iLOne, szTwo, iLTwo - 1); // shorten string length on 2 only
	c = levenshtein(szOne, iLOne - 1, szTwo, iLTwo); // shorten string length on 1 only

	if (a > b) a = b;
	if (a > c) a = c;

	//	printf(" %s - %d %s - %d %d %d %d \n",szOne, iLOne, szTwo, iLTwo, a, b, c); 

	return a + 1;
}
