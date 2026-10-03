/*
 * function: func_022113FC
 * address: 0x022113FC
 * packet: pkt_ov198_022113FC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: delta is word-wide at this call; the callee's short extern inserts lsls/asrs absent from 0x02211418.
 * symbols:
 *   func_0220F22C 0x0220F22C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0220F22C(u8 *, int, int);
void func_022113FC(u8 *p, int a, int b)
{
    int delta = 1;
    if (a & delta) {
        if (b == 0) delta = 8;
        else delta = -8;
    } else {
        delta = -8;
        if (b != 0) delta = 8;
    }
    func_0220F22C(p, a, delta);
}
