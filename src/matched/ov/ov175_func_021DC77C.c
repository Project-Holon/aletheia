/*
 * function: WIFIBATTLEMATCH_NET_HttpRapProcess
 * address: 0x021DC77C
 * packet: pkt_ov175_021DC77C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * checks: 1 copied own ov114/DC610 signatures and ARM9 blocker input reads; 2 existing DC8A0 Pair twin used; 3 Pair replaces scalar two-word copy; 4 aggregate-copy idioms applied; 5 fresh directory and ov175 neighbours read. Caller TU MATCH has no viable split; only ARM90200FB4C blocks it.
 * lever: Pair aggregate assignment fixes all four payload-copy register bytes; TU --suggest-split confirms MATCH, no viable cut.
 * extent: lead 292 bytes; following 20-byte DC8A0 is already B7's src/matched/ov/WIFIBATTLEMATCH_NET_GetRapPair.c.
 * blocker: integrator-owned ARM9 0200FB4C, unresolved at caller +008E/+009C/+00C6; verified EXACT32 with one --thumb, fixed flags, no --region, scratch fb4c-r1.log.
 *   symbols: d_0214617C 0x0214617C data a4; d_021461BC 0x021461BC data a4.
 *   typedef unsigned char u8; typedef unsigned int u32;
 *   extern u8 d_0214617C[],d_021461BC[];
 *   void GFL_NET_ERR_RaiseFatal(int value) {
 *       if(*(u32 *)(d_0214617C+0x2c)!=2) {
 *           *(u32 *)(d_0214617C+0x60)=value;
 *           d_021461BC[0x1a]=1; d_021461BC[0x19]=1;
 *           *(u32 *)(d_0214617C+0x2c)=2;
 *       }
 *   }
 * symbols:
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   WIFIBATTLEMATCH_NET_DownloadError 0x021DC610 thumb ov175
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u32 a,b;} Pair;
extern int NHTTP_RAP_CreateRequest(int,u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern void NHTTP_RAP_DeleteConnection(u8 *);
extern int WIFIBATTLEMATCH_NET_DownloadError(u32);
extern void GFL_NET_ERR_RaiseFatal(unsigned int x);
extern void MI_CpuFill8(void *,int,int);
int WIFIBATTLEMATCH_NET_HttpRapProcess(u8 *p)
{
    int query,status;
    const u8 *r;
    if(*(u8 **)(p+0x121c)==0)return 2;
    switch(*(u32 *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(5,*(u8 **)(p+0x121c))!=0)*(u32 *)(p+0x12c)=1;
        break;
    case 1:
        if(NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))==0) {*(u32 *)(p+0x12c)=2;break;}
        if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32 *)(p+0x121c)=0;}
        return 2;
    case 2:
        query=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            r=NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
            if(query!=0x1f6) {
                if(query==0x1f7) {*(u32 *)(p+0x12c)=4;GFL_NET_ERR_RaiseFatal(62);return 0;}
            } else {*(u32 *)(p+0x12c)=4;GFL_NET_ERR_RaiseFatal(63);return 0;}
            *(Pair *)(p+0x1220)=*(const Pair *)(r+0x80);
            if(*(u32 *)r==0)*(u32 *)(p+0x12c)=3;
            else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*(u32 *)r));*(u32 *)(p+0x12c)=4;}
        } else if(status!=15) {
            if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32 *)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 4:
        MI_CpuFill8(p+0x1220,0,8);
        if(*(u8 **)(p+0x121c)!=0) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32 *)(p+0x121c)=0;
        }
        return 3;
    case 3:
        if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32 *)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}
