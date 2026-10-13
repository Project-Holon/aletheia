/*
 * function: DWCi_Ndi_unprepareHttpCallback
 * address:  0x021C797C
 * packet:   pkt_ov114_021C797C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 1703.
 *
 * symbols:
 *   d_021D3C20   0x021D3C20  data
 *   gDwciNdStatics   0x021D3B9C  data
 */
typedef unsigned long u32;

extern char d_021D3C20[];
extern char gDwciNdStatics[];
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);

void DWCi_Ndi_unprepareHttpCallback(void)
{
    OS_LockMutex(d_021D3C20);
    *(u32 *)(gDwciNdStatics + 0x20) = 0;
    OS_UnlockMutex(d_021D3C20);
}
