/*
 * function: func_021DED3C
 * address: 0x021DED3C
 * packet: pkt_ov137_021DED3C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E17EC 0x021E17EC thumb ov137
 *   func_021E1910 0x021E1910 thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj03304.h"
typedef unsigned char u8;
extern int func_021E17EC(void *);
extern int func_021E1910(void *);
typedef unsigned int   u32;
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
int func_021DED3C(u8 *p)
{
    if (((struct Obj03304 *)p)->f30 == func_021E17EC(p)) {
        if (func_021E1910(p) == 1) {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10253, 0, 0);
            ((struct Obj03304 *)p)->f0 = 45;
        } else {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10254, 0, 0);
            ((struct Obj03304 *)p)->f0 = 15;
        }
    }
    return 0;
}
