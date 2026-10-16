/*
 * function: GURU2_EntryStateAfterPartyList
 * address: 0x021DC9F4
 * packet: pkt_ov137_021DC9F4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020307B0 0x020307B0 arm
 * func_02030734 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * PROCSYS_Push 0x02031348 arm
 * gGuru2AllocFileName 0x021E2260 data a4
 * gPokeStatusProcData 0x021DC800 data a4 ov131
 * gGuru2MainProcData 0x021E1A44 data a4
 * d_00000083 0x00000083 data a1
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32);
struct BigObj;
struct Blk37;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern const u8 gGuru2AllocFileName[],gPokeStatusProcData[],gGuru2MainProcData[],d_00000083[];
int GURU2_EntryStateAfterPartyList(u32 *p)
{
    u32 *v=(u32 *)p[6];
    int mode=v[16],sel=v[15];
    void *q;
    void *r;
    func_020307B0(v);
    if(mode==1) {
        GAME_DATA_GetMyStatus((void *)p[4]);
        q=ZUKAN_SAVE_GetFromGameData((void *)p[4]);
        p[7]=(u32)func_02030734(4,40,0,(const char *)gGuru2AllocFileName,328);
        MI_CpuFill8((void *)p[7],0,40);
        r=(void *)GAME_DATA_GetMyParty((void *)p[4]);
        *(void **)p[7]=r;
        *(u32 *)(p[7]+8)=p[4];
        *(u8 *)(p[7]+12)=1;
        *(u8 *)(p[7]+14)=POKEPARTY_GetCount(r);
        *(u8 *)(p[7]+15)=0;
        *(u8 *)(p[7]+13)=1;
        *(u16 *)(p[7]+20)=0;
        *(u8 *)(p[7]+16)=0;
        *(u32 *)(p[7]+24)=ZUKAN_SAVE_IsNationalDexEnabled(q);
        p[1]=sel;
        *(u8 *)(p[7]+15)=sel;
        PROCSYS_Push((void *)p[8],(int)d_00000083,gPokeStatusProcData,(void *)p[7]);
        p[0]=3;
    } else {
        *(u32 *)(p[3]+4)=sel;
        PROCSYS_Push((void *)p[8],-1,gGuru2MainProcData,(void *)p[3]);
        *(u32 *)p[3]=3;
        p[0]=4;
    }
    return 0;
}
