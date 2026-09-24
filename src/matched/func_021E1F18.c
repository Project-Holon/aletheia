/*
 * function: func_021E1F18
 * address:  0x021E1F18
 * packet:   pkt_021E1F18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021E47B0   0x021E47B0  data
 *
 * func_021E1EC4's sibling with the selector in the second argument: the first
 * argument survives the acquire and is handed to the sub-id allocator.
 */

typedef unsigned int u32;

extern int  func_021E1DD0(int mode, int *out);
extern void func_021E17D8(int id, int a, int b);
extern int  func_021E1EAC(int a, int b);
extern void func_02059F54(int a, int b);
extern u32  g_021E47B0[];

int func_021E1F18(int a, int mode)
{
    int local;
    int h = func_021E1DD0(mode, &local);

    if (h != 0) {
        func_021E17D8(0x6ec, (int)g_021E47B0, h);
        func_02059F54(local, func_021E1EAC(a, h));
    }
    return h;
}
