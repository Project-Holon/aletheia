/*
 * function: GURU2_EntryStateOpenPartyList
 * address: 0x021DC9AC
 * packet: pkt_ov137_021DC9AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * GURU2_SessionGetArgs 0x021DC924 thumb ov137
 * GURU2_PartyListArgsCreate 0x021DC950 thumb ov137
 * GFL_NET_SetAutoExit 0x0203D7B0 arm
 * PROCSYS_Push 0x02031348 arm
 * gPartyListProcData 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
typedef unsigned int u32;
typedef unsigned char  u8;
extern void *GURU2_SessionGetArgs(u8 *p);
struct DC950Obj;
struct DC950Src;
extern struct DC950Obj *GURU2_PartyListArgsCreate(struct DC950Src *p, int a, int b);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern const unsigned char gPartyListProcData[];
extern const unsigned char d_0000005B[];
int GURU2_EntryStateOpenPartyList(u32 *p)
{
    void *v;
    if (!GURU2_SessionGetArgs((void *)p[3])) p[0]=5;
    else {
        GFL_NET_SetAutoExit(1);
        v=GURU2_PartyListArgsCreate((struct DC950Src *)p,21,0);
        p[6]=(u32)v;
        PROCSYS_Push((void *)p[8],(int)d_0000005B,gPartyListProcData,v);
        *(u32 *)p[3]=1;
        p[0]=2;
    }
    return 0;
}
