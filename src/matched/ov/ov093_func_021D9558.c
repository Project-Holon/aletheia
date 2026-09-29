/*
 * unit:     yes
 * function: func_021D9558, func_021D956C, func_021D957C, func_021D958C
 * address:  0x021D9558
 * packet:   pkt_ov093_021D9558
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9670  0x021D9670  thumb
 *   func_021D96DC  0x021D96DC  thumb  ov093
 *   func_021D96FC  0x021D96FC  thumb  ov093
 *   d_021F0BB4     0x021F0BB4  data   ov093  a4
 */

extern void func_021D9670(int, int, int, int, int);
extern void func_021D96DC(int, int, int);
extern void func_021D96FC(int, int, int);
extern int d_021F0BB4[];

void func_021D9558(int a, int b, int c, int d)
{
    func_021D9670(a, b, c, d, 0x165);
}

void func_021D956C(int a, int b, int c)
{
    func_021D96DC(b, c, 6);
}

void func_021D957C(int a, int b, int c)
{
    func_021D96FC(b, c, 6);
}

int *func_021D958C(int *p)
{
    *p = 4;
    return d_021F0BB4;
}
