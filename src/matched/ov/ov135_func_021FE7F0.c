/*
 * function: func_021FE7F0
 * address: 0x021FE7F0
 * packet: pkt_ov135_021FE7F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006210 0x02006210 thumb
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021FF474 0x021FF474 thumb ov135
 */
#include "../include/Obj03832.h"
extern void func_02006210(void);
extern void func_021FFB20(char *, int, int);
extern void func_021FF474(void *, void *, int, void *);
int func_021FE7F0(char *p)
{
    if (((struct Obj03832 *)p)->f12E8 == 0) {
        func_02006210();
        func_021FFB20(p, ((struct Obj03832 *)p)->fD0, 1);
        if (((struct Obj03832 *)p)->fD0 == 0)
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 0, p + 0xfa0);
        else
            func_021FF474(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 1, p + 0xfa0);
        ((struct Obj03832 *)p)->f28 = 20;
    }
    return 2;
}
