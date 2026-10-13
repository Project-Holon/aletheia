/*
 * function: DWC_RAP_FreeRecvBuffer
 * address: 0x02156BD8
 * packet: pkt_ov009_02156BD8
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *g_021A8264;
extern void GFL_NET_FreeAligned(void *);
void DWC_RAP_FreeRecvBuffer(u32 i)
{
    void *p;
    p = *(void **)(g_021A8264 + i * 4 + 0x174);
    if (p != 0) {
        GFL_NET_FreeAligned(p);
        *(void **)(g_021A8264 + i * 4 + 0x174) = 0;
    }
}
