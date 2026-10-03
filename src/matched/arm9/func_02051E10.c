/*
 * function: func_02051E10
 * address:  0x02051E10
 * packet:   pkt_02051E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02051E64   0x02051E64  arm
 *
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through func_02051E64 and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E10.c \
 *       --func func_02051E10 --addr 0x02051E10 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02051E64(void *p, int a);

int func_02051E10(char *p, u32 x)
{
    if (*(u8 *)(p + 1) != 0) {
        u16 v = *(u16 *)(p + 2);

        if (v < 0xFFFF)
            *(u16 *)(p + 2) = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        func_02051E64(p, 0);
        return 3;
    }
    func_02051E64(p, 0);
    return 1;
}
