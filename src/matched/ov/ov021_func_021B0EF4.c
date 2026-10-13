/*
 * function: SCRCMD_MSGWIN_CmdBalloonWinSavedText
 * address:  0x021B0EF4
 * packet:   pkt_ov021_021B0EF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CmdBalloonWinSavedText  0x021B0EF4  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetMsgBuffer  0x02158F78  thumb  ov010
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   func_0202A310  0x0202A310  thumb
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRCMD_WORK_GetWordSetWork  0x0215A63C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRCMD_MSGWIN_GetBalloonSide  0x021B0A40  thumb  ov021
 *   SCRCMD_MSGWIN_UpdateBalloonPos  0x021B0B08  thumb  ov021
 *   SCRCMD_MSGWIN_OpenTalkWin  0x021B0ADC  thumb  ov021
 *   SCRCMD_WORK_SetWindowState  0x0215A660  thumb  ov010
 *   VM_SetWait  0x020113D0  thumb
 *   SCRCMD_MSGWIN_WaitBalloonWin  0x021B0CEC  thumb
 */

typedef unsigned short u16;

typedef struct V3 {
    int y;
    void *x;
    void *z;
} V3;

typedef struct S {
    u16 id;
    u16 flag;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 SCRIPT_WORK_GetMsgBuffer(u8 *p);
extern int SCRIPT_WORK_CheckFlag(int);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void func_0202A310(int key, int want, void *dest, u32 heap);
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Q;
extern u8 *SCRCMD_WORK_GetWordSetWork(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern int SCRCMD_MSGWIN_GetBalloonSide(u32 a, struct Q *q);
extern void SCRCMD_MSGWIN_UpdateBalloonPos(void *a, int b);
extern void SCRCMD_MSGWIN_OpenTalkWin(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void SCRCMD_WORK_SetWindowState(u8 *p, u32 v);
extern void VM_SetWait(char *p, int val);
extern int SCRCMD_MSGWIN_WaitBalloonWin(int, int);

int SCRCMD_MSGWIN_CmdBalloonWinSavedText(void *a, int b)
{
    void *o;
    unsigned char **q;
    int k0, k1, k2, m, r, flag;
    int y;
    void *x;
    void *z;
    S *s;
    V3 v;

    o = SCRCMD_WORK_GetScriptWork((void *)b);
    q = (unsigned char **)SCRIPT_WORK_ResetFieldParam((int)o);
    k0 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    k1 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    k2 = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    m = SCRIPT_WORK_GetMsgBuffer(o);
    if (SCRIPT_WORK_CheckFlag(2) != 0) {
        return 1;
    }
    func_0202A310(k0, k1, (void *)m, SCRCMD_WORK_GetHeapId((void *)b));
    if (FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetOccupyInfo((void *)b), k2) == 0) {
        k2 = 0xff;
    }
    s = (S *)SCRCMD_WORK_GetWordSetWork((u8 *)b);
    flag = 0;
    func_02082BCC(s, 0, 0x28);
    s->id = k2;
    x = FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1]);
    y = (int)SCRCMD_WORK_GetOccupyInfo((void *)b);
    z = FIELD_PLAYER_GetMmdl((void *)x);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId((void *)y, s->id), (struct VecFx32 *)&v);
    r = SCRCMD_MSGWIN_GetBalloonSide((u32)z, (struct Q *)(&v));
    if (r != 1) {
        flag = 1;
    }
    s->flag = flag;
    SCRCMD_MSGWIN_UpdateBalloonPos((void *)b, 1);
    SCRCMD_MSGWIN_OpenTalkWin(b, (u32)(*q), flag, (u32)(&s->sum), m, 0, 0);
    SCRCMD_WORK_SetWindowState((u8 *)b, r);
    VM_SetWait(a, (int)SCRCMD_MSGWIN_WaitBalloonWin);
    return 1;
}
