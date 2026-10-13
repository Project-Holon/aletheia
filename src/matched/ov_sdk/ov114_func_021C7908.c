/*
 * function: DWCi_Ndi_initHttpCallback
 * address:  0x021C7908
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
 *
 *
 * Flushes the 0x021D3C20 block and clears the +0x20 word of the 0x021D3B9C block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gDwciNdHttpMutex[];
extern u8 gDwciNdStatics[];
extern void func_02086004(void *);

int DWCi_Ndi_initHttpCallback(void)
{
    func_02086004(gDwciNdHttpMutex);
    *(u32 *)(gDwciNdStatics + 0x20) = 0;
    return 1;
}
