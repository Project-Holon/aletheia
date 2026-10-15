/*
 * function: INTRO_G3D_SetSlotAlpha
 * address: 0x021BF794
 * packet: pkt_ov204_021BF794
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: The shifts at 021BF7B8/021BF7BC narrow the outgoing alpha to u8.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   MCSS_SetAlpha 0x02015FBC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207D63C(void *,int,int,int,int);
extern void MCSS_SetAlpha(char *p, int v);
void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha)
{
    func_0207D63C((void *)0x04000050,1,9,0,0);
    if(alpha>31)alpha=31;
    MCSS_SetAlpha(*(char **)((u32)p+(u32)index*12+8),(u8)alpha);
}
