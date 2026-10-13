/*
 * function: func_021E2094
 * address: 0x021E2094
 * packet: pkt_ov170_021E2094
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00000.h"

typedef unsigned int u32;
extern int TOUCHPANEL_GetTrg(void);
extern u32 func_020362DC(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned);
int func_021E2094(char *p)
{
    if (TOUCHPANEL_GetTrg() == 1) {
        func_020061E4(0x54C);
        func_020355D8(1);
        return ((struct Obj00000 *)p)->f28;
    }
    if (func_020362DC() & 3) {
        func_020061E4(0x54C);
        func_020355D8(0);
        return ((struct Obj00000 *)p)->f28;
    }
    return 6;
}
