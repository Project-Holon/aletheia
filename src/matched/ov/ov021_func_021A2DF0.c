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
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb
 *   FIELD_PLAYER_MoveGrid  0x021A35F0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19760.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetCtrlWork(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern int FIELD_PLAYER_CheckMoveRestrictFlag(int a);
extern int FIELD_PLAYER_MoveGrid(u32 a, u32 b, u32 c, u32 d);

void FIELDMAP_CTRL_GRID_Main(u32 a)
{
    u8 *p = (u8 *)FIELDMAP_GetCtrlWork((u8 *)a);
    void *q = FIELDMAP_GetFieldPlayer((void *)a);

    if (((struct Obj19760 *)p)->fC == 0) {
        u32 x = KEY_GetTrg();
        u32 y = KEY_GetCont();
        u32 f = 0;

        if (FIELD_PLAYER_CheckMoveRestrictFlag((int)q) == 1)
            f |= 1;
        FIELD_PLAYER_MoveGrid((u32)q, x, y, f);
    }
}
