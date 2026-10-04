/*
 * function: func_02204EB0
 * address:  0x02204EB0
 * packet:   pkt_02204EB0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 */
#include "../include/Obj14523.h"
#include "../include/Obj24946.h"

extern int func_02005E9C(int);
typedef unsigned int   u32;
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);

void func_02204EB0(char *a, char *b)
{
    if (((struct Obj24946 *)b)->f30 == 0 && ((struct Obj14523 *)a)->fC != 0) {
        func_02005E9C(((struct Obj14523 *)a)->fC);
        func_02005DE4(0);
        func_02005DF8(0x3c);
    }
}
