/*
 * function: func_021F3B44
 * address:  0x021F3B44
 * packet:   pkt_ov051_021F3B44
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F3D38  0x021F3D38  thumb  ov051
 *   func_021F3C98  0x021F3C98  thumb  ov051
 *   func_0216D88C  0x0216D88C  thumb
 *   func_02188CD0  0x02188CD0  thumb
 *   func_021C9064  0x021C9064  thumb
 *   func_021C909C  0x021C909C  thumb
 */

extern int func_021F3D38(int a, int b, int c);
extern int func_021F3C98(int *a, int *b);
extern void func_0216D88C(int a, int *b);
extern int func_02188CD0(int a);
extern int func_021C9064(int a, int *b, int c);
extern void func_021C909C(int a);

void func_021F3B44(int *a, int *out, int x, int y)
{
    int buf[3];

    out[0] = func_021F3D38(a[2], x, y);
    func_0216D88C(out[0], buf);
    out[1] = func_021C9064(func_02188CD0(a[2]), buf, out[0]);
    if (func_021F3C98(a, out) == 1)
        func_021C909C(out[1]);
}
