/*
 * function: func_021DF040
 * address:  0x021DF040
 * packet:   pkt_ov170_021DF040
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC000 0x021EC000 thumb
 *   func_021EB324 0x021EB324 thumb
 *   func_021DF128 0x021DF128 thumb
 *   func_02041EE4 0x02041EE4 arm
 */

extern void func_021EC000(char *p, int i, int v);
extern void func_021EB324(char *w);
extern void func_021DF128(char *w);
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021DF040(char *p)
{
    unsigned i;
    if (*(int *)(WORK(p) + 0x9EA0) != 0)
        func_021EC000(WORK(p), 0xB, 0);
    if (*(int *)(WORK(p) + 0x9EA4) != 0)
        func_021EC000(WORK(p), 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        func_021EC000(WORK(p), i, 0);
    func_021EB324(WORK(p));
    func_021DF128(WORK(p));
    func_021EC000(WORK(p), 0x19, 0);
    func_021EC000(WORK(p), 0x1A, 0);
    func_021EC000(WORK(p), 0x1B, 0);
    func_02041EE4(5, 3, 0xC0);
}
