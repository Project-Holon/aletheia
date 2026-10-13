/*
 * function: FIELD_TILE_MOVE_SpinFinish
 * address:  0x021C8B78
 * packet:   pkt_ov021_021C8B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_TILE_MOVE_GetSpinStopDir  0x021C8A8C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern int FIELD_TILE_MOVE_GetSpinStopDir(u32 a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
void FIELD_TILE_MOVE_SpinFinish(P *p)
{
    FLDMMDL_ClearStatusBit((u32 *)p->fC, 8);
    if (p->f10 != 0)
        FLDMMDL_SetDirDispCheckPause(p->fC, FIELD_TILE_MOVE_GetSpinStopDir((u32)p));
}
