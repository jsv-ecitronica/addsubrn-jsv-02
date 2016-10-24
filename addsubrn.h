/*
* Library for add and sub roman numbers.
* Designed by Javier Soto Vargas
*/

#ifndef ADDSUBRN_H
#define ADDSUBRN_H

char pdm; //print debug messages, 0 disabled, others enabled

typedef int bool;
enum {false, true};

int AddRomanNumerals(char *num1, char *num2, char *ope);
int SubRomanNumerals(char *num1, char *num2, char *ope);
int ConvertUppercaseValidateChar(char *num);
int ValidateRoman(char *num);
void SubstituteSubstractiveValues(char *ori_num,char *dest_num);
void CombineGroupsOfSymbols(char *ope);
void SubstituteValuesToSubstractiveValues(char *ope);
int SubstituteNextSuperiorOfSymbol(char *num, char symbol);

#define OK                          0
#define NOK                         1
#define NO_INPUT                    2
#define TOO_LONG                    3
#define CHAR_IS_NO_ROMAN            4
#define MORE_THAN_THREE_IXCM_ROMAN  5
#define MORE_THAN_ONE_VLD_ROMAN     6
#define SYNTAX_ERROR_ROMAN          7
#define SUBTRACTION_NOT_POSSIBLE    8
#define SUBTRACTION_IS_ZERO         9

//
#define MAX_LEN      16 //represents the lenght of the number including de final


#endif
