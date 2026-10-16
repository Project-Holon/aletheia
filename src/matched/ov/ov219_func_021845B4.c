/*
 * function: BEACON_DETAIL_LoadRecords
 * address: 0x021845B4
 * packet: pkt_ov219_021845B4
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: permuter split-assign(count2) moves the otherwise swapped outer/inner count spill slots; fixed-flag one validates MATCH*258B; trailing2B alignment excluded.
 * blocker: ARM9 02025B38,02025BB8,02025BD0 have no matched witnesses. Independent scratch one:02025B38 EXACT4B;02025BB8 MATCH24B sole data0209FA34;02025BD0 MATCH24B sole data0209FA35. the integrator owns their sources.
 * blocker C: int BMP_OAM_GetNumRecords(void){return 19;} typedef unsigned int u32; extern const unsigned char d_0209FA34[],d_0209FA35[]; u32 BMP_OAM_GetRecordKey(u32 i){if(i<19)return d_0209FA34[i*12];return 0;} u32 BMP_OAM_GetRecordParam(u32 i){if(i<19)return d_0209FA35[i*12];return 18;}
 * note 2026-10-04 (D2): still MATCH*; the three arm9 leaves 02025B38, 02025BB8, 02025BD0 are now filed EXACT in
 *   src/matched/arm9/func_<ADDR>.c (D2 lane 11). Rerun after the integrator regenerates shards: expected EXACT*.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   BEACON_DETAIL_SetRecord 0x021846B8 thumb ov219
 *   func_020307B0 0x020307B0 arm
 *   BMP_OAM_GetNumRecords 0x02025B38 thumb
 *   BMP_OAM_GetRecordParam 0x02025BD0 thumb
 *   BMP_OAM_GetRecordKey 0x02025BB8 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *,int,int,u32,u32 *);
extern void BEACON_DETAIL_SetRecord(char *,int,int,int,u16,u16);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern int BMP_OAM_GetNumRecords(void);
extern u32 BMP_OAM_GetRecordParam(u32),BMP_OAM_GetRecordKey(u32);
void BEACON_DETAIL_LoadRecords(char *p)
{
    void *arc,*data,*data2;
    u32 size,size2;
    short *cursor;
    long count2;
    long count;
    int firstcount,i,j;
    arc=func_020490F4(0x35,(u16)(*(u32 *)p));
    *(u32 *)(p+0x14)=0;
    data=ARC_UTIL_LoadHandleMemberWithSize(arc,0x12,0,*(u32 *)p,&size);
    firstcount=size/6u;
    cursor=(short *)((char *)data+6);
    for(i=1;i<firstcount;i++,cursor+=3){
        if(*(u16 *)cursor!=2){
            BEACON_DETAIL_SetRecord(p,*(u32 *)(p+0x14),cursor[1],cursor[2],i,0);
            (*(u32 *)(p+0x14))++;
        }
    }
    func_020307B0(data);
    j=1;
    count=BMP_OAM_GetNumRecords();
    for(;j<count;j++){
        data2=ARC_UTIL_LoadHandleMemberWithSize(arc,BMP_OAM_GetRecordParam(j),0,*(u32 *)p,&size2);
        count2=size2;
        count2=count2/4u;
        cursor=(short *)((char *)data2+4);
        for(i=1;i<count2;i++,cursor+=2){
            BEACON_DETAIL_SetRecord(p,*(u32 *)(p+0x14),cursor[0],cursor[1],BMP_OAM_GetRecordKey(j),i);
            (*(u32 *)(p+0x14))++;
        }
        func_020307B0(data2);
    }
    ARC_TOOL_DeleteHandle(arc);
}
