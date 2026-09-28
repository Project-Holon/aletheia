/*
 * function: func_02052F90
 * address:  0x02052F90
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8140  0x020A8140  data
 *
 * Twin of src/matched/func_02052F58.c: same twelve instructions and the same
 * two pool words by position, differing only in the global function pointer
 * it calls (0x020A8140 against 0x020A8148).  Carries the same per-file pin
 * for the same measured tells (register `blx r3` beside an ARMv4T
 * `ldm sp!, {lr}; bx lr` return, and `sub sp, sp, #4` where 1.1p1 pads with a
 * dead `push {r3}`).
 *
 * Evidence recorded in docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F90.c \
 *       --func func_02052F90 --addr 0x02052F90 --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);

int func_02052F90(u32 a0, u32 a1)
{
    return (g_020A8140(a0, a1, 0) & 0xffff) << 3;
}
