/*
 * function: func_02052F90
 * address:  0x02052F90
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, same residue as func_02052F58 (its 0x020A8140 twin)
 *
 * Twin of func_02052F58 over the pointer slot at 0x020A8140.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052F90.c \
 *       --func func_02052F90 --addr 0x02052F90 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_020A8140;

int func_02052F90(int a, int b)
{
    return (((int (*)(int, int, int))g_020A8140)(a, b, 0) & 0xFFFF) << 3;
}
