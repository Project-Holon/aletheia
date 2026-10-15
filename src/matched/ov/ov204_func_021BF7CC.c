/*
 * function: INTRO_G3D_SetSlotMepachi
 * address: 0x021BF7CC
 * packet: pkt_ov204_021BF7CC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_SetMepachiFlag 0x02015DB0 thumb
 *   MCSS_ResetMepachiFlag 0x02015DC0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MCSS_SetMepachiFlag(void *);
extern void MCSS_ResetMepachiFlag(void *);
void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag)
{
    if(flag!=0)MCSS_SetMepachiFlag(*(void **)((u32)p+(u32)index*12+8));
    else MCSS_ResetMepachiFlag(*(void **)((u32)p+(u32)index*12+8));
}
