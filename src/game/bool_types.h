#ifndef GAME_BOOL_TYPES_H
#define GAME_BOOL_TYPES_H

/* The Bool of the functions that return an enum with the values FALSE and TRUE.
 * It is an enum, not an int: the compiler treats a return value of it differently. */
typedef enum { FALSE, TRUE } Bool;

#endif
