/*
 * function: FIELD_PLAYER_GRID_ResetBlockedPose
 * address:  0x021A53D0
 * packet:   pkt_ov021_021A53D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 */
#include "../include/Obj09569.h"

typedef unsigned int u32;

void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
typedef unsigned short u16;
u16 FLDMMDL_GetDirDisp(void *p);
void *FLDMMDL_FreeAcmd(char *p);
typedef unsigned char  u8;
void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
void FLDMMDL_SetDrawStatus(void *p, u16 v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_GRID_ResetBlockedPose(u32 *p)
{
    void *h;
    int v;

    if (p[0] == 3) {
        h = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj09569 *)p)->fC);
        v = FLDMMDL_GetDirDisp(h);
        FLDMMDL_FreeAcmd(h);
        FLDMMDL_SetDirDispCheckPause((int)h, v);
        FLDMMDL_SetDrawStatus(h, 0);
        FIELD_PLAYER_CORE_SetStepKind((u8 *)p[3], 0);
    }
}
