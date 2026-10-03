/*
 * function: func_021E17B0
 * address:  0x021E17B0
 * packet:   pkt_ov093_021E17B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The product passed through a static inline helper is computed before the
 * helper's constant first argument is loaded (no result copy).
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern unsigned char func_021D69AC(void *a, int i);
extern int func_021D76BC(int a, unsigned int b);

static inline void func_021E17B0_set48(int v)
{
    func_021D76BC(48, v);
}

void func_021E17B0(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021E17B0_set48(func_021D69AC(func_021C7CF4(b, c), 0) * 100);
}
