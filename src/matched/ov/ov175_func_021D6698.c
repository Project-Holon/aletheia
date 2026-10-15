/*
 * function: func_021D6698
 * address: 0x021D6698
 * packet: pkt_ov175_021D6698
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0200E6E8 0x0200E6E8 thumb
 *   MISC_SAVEDATA_CopyQuadRecord 0x0200E6FC thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009CC0 0x02009CC0 thumb
 */
typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct BigObj;
struct Rec0200E6FC;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int MYSTATUS_GetSize(void);
extern void MI_CpuCopy8(const void *,void *,int);
extern void *func_0200E6E8(u32 a);
extern void MISC_SAVEDATA_CopyQuadRecord(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 BSUBWAY_SAVEDATA_GetStat(u32,u32,u32);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern int func_02009CC0(void *a0);
void func_021D6698(u32 *p,u32 *q)
{
    u32 save=((u32 *)((u32 *)q[16])[2])[0];
    u32 profile=(u32)GAME_DATA_GetSaveControl((struct Big *)save);
    u32 blob;
    u32 *ctx;
    p[17]=100;
    blob=(u32)GAME_DATA_GetMyStatus((void *)save);
    MI_CpuCopy8((void *)blob,p,MYSTATUS_GetSize());
    MISC_SAVEDATA_CopyQuadRecord(func_0200E6E8(profile),0,(struct Rec0200E6FC *)((char *)(p+14)));
    ctx=(u32 *)q[16];
    if(ctx[0]==0) {
        p[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1]+5,1);
        ctx=(u32 *)q[16];
        p[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1]+5,2);
    } else {
        p[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1],1);
        ctx=(u32 *)q[16];
        p[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1],2);
    }
    p[18]=func_02009CC0((void *)GAME_DATA_GetWifiList((const struct BigObj *)save));
}
