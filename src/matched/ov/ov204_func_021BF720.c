/*
 * function: func_021BF720
 * address: 0x021BF720
 * packet: pkt_ov204_021BF720
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
void func_021BF720(u8 *p, int flag, u8 index)
{
    if(flag==1)MCSS_ResetVanishFlag(*(void **)((u32)p+(u32)index*12+8));
    else MCSS_SetVanishFlag(*(void **)((u32)p+(u32)index*12+8));
}
