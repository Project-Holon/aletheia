/*
 * function: func_0206B7A8
 * address:  0x0206B7A8
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 3 bytes: same register choice residue as func_0206B780 (field +16, flag bit 5)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B7A8.c \
 *       --func func_0206B7A8 --addr 0x0206B7A8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

void func_0206B7A8(char *p)
{
    void (*fn)(void) = *(void (**)(void))(p + 16);

    if (fn != 0)
        fn();
    *(u32 *)(p + 8) |= 32;
}
