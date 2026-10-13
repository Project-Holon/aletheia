/*
 * function: NHTTP_RAP_Free
 * address: 0x021B95B0
 * packet: pkt_ov114_021B95B0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * DWC_RAPCOMMON_Free 0x02156FDC thumb ov009
 */
typedef unsigned int   u32;
extern void DWC_RAPCOMMON_Free(u32 a, void *p, int b);
void NHTTP_RAP_Free(int a)
{
    DWC_RAPCOMMON_Free(13, (void *)a, 0);
}
