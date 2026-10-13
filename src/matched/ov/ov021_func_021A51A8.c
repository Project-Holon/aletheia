/*
 * function: FIELD_PLAYER_GRID_StartStandOnSurf
 * address:  0x021A51A8
 * packet:   pkt_ov021_021A51A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 */
#include "../include/Obj19800.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 FLDMMDL_GetDirDisp(void *p);
int FLDMMDL_ACMD_ConvertCodeByDir(int k, int a);
void FLDMMDL_SetAcmd(int b, int v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_GRID_StartStandOnSurf(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19800 *)c)->f8;

    if (k == 9)
        k = FLDMMDL_GetDirDisp((void *)b);
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(k, 0));
    p[0] = 0;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)p[3], 0);
}
