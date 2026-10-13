/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue
 * address:  0x02186D48
 * packet:   pkt_ov020_02186D48
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl  0x02186090  thumb  ov020
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FIELD_WFBC_ReloadSaveData  0x02193904  thumb  ov021
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetNpcRecord  0x02193C00  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetPersonData  0x02193C04  thumb  ov021
 *   FIELD_WFBC_DATA_LOCAL_IsMoodLow  0x021867B4  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_HasParent  0x021867A8  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetCounter  0x021869AC  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetValue  0x021869B8  thumb  ov020
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   FIELD_WFBC_DATA_LOCAL_ReadCounter  0x021869D8  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_ReadValue  0x021869D0  thumb  ov020
 *   FIELD_WFBC_GetPeopleArrivalFlag  0x02193BE4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct {
    int f0;
    int f4;
} Ent;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned int   u32;
extern int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p, int which);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern int GAME_DATA_GetMysteryRecvFlagB(int a0);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p);
extern u16 FLDMMDL_GetObjId(void *p);
extern int FIELD_WFBC_ReloadSaveData(void *p);
extern void *FIELD_WFBC_GetPeople(void *a, unsigned int b);
extern char *FIELD_WFBC_PEOPLE_GetNpcRecord(char *p);
extern void *FIELD_WFBC_PEOPLE_GetPersonData(u8 *p);
extern int FIELD_WFBC_DATA_LOCAL_IsMoodLow(u8 *p);
extern int FIELD_WFBC_DATA_LOCAL_HasParent(void *a);
extern u16 FIELD_WFBC_DATA_LOCAL_GetCounter(u16 *p);
extern u16 FIELD_WFBC_DATA_LOCAL_GetValue(u16 *p);
extern int FIELD_WFBC_GetPeopleNum(unsigned char *a);
extern u16 FIELD_WFBC_DATA_LOCAL_ReadCounter(u16 *p);
extern u16 FIELD_WFBC_DATA_LOCAL_ReadValue(char *p);
extern int FIELD_WFBC_GetPeopleArrivalFlag(void *a, unsigned int b);

int FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue(int a0, int a1)
{
    int cur;
    int st;
    void *id;
    int *rec;
    void *sub;
    void *b;
    void *obj;
    int c;
    void *d;
    void *w;
    int kind;
    u16 *out;
    Ent *ent;
    void *m;
    void *s;
    s16 v[3];

    m = SCRCMD_WORK_GetScriptWork((void *)a1);
    b = SCRCMD_WORK_GetGameData((void *)a1);
    c = (int)GAME_DATA_GetSecondUnionInfo(b);
    kind = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    if (kind == 3) {
        *out = FIELD_WFBC_DATA_LOCAL_CountPeople((char *)c, 0);
    } else {
    ent = (Ent *)SCRIPT_WORK_ResetFieldParam((int)m);
    m = FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper((u8 *)ent->f4));
    d = FIELDMAP_GetFieldPlayer((struct Obj00020 *)ent->f4);
    w = FIELDMAP_GetMmdlSys((u8 *)ent->f4);
    s = (void *)GAME_DATA_GetMysteryRecvFlagB((int)b);
    FIELD_PLAYER_GetFrontGridPos((u32)d, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    obj = FLDMMDL_SysSearchGridPos((u32)w, v[2], v[0], 0);
    if (obj != 0) {
        cur = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(obj);
        st = FLDMMDL_GetObjId(obj);
        FIELD_WFBC_ReloadSaveData(m);
        sub = FIELD_WFBC_GetPeople(m, cur);
        if (sub != 0) {
            rec = (int *)FIELD_WFBC_PEOPLE_GetNpcRecord(sub);
            id = FIELD_WFBC_PEOPLE_GetPersonData(sub);
        }
    }
    switch (kind) {
    case 0:
        *out = rec[6];
        break;
    case 1:
        *out = FIELD_WFBC_DATA_LOCAL_IsMoodLow(id);
        break;
    case 2:
        *out = FIELD_WFBC_DATA_LOCAL_HasParent(id);
        break;
    case 3:
        break;
    case 4:
        *out = FIELD_WFBC_DATA_LOCAL_GetCounter(s);
        break;
    case 5:
        *out = FIELD_WFBC_DATA_LOCAL_GetValue(s);
        break;
    case 6:
        if (FIELD_WFBC_GetPeopleNum(m) == 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 7:
        *out = FIELD_WFBC_DATA_LOCAL_ReadCounter(s);
        break;
    case 8:
        *out = FIELD_WFBC_DATA_LOCAL_ReadValue(s);
        break;
    case 9:
        *out = cur;
        break;
    case 10:
        *out = FIELD_WFBC_GetPeopleArrivalFlag(m, cur);
        break;
    case 11:
        *out = st;
        break;
    }
    }
    return 0;
}
