/*
 * function: SCRCMD_NETWORK_BattleRecordLinkEventMain
 * address:  0x0215FD0C
 * packet:   pkt_ov010_0215FD0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Nine-state link setup task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   FIELD_SUBSCREEN_ClearPanelResult  0x021A0FA8  thumb  ov021
 *   FIELD_SUBSCREEN_GetMenuSelectedButton  0x021A12A4  thumb  ov021
 *   func_021945A4  0x021945A4  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   SCRCMD_NETWORK_GetRecordKindByFrameRate  0x0215FEC8  thumb  ov010
 *   MOVE_POKEMON_InitSkillInfo  0x0215E840  thumb  ov010
 *   MOVE_POKEMON_InitSkillTarget  0x0215EA30  thumb  ov010
 *   MOVE_POKEMON_CreateSkillEvent  0x0215EA38  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CreateProcEvent  0x0216075C  thumb  ov010
 *   EVENTDATA_SYSTEM_CreateFieldLinkEvent  0x021644F4  thumb  ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetFrameRate  0x020129D0  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Info {
    u16 id;
    u16 flags;
    u32 f04;
    u32 f08;
    void *obj;
    void *field;
} Info;

typedef struct Query {
    u16 a;
    u16 b;
    u32 c;
} Query;

typedef struct Ctx {
    u16 f00;            /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *field;        /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 state;          /* 0x14 */
    u32 f18;            /* 0x18 */
    u8 req[0x28 - 0x1C];/* 0x1C */
    u32 f28;            /* 0x28 */
    u8 pad2C[0x40 - 0x2C];
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
} Ctx;

extern u32 FIELDMAP_GetSubscreen(u8 *p);
struct BigObj;
struct Evt;
struct Obj;
struct S0201235C;
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
extern int FIELD_SUBSCREEN_GetPanelResult(u32 a);
extern void FIELD_SUBSCREEN_ClearPanelResult(int *p);
extern u32 FIELD_SUBSCREEN_GetMenuSelectedButton(void *link);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void FLDMMDL_SysPauseMove(void *map);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern u32 SCRCMD_NETWORK_GetRecordKindByFrameRate(u32 n);
extern void MOVE_POKEMON_InitSkillInfo(void *field, Info *out);
extern void MOVE_POKEMON_InitSkillTarget(Query *q, u16 a, u16 b, u32 c);
extern int MOVE_POKEMON_CreateSkillEvent(int a0, int a1, int a2);
struct Owner;
extern void *EVENT_SHORTCUT_MENU_CreateProcEvent(struct Owner *o, u16 id);
extern int EVENTDATA_SYSTEM_CreateFieldLinkEvent(int i, void *a, void *p);
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAME_DATA_SetFrameRate(struct BigObj *p, u8 v);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int SCRCMD_NETWORK_BattleRecordLinkEventMain(void *task, void *unused, Ctx *c)
{
    Query q;
    Info info;
    void *map;
    void *sys;
    void *next;
    u32 n;
    int r;

    switch (c->state) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(c->field)) == 1) {
            map = FIELDMAP_GetMmdlSys(c->field);
            sys = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(task));
            FLDMMDL_SysPauseMove(map);
            GAME_DATA_SetFrameRate(sys, 1);
            FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(c->field), 1);
            c->state = 1;
        }
        break;
    case 1:
        r = FIELD_SUBSCREEN_GetPanelResult(FIELDMAP_GetSubscreen(c->field));
        if (r == 3) {
            c->state = 2;
            FIELD_SUBSCREEN_ClearPanelResult((int *)FIELDMAP_GetSubscreen(c->field));
        } else if (r == 4) {
            c->state = 3;
            FIELD_SUBSCREEN_ClearPanelResult((int *)FIELDMAP_GetSubscreen(c->field));
        }
        break;
    case 2:
        sys = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(task));
        n = FIELD_SUBSCREEN_GetMenuSelectedButton((void *)FIELDMAP_GetSubscreen(c->field));
        GAME_DATA_SetFrameRate(sys, n);
        c->f10 = FIELD_SUBSCREEN_GetMenuSelectedButton((void *)FIELDMAP_GetSubscreen(c->field));
        c->f28 = SCRCMD_NETWORK_GetRecordKindByFrameRate(n);
        c->state = 5;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->field));
        if (c->f40 != 1 && c->f40 != 4) {
            GAME_EVENT_ChangeEvent(task, func_021945A4(GAME_EVENT_GetGameSystem(task), (u32)c->field, c->f18));
            return 0;
        }
        return 1;
    case 4:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->field));
        MOVE_POKEMON_InitSkillInfo(GAMESYSTEM_GetFieldMap(c->f08), &info);
        MOVE_POKEMON_InitSkillTarget(&q, c->f48, c->f44, c->f4c);
        next = (void *)MOVE_POKEMON_CreateSkillEvent(c->f44, (int)(&q), (int)(&info));
        if (next == 0)
            return 1;
        GAME_EVENT_ChangeEvent(c->f04, next);
        break;
    case 5:
        GAME_EVENT_CallEvent(task, EVENT_SHORTCUT_MENU_CreateProcEvent((struct Owner *)c->req, c->f00));
        c->state = 6;
        break;
    case 6:
        if (c->f40 == 0)
            c->state = 1;
        else if (c->f40 == 1)
            c->state = 3;
        else if (c->f40 == 3)
            c->state = 7;
        else if (c->f40 == 2)
            c->state = 4;
        else if (c->f40 == 4)
            c->state = 3;
        break;
    case 7:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->field));
        GAME_EVENT_CallEvent(task, (struct Evt **)EVENTDATA_SYSTEM_CreateFieldLinkEvent(c->f44, c->f08, c->field));
        c->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}
