/*
 * function: func_021E17B0
 * address:  0x021E17B0
 * packet:   pkt_ov093_021E17B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: one residue. Original: bl 69AC; movs r1,#0x64; muls r1,r0,r1;
 * movs r0,#0x30. Ours copies the result first (adds r2,r0; movs r1,#0x64;
 * muls r1,r2,r1), 2 bytes longer. Tried x*100, 100*x, int/u8/u16/s8 locals and
 * return types, n *= 100, unsigned 76BC parameter.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern int func_021C7CF4(int a, int b);
extern unsigned char func_021D69AC(void *a, int i);
extern int func_021D76BC(int a, unsigned int b);

void func_021E17B0(int a, int b, int c)
{
    int n;

    if (c != func_021D775C(3))
        return;
    n = func_021D69AC((void *)func_021C7CF4(b, c), 0);
    n *= 100;
    func_021D76BC(48, n);
}
