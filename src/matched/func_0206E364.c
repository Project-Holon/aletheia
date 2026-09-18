/*
 * function: func_0206E364
 * address:  0x0206E364
 * packet:   pkt_0206E364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E364.c \
 *       --func func_0206E364 --addr 0x0206E364 --cc 1.1p1 --arm
 */

extern int  func_02069C14(int a, int b);
extern void func_02061330(void *p, int v);

void func_0206E364(void *p, int a, int b)
{
    func_02061330(p, func_02069C14(a, b));
}
