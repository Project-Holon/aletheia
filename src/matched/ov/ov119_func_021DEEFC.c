/*
 * function: POKETRADE_NEGO_AbortHttpRequest
 * address:  0x021DEEFC
 * packet:   pkt_ov119_021DEEFC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NHTTP_RAP_DeleteConnection  0x021B9774  thumb  ov114
 *   NHTTP_RAP_Destroy  0x021B9838  thumb  ov114
 *   DWC_RAPCOMMON_DestroySubHeap  0x02156ED0  thumb  ov009
 */

typedef unsigned char  u8;
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern void DWC_RAPCOMMON_DestroySubHeap(void);

void POKETRADE_NEGO_AbortHttpRequest(void **p)
{
    if (*p != 0) {
        NHTTP_RAP_DeleteConnection(*p);
        NHTTP_RAP_Destroy(*p);
        *p = 0;
        DWC_RAPCOMMON_DestroySubHeap();
    }
}
