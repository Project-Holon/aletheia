/*
 * function: func_021BE874
 * address:  0x021BE874
 * packet:   pkt_ov091_021BE874
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201C158  0x0201C158  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201C158(u32 a, u32 b);

int func_021BE874(void *a, int b, int c)
{
    int r = 0;
    u32 x;
    u32 y;
    u32 v;
    u32 n;
    int t;
    n = (u8)func_02017E1C(a, b + 0x3E, 0);
    if (n == 3)
        return r;
    x = (u16)func_02017E1C(a, b + 0x36, r);
    if (func_0201C158(x, r) < 5)
        return r;
    v = (u8)func_02017E1C(a, b + 0x3A, r);
    y = func_0201C158(x, n);
    t = n + c;
    if ((u32)t > 3)
        n = 3;
    else
        n = (u8)t;
    v = (u8)(v + func_0201C158(x, n) - y);
    func_02017E40(a, b + 0x3E, n);
    func_02017E40(a, b + 0x3A, v);
    return 1;
}
