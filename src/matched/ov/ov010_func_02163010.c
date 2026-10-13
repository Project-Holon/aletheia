/*
 * function: FLDMMDL_MOVE_SetupMove
 * address:  0x02163010
 * packet:   pkt_02163010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by the recursive MATCH unblocker: the +000A call targets
 * 0x0219B414, a labelless Thumb tail-call thunk in ov021 now matched in
 * src/matched/ov021_func_0219B414.c, so the site attests as `matched`.
 *
 * symbols:
 *   FLDMMDL_CallMoveInitProc  0x0216D6F4  thumb  ov010
 *   FLDMMDL_MOVECODE_InitEventTypeProcThunk  0x0219B414  thumb  ov021
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void FLDMMDL_CallMoveInitProc(void *a0);
extern int FLDMMDL_MOVECODE_InitEventTypeProcThunk(int a);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);

int FLDMMDL_MOVE_SetupMove(u32 *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    FLDMMDL_CallMoveInitProc((void *)a0);
loc_02163018:
a0 = (u32 *)(t4 + 0);
    a0 = (u32 *)FLDMMDL_MOVECODE_InitEventTypeProcThunk((int)a0);
loc_0216301E:
a0 = (u32 *)(t4 + 0);
a1 = 2;
    a0 = (u32 *)FLDMMDL_SetStatusBit(a0, a1);
loc_02163026:
    return (int)a0;}
