/*
 * function: func_021F9024
 * address: 0x021F9024
 * packet: pkt_ov135_021F9024
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021C8658 0x021C8658 arm ov114
 *   DWC_ShutdownFriendsMatch 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 */
#include "../include/Obj04528.h"
typedef unsigned char u8;
typedef signed short s16;
extern int func_021D5C70(u8 *p);
extern void func_021C8658(void);
extern void DWC_ShutdownFriendsMatch(void);
extern void func_0205CC20(void);
int func_021F9024(u8 *p, void *dialog)
{
    switch (((struct Obj04528 *)p)->fF88) {
    case 0:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 1:
        if (func_021D5C70(dialog)) (((struct Obj04528 *)p)->fF88)++;
        break;
    case 2:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 3:
        func_021C8658();
        DWC_ShutdownFriendsMatch();
        func_0205CC20();
        (((struct Obj04528 *)p)->fF88)++;
        break;
    default:
        (((struct Obj04528 *)p)->fF8A)++;
        if (((struct Obj04528 *)p)->fF8A > 60) return 1;
        break;
    }
    return 0;
}
