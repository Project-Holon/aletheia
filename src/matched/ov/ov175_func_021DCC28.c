/*
 * function: func_021DCC28
 * address: 0x021DCC28
 * packet: pkt_ov175_021DCC28
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0200FB4C has no outside code-start witness; four own calls unresolved. TU --suggest-split leaves caller out, zero viable pieces.
 * blocker-C: copied verified32B Thumb EXACT from ov116_func_021D7200.c header, prior scratch blocker-1.log, dsi/1.1p1 -O4,p.
 * extern unsigned char gNetErrWork[],g_021461BC[];
 * void GFL_NET_ERR_RaiseFatal(int a) {
 *   if(*(int *)(gNetErrWork+44)!=2) {
 *     *(int *)(gNetErrWork+96)=a;
 *     g_021461BC[26]=1;g_021461BC[25]=1;
 *     *(int *)(gNetErrWork+44)=2;
 *   }
 * }
 * Blocker symbols: gNetErrWork 0x0214617C data; g_021461BC 0x021461BC data.
 * abi: CE58 retains visibly loaded third argument despite its two-argument body; 9A14 reads live r1, the count last loaded by the loop.
 * symbols:
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   func_021DCE58 0x021DCE58 thumb ov175
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetRecord 0x021B9A14 thumb ov114
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_RAP_CreatePostRequest(u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern void GFL_NET_ERR_RaiseFatal(u32);
extern void NHTTP_RAP_FreePostData(u8 *);
extern void NHTTP_RAP_DeleteConnection(u8 *);
extern void func_021DCE58(char *,unsigned long,u32);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 p, u32 i);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *,u32);
extern void MI_CpuCopy8(const void *,void *,u32);
static inline void clear(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32 *)(p+0x12c)=0;
    }
}
static inline void release(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
        NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
        NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32 *)(p+0x12c)=0;
    }
}
int func_021DCC28(char *p,u8 *out)
{
    int result;
    int status;
    u32 i;
    u8 *data;
    switch(*(u32 *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreatePostRequest(*(u8 **)(p+0x121c))) {
            if(!NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))) (*(u32 *)(p+0x12c))++;
            else {clear(p);return 2;}
        } else {clear(p);return 2;}
        break;
    case 1:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            switch(result) {
            case 400: GFL_NET_ERR_RaiseFatal(0x41);release(p);return 3;
            case 401: GFL_NET_ERR_RaiseFatal(0x42);release(p);return 3;
            case 408: GFL_NET_ERR_RaiseFatal(0x44);release(p);return 3;
            default: GFL_NET_ERR_RaiseFatal(0x43);release(p);return 3;
            case 200: (*(u32 *)(p+0x12c))++;break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x17a4);
            NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
            clear(p);
            return 2;
        }
        break;
    case 2:
        data=NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
        *out=NHTTP_RAP_RecordList_GetCount(data);
        for(i=0;i<*(u32 *)(p+0x174);i++) *(u32 *)(out+4+i*4)=NHTTP_RAP_RecordList_GetValue((u32)data,i);
        if(*out==0) MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(data,*(u32 *)(p+0x174)),out+0x1c,128);
        NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
        if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}
