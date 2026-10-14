/*
 * function: GSYNC_STATE_StateSendRecordRequest
 * address: 0x021D8D08
 * packet: pkt_ov123_021D8D08
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020071D8 is unlabelled and lacks an outside witness;
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 * blocker: 0x020071D8 Thumb, verified EXACT in blocker-71D8-r1.log:
 *   extern unsigned int BACKUP_SYSTEM_GetWork(void *, int *);
 *   unsigned int SAVE_CONTROL_GetWorkArea(char *p, int *out) {
 *       return BACKUP_SYSTEM_GetWork(*(void **)(p + 0x10), out);
 *   }
 *   symbols: BACKUP_SYSTEM_GetWork 0x02031994 arm
 * symbols:
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_STATE_IsConnectionAlive 0x021D6E70 thumb ov123
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateReceiveRecordResponse 0x021D8C04 thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern int GSYNC_STATE_IsConnectionAlive(u8 *p);
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_GetConnection(char *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);
struct Ctrl020071D8;
extern void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out);
extern void GSYNC_DISP_UpdateProgressPosition(u8 *p, int n);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateReceiveRecordResponse(char *p);
void GSYNC_STATE_StateSendRecordRequest(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (GSYNC_MESSAGE_UpdateStream(*(char **)(p+0x18))) {
        *(int *)(p+0x74)=0;
        if (GSYNC_STATE_IsConnectionAlive((u8 *)p)) {
            if (NHTTP_RAP_CreateRequest(3,*(void **)(p+0x10))) {
                v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
                NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(void **)(p+0x10)),(void *)v,0x80000);
                GSYNC_DISP_UpdateProgressPosition(*(void **)(p+0x14),0);
                *(int *)(p+0x70)=0;
                if (!NHTTP_RAP_StartConnection(*(void **)(p+0x10)))
                    GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x986);
            }
        } else {
            GSYNC_DISP_UpdateProgressPosition(*(void **)(p+0x14),0);
            GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateReceiveRecordResponse,0x98c);
        }
    }
}
