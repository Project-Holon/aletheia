/*
 * function: func_020528BC
 * address:  0x020528BC
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 4 bytes: same pool-load order residue as func_020528A8; ABS32 func_02052F90 at +0x0c needs that function matched
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528BC.c \
 *       --func func_020528BC --addr 0x020528BC --cc 1.1p1 --arm
 */

extern int func_02052984(int a, int (*cb)(void));
extern int func_02052F90(int a, int b);

int func_020528BC(int a)
{
    return func_02052984(a, (int (*)(void))func_02052F90);
}
