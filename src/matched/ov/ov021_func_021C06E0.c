/*
 * function: EVENT_COMM_ERROR_Run
 * address:  0x021C06E0
 * packet:   pkt_ov021_021C06E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sCommErrorSubProcData  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020124E4  0x020124E4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   EVENT_COMM_ERROR_RunCommExit  0x021C0780  thumb  ov021
 */

typedef unsigned int u32;

extern u32 sCommErrorSubProcData[];
extern char ov021_id[];
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u32 func_0202647C(void *obj);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void GFL_NET_ERR_RequestScreen(void);
struct Evt;
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern int FIELDMAP_IsReady(void *);
extern void FLDMMDL_SysPauseMove(void *);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern int EVENT_COMM_ERROR_RunCommExit(u32 a, int *st);

int EVENT_COMM_ERROR_Run(u32 a, int *st)
{
    void *h = func_020124E4((void *)a);
    void *o = GAMESYSTEM_GetFieldMap(h);
    void *v;

    switch (*st) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((void *)o));
        if (func_0202647C((void *)GAMESYSTEM_GetGameComm(h)) == 2) {
            if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(h)) == 1) {
                GFL_NET_ERR_RequestScreen();
                v = FIELD_STATUS_CreateSubProcEvent(h, (int)o, (int)ov021_id, (int)sCommErrorSubProcData, (int)h);
            } else {
                v = func_020122C0(h, 0, EVENT_COMM_ERROR_RunCommExit, 0);
            }
        } else {
            GFL_NET_ERR_RequestScreen();
            v = FIELD_STATUS_CreateSubProcEvent(h, (int)o, (int)ov021_id, (int)sCommErrorSubProcData, (int)h);
        }
        GAME_EVENT_CallEvent((struct Evt *)a, v);
        (*st)++;
        break;
    case 1:
        if (o != 0 && FIELDMAP_IsReady(o) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((void *)o));
            return 1;
        }
        break;
    }
    return 0;
}
