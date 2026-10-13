/*
 * function: NHTTPi_SocCancel
 * address:  0x021BA068
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_lockReqList  0x021BEFCC  arm  ov114
 *   NHTTPi_unlockReqList  0x021BEFD8  arm  ov114
 *   SOC_Shutdown  0x0215F638  arm  ov009
 *
 *
 * Releases a resource id (>= 0) then tears the +0x3b4 object down.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTPi_lockReqList(void);
extern void NHTTPi_unlockReqList(int);
extern void SOC_Shutdown(int, int);

void NHTTPi_SocCancel(int a, int b, int c)
{
    NHTTPi_lockReqList();
    if (c >= 0)
        SOC_Shutdown(c, 2);
    NHTTPi_unlockReqList(a);
}
