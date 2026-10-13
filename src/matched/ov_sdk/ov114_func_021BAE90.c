/*
 * function: NHTTPi_allFreeReqQueue
 * address:  0x021BAE90
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_freeReqQueue  0x021BADE0  arm  ov114
 *
 *
 * Walks the unlink list, flushing each node through NHTTPi_freeReqQueue.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTPi_freeReqQueue(void *, int, int);

void NHTTPi_allFreeReqQueue(u32 **p, int v)
{
    u32 *n = *p;
    while (n != 0) {
        NHTTPi_freeReqQueue(p, v, n[2]);
        n = *p;
    }
}
