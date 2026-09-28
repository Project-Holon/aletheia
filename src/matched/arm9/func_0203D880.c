/*
 * function: func_0203D880
 * address:  0x0203D880
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A bare tail-call thunk to func_02039414.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D880.c \
 *       --func func_0203D880 --addr 0x0203D880 --arm --cc 1.1p1
 */

extern void func_02039414(void);

void func_0203D880(void)
{
    func_02039414();
}
