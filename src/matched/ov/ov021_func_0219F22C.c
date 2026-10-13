/*
 * function: FLDMMDL_DRAW_InitDirAnimeB
 * address:  0x0219F22C
 * packet:   pkt_ov021_0219F22C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitDrawProcWork  0x0216D6D8  thumb  ov010
 *   FLDMMDL_DRAW_InitDirState  0x0219FE9C  thumb  ov021
 *   FLDMMDL_BLACT_AddActorMmdlOrReserve  0x0219C814  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_InitDrawProcWork(int a0, int a1);
extern void FLDMMDL_DRAW_InitDirState(u8 *);
extern int FLDMMDL_BLACT_AddActorMmdlOrReserve(u32 a, u16 *b);

void FLDMMDL_DRAW_InitDirAnimeB(u32 a)
{
    u8 *q = FLDMMDL_InitDrawProcWork(a, 8);
    FLDMMDL_DRAW_InitDirState(q + 4);
    FLDMMDL_BLACT_AddActorMmdlOrReserve(a, (u16 *)q);
}
