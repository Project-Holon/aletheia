/*
 * unit:     yes
 * function: func_021E27B0, func_021E2810
 * address:  0x021E27B0
 * packet:   pkt_ov093_021E27B0
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
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2474     0x021F2474  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u16 func_021C81C8(u8 *p, u8 *x, int flag);
extern int func_021D76BC(int key, u32 v);
extern int d_021F2474[];

void func_021E27B0(int a, void *b, int c)
{
    void *x;
    void *y;
    int p;
    int q;
    u32 r;

    if (c == func_021D775C(3)) {
        x = func_021C7CF4(b, c);
        y = func_021C7CF4(b, (u8)func_021D775C(4));
        p = func_021C81C8(b, x, 0);
        q = func_021C81C8(b, y, 0);
        r = q * 25 / p + 1;
        if (r > 0x96)
            r = 0x96;
        func_021D76BC(0x30, r);
    }
}

int *func_021E2810(int *p)
{
    *p = 1;
    return d_021F2474;
}
