/*
 * function: FIELDMAP_CTRL_GRID_Main
 * address:  0x021A2DF0
 * packet:   pkt_ov021_021A2DF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb
 *   FIELD_PLAYER_SetupGrid  0x021A35F0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19760.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetCtrlWork(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int FIELD_PLAYER_CheckMoveRestrictFlag(int a);
extern int FIELD_PLAYER_SetupGrid(u32 a, u32 b, u32 c, u32 d);

void FIELDMAP_CTRL_GRID_Main(u32 a)
{
    u8 *p = (u8 *)FIELDMAP_GetCtrlWork((u8 *)a);
    void *q = FIELDMAP_GetFieldPlayer((void *)a);

    if (((struct Obj19760 *)p)->fC == 0) {
        u32 x = func_020362DC();
        u32 y = func_0203630C();
        u32 f = 0;

        if (FIELD_PLAYER_CheckMoveRestrictFlag((int)q) == 1)
            f |= 1;
        FIELD_PLAYER_SetupGrid((u32)q, x, y, f);
    }
}
