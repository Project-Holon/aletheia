/*
 * unit:     yes
 * function: func_021D9934, func_021D996C
 * address:  0x021D9934
 * packet:   pkt_ov093_021D9934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F0930     0x021F0930  data   ov093  a4
 */

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021C8288(int);
extern int func_0201C1E8(u16);
typedef signed int     s32;
extern void func_021D7704(int key, s32 m);
extern int d_021F0930[];

void func_021D9934(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021C8288(b) == 1) {
        if (func_0201C1E8(func_021D775C(0x12)) == 2)
            func_021D7704(0x35, 0x1800);
    }
}

int *func_021D996C(int *p)
{
    *p = 2;
    return d_021F0930;
}
