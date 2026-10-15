/*
 * function: DOUBLE3DDISP_Delete
 * address:  0x0204EA64
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A80      0x02146A80  data
 *   DOUBLE3DDISP_SetupGraphics_EB68   0x0204EB68  arm
 *   DOUBLE3DDISP_SetupGraphics   0x0204EAD4  arm
 *
 * The cell-actor system's shutdown step: it bails out while the power-control
 * halfword at 0x04000304 is non-zero, then tears the system down one way or
 * the other depending on the +4 word of the singleton, clears +8 and toggles
 * +4 to 1 if it was 0.
 *
 * 0x04000606 is a hardware address cast in the source, not a relocation: it
 * is a pool word with no symbols block entry, and the halfword there is read
 * (which is what a `u16` hardware register at that address looks like).
 *
 * The +4 word is both tested and then re-read, and both re-reads of the
 * singleton (`ldr r0, [pc, #0x24]; ldr r1, [r0]`) are the global's own address
 * being reloaded after the call, so the source spells `g_02146A80` out again
 * instead of holding it in a local.
 *
 * `x = (x == 0) ? 1 : 0` comes out as `mov r2, #0` before the earlier store
 * and a single predicated `moveq r2, #1` here: the zero is materialised once
 * and shared with the store of 0 to +8.
 */

#include "../include/G_Double3Ddisp.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Double3Ddisp *g_02146A80;

extern void DOUBLE3DDISP_SetupGraphics_EB68(void);
extern void DOUBLE3DDISP_SetupGraphics(void);

void DOUBLE3DDISP_Delete(void)
{
    if (*(volatile u16 *)0x04000606 != 0) {
        return;
    }
    if (*(u32 *)(((u8 *)g_02146A80) + 8) == 0) {
        return;
    }
    if (*(u32 *)(((u8 *)g_02146A80) + 4) != 0) {
        DOUBLE3DDISP_SetupGraphics_EB68();
    } else {
        DOUBLE3DDISP_SetupGraphics();
    }
    *(u32 *)(((u8 *)g_02146A80) + 8) = 0;
    *(u32 *)(((u8 *)g_02146A80) + 4) = (*(u32 *)(((u8 *)g_02146A80) + 4) == 0) ? 1 : 0;
}
