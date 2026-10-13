/*
 * function: FLDMMDL_DRAW_InitFixedState
 * address:  0x0219F8C8
 * packet:   pkt_ov021_0219F8C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitDrawProcWork  0x0216D6D8  thumb  ov010
 *   FLDMMDL_BLACT_AddActorMmdlOrReserve  0x0219C814  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_InitDrawProcWork(int a0, int a1);
extern int FLDMMDL_BLACT_AddActorMmdlOrReserve(u32 a, u16 *b);

void FLDMMDL_DRAW_InitFixedState(u32 a)
{
    u8 *q = FLDMMDL_InitDrawProcWork(a, 8);
    q[2] = 9;
    FLDMMDL_BLACT_AddActorMmdlOrReserve(a, (u16 *)q);
}
