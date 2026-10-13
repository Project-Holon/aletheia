/*
 * function: DWCi_NdCleanupAsync
 * address:  0x021C651C
 * packet:   pkt_ov114_021C651C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 519, param callback.
 *
 * symbols:
 *   gDwciNdStatics   0x021D3B9C  data
 *   nhttpCleanupCallback   0x021C64E0  arm
 *   NHTTP_CleanupAsync  0x021BE680  arm
 *   DWCi_NdCleanupConnectionHandle  0x021C654C  arm
 */
typedef unsigned long u32;

extern char gDwciNdStatics[];
extern int DWCi_NdCleanupConnectionHandle(void * volatile handle);
extern void NHTTP_CleanupAsync(int a);
extern void nhttpCleanupCallback(void);

void DWCi_NdCleanupAsync(void *callback)
{
    *(u32 *)(gDwciNdStatics + 8) = 0;
    *(void **)(gDwciNdStatics + 0x24) = callback;
    DWCi_NdCleanupConnectionHandle(*(void **)(gDwciNdStatics + 0x10));
    NHTTP_CleanupAsync((int)nhttpCleanupCallback);
}
