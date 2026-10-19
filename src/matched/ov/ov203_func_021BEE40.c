/*
 * function: DEMO3D_DATA_TaskPlayBgm
 * address: 0x021BEE40
 * packet: pkt_ov203_021BEE40
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_ScaleTime 0x021BF7AC thumb ov203
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   DEMO3D_DATA_CreateBgmFade 0x021BEE8C thumb ov203
 */
extern int DEMO3D_DATA_ScaleTime(char *,int);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
typedef unsigned int   u32;
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void DEMO3D_DATA_CreateBgmFade(char *,int,int,int,unsigned);
void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s)
{
    int channel,a,b;
    channel=s[0];a=DEMO3D_DATA_ScaleTime(p,s[1]);b=DEMO3D_DATA_ScaleTime(p,s[2]);
    if(s[3]==0){GFL_USE_CancelChangeAndPlayBgm(channel,0xffff);GFL_USE_FadeInBgmFull((unsigned short)b);}
    else {DEMO3D_DATA_CreateBgmFade(p,channel,a,b,s[3]);}
}
