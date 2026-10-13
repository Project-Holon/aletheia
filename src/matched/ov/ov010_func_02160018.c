/*
 * function: EVENT_SHORTCUT_MENU_MainEvent
 * address:  0x02160018
 * packet:   pkt_ov010_02160018
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Proc main of the ov010 link exchange: a 16-state machine that drives
 * the ov021 connection object at +0xC, classifies the received result
 * code, and hands off to the result screens before tearing down.
 *
 * The ov021 calls to 0x021C536C, 0x021C5380 and 0x021C5394 (once folded
 * into SHORTCUT_MENU_Start) resolve since seeds_2 labelled them. Levers: in state 4 `retry` declared first and `bad`
 * last (retry spills to sp+4, ok to sp+0, next stays in r7), the result
 * code dispatched as a switch and the case-10 value as an if chain with
 * the f18 != 0 arm first; in state 12 the tail call in a local written
 * as a nested if (i == 0, then the save test) with the call in all
 * three arms, which is what makes both w->f04 loads hoist above their
 * branches and lets state 11 cross-jump into the shared tail.
 *
 * symbols:
 *   EVENT_SHORTCUT_MENU_OpenLink  0x021605C0  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CloseLink  0x0216060C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_GetAvailBit  0x02160564  thumb  ov010
 *   EVENT_SHORTCUT_MENU_ResolveShortcut  0x0216040C  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CheckPartyRibbon  0x0216070C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_CreateProcEvent  0x0216075C  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   EVENTDATA_SYSTEM_CreateFieldLinkEvent  0x021644F4  thumb  ov010
 *   EVENT_SHORTCUT_MENU_OpenMessage  0x021606DC  thumb  ov010
 *   SHORTCUT_MENU_Main  0x021C5224  thumb  ov021
 *   SHORTCUT_MENU_Start  0x021C5348  thumb  ov021
 *   SHORTCUT_MENU_RequestClose  0x021C536C  thumb  ov021
 *   SHORTCUT_MENU_IsWaitingInput  0x021C5380  thumb  ov021
 *   SHORTCUT_MENU_GetResult  0x021C5394  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02028754  0x02028754  thumb
 *   func_020307B0  0x020307B0  arm
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
    u8 pad00[0x24];
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Req;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Req *f10;           /* 0x10 */
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
} Work;

extern void EVENT_SHORTCUT_MENU_OpenLink(int a0, int a1);
struct Obj;
struct Owner;
extern int EVENT_SHORTCUT_MENU_CloseLink(int a0, int a1);
extern int EVENT_SHORTCUT_MENU_GetAvailBit(u32 state, u32 *out, u32 *err);
extern int EVENT_SHORTCUT_MENU_ResolveShortcut(Req *r, u32 code);
extern void func_02164480(Flags *f, void *a, void *b);
extern int EVENT_SHORTCUT_MENU_CheckPartyRibbon(Work *w);
extern void *EVENT_SHORTCUT_MENU_CreateProcEvent(struct Owner *o, u16 id);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern int EVENTDATA_SYSTEM_CreateFieldLinkEvent(int i, void *a, void *p);
extern void *EVENT_SHORTCUT_MENU_OpenMessage(void *p, u32 a);
struct BigObj;
struct Ctx;
struct Evt;
struct Rec44;
struct SaveBlock;
extern void SHORTCUT_MENU_Main(char *p);
extern void SHORTCUT_MENU_Start(u8 *p);
extern void SHORTCUT_MENU_RequestClose(u8 *p);
extern int SHORTCUT_MENU_IsWaitingInput(u8 *p);
extern u32 SHORTCUT_MENU_GetResult(u8 *p, u32 *out);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern u32 func_020307B0(void *p);

int EVENT_SHORTCUT_MENU_MainEvent(void *evt, u32 *state, Work *w)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        EVENT_SHORTCUT_MENU_OpenLink(0, (int)w);
        *state = 2;
        break;
    case 2:
        SHORTCUT_MENU_Start(w->f0c);
        *state = 3;
        break;
    case 3:
        SHORTCUT_MENU_Main(w->f0c);
        if (SHORTCUT_MENU_IsWaitingInput(w->f0c) == 0)
            *state = 4;
        break;
    case 4: {
        u32 code;
        int r;

        SHORTCUT_MENU_Main(w->f0c);
        r = SHORTCUT_MENU_GetResult(w->f0c, &code);
        if (r == 1) {
            Flags fl;
            u32 n;
            u32 err;
            int retry = 0;
            int ok;
            int next;
            int bad = 0;

            ok = EVENT_SHORTCUT_MENU_GetAvailBit(code, &n, &err);
            next = EVENT_SHORTCUT_MENU_ResolveShortcut(w->f10, code);
            if (err == 0 && GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(w->f04)) == 1) {
                bad = 1;
            } else if (ok == 1) {
                func_02164480(&fl, w->f04, w->f08);
                if (func_02028754((struct Obj *)(&fl), n) == 0)
                    bad = 1;
            }
            if (code == 9 && EVENT_SHORTCUT_MENU_CheckPartyRibbon(w) == 0)
                retry = 1;
            if (bad == 1) {
                *state = 12;
            } else if (retry == 1) {
                *state = 14;
            } else {
                switch (next) {
                case 0:
                    *state = 9;
                    break;
                case 1:
                    *state = 11;
                    break;
                }
            }
        } else if (r == 2) {
            *state = 5;
        }
        break;
    }
    case 5:
        SHORTCUT_MENU_RequestClose(w->f0c);
        *state = 6;
        break;
    case 6:
        SHORTCUT_MENU_Main(w->f0c);
        if (SHORTCUT_MENU_IsWaitingInput(w->f0c) == 0)
            *state = 7;
        break;
    case 7:
        if (EVENT_SHORTCUT_MENU_CloseLink((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->f08));
            return 1;
        }
        break;
    case 8:
        EVENT_SHORTCUT_MENU_OpenLink(1, (int)w);
        *state = 4;
        break;
    case 9:
        GAME_EVENT_CallEvent(evt, EVENT_SHORTCUT_MENU_CreateProcEvent((struct Owner *)w->f10, w->f14));
        *state = 10;
        break;
    case 10:
    {
        u32 v = w->f10->f24;

        if (v == 0) {
            if (w->f18 != 0)
                *state = 7;
            else
                *state = 8;
        } else if (v == 1) {
            *state = 7;
        } else if (v == 3) {
            *state = 11;
        }
        break;
    }
    case 11:
        if (EVENT_SHORTCUT_MENU_CloseLink((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            GAME_EVENT_CallEvent(evt, (struct Evt **)EVENTDATA_SYSTEM_CreateFieldLinkEvent(i, w->f04, w->f08));
            *state = 13;
        }
        break;
    case 12:
        if (EVENT_SHORTCUT_MENU_CloseLink((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            {
                void *t;

                if (i == 0) {
                    if (GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(w->f04))) == 1)
                        t = EVENT_SHORTCUT_MENU_OpenMessage(w->f04, 1);
                    else
                        t = EVENT_SHORTCUT_MENU_OpenMessage(w->f04, 0);
                } else {
                    t = EVENT_SHORTCUT_MENU_OpenMessage(w->f04, 0);
                }
                GAME_EVENT_CallEvent(evt, t);
            }
            *state = 13;
        }
        break;
    case 13:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->f08));
        return 1;
    case 14:
        if (EVENT_SHORTCUT_MENU_CloseLink((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            w->f10 = 0;
            GAME_EVENT_CallEvent(evt, EVENT_SHORTCUT_MENU_OpenMessage(w->f04, 2));
            *state = 15;
        }
        break;
    case 15:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(w->f08));
        return 1;
    }
    return 0;
}
