/*
 * function: func_021DD38C
 * address: 0x021DD38C
 * packet: pkt_ov171_021DD38C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE76C 0x021DE76C thumb ov171
 *   func_021DCBA4 0x021DCBA4 thumb ov171
 *   func_021DCBE8 0x021DCBE8 thumb ov171
 *   func_021DE080 0x021DE080 thumb ov171
 *   func_021DDFBC 0x021DDFBC thumb ov171
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 */
#include "../include/Obj10659.h"
extern void func_021DE76C(unsigned char *p, int mode);
extern void func_021DCBA4(char *);
extern int func_021DCBE8(unsigned char *p);
typedef unsigned char  u8;
extern void func_021DE080(u8 *p, int i, int value);
extern void func_021DDFBC(u8 *p);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
int func_021DD38C(char *p)
{
    switch (((struct Obj10659 *)p)->fC70) {
    case 0:
        func_021DE76C((unsigned char *)p, 0);
        func_021DCBA4(p);
        BG_SYS_SetMainPlaneVisible(2, 0);
        ++((struct Obj10659 *)p)->fC70;
        break;
    case 1:
        if (!func_021DCBE8((unsigned char *)p)) {
            func_021DE080((u8 *)p, 12, 4);
            func_021DE080((u8 *)p, 13, 5);
            func_021DE080((u8 *)p, 14, 0);
            func_021DDFBC((u8 *)p);
            ((struct Obj10659 *)p)->fC70 = 0;
            return 4;
        }
        break;
    }
    return 8;
}
