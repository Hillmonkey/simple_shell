/**
 *_strcmp - function that compares two strings.
 *@s1:argument
 *@s2:arguments
 *
 *Return: 0
*/

int _strcmp(char *s1, char *s2)
{
	int a = 0;
	int b = 0;

	while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a])
	{
		a++;
	}
	if (s1[a] != s2[a])
	{
		b = s1[a] - s2[a];
		return (b);
	}
	return (0);

}

/**
 **_strcpy - function returns the length of a string.
 *@src: variable
 *@dest: variable
 *Description: returns length
 *Return: variable
**/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	char *ptr1;

	while ((dest[i] = src[i]))
		i++;

	ptr1 = dest;

	return (ptr1);
}
/**
**_strlen - length of the string
**@s: pointer to string
**Return: Counter
**/
int _strlen(char *s)
{
	int i;
	
	for (i = 0; *s != '\0'; i++)
	{
		++s;
	}
	return (i);
}

