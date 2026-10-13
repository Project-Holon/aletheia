/*
 * function: ov021_func_021A4698
 * address:  0x021A4698
 * packet:   pkt_ov021_021A4698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetWalkResultOnFoot  0x021A4598  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnFoot  0x021A4544  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_FreeAcmd(char *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetWalkResultOnFoot(u8 *a, void *b, u8 *c);
extern int FIELD_PLAYER_GRID_GetStandResultOnFoot(u8 *p, u32 r, u8 *q);

int ov021_func_021A4698(u32 a, u32 b, u8 *c)
{
    u32 r = FLDMMDL_GetDirDisp((void *)b);
    if (((struct Obj01657 *)c)->f8 != 9 && ((struct Obj01657 *)c)->f8 != r) {
        FLDMMDL_FreeAcmd((char *)b);
        return FIELD_PLAYER_GRID_GetWalkResultOnFoot((u8 *)a, (void *)b, (u8 *)((u32)c));
    }
    if (FLDMMDL_CheckPossibleAcmd(b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnFoot((u8 *)a, b, (u8 *)((u32)c));
    }
    return FIELD_PLAYER_GRID_GetWalkResultOnFoot((u8 *)a, (void *)b, (u8 *)((u32)c));
}
