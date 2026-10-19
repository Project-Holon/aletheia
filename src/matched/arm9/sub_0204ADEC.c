/*
 * function: CLACT_TransferPalette
 * address:  0x0204ADEC
 * packet:   pkt_0204ADEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   NNSi_G2dIsVramHandleSetEx  0x0206380C  arm
 *   NNSi_G2dGetVramHandleEx  0x02063800  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *
 * Flush both halves of one slot of the 0x18-byte-stride table at +0x110 of
 * the singleton behind 0x02146A74 into the destination the caller supplies.
 * Each half is guarded by NNSi_G2dIsVramHandleSetEx, fetched with NNSi_G2dGetVramHandleEx and
 * written through GX_LoadOBJPltt (selector 1) or func_0207E5D0 (selector 2),
 * with DC_FlushRange invalidating the destination first.
 *
 * `count` is in 32-byte units; zero means "use the length the destination
 * already records at +8" instead.  The shift happens unconditionally and is
 * overwritten by the predicated `ldreq`, so the guard has to be written as
 * a plain `if` after the shift, not as a ternary around it.
 *
 * `size` has to be spelled as a fourth parameter that the body immediately
 * overwrites, not as a local: as a local it takes r4 and the `idx * 0x18`
 * temporary takes r5, which is the original's assignment exactly swapped
 * and the only difference in the whole function.  The image says the
 * fourth argument is not actually passed: the one call site, the `blx` at
 * 0x0202DAD2, sets r0, r1 and r2 and leaves r3 alone.  So read the fourth
 * parameter as a register-allocation device for this rewrite, not as
 * evidence about the function's real arity.
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Slot {
    u8 pad_00[0x18];
};

struct Dest {
    u8    pad_00[8];
    u32   unk_08;
    void *unk_0c;
};

extern struct Mgr *g_ClactSystem;

extern int NNSi_G2dIsVramHandleSetEx(char *p, int i);
extern int NNSi_G2dGetVramHandleEx(char *p, int i);
extern void DC_FlushRange(void *dest, u32 size);
extern void GX_LoadOBJPltt(void *dest, void *src, u32 size);
extern void func_0207E5D0(void *dest, void *src, u32 size);

void CLACT_TransferPalette(u32 idx, struct Dest *dest, u32 count, u32 size)
{
    size = count << 5;

    if (count == 0) {
        size = dest->unk_08;
    }

    if (NNSi_G2dIsVramHandleSetEx((char *)(&((struct Slot *)g_ClactSystem->owner_slots2)[idx]), 1) != 0) {
        void *src = (void *)NNSi_G2dGetVramHandleEx((char *)(&((struct Slot *)g_ClactSystem->owner_slots2)[idx]), 1);

        DC_FlushRange(dest->unk_0c, size);
        GX_LoadOBJPltt(dest->unk_0c, src, size);
    }

    if (NNSi_G2dIsVramHandleSetEx((char *)(&((struct Slot *)g_ClactSystem->owner_slots2)[idx]), 2) != 0) {
        void *src = (void *)NNSi_G2dGetVramHandleEx((char *)(&((struct Slot *)g_ClactSystem->owner_slots2)[idx]), 2);

        DC_FlushRange(dest->unk_0c, size);
        func_0207E5D0(dest->unk_0c, src, size);
    }
}
