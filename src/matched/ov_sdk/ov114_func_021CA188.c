/*
 * function: DWCi_EncSessionCancel
 * address:  0x021CA188
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sGhttpChunkSizeFormat  0x021CF248  data
 *   gDwciNdHttpMutex  0x021D3C20  data
 *   gDwciNdStatics  0x021D3B9C  data
 *   gDwcEncSession  0x021CF7AC  data
 *   DWC_CancelGHTTPRequest  0x021BF880  arm  ov114
 *
 *
 * Cancels the armed resource and clears the 0x021CF7AC head word.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gDwcEncSession[];
extern void DWC_CancelGHTTPRequest(int);

void DWCi_EncSessionCancel(void)
{
    int v = *(int *)(gDwcEncSession + 8);
    if (v >= 0)
        DWC_CancelGHTTPRequest(v);
    *(u32 *)gDwcEncSession = 0;
}
