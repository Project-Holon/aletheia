/*
 * function: func_021BBFEC
 * address: 0x021BBFEC
 * packet: pkt_ov216_021BBFEC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Verified EXACT Thumb C copied from parked ov032_func_021F27D4 header:
 * u32 BEACON_STATUS_GetLog(u32 a) { return a; }
 * Singleton TU --suggest-split leaves caller out; no viable partition.
 * Trailing 021BC0B2..021BC0B4 is zero alignment padding.
 * lever: array index uses p[47]++ so byte count advances before the store.
 * symbols:
 *   GAME_BEACON_ACCESSOR_AllocInfo 0x02165B10 thumb ov010
 *   GAME_DATA_GetItemUseWork 0x02012A54 thumb
 *   BEACON_STATUS_GetLog 0x020275A8 thumb
 *   GAME_BEACON_ACCESSOR_TableGetCount 0x02165B04 thumb ov010
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   GAME_BEACON_ACCESSOR_IsInfoInvalid 0x02165B5C thumb ov010
 *   GAME_BEACON_ACCESSOR_IsDistributionAction 0x02165C10 thumb ov010
 *   func_02012FFC 0x02012FFC thumb
 *   TOWNMAP_GRH_LoadTownInfo 0x021BBB24 thumb ov072
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Queue; struct Rec; struct BigObj;
extern u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32);
extern u32 GAME_DATA_GetItemUseWork(const struct BigObj *);
extern u32 BEACON_STATUS_GetLog(u32 a);
extern u8 GAME_BEACON_ACCESSOR_TableGetCount(u8 *);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *,struct Rec *,u16 *,int);
extern int GAME_BEACON_ACCESSOR_IsInfoInvalid(struct Rec *);
extern int GAME_BEACON_ACCESSOR_IsDistributionAction(u8 *);
extern signed char func_02012FFC(void);
extern int TOWNMAP_GRH_LoadTownInfo(int);
void func_021BBFEC(u8 *p)
{
    int i,count;
    *(u8 **)(p+40)=GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)p);
    *(u32 *)(p+32)=GAME_DATA_GetItemUseWork(*(const struct BigObj **)(*(u8 **)(p+20)+4));
    *(void **)(p+36)=(void *)BEACON_STATUS_GetLog((u32)(*(void **)(p+32)));
    count=GAME_BEACON_ACCESSOR_TableGetCount(*(u8 **)(p+36));
    p[48]=255;
    for(i=0;i<count;i++){
        GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue **)(p+36),*(struct Rec **)(p+40),(u16 *)(p+44),i);
        if(GAME_BEACON_ACCESSOR_IsInfoInvalid(*(struct Rec **)(p+40))==0 && GAME_BEACON_ACCESSOR_IsDistributionAction(*(u8 **)(p+40))==0){
            if((*(u8 **)(p+20))[8]==i)p[48]=p[47];
            p[p[47]++ +49]=i;
        }
    }
    if(p[48]==255 || p[48]>=p[47])p[48]=0;
    if(p[47]==0)*(u32 *)(p+16)=1;
    p[79]=func_02012FFC();
    *(int *)(p+28)=TOWNMAP_GRH_LoadTownInfo(*(u16 *)p);
}
