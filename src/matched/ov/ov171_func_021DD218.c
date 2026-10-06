/*
 * function: func_021DD218
 * address: 0x021DD218
 * packet: pkt_ov171_021DD218
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021DE914 0x021DE914 thumb ov171
 *   func_021DD558 0x021DD558 thumb ov171
 *   func_021DD620 0x021DD620 thumb ov171
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD500 0x021DD500 thumb ov171
 *   func_021DD5A8 0x021DD5A8 thumb ov171
 *   func_021DD5D4 0x021DD5D4 thumb ov171
 *   d_021DEB50 0x021DEB50 data a4
 */
#include "../include/Obj00347.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021DE914(char *);
extern int func_021DD558(char *, s8);
extern void func_021DD620(char *p, int step);
extern void func_020061E4(u32 a);
extern int func_021DD500(char *, int, int, int);
extern int func_021DD5A8(u8 *p, int i);
extern u8 func_021DD5D4(char *, s8, int, s8);
extern const u8 d_021DEB50[];
int func_021DD218(char *p) {
    int choice;
    s8 old;
    if (!func_0201C6B4(((struct Obj00347 *)p)->fB6C)) return 7;
    choice = func_021DE914(p);
    switch (choice) {
    case 0:
        if (func_021DD558(p, 1) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-1));
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 1:
        if (func_021DD558(p, -1) == 1) {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)1);
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 3:
        func_020061E4(0x551);
        return func_021DD500(p, 15, 9, 8);
    case 5: case 6: case 7: case 8: case 9: case 10:
        old = ((struct Obj00347 *)p)->fC5C;
        if (choice - 5 == old) break;
        ((struct Obj00347 *)p)->fC5C = choice - 5;
        if (func_021DD5A8((u8 *)p, choice - 5) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-func_021DD5D4(p, old, (s8)(choice - 5), 1)));
        } else {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)func_021DD5D4(p, old, (s8)(choice - 5), -1));
        }
        func_020061E4(0x57b);
        return 9;
    }
    return 7;
}
