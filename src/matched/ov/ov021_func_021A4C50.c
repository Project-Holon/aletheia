/*
 * function: ov021_func_021A4C50
 * address:  0x021A4C50
 * packet:   pkt_ov021_021A4C50
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
 *   FIELD_PLAYER_GRID_GetWalkResultOnSurf  0x021A4B98  thumb  ov021
 *   FIELD_PLAYER_GRID_GetStandResultOnSurf  0x021A4B54  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09568.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_FreeAcmd(char *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern int FIELD_PLAYER_GRID_GetWalkResultOnSurf(u32, u32, u32);
extern int FIELD_PLAYER_GRID_GetStandResultOnSurf(u32, u32, u32);

int ov021_func_021A4C50(u32 a, u32 b, u8 *c)
{
    u32 r = FLDMMDL_GetDirDisp((void *)b);
    if (((struct Obj09568 *)c)->f8 != 9 && ((struct Obj09568 *)c)->f8 != r) {
        FLDMMDL_FreeAcmd((char *)b);
        return FIELD_PLAYER_GRID_GetWalkResultOnSurf(a, b, (u32)c);
    }
    if (FLDMMDL_CheckPossibleAcmd(b) == 0) {
        return 0;
    }
    if (((struct Obj09568 *)c)->f8 == 9) {
        return FIELD_PLAYER_GRID_GetStandResultOnSurf(a, b, (u32)c);
    }
    return FIELD_PLAYER_GRID_GetWalkResultOnSurf(a, b, (u32)c);
}
