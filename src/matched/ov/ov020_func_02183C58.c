/*
 * function: func_02183C58
 * address:  0x02183C58
 * packet:   pkt_ov020_02183C58
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021860D4  0x021860D4  thumb  ov020
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02161F14  0x02161F14  thumb  ov010
 */

extern int func_020120F4(int a);
extern int func_020127C4(int a);
extern int func_02012944(int a);
extern void func_021860D4(int a, int b, int c);
extern void func_02161D64(int a);
extern int func_020127F0(int a);
extern void func_02161F14(int a, int b, int c);

void func_02183C58(int a)
{
    int w = func_020120F4(a);
    int r5 = func_020127C4(w);

    func_021860D4(r5, func_02012944(w), 1);
    func_02161D64(func_020127C4(w));
    r5 = func_020127F0(w);
    func_02161F14(r5, func_020127C4(w), 1);
}
