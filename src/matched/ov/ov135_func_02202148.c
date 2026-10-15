/*
 * function: WORLDTRADE_SERVER_StateStartWipeOutRestore
 * address: 0x02202148
 * packet: pkt_ov135_02202148
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: nested if with equal sentinel arm first preserves the branch hop.
 * symbols:
 *   WORLDTRADE_DeleteTimeIcon 0x021F4FC4 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj14178.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void WORLDTRADE_DeleteTimeIcon(u8 *p);
extern int GXx_GetMasterBrightness_(volatile u16 *reg);
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int WORLDTRADE_SERVER_StateStartWipeOutRestore(u8 *p)
{
    WORLDTRADE_DeleteTimeIcon(p);
    if (((struct Obj14178 *)p)->fEB4 == 1) {
        if (GXx_GetMasterBrightness_((u16 *)0x0400106C) == -16)
            WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
        else
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj14178 *)p)->f28 = 0;
    return 3;
}
