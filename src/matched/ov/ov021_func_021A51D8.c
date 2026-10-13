/*
 * function: FIELD_PLAYER_GRID_StartWalkOnSurf
 * address:  0x021A51D8
 * packet:   pkt_ov021_021A51D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 */
#include "../include/Obj07499.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FLDMMDL_ACMD_ConvertCodeByDir(int k, int a);
void FLDMMDL_SetAcmd(int b, int v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_GRID_StartWalkOnSurf(u32 *p, int b, u8 *c)
{
    int a = (((struct Obj07499 *)c)->f10 == 1) ? 0x14 : 0x10;

    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj07499 *)c)->f8, a));
    p[0] = 1;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)p[3], 1);
}
