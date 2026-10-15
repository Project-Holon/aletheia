/*
 * function: SCRCMD_SYMBOL_ViewEventMain
 * address:  0x0216B004
 * packet:   pkt_ov010_0216B004
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * Proc main of an ov010 sub-sequence: a 9-state machine that registers the
 * party member's species/form key with the save (clearing the form to 12
 * when it is not yet seen), runs the ov098 screen and then the ov227 one,
 * and frees both work buffers when it runs past the last state.
 *
 * Byte-correct. Evidence gaps, not C: 0x02189A08 (ov021), 0x021B6158
 * (ov098) and 0x021B95C8 (ov227) carry no func_ label in their overlay
 * and have no second caller; gPdcProcData and d_021B98A4 are the ov098 and
 * ov227 proc tables. Levers: `ok` at function scope (its slot sits above
 * the case-1 locals), heap declared before mon in both key blocks, and
 * the u16 flag stored in both arms of an if/else.
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_FindRecord  0x0200E2BC  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0200873C  0x0200873C  thumb
 *   ZUKAN_SAVE_GetBlock  0x0200CA10  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   PDC_CreateArgs  0x021B6100  thumb  ov098
 *   PDC_GetResult  0x021B6158  thumb  ov098
 *   func_021B95A0  0x021B95A0  thumb  ov227
 *   func_021B95C8  0x021B95C8  thumb  ov227
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   gPdcProcData     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Key {
    u32 species : 11;
    u32 pad0 : 12;
    u32 form : 6;
    u32 pad1 : 3;
} Key;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 f10[0x10];       /* 0x10 */
    Key f20;            /* 0x20 */
    u16 f24;            /* 0x24 */
    u8 pad26[2];
    u16 *f28;           /* 0x28 */
} Work;

extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 gPdcProcData[];
extern u8 d_021B98A4[];

typedef signed int     s32;
struct Big;
struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct P;
struct Sub02008700Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 SYMBOL_SAVE_FindRecord(void *a0, u32 *a1, void *heap, u32 mode);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *ZUKAN_SAVE_GetBlock(void *sv);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *h);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *h);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *h);
extern u32 func_020307B0(void *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
extern struct P *PDC_CreateArgs(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap);
extern int PDC_GetResult(void *p);
extern void *func_021B95A0(u32 a, int b, u32 c, u32 heap);
extern void func_021B95C8(void *p);

int SCRCMD_SYMBOL_ViewEventMain(void *evt, u32 *state, Work *w)
{
    void *h = GAME_EVENT_GetGameSystem(evt);
    void *sys = GAMESYSTEM_GetGameData(h);
    int ok;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(h, 0x468));
        (*state)++;
        break;
    case 1: {
        u32 heap;
        void *mon;
        Key key;

        mon = w->f0c;
        heap = w->f24;

        key.species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        key.form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
        if (SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(sys), (u32 *)(&key), (void *)heap, 1) == 0)
            w->f20.form = 12;
        ENCEFF_Start((struct Ctx *)FIELDMAP_GetEncEff(w->f00), (u32)evt, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)h, (int)w->f00));
        (*state)++;
        break;
    case 4: {
        void *sv = GAME_DATA_GetSaveControl(sys);

        func_02007E50(GAME_DATA_GetMyItem(sys), 0x240, 1, w->f24);
        func_02034AC4((u32)ov098_id);
        w->f04 = PDC_CreateArgs((u32)sys, (u32)w->f0c, (u32)w->f10, (u32)GAME_DATA_GetMyStatus(sys), (u32)GAME_DATA_GetMyItem(sys),
                               (u32)func_0200873C(sv), (u32)ZUKAN_SAVE_GetBlock(sv), w->f24);
        GAME_EVENT_CallProc(evt, -1, (u32)gPdcProcData, (u32)w->f04);
        (*state)++;
        break;
    }
    case 5: {
        u32 heap;
        void *mon;
        Key key;

        ok = PDC_GetResult(w->f04);
        mon = w->f0c;
        heap = w->f24;

        key.species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        key.form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
        if (SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(sys), (u32 *)(&key), (void *)heap, 1) == 0
            || SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(sys), (u32 *)(&w->f20), (void *)w->f24, 0) == 0)
            ok = 0;
        if (ok == 1)
            *w->f28 = 1;
        else
            *w->f28 = 0;
        func_02034A5C((u32)ov098_id);
        func_02034AC4((u32)ov227_id);
        w->f08 = func_021B95A0((u32)sys, ok, (u32)w->f0c, w->f24);
        GAME_EVENT_CallProc(evt, -1, (u32)d_021B98A4, (u32)w->f08);
        func_02007F1C(GAME_DATA_GetMyItem(sys), 0x240, 1, w->f24);
        (*state)++;
        break;
    }
    case 6:
        func_021B95C8(w->f08);
        func_02034A5C((u32)ov227_id);
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(h));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(h));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(h));
        (*state)++;
        break;
    default:
        func_020307B0(w->f0c);
        func_020307B0(w->f04);
        return 1;
    }
    return 0;
}
