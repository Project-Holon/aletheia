/*
 * function: func_021E0ED4
 * address: 0x021E0ED4
 * packet: pkt_ov170_021E0ED4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC01C 0x021EC01C thumb ov170
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 */
#include "../include/Obj08236.h"
extern int func_021EC01C(char *, int);
extern void func_021EBFEC(char *p, int i);
extern void func_021ED108(char *, int);
extern void func_021EBFA8(char *, int, int);
extern void func_021EC000(char *, int, int);
extern int func_021E0190(char *p);
#define W(p) (*(char **)((p) + 0x2C))
int func_021E0ED4(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((struct Obj08236 *)b)->fC) {
    case 0:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 1);
            func_021EBFA8(W(p), 10, 2);
        }
        (((struct Obj08236 *)b)->fC)++;
        /* fall through */
    case 1:
        if (!func_021E0190((char *)p))
            (((struct Obj08236 *)b)->fC)++;
        break;
    case 2:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 0);
            func_021EC000(W(p), 10, 0);
        }
        ((struct Obj08236 *)b)->fC = 0;
        return 0;
    }
    return 1;
}
