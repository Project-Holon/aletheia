/*
 * function: ZUKAN_SAVE_CountCaughtNationalCounted
 * address:  0x0200D2D8
 * packet:   pkt_0200D2D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200C780 - not matched (parked at src/pending/ZUKAN_SAVE_IsCountedForNationalCompletion.c, itself capped on its own data table), and this call at 0x0200D2F4 is the only branch to it in the image.  All 56 bytes right.
 *
 * symbols:
 *   ZUKAN_SAVE_IsCountedForNationalCompletion  0x0200C780  thumb
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Blk37;
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
extern int ZUKAN_SAVE_IsCountedForNationalCompletion(u32 v);

u16 ZUKAN_SAVE_CountCaughtNationalCounted(void *a0)
{
    int i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsCaught(a0, i) == 1 && ZUKAN_SAVE_IsCountedForNationalCompletion((u16)i) == 1)
            n++;
    }
    return n;
}
