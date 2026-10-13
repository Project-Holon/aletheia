/*
 * function: FIELD_PLAYER_GRID_StopTurnOrBlocked
 * address:  0x021A5408
 * packet:   pkt_ov021_021A5408
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetMmdl  0x021A572C  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09570.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_GRID_GetMmdl(u8 *p);
extern u32 FLDMMDL_GetDirDisp(void);
extern void *FLDMMDL_FreeAcmd(char *p);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

int FIELD_PLAYER_GRID_StopTurnOrBlocked(u8 *a)
{
    u32 x;
    u32 y;
    switch (((struct Obj09570 *)a)->f0) {
    case 0:
        break;
    case 1:
        return 0;
    case 2:
    case 3:
        x = (u32)FIELD_PLAYER_GRID_GetMmdl(a);
        y = FLDMMDL_GetDirDisp();
        FLDMMDL_FreeAcmd((char *)x);
        FLDMMDL_SetDirDispCheckPause(x, y);
        FLDMMDL_SetDrawStatus((void *)x, 0);
        FIELD_PLAYER_CORE_SetStepKind((u8 *)(*(u32 *)&((struct Obj09570 *)a)->fC), 0);
        break;
    }
    return 1;
}
