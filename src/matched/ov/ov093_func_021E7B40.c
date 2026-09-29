/*
 * unit:     yes
 * function: func_021E7B40, func_021E7B8C
 * address:  0x021E7B40
 * packet:   pkt_ov093_021E7B40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021F283C: the ov093 hint is contested at this address; the plain
 * `data a4` line resolves it as sole-ref/data.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021E8D48  0x021E8D48  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F283C     0x021F283C  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C7CF4(int a, int b);
extern u16 func_021D57FC(int p);
extern int func_021E8D48(u32 a, u32 b);
extern int func_021D76BC(int key, int val);
extern int d_021F283C[];

void func_021E7B40(int a, int b, int c)
{
    u8 k;
    int x, y;
    u32 u;

    if (c == func_021D775C(3)) {
        k = func_021D775C(4);
        x = func_021C7CF4(b, k);
        y = func_021C7CF4(b, c);
        u = func_021D57FC(y);
        if (func_021E8D48(u, func_021D57FC(x)) == 0)
            func_021D76BC(0x40, 1);
    }
}

int *func_021E7B8C(int *p)
{
    *p = 1;
    return d_021F283C;
}
