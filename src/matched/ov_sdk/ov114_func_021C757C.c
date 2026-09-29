/*
 * function: func_021C757C
 * address:  0x021C757C
 * packet:   pkt_ov114_021C757C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdGetProgress (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   NHTTP_GetConnectionProgress  0x021BF4B0  arm
 *   g_021D3B9C                   0x021D3B9C  data
 */

typedef struct NdGlobals {
    unsigned char pad0[8];
    int f8;
    unsigned char pad1[0x10 - 0xC];
    void *f10;
} NdGlobals;

extern int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);
extern NdGlobals g_021D3B9C;

int func_021C757C(unsigned long *received, unsigned long *contentlen)
{
    if (g_021D3B9C.f8 == 0)
        return 0;
    return NHTTP_GetConnectionProgress(g_021D3B9C.f10, received, contentlen) == 0;
}
