/*
 * function: NHTTPi_popReqQueue
 * address:  0x021BAEC8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_getHdrFromList  0x021BABF4  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Node;
extern struct Node *NHTTPi_getHdrFromList(struct Node **head);

struct Node *NHTTPi_popReqQueue(struct Node **a0)
{
    return NHTTPi_getHdrFromList(a0);
}
