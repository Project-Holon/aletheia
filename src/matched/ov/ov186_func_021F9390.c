/*
 * function: func_021F9390,func_021F93D0
 * address: 0x021F9390
 * packet: pkt_ov186_021F9390
 * region: ov186
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 * Extent includes empty follower021F93D0; zeros021F93CE and021F93D2 are alignment.
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
void func_021F9390(int *out,int *source,int unused,int type)
{
    out[3]=source[1];
    out[2]=source[3];
    out[4]=source[2];
    out[1]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
    out[5]=source[4];
    if(type==1) out[0]=1;
    else if(((int *)source[6])[1]==0) out[0]=0;
    else out[0]=2;
}
void func_021F93D0(void)
{
}
