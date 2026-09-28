/*
 * function: func_021E1EC4
 * address:  0x021E1EC4
 * packet:   pkt_021E1EC4
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
 * Acquire-by-mode wrapper: the mode the caller passed picks a handle; on
 * success the handle is announced (message 0x6db), a sub-id is allocated and
 * the pair is released.
 */

typedef unsigned int u32;

extern int  func_021E1D70(int mode, int *out);
extern void func_021E17D8(int id, int a, int b);
extern int  func_021E1EAC(int a, int b);
extern void func_02059F54(int a, int b);
extern u32  g_021E47B0[];

int func_021E1EC4(int mode)
{
    int local;
    int h = func_021E1D70(mode, &local);

    if (h != 0) {
        func_021E17D8(0x6db, (int)g_021E47B0, h);
        func_02059F54(local, func_021E1EAC(1, h));
    }
    return h;
}
