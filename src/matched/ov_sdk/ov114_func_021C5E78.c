/*
 * function: func_021C5E78
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
 *   g_021D3BD8  0x021D3BD8  data
 *   g_021D3B9C  0x021D3B9C  data
 */

typedef struct NdGlobals {
    unsigned char pad0[0x14];
    void (*f14)(void *p);
} NdGlobals;

extern void *g_021D3BD8[3];
extern NdGlobals g_021D3B9C;

void func_021C5E78(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (g_021D3BD8[i] != 0) {
            g_021D3B9C.f14(g_021D3BD8[i]);
            g_021D3BD8[i] = 0;
        }
    }
}
