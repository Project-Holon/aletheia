/*
 * function: func_0203D7FC
 * address:  0x0203D7FC
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Releases the aligned block func_0203D7C8 returns, via the pointer kept
 * just before it, and tolerates a null.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D7FC.c \
 *       --func func_0203D7FC --addr 0x0203D7FC --arm --cc 1.1p1
 */

typedef unsigned char u8;

extern void func_020307B0(void *p);

void func_0203D7FC(void *p)
{
    if (p == 0) {
        return;
    }
    func_020307B0(*(void **)((u8 *)p - 4));
}
