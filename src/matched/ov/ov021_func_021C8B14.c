/*
 * function: FIELD_TILE_MOVE_SpinStartStep
 * address:  0x021C8B14
 * packet:   pkt_ov021_021C8B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FIELD_TILE_MOVE_GetSpinStepAcmd  0x021C8A7C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern int FIELD_TILE_MOVE_GetSpinStepAcmd(u32 a);
extern void FLDMMDL_SetAcmd(u32 a, u32 b);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern int GFL_USE_GetSeSlot(u32 a0);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void func_020061E4(u32 id);
void FIELD_TILE_MOVE_SpinStartStep(P *p)
{
    FLDMMDL_SetAcmd(p->fC, FIELD_TILE_MOVE_GetSpinStepAcmd((u32)p));
    FLDMMDL_SetStatusBit((u32 *)p->fC, 8);
    if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x694)) == 0)
        func_020061E4(0x694);
}
