#ifndef SRC_F_STRING_H_
#define SRC_F_STRING_H_

/**
 * @brief 	f_strlen - calculate the length of a string
 * 				The f_strlen() function calculates the length of the string
 * 				pointed to by s_, excluding the terminating null byte ('\0').

 *
 * @param s_ (string)
 *
 * @return  The f_strlen() function returns the number of bytes in
 *		        the string pointed to by s_
 */
unsigned f_strlen(const char *s_);

// -------------------------------------------------------

/**
 * @brief 	   	f_strdup - duplicate string.
 * 					Memory for the new string is obtained with calloc.
 *
 * @param s_ 	(char const *) original string.
 *
 * @return  	a pointer to a new string which is a duplicate of the string s.
 */
char *f_strdup(const char *s_);

// -------------------------------------------------------

/**
 * @brief 	f_strcmp  The strcmp() function compares the two strings s1 and s2. 
 * 			    The locale is not taken into account 
 * 			    (for a locale-aware comparison, see strcoll(3)). 
 * 			    The comparison is done using unsigned characters.
 *
 * @param s1_ (char const *) string one
 * @param s2_ (char const *) string two
 *
 * @return      integer indicating the result of the comparison, as follows: 
 *						• 0, if the s1 and s2 are equal;
 *						• a negative value if s1 is less than s2;
 *						• a positive value if s1 is greater than s2.
 */
int f_strcmp(const char *s1_, const char *s2_);

// -------------------------------------------------------

/**
 * @brief  	f_atoi() function converts the initial portion of the string pointed 
 * 						to by nptr to int.
 *
 * @param nptr (char *) string
 *
 * @return 	The converted value or 0 on error.
 */
int f_atoi(const char *nptr);

#endif // SRC_F_STRING_H_
