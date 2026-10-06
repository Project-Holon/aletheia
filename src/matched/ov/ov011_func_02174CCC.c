/*
 * function: func_02174CCC
 * address:  0x02174CCC
 * packet:   pkt_ov011_02174CCC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is func_020127C4's argument (the r0 at that call is never re-set).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02174734  0x02174734  thumb ov011
 *   func_02174D5C  0x02174D5C  thumb ov011
 *   func_021748CC  0x021748CC  thumb ov011
 *   func_02174954  0x02174954  thumb ov011
 */
#include "../include/Obj04951.h"

typedef unsigned int   u32;
u32 func_02026478(void *obj);
unsigned char *func_020127C4(void *p);
typedef unsigned char  u8;
int func_02174734(char *p, int b, void *c);
void func_02174D5C(int *p, const u8 *q);
int func_021748CC(char *p, int a);
u32 func_02174954(u32 p);

void func_02174CCC(unsigned char *p)
{
    unsigned char i;
    unsigned char *e;
    unsigned char *q;
    int h;

    h = func_02026478((void *)(((struct Obj04951 *)p)->f4));
    if (p[0x908] != 0) {
        if (func_02174734((char *)p, p[0x908], (void *)func_020127C4((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    e = p + 0x8D4;
    for (i = 0; i < 3; i++) {
        q = p + i * 4;
        if (q[0x8D5] == 1) {
            func_02174D5C((int *)p, e + i * 4);
            if (func_021748CC((char *)p, i) == 1) {
                q[0x8D5] = 0;
            }
        }
    }
    if (p[0x8E1] == 1) {
        if (func_02174954((u32)(p + 0x8E0)) == 1) {
            p[0x8E1] = 0;
        }
    }
}
