/*
 * function: func_021EC804
 * address:  0x021EC804
 * packet:   pkt_ov170_021EC804
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC428 0x021EC428 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ECB74 0x021ECB74 thumb
 *   func_021EC08C 0x021EC08C thumb
 */
#include "../include/Obj24013.h"
#include "../include/Obj24014.h"
#include "../include/Obj24015.h"

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC428(char *p, int a, int i, int b);
extern void func_021EC000(char *p, int i, int v);
extern void func_021ECB74(char *a, int b);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);

void func_021EC804(char **p, short dx)
{
    short t[2];
    short reset;
    short lim;
    unsigned short i;
    unsigned char k;
    if (dx >= 0) {
        lim = 0xB0;
        reset = -8;
    } else {
        lim = -8;
        reset = 0xB0;
    }
    for (i = 0; i < 0x1E; i++) {
        k = *(unsigned char *)(p[11] + i + 0x3DD2);
        func_021EC0B0(p[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            func_021EC428(p[11], (int)(p[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(p[11] + i + 0x3DB4));
            func_021EC000(p[11], k, *(int *)(p[11] + i * 4 + 0x3DF8));
            if (((struct Obj24013 *)(p[11]))->fA17A == 0 && (((struct Obj24014 *)(p[0]))->f24 == 3 || ((struct Obj24015 *)(p[0]))->f24 == 5))
                func_021ECB74((char *)p, i);
        }
        func_021EC08C(p[11], k, t[1], t[0], 0);
    }
}
