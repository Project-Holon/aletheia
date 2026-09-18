/*
 * function: func_020528A8
 * address:  0x020528A8
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 4 bytes: the pool loads come out in the opposite order (`ldr ip,[pc]` then `ldr r1,[pc]` in the original); also ABS32 func_02052F58 at +0x0c needs that function matched
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528A8.c \
 *       --func func_020528A8 --addr 0x020528A8 --cc 1.1p1 --arm
 */

extern int func_020528D0(int a, int (*cb)(void));
extern int func_02052F58(int a, int b);

int func_020528A8(int a)
{
    return func_020528D0(a, (int (*)(void))func_02052F58);
}
