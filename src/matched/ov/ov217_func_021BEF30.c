/*
 * function: func_021BEF30
 * address: 0x021BEF30
 * packet: pkt_ov217_021BEF30
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 * symbols:
 *   func_021BF7E0 0x021BF7E0 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021C11E8 0x021C11E8 thumb ov217
 *   func_021C1224 0x021C1224 thumb ov217
 *   func_021C272C 0x021C272C thumb ov217
 *   func_021C271C 0x021C271C thumb ov217
 */
#include "../include/Obj25921.h"
typedef unsigned char u8;
typedef signed int s32;
extern unsigned func_021BF7E0(void *);
extern u8 *func_021BF76C(void *p);
extern u8 func_021C11E8(u8 *p, u8 n);
extern void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py);
extern unsigned func_021C272C(unsigned,unsigned);
extern unsigned func_021C271C(unsigned,unsigned,unsigned);
void func_021BEF30(char *p)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    unsigned slot;
    n=func_021BF7E0(p);
    object=func_021BF76C(p);
    i=0;
    n--;
    for (;n>=0;n--) {
        id=func_021C11E8(object,n);
        func_021C1224(object,n,&x,&y);

        if (id>=10) {
            slot=*(unsigned *)(p+i*4+0x2d4);
            func_021C272C(slot,id);
            func_021C271C(slot,x,y);
            i++;
        }
    }
    ((struct Obj25921 *)p)->f2FC=i;
}
