/*
 * function: NHTTPi_CompleteCallback
 * address:  0x021BEE1C
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
 *
 * Fires the record's +0x1c callback with code 4 once the node exists.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *NHTTPi_GetConnection(int a, int b);

void NHTTPi_CompleteCallback(int a, u8 *b)
{
    void (*g)(u8 *, int, int);
    if (NHTTPi_GetConnection(a, (int)b) == 0)
        return;
    g = *(void (**)(u8 *, int, int))(b + 0x1c);
    if (g == 0)
        return;
    g(b, 4, 0);
}
