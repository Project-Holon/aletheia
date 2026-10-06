/*
 * function: func_021DD10C
 * address: 0x021DD10C
 * packet: pkt_ov171_021DD10C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE080 0x021DE080 thumb ov171
 *   func_020434DC 0x020434DC arm
 *   func_021DE76C 0x021DE76C thumb ov171
 *   func_021DCBA4 0x021DCBA4 thumb ov171
 *   func_021DCBE8 0x021DCBE8 thumb ov171
 *   func_021DDC28 0x021DDC28 thumb ov171
 *   func_021DD5A8 0x021DD5A8 thumb ov171
 *   func_021DD5D4 0x021DD5D4 thumb ov171
 *   func_021DD620 0x021DD620 thumb ov171
 *   func_020061E4 0x020061E4 thumb
 *   d_021DEB50 0x021DEB50 data a4
 */
#include "../include/Obj01420.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_021DE080(u8 *p, int i, int value);
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021DE76C(u8 *p, int mode);
extern void func_021DCBA4(char *);
extern int func_021DCBE8(u8 *p);
extern void func_021DDC28(u8 *p);
extern int func_021DD5A8(u8 *p, int i);
extern u8 func_021DD5D4(char *,s8,int,s8);
extern void func_021DD620(char *p, int step);
extern void func_020061E4(u32 a);
extern const u8 d_021DEB50[];
int func_021DD10C(char *p) {
    s8 old;
    switch (((struct Obj01420 *)p)->fC70) {
    case 0:
        func_021DE080((u8 *)p,12,18);
        func_021DE080((u8 *)p,13,19);
        func_021DE080((u8 *)p,14,14);
        func_020434DC(2,1);
        func_021DE76C((u8 *)p,1);
        func_021DCBA4(p);
        (((struct Obj01420 *)p)->fC70)++;
        break;
    case 1:
        if (!func_021DCBE8((u8 *)p)) {
            ((struct Obj01420 *)p)->fC70=0;
            old=((struct Obj01420 *)p)->fC5C;
            if (((struct Obj01420 *)p)->fC5D==old) {
                ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
                func_021DDC28((u8 *)p);
                return 7;
            }
            ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
            if (func_021DD5A8((u8 *)p,((struct Obj01420 *)p)->fC5D)==1) {
                ((struct Obj01420 *)p)->fC61=-d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)(-func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,1)));
            } else {
                ((struct Obj01420 *)p)->fC61=d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,-1));
            }
            func_020061E4(0x57b);
            return 9;
        }
        break;
    }
    return 6;
}
