/*
 * function: NHTTPi_decRef
 * address:  0x021BF018
 * packet:   pkt_ov114_021BF018
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlWiFi_base/libnhttp.TWL.HYB.a(d_nhttp_common.).  decl_line 825,
 * params mutexInfo_p, connection_p.
 *
 * symbols:
 *   NHTTPi_lockReqList   0x021BEFCC  arm
 *   NHTTPi_unlockReqList   0x021BEFD8  arm
 */
typedef unsigned long u32;

extern void NHTTPi_lockReqList(void);
extern void NHTTPi_unlockReqList(void *mutexInfo_p);

int NHTTPi_decRef(void *mutexInfo_p, char *connection_p)
{
    NHTTPi_lockReqList();
    --*(u32 *)(connection_p + 0x8048);
    NHTTPi_unlockReqList(mutexInfo_p);
    return *(u32 *)(connection_p + 0x8048);
}
