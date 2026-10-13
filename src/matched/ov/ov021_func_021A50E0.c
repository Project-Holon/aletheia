/*
 * function: FIELD_PLAYER_GRID_StartBlockedOnCycle
 * address:  0x021A50E0
 * packet:   pkt_ov021_021A50E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 *   FIELD_PLAYER_GRID_CheckMapConnectAhead  0x021A5810  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj06012.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 FLDMMDL_GetDirDisp(void *p);
int FLDMMDL_ACMD_ConvertCodeByDir(int k, int a);
void FLDMMDL_SetAcmd(int b, int v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

int FIELD_PLAYER_GRID_CheckMapConnectAhead(u8 *p, int dir);
void func_020061E4(u32 a);

void FIELD_PLAYER_GRID_StartBlockedOnCycle(u32 *p, int b, u8 *c)
{
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj06012 *)c)->f8, 0x1C));
    p[0] = 3;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)p[3], 0);
    if (FIELD_PLAYER_GRID_CheckMapConnectAhead((u8 *)p, ((struct Obj06012 *)c)->f8) == 0)
        func_020061E4(0x55A);
}
