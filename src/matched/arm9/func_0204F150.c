/*
 * function: BILLBOARD_DeleteImage
 * address:  0x0204F150
 * packet:   pkt_0204F150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_FreeVramTexture   0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource   0x02046EFC  arm
 *
 * The direct form of the entry teardown: release the 0x28-byte entry's first
 * word if it is live, zero it, and stamp 5 into the halfword-style state word
 * at +0x14, which is what BILLBOARD_FindFreeImage's scan looks for.
 *
 * Every access re-reads the descriptor's +4 word, so the source spells the
 * base out at each use instead of binding it to a pointer local; the two
 * release calls take a fresh read of the entry's first word each, since the
 * first call may have changed it.  The value the `cmp` tested is the one the
 * first call receives, which is why there is no reload between them.
 *
 * The sibling entry points are BILLBOARD_ReleaseImageVramIfUsed (guarded, through two
 * function-pointer globals) and BILLBOARD_ReleaseImageVram (unguarded, same two globals);
 * neither is contiguous with this one.
 */
#include "../include/Obj05758.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void BILLBOARD_DeleteImage(u8 *a0, int i)
{
    u32 off = i * 0x28;

    if (*(u32 *)(((struct Obj05758 *)a0)->f4 + off) != 0) {
        G3D_SYSTEM_FreeVramTexture((u32 *)(*(u32 *)(((struct Obj05758 *)a0)->f4 + off)));
        G3D_SYSTEM_DeleteResource((struct Tagged *)(*(u32 *)(((struct Obj05758 *)a0)->f4 + off)));
        *(u32 *)(((struct Obj05758 *)a0)->f4 + off) = 0;
    }
    *(u32 *)(((struct Obj05758 *)a0)->f4 + off + 0x14) = 5;
}
