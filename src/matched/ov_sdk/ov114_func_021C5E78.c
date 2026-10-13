/*
 * function: DWCi_Ndi_freeAttr
 * address:  0x021C5E78
 * packet:   pkt_ov114_021C5E78
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_freeAttr (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   gDwciNdAttrEncoded  0x021D3BD8  data
 *   gDwciNdStatics  0x021D3B9C  data
 */

typedef struct NdGlobals {
    unsigned char pad0[0x14];
    void (*f14)(void *p);
} NdGlobals;

extern void *gDwciNdAttrEncoded[3];
extern NdGlobals gDwciNdStatics;

void DWCi_Ndi_freeAttr(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (gDwciNdAttrEncoded[i] != 0) {
            gDwciNdStatics.f14(gDwciNdAttrEncoded[i]);
            gDwciNdAttrEncoded[i] = 0;
        }
    }
}
