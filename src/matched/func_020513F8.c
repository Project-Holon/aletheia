/*
 * function: func_020513F8
 * address:  0x020513F8
 * packet:   pkt_02051230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020513F8.c \
 *       --func func_020513F8 --addr 0x020513F8 --cc 1.1p1 --arm
 */

extern void func_02051394(int a);
extern void func_02030EAC(void *p);

void func_020513F8(void *p, int a)
{
    func_02051394(a);
    func_02030EAC(p);
}
