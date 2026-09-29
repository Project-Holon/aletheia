/*
 * unit:     yes
 * function: func_021E7164, func_021E71D8
 * address:  0x021E7164
 * packet:   pkt_ov093_021E7164
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C81C8  0x021C81C8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F24EC     0x021F24EC  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C7CF4(int a, int b);
extern int func_021C81C8(int a, int b, int c);
extern int func_021D76BC(int key, int val);
extern int d_021F24EC[];

void func_021E7164(int u, int a, int b)
{
    int x, y, q, v;

    if (b == func_021D775C(3)) {
        x = func_021C7CF4(a, b);
        y = func_021C7CF4(a, (u8)func_021D775C(4));
        x = func_021C81C8(a, x, 0);
        y = func_021C81C8(a, y, 0);
        q = x / y;
        if (q >= 4)
            v = 150;
        else if (q >= 3)
            v = 120;
        else if (q >= 2)
            v = 80;
        else {
            v = 60;
            if (q < 1)
                v = 40;
        }
        func_021D76BC(0x30, v);
    }
}

int *func_021E71D8(int *p)
{
    *p = 1;
    return d_021F24EC;
}
