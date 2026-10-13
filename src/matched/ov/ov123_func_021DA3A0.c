/*
 * function: func_021DA3A0
 * address: 0x021DA3A0
 * packet: pkt_ov123_021DA3A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: 0x020071D8 ARM9 leaf has no outside witness; verified EXACT
 *   in scratch blocker071d8-r1.log, 12 bytes. the integrator owns filing it.
 *   extern unsigned BACKUP_SYSTEM_GetWork(void *, unsigned *);
 *   symbols: BACKUP_SYSTEM_GetWork 0x02031994 arm
 *   unsigned SAVE_CONTROL_GetWorkArea(char *p, unsigned *out) {
 *       return BACKUP_SYSTEM_GetWork(*(void **)(p + 0x10), out);
 *   }
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   KEY_GetTrg 0x020362DC arm
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA328 0x021DA328 thumb ov123
 */
extern int GFL_NET_GetRunState(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 KEY_GetTrg(void);
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_GetConnection(char *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);
struct Ctrl020071D8;
extern void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021DA034(char *p, int n, int unused);
extern void func_021DA328(char *p);
void func_021DA3A0(char *p)
{
    int a;
    unsigned b;
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(9,*(void **)(p + 8))) {
            b = (unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p + 0x1c),&a);
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(void **)(p + 8)),(void *)b,0x80000);
            if (!NHTTP_RAP_StartConnection(*(void **)(p + 8))) {
                func_021DA034(p,(int)func_021DA328,0x1f6);
                return;
            }
        }
    } else if (KEY_GetTrg()) {
        func_021DA034(p,(int)func_021DA328,0x1fc);
    }
}
