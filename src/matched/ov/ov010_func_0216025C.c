/*
 * function: EVENT_SHORTCUT_MENU_ReturnEvent
 * address:  0x0216025C
 * packet:   pkt_ov010_0216025C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nine-state connection sequence; returns 1 when the sequence has ended.
 * EXACT* because the listing extent runs over the unlabelled followers
 * 0x0216040C, 0x02160564 and 0x021605C0. Levers: the case-3 test is an
 * else-if chain with the `*state = 1` arm written twice (the first copy is
 * cross-jumped into `b`), and cases 4 and 5 hand one local `h` to
 * GAME_EVENT_CallEvent, which is what lets case 4 cross-jump into case 5's call.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlockFromSys  0x0200C404  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetIdAt  0x0200C464  thumb
 *   EVENT_SHORTCUT_MENU_ResolveShortcut  0x0216040C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_GetAvailBit  0x02160564  thumb  ov010
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   func_02164480  0x02164480  thumb  ov010
 *   func_02028754  0x02028754  thumb
 *   EVENT_SHORTCUT_MENU_CheckPartyRibbon  0x0216070C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CloseLink  0x0216060C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CreateProcEvent  0x0216075C  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENTDATA_SYSTEM_CreateFieldLinkEvent  0x021644F4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   EVENT_SHORTCUT_MENU_OpenMessage  0x021606DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

typedef struct Req {
    u8 pad[0x24];
    u32 result;         /* 0x24 */
    u32 next;           /* 0x28 */
} Req;

typedef struct Ctx {
    u32 f00;
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;
    Req *req;           /* 0x10 */
    u16 id;             /* 0x14 */
} Ctx;

struct Big;
struct BigObj;
struct Evt;
struct Rec44;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(void *p);
extern u8 RECENT_ID_LIST_SAVEDATA_GetIdAt(const u8 *a, u32 i);
extern int EVENT_SHORTCUT_MENU_ResolveShortcut(Req *r, u32 code);
extern int EVENT_SHORTCUT_MENU_GetAvailBit(u32 state, u32 *out, u32 *err);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern void func_02164480(Flags *f, void *a, void *b);
struct Obj;
struct Owner;
struct Work;
extern u32 func_02028754(struct Obj *obj, u32 n);
extern int EVENT_SHORTCUT_MENU_CheckPartyRibbon(struct Work *w);
extern u32 func_020307B0(void *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern int EVENT_SHORTCUT_MENU_CloseLink(int a0, int a1);
extern void *EVENT_SHORTCUT_MENU_CreateProcEvent(struct Owner *o, u16 id);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int EVENTDATA_SYSTEM_CreateFieldLinkEvent(int i, void *a, void *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern void *EVENT_SHORTCUT_MENU_OpenMessage(void *p, u32 a);

int EVENT_SHORTCUT_MENU_ReturnEvent(void *evt, u32 *state, Ctx *c)
{
    Flags flags;
    u32 idx;
    u32 err;
    u32 code;
    int r;
    int ok;
    int failed;
    int busy;
    u32 next;
    void *h;

    switch (*state) {
    case 0:
        code = RECENT_ID_LIST_SAVEDATA_GetIdAt(RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(c->f04))), 0);
        failed = 0;
        r = EVENT_SHORTCUT_MENU_ResolveShortcut(c->req, code);
        busy = 0;
        ok = EVENT_SHORTCUT_MENU_GetAvailBit(code, &idx, &err);
        if (err == 0 && GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(c->f04)) == 1) {
            failed = 1;
        } else if (ok == 1) {
            func_02164480(&flags, c->f04, c->f08);
            if (func_02028754((struct Obj *)(&flags), idx) == 0)
                failed = 1;
        }
        if (code == 9 && EVENT_SHORTCUT_MENU_CheckPartyRibbon((struct Work *)c) == 0)
            busy = 1;
        if (failed == 1) {
            *state = 5;
        } else if (busy == 1) {
            *state = 7;
        } else {
            switch (r) {
            case 0:
                *state = 2;
                break;
            case 1:
                *state = 4;
                break;
            }
        }
        break;
    case 1:
        func_020307B0(c->req);
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->f08));
        return 1;
    case 2:
        if (EVENT_SHORTCUT_MENU_CloseLink((int)c, (int)state) != 0) {
            GAME_EVENT_CallEvent(evt, EVENT_SHORTCUT_MENU_CreateProcEvent((struct Owner *)c->req, c->id));
            *state = 3;
        }
        break;
    case 3:
        r = c->req->result;
        if (r == 0) {
            *state = 1;
        } else if (r == 1) {
            *state = 1;
        } else if (r == 3) {
            *state = 4;
        }
        break;
    case 4:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        h = (void *)EVENTDATA_SYSTEM_CreateFieldLinkEvent(next, c->f04, c->f08);
        GAME_EVENT_CallEvent(evt, h);
        *state = 6;
        break;
    case 5:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        if (next == 0) {
            if (GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(c->f04))) == 1)
                h = EVENT_SHORTCUT_MENU_OpenMessage(c->f04, 1);
            else
                h = EVENT_SHORTCUT_MENU_OpenMessage(c->f04, 0);
        } else {
            h = EVENT_SHORTCUT_MENU_OpenMessage(c->f04, 0);
        }
        GAME_EVENT_CallEvent(evt, h);
        *state = 6;
        break;
    case 6:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->f08));
        return 1;
    case 7:
        func_020307B0(c->req);
        c->req = 0;
        GAME_EVENT_CallEvent(evt, EVENT_SHORTCUT_MENU_OpenMessage(c->f04, 2));
        *state = 8;
        break;
    case 8:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->f08));
        return 1;
    }
    return 0;
}
