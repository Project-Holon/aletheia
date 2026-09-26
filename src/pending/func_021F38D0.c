/*
 * function: func_021F38D0
 * address:  0x021F38D0
 * packet:   pkt_021F38D0
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  0x021897BC (the bl at +0x0E) has no func_ label in any of the
 * four overlays overlapping it (ov009/ov021/ov096/ov230); label, sole-ref/code
 * and matched all fail, so the call site stays wildcarded. Byte-correct.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb
 */

extern void func_020124E4(void);
extern int func_0201210C(void);
extern int *func_021897BC(int, int);

int func_021F38D0(void)
{
    int a;
    int r;
    func_020124E4();
    a = func_0201210C();
    r = 1;
    if (*func_021897BC(a, 1) != 0)
        r = 0;
    return r;
}
