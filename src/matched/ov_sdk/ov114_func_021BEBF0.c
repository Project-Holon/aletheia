/*
 * function: NHTTPi_Response2Connection
 * address:  0x021BEBF0
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
 * ov114 tail-call thunk: NHTTPi_ControlConnectionList(a, b, 2) via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *NHTTPi_ControlConnectionList(void *mutexInfo_p, struct Conn *handle_p, unsigned long order);

struct Conn *NHTTPi_Response2Connection(int a, int b)
{
    return NHTTPi_ControlConnectionList((void *)a, (struct Conn *)b, 2);
}
