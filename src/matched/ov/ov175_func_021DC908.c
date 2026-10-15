/*
 * function: WIFIBATTLEMATCH_NET_HttpRapSend
 * address: 0x021DC908
 * packet: pkt_ov175_021DC908
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: two-case result switch sorts compares while preserving case body order; the equivalent if chain differed21 bytes.
 * blocker: ARM9 0x0200FB4C has no outside code-start witness; three own calls unresolved. TU --suggest-split leaves caller out.
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
 * abi: CE58 retains visibly loaded third argument despite its two-argument setter body.
 * symbols:
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   WIFIBATTLEMATCH_NET_DownloadError 0x021DC610 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetResultD 0x021DCE58 thumb ov175
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int NHTTP_RAP_CreateRequest(int,u8 *);
extern int NHTTP_RAP_GetConnection(char *);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);
extern int NHTTP_RAP_StartConnection(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *p);
extern void GFL_NET_ERR_RaiseFatal(u32);
extern int WIFIBATTLEMATCH_NET_DownloadError(u32);
extern void WIFIBATTLEMATCH_NET_SetResultD(char *,unsigned long,u32);
extern void NHTTP_RAP_DeleteConnection(u8 *);
int WIFIBATTLEMATCH_NET_HttpRapSend(char *p)
{
    int result;
    int status;
    u32 *data;
    if(*(u8 **)(p+0x121c)==0) return 2;
    switch(*(u32 *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(6,*(u8 **)(p+0x121c))) {
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(char **)(p+0x121c)),(void *)((u32)(p+0x1228)),8);
            *(u32 *)(p+0x12c)=1;
        }
        break;
    case 1:
        if(!NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))) *(u32 *)(p+0x12c)=2;
        else {
            if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 2:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            data=(u32 *)NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
            switch(result) {
            case 0x1f7: *(u32 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3e);return 0;
            case 0x1f6: *(u32 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3f);return 0;
            default:
                if(*data==0) *(u32 *)(p+0x12c)=4;
                else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*data));*(u32 *)(p+0x12c)=3;}
                break;
            }
        } else if(status!=15) {
            WIFIBATTLEMATCH_NET_SetResultD(p+0x18,status,0x16a0);
            if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 3:
        if(*(u8 **)(p+0x121c)) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));
            NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
            *(u8 **)(p+0x121c)=0;
        }
        return 3;
    case 4:
        if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}
