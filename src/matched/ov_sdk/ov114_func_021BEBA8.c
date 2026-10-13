/*
 * function: NHTTPi_OmitConnectionList
 * address:  0x021BEBA8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_ControlConnectionList  0x021BEAB8  arm  ov114
 *
 *
 * Unlinks node `a` from list class 4: 0 on success, -1 when absent.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *NHTTPi_ControlConnectionList(void *mutexInfo_p, struct Conn *handle_p, unsigned long order);

int NHTTPi_OmitConnectionList(int a, int b)
{
    return -(NHTTPi_ControlConnectionList((void *)a, (struct Conn *)b, 4) == 0);
}
