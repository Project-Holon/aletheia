/*
 * function: func_02051DE8
 * address:  0x02051DE8
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The conjunction shares one exit; `*(u8 *)(p+1)` is the armed flag the
 * 0x02051E10 sibling also tests.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051DE8.c \
 *       --func func_02051DE8 --addr 0x02051DE8 --cc 1.1p1 --arm
 */

extern void func_02051E64(void *p, int a, int b);

int func_02051DE8(void *p, int a, int b)
{
    if (*(unsigned char *)((char *)p + 1) == 0 || b == 0)
        return -1;
    func_02051E64(p, 1, b);
    return 0;
}
