/*
 * function: func_021F1004
 * address:  0x021F1004
 * packet:   pkt_ov032_021F1004
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1004  0x021F1004  thumb
 *   func_021F0FE8  0x021F0FE8  thumb  ov032
 *   func_02165CC0  0x02165CC0  thumb  ov010
 *   func_02021F64  0x02021F64  thumb
 *   func_020215BC  0x020215BC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F0FE8(int a);
extern void func_02165CC0(u16 *a, int b);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020215BC(int slots, u16 *src, u32 idx, u32 off, u16 size);

void func_021F1004(char *p, u8 *q, int r)
{
    u16 a[5];
    int x;
    int b;
    u16 *t;

    x = func_021F0FE8(r);
    b = x * 16;
    t = *(u16 **)(p + 0x3c8);
    a[0] = t[b];
    a[1] = t[b + 1];
    a[2] = t[b + 2];
    func_02165CC0(&a[3], r);
    func_02021F64(&a[3], &a[4], 1, 3, 0);
    func_020215BC(*(int *)(p + 0xac), a, 3, (u16)((q[0] + 4) * 16 + 1), 10);
}
