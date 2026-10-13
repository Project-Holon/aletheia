/*
 * function: ZUKAN_SAVE_IsNationalCaughtComplete
 * address:  0x0200D298
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200D2D8 - not matched yet; this call at 0x0200D29A is the only branch to it in the image, so matching 0x0200D2D8 (pkt_0200D2D8) would convert the site to the `matched` class.  All 24 bytes right.
 *
 * symbols:
 *   ZUKAN_SAVE_CountCaughtNationalCounted  0x0200D2D8  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 ZUKAN_SAVE_CountCaughtNationalCounted(void *a0);

int ZUKAN_SAVE_IsNationalCaughtComplete(void *a0)
{
    u32 v = ZUKAN_SAVE_CountCaughtNationalCounted(a0);

    if (v >= 0x27a)
        return 1;
    return 0;
}
