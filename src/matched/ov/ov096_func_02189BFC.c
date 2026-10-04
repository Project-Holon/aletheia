/*
 * function: func_02189BFC
 * address:  0x02189BFC
 * packet:   pkt_ov096_02189BFC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A390  0x0218A390  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */

typedef unsigned char u8;
extern int func_0201134C(int);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cur;
struct QL;
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A390(int, u8 *, u8 *, int);
extern u16 func_021D67A8(struct QL *p);
extern u8 func_021D5440(u8 *p);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);

int func_02189BFC(int a, int b)
{
    int t0;
    int t1;
    int t2;
    u8 *v;
    unsigned int w;
    int x;
    int y;
    int z;
    unsigned int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    v = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0));
    w = func_0218A390(b, *(u8 **)(b + 0xbc), *(u8 **)(b + 0xc0), t1);
    x = func_021D67A8((struct QL *)v);
    y = func_021D5440(v);
    z = func_021D5440(*(u8 **)(b + 0xc0));
    r = func_021C7E14((u8 *)(*(int *)(b + 0xb4)), y, z, x, 1, t1);
    if (w < r)
        func_020113B0((struct Cur *)a, *(int *)(a + 0x14) + t2);
    return *(int *)(b + 0xc4);
}
