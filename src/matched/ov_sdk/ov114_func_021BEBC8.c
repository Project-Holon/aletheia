/*
 * function: NHTTPi_Connection2Response
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
 *   NHTTPi_GetConnection  0x021BEC00  arm  ov114
 *
 * Keyed field read of a node; 0 when the node is absent.  The conditional
 * expression is what emits the load before the zero move.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *NHTTPi_GetConnection(int a, int b);

int NHTTPi_Connection2Response(int a, int b)
{
    u8 *p = (u8 *)NHTTPi_GetConnection(a, b);

    return p ? *(u32 *)(p + 0x14) : 0;
}
