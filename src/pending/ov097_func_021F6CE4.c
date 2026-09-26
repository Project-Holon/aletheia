/*
 * function: func_021F6CE4
 * address:  0x021F6CE4
 * packet:   pkt_ov097_021F6CE4
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: codegen only.  The original keeps the third parameter in r4 and the
 * first in r5; every spelling tried (plain int/unsigned index, a named zero
 * local, spilled u) makes mwccarm colour them the other way (first->r4,
 * second->r5) and rematerialise the zero instead of hoisting it into r7.
 * Same instruction count until the allocation diverges, 136 vs 140 bytes.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C724  0x0201C724  thumb
 */

extern int func_020457B0(int, int);
extern int func_02045EC0(int, int);
extern int func_02045770(int);
extern void func_02045808(int);
extern int func_02017E1C(int, int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, int, int);
extern void func_0201C724(int, int, int, int, int, int, int);

void func_021F6CE4(int a, int b)
{
    int t;
    int u;
    int z = 0;

    t = func_020457B0(0x20, 0x8071);
    u = func_02045EC0(*(int *)(a + 0x14), 0xb);
    func_0201EFA4(*(int *)(a + 0x18), 0,
                  func_02017E1C(*(int *)(a + b * 4 + 0xf8), 0x9e, z), 3, z, 1);
    func_0201F250(*(int *)(a + 0x18), t, u);
    func_0201C724(*(int *)(a + 0x1c),
                  func_02045770(*(int *)(a + b * 8 + 0x20)), 8, 0x20, t,
                  *(int *)(a + 0x10), 0x3dc0);
    *(char *)(a + b * 8 + 0x24) = 1;
    func_02045808(u);
    func_02045808(t);
}
