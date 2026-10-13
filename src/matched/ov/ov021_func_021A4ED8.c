/*
 * function: FIELD_PLAYER_GRID_StartLedgeJumpOnFoot
 * address:  0x021A4ED8
 * packet:   pkt_ov021_021A4ED8
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
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj19792.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 FLDMMDL_GetDirDisp(void *p);
int FLDMMDL_ACMD_ConvertCodeByDir(int k, int a);
void FLDMMDL_SetAcmd(int b, int v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void GFL_USE_PlaySeDefaultVolume(u32 a);

void FIELD_PLAYER_GRID_StartLedgeJumpOnFoot(u32 *p, int b, u8 *c)
{
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj19792 *)c)->f8, 0x38));
    p[0] = 1;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)p[3], 1);
    GFL_USE_PlaySeDefaultVolume(0x55E);
}
