/*
 * function: func_021BEEA4
 * address: 0x021BEEA4
 * packet: pkt_ov217_021BEEA4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 * symbols:
 *   func_021C20D8 0x021C20D8 thumb ov217
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   func_021C11DC 0x021C11DC thumb ov217
 *   func_021C11FC 0x021C11FC thumb ov217
 *   func_021C20B4 0x021C20B4 thumb ov217
 *   func_021C20CC 0x021C20CC thumb ov217
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef signed int s32;
extern unsigned func_021C20D8(unsigned);
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern u8 *func_021BF76C(void *p);
extern unsigned func_021BF7F4(void *);
extern u8 func_021C11DC(u8 *p, u8 key);
extern void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
extern void func_021C20B4(int a0, int a1, int a2, int a3, int a4);
extern void func_021C20CC(unsigned);
void func_021BEEA4(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    func_021C20D8(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    if (((struct Obj00021 *)p)->f3D0==1) return;
    if (((struct Obj00021 *)p)->f3C8==0) return;
    if (func_021BF810(p)==0) return;
    object=func_021BF76C(p);
    index=func_021BF7F4(p);
    if (func_021C11DC(object,index)==0) return;
    if (((struct Obj00021 *)p)->f3C8!=0) {
        object=func_021BF76C(p);
        index=func_021BF7F4(p);
        func_021C11FC(object,index,&x,&y);

        func_021C20B4(*(unsigned *)&((struct Obj00021 *)p)->f2D0,104,34,x,y);
        func_021C20CC(*(unsigned *)&((struct Obj00021 *)p)->f2D0);
    }
}
