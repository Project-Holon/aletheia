/*
 * function: func_02035138
 * address:  0x02035138
 * packet:   pkt_02035138
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469BC    0x021469BC  data
 *   func_0203512C 0x0203512C  arm
 *
 * Tail call: func_0203512C(*g_021469BC, fn, arg).  Called from func_02012248
 * and func_02012258.
 */

typedef unsigned int u32;

extern void *g_021469BC;
struct Obj02035120;
extern void func_0203512C(struct Obj02035120 *p, u32 a, u32 b);

void func_02035138(void *fn, u32 arg)
{
    func_0203512C(g_021469BC, (u32)fn, arg);
}
