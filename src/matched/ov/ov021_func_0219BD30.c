/*
 * function: FLDMMDL_MOVE_TurnToFellow
 * address:  0x0219BD30
 * packet:   pkt_ov021_0219BD30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 */
#include "../include/Obj05999.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern u32 FLDMMDL_MOVE_GetDirAddGridZ(u16);
extern u32 FLDMMDL_ACMD_ConvertCodeByDir(u16, u32);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);

int FLDMMDL_MOVE_TurnToFellow(char *a, struct Obj05999 *b)
{
    u32 x = FLDMMDL_GetGridNowX((void *)a);
    u32 y = FLDMMDL_GetGridNowZ((void *)a);
    u32 px = FLDMMDL_GetGridNowX((void *)(b->f8));
    u32 py = FLDMMDL_GetGridNowZ((void *)(b->f8));
    u32 pz = FLDMMDL_GetGridOldX((void *)(b->f8));
    u32 pw = FLDMMDL_GetGridOldZ((void *)(b->f8));
    u32 r;
    if (x == px && y == py) {
        return 0;
    }
    r = FLDMMDL_MOVE_GetDirFromPoints(x, y, pz, pw);
    x += (u32)FLDMMDL_MOVE_GetDirAddGridX((u16)r);
    y += FLDMMDL_MOVE_GetDirAddGridZ(r);
    if (x != px || y != py) {
        FLDMMDL_SetLocalAcmd(a, (u16)FLDMMDL_ACMD_ConvertCodeByDir(r, 12));
        return 1;
    }
    return 0;
}
