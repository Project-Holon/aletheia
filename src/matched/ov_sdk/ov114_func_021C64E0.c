/*
 * function: nhttpCleanupCallback
 * address:  0x021C64E0
 * packet:   pkt_ov114_021C64E0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      nhttpCleanupCallback (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   DWCi_Ndi_freeAttr  0x021C5E78  arm  ov114
 *   DWCi_Ndi_freeLockGlobal  0x021C78DC  arm  ov114
 *   DWCi_Ndi_freeHttpCallback  0x021C7930  arm  ov114
 *   gDwciNdStatics     0x021D3B9C  data
 */

typedef struct NdGlobals {
    unsigned char pad0[0x14];
    void (*f14)(void *arg);
    void *f18;
    void *f1C;
    unsigned char pad1[0x24 - 0x20];
    void (*f24)(void);
} NdGlobals;

extern void DWCi_Ndi_freeAttr(void);
extern void DWCi_Ndi_freeLockGlobal(void);
extern void DWCi_Ndi_freeHttpCallback(void);
extern NdGlobals gDwciNdStatics;

void nhttpCleanupCallback(void)
{
    DWCi_Ndi_freeAttr();
    DWCi_Ndi_freeLockGlobal();
    DWCi_Ndi_freeHttpCallback();
    gDwciNdStatics.f14(gDwciNdStatics.f18);
    gDwciNdStatics.f14(gDwciNdStatics.f1C);
    gDwciNdStatics.f24();
}
