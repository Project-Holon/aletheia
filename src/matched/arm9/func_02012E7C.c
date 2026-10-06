/*
 * function: func_02012E7C
 * address:  0x02012E7C
 * packet:   pkt_02012E7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0016 THM_CALL func_020073B0       : 020073B0 (thumb, from name) has no witness outside 02012E7C..02012EBC
 */
#include "../include/Obj00054.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_02005C64(void);
extern int func_020073B0(char *a0, u32 a1);
extern int func_020351A0(u32 v);
extern void func_02010444(void);
extern void func_02034FB8(u32 a);

int func_02012E7C(char *p, int a1)
{
    int r;

    if (func_02005C64() == 1)
        return 0;
    r = func_020073B0((char *)(*(u32 *)&((struct Obj00054 *)p)->f0), a1);
    if (r == 2 || r == 3) {
        func_020351A0(2);
        func_02010444();
        ((struct Obj00054 *)p)->f1CE = 0;
        func_02034FB8(0x80);
    }
    return r;
}
