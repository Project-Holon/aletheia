/*
 * function: func_021E15B0
 * address:  0x021E15B0
 * packet:   pkt_ov093_021E15B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D59B4(u8 *p, int k);
typedef unsigned int   u32;
extern int func_021D76BC(int key, u32 val);

void func_021E15B0(int a, int b, int c)
{
    int n;

    if (c != func_021D775C(3))
        return;
    n = (unsigned char)func_021D59B4(func_021C7CF4(b, c), 15);
    func_021D76BC(55, n);
}
