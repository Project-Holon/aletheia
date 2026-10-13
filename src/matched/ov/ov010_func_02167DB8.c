/*
 * function: BSUBWAY_COMM_RecvTrainerData
 * address: 0x02167DB8
 * packet: pkt_ov010_02167DB8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void MI_CpuCopy8(void *, void *, unsigned int);
void BSUBWAY_COMM_RecvTrainerData(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != GFL_NET_SYSTEM_GetCurrentAid() && GFL_NET_SYSTEM_GetCurrentAid() != 0)
        MI_CpuCopy8(c, p + 0x32, 0x1c);
}
