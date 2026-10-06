/*
 * function: func_021BEBC8
 * address:  0x021BEBC8
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
 * Keyed field read of a node; 0 when the node is absent.  The conditional
 * expression is what emits the load before the zero move.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *func_021BEC00(int a, int b);

int func_021BEBC8(int a, int b)
{
    u8 *p = (u8 *)func_021BEC00(a, b);

    return p ? *(u32 *)(p + 0x14) : 0;
}
