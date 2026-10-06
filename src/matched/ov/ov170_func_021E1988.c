/*
 * function: func_021E1988
 * address: 0x021E1988
 * packet: pkt_ov170_021E1988
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021DEA3C 0x021DEA3C thumb ov170
 *   func_021DEAFC 0x021DEAFC thumb ov170
 */
#include "../include/Obj08237.h"
#include "../include/Obj10653.h"
extern int func_021EBFEC(char *, int);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021DEAFC(int a);
int func_021E1988(unsigned char *p)
{
    char *w = *(char * *)&((struct Obj10653 *)p)->f2C;
    char *b = w + 0x58;
    switch (((struct Obj08237 *)b)->fC) {
    case 0:
        if (!func_021EBFEC(w, 10)) {
            unsigned old = p[0x16];
            p[0x16] = **(unsigned short * *)&((struct Obj08237 *)b)->f8;
            func_021DEA3C((int)p, old, old, 1);
            ((struct Obj08237 *)b)->fC = 1;
        }
        break;
    case 1:
        if (!func_021DEAFC((int)p)) {
            ((struct Obj08237 *)b)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
