/*
 * function: FIELD_PLAYER_GRID_GetStandResultOnFoot
 * address:  0x021A4544
 * packet:   pkt_ov021_021A4544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_PLAYER_GRID_GetWalkResultOnFoot  0x021A4598  thumb  ov021
 */
#include "../include/Obj01657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFoot(u8 *a, void *b, u8 *c);

int FIELD_PLAYER_GRID_GetStandResultOnFoot(u8 *p, u32 r, u8 *q)
{
    if (FLDMMDL_CheckPossibleAcmd(r) == 1) {
        if (((struct Obj01657 *)q)->f8 != 9) {
            if (((struct Obj01657 *)q)->f8 != FLDMMDL_GetDirDisp((void *)r) && ((struct Obj01657 *)q)->f10 == 0) {
                if ((((struct Obj01657 *)q)->fC & 1) == 0) {
                    return 3;
                }
                if ((2 & ((struct Obj01657 *)q)->f4) == 0) {
                    return 3;
                }
            }
            return FIELD_PLAYER_GRID_GetWalkResultOnFoot(p, (void *)r, q);
        }
        return 1;
    }
    return 0;
}
