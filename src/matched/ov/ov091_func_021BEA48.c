/*
 * function: func_021BEA48
 * address:  0x021BEA48
 * packet:   pkt_021BEA48
 * region:   ov091
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The sixth parameter is passed as the callee's narrow fourth parameter, so
 * mwcc truncates it at the call site; see
 * docs/idioms/a-narrow-callee-parameter-truncates-at-the-call-site.md.
 *
 * symbols:
 *   func_0201B7B4  0x0201B7B4  thumb
 */

typedef unsigned short u16;

void func_0201B7B4(void *a0, int a1, u16 a2, u16 a3);

int func_021BEA48(int a0, int a1, int a2, int a3, u16 a4, int a5)
{
    if (a1 == 0xff && a2 > 0)
        return 0;
    if (a1 == 0 && a2 < 0)
        return 0;
    func_0201B7B4((void *)a0, a3, a4, a5);
    return 1;
}
