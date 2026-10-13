/*
 * function: func_021DC9AC
 * address: 0x021DC9AC
 * packet: pkt_ov137_021DC9AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021DC924 0x021DC924 thumb ov137
 * func_021DC950 0x021DC950 thumb ov137
 * GFL_NET_SetAutoExit 0x0203D7B0 arm
 * PROCSYS_Push 0x02031348 arm
 * gPartyListProcData 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
typedef unsigned int u32;
typedef unsigned char  u8;
extern void *func_021DC924(u8 *p);
struct DC950Obj;
struct DC950Src;
extern struct DC950Obj *func_021DC950(struct DC950Src *p, int a, int b);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern const unsigned char gPartyListProcData[];
extern const unsigned char d_0000005B[];
int func_021DC9AC(u32 *p)
{
    void *v;
    if (!func_021DC924((void *)p[3])) p[0]=5;
    else {
        GFL_NET_SetAutoExit(1);
        v=func_021DC950((struct DC950Src *)p,21,0);
        p[6]=(u32)v;
        PROCSYS_Push((void *)p[8],(int)d_0000005B,gPartyListProcData,v);
        *(u32 *)p[3]=1;
        p[0]=2;
    }
    return 0;
}
