/*
 * function: freeHttp
 * address:  0x021C6BEC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_NdCleanupConnectionHandle  0x021C654C  arm  ov114
 *   freeHttpParam  0x021C6B44  arm  ov114
 *   DWCi_Ndi_unprepareHttpCallback  0x021C797C  arm  ov114
 *
 *
 * Rebuilds the +0x? table for `b`, refreshes the pool, then re-links `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int DWCi_NdCleanupConnectionHandle(void * volatile handle);
extern void DWCi_Ndi_unprepareHttpCallback(void);
extern void freeHttpParam(int *hrq);

void freeHttp(void *a, int b)
{
    DWCi_NdCleanupConnectionHandle((void * volatile)b);
    DWCi_Ndi_unprepareHttpCallback();
    freeHttpParam(a);
}
