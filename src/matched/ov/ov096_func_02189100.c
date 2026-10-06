/*
 * function: func_02189100
 * address:  0x02189100
 * packet:   pkt_ov096_02189100
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D59B4(u8 *p, int k);

int func_02189100(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int t3;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    r = func_021D59B4(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0)), t1);
    return func_0218A0F4((u8 *)a, c, r, t2, t3);
}
