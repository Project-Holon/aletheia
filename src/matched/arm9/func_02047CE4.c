/*
 * function: G3D_SYSTEM_ResetDrawCounts
 * address:  0x02047CE4
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem  0x02146A5C  data
 *
 * An unlabelled ARM leaf that follows G3D_SYSTEM_DrawRenderObj's pool word: it clears
 * the two counters at +4 and +8 of the global at 0x02146A5C (the same global
 * G3D_SYSTEM_SetLight indexes through, whose first word is the context pointer).
 * One `mov r1, #0` feeds both stores.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_ResetDrawCounts.c \
 *       --func G3D_SYSTEM_ResetDrawCounts --addr 0x02047CE4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct G02146A5C {
    void *obj;          /* +0x00 */
    u32   f4;           /* +0x04 */
    u32   f8;           /* +0x08 */
};

extern struct G02146A5C _G3dSystem;

void G3D_SYSTEM_ResetDrawCounts(void)
{
    _G3dSystem.f4 = 0;
    _G3dSystem.f8 = 0;
}
