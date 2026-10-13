/*
 * function: func_021BEE40
 * address: 0x021BEE40
 * packet: pkt_ov203_021BEE40
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_021BEE8C 0x021BEE8C thumb ov203
 */
extern int func_021BF7AC(char *,int);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
typedef unsigned int   u32;
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_021BEE8C(char *,int,int,int,unsigned);
void func_021BEE40(char *p,int unused,int *s)
{
    int channel,a,b;
    channel=s[0];a=func_021BF7AC(p,s[1]);b=func_021BF7AC(p,s[2]);
    if(s[3]==0){GFL_USE_CancelChangeAndPlayBgm(channel,0xffff);GFL_USE_FadeInBgmFull((unsigned short)b);}
    else {func_021BEE8C(p,channel,a,b,s[3]);}
}
