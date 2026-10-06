/*
 * function: func_021BEC2C
 * address:  0x021BEC2C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC00  0x021BEC00  arm  ov114
 *
 *
 * Looks node `a` up and returns its +0x14 field, or `d` when absent.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *func_021BEC00(int a, int b);

int func_021BEC2C(int a, int d)
{
    u8 *p = (u8 *)func_021BEC00(a, d);
    if (p != 0)
        d = *(int *)(p + 0x14);
    return d;
}
