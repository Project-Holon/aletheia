/*
 * function: NNS_G3dGlbFlush
 * address:  0x0206A854
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_renderState       0x02148B4C  data
 *   NNS_G3dGeBufferOP_N    0x0206DDA4  arm
 *
 * The "leave this rig mode" counterpart of src/matched/NNS_G3dGlbFlushWVP.c: one
 * registration of the 0x3e record at g_renderState + 4, keyed by the word at
 * g_renderState[0], then bits 0 and 1 of the "initialised subsystems" flag word
 * at g_renderState + 0xFC are both cleared (the exact pair NNS_G3dGlbFlushWVP sets and
 * clears on the way in).
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell, same family and same pass as
 * NNS_G3dGlbFlushWVP.  The image RE-LOADS the single pool word at 0x0206A880
 * (0x02148B4C) twice, at 0x0206A858 and 0x0206A868, and keeps the frame at
 * `push {r3, lr}` (`08 40 2d e9`).  dsi/1.1p1 -O4,p hoists that one address
 * into callee-saved r4, giving `push {r4, lr}` and a single `ldr r4, [pc]`,
 * 36 concrete bytes out at the same 48.  Under the pin the C below is 48
 * bytes, 0 mismatches, both sites resolving.
 *
 * TWO SPELLING POINTS, both of them four bytes each and both needed at once,
 * which is why the intermediate attempts all sat at 52 bytes:
 *   1. the record pointer is `(char *)g_renderState + 4`, NOT `g_renderState + 1`.
 *      Spelled as the array index the front end folds the offset into a
 *      SECOND pool word; through the char cast the offset stays a runtime add,
 *      which 2.0 then fuses with the value load into the image's single
 *      post-indexed `ldr r0, [r1], #4` at 0x0206A860.  The same cast is what
 *      pins the 0xE registration in NNS_G3dGlbFlushWVP, for the same reason.
 *   2. the two bit clears must be SEPARATE statements.  Written as one
 *      expression (`& ~1u & ~2u`, or `& ~3u`) the front end folds them to a
 *      single `bic r1, r1, #3`, four bytes short of the image's `bic #1` at
 *      0x0206A870 followed by `bic #2` at 0x0206A874.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbFlush.c \
 *       --func NNS_G3dGlbFlush --addr 0x0206A854 --arm --cc ../2.0/sp2
 */

typedef unsigned int u32;

extern u32  g_renderState[];
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);

void NNS_G3dGlbFlush(void)
{
    NNS_G3dGeBufferOP_N(g_renderState[0], (char *)g_renderState + 4, 0x3e);
    g_renderState[0x3f] &= ~1u;
    g_renderState[0x3f] &= ~2u;
}
