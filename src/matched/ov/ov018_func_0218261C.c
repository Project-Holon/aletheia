/*
 * function: EVENT_COMM_COMMON_ItemPurchaseEventMain
 * address:  0x0218261C
 * packet:   pkt_ov018_0218261C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   BEACON_GetMoney  0x0200C274  thumb
 *   BEACON_SubMoney  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   INTRUDE_COMM_PickEntryForKind  0x021763D8  thumb  ov011
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_DeleteChoice  0x0217F4C4  thumb  ov018
 *   EVENT_COMM_COMMON_StartChoice  0x0217F4D8  thumb  ov018
 *   EVENT_COMM_COMMON_PollChoice  0x0217F508  thumb  ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb  ov018
 *   d_021839A4     0x021839A4  data  a2
 *
 * EXACT*: the listing extent runs into two unlabelled 8-byte Thumb
 * followers at 0x021828A8 and 0x021828B0 (ldr r3,[pc,#0]; bx r3 thunks
 * to 0x0218236D and 0x021825F9).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Outer {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
} Outer;

extern const u16 d_021839A4[6][5];

struct BigObj;
struct Blk34;
struct Ctx;
struct Obj;
struct WordSet;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *GAME_DATA_GetLastBattleRecSlot(void *);
extern u32 BEACON_GetMoney(struct Blk34 *p);
extern u32 BEACON_SubMoney(struct Blk34 *p, u32 v);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_COMM_SendReply(int a, int b, int c, int d);
extern void INTRUDE_COMM_PickEntryForKind(u8 *p, u32 key);
extern void  EVENT_COMM_COMMON_PrintMsg(u8 *, int);
extern int   EVENT_COMM_COMMON_IsPrintFinished(u8 *);
extern int   EVENT_COMM_COMMON_IsKeyTrg();
extern void  EVENT_COMM_COMMON_DeleteChoice(u8 *);
extern void EVENT_COMM_COMMON_StartChoice(void **p, int a);
extern int EVENT_COMM_COMMON_PollChoice(void **p);
extern void  EVENT_COMM_COMMON_ExitCommonWork(u8 *, Outer *);

int EVENT_COMM_COMMON_ItemPurchaseEventMain(void *a, int *state, Outer *c)
{
    void *sub;
    void *x;
    u8 *v;
    u16 *h;
    void *t;
    int flag;
    int r;

    sub = GAME_EVENT_GetGameSystem(a);
    x = GAMESYSTEM_GetGameData(sub);
    t = (void *)GAMESYSTEM_GetGameComm(sub);
    h = c->h58;
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)t);
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 0) {
            return 0;
        }
        if (*state < 8 && *state != 2 && *state != 3) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, 4);
            *state = 8;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        WORDSET_SetSlotMyStatus(c->p10, 0, c->f78);
        WORDSET_SetSlotFromMsg36(c->p10, 1, h[0]);
        WORDSET_SetSlotNumber(c->p10, 2, h[1], 5, 0, 1);
        WORDSET_SetSlotMyStatus(c->p10, 3, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(sub)));
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 1) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[1][c->b42]);
            (*state)++;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 1) {
            EVENT_COMM_COMMON_StartChoice((void **)((u8 *)c + 0x10), (int)sub);
            (*state)++;
        }
        break;
    case 3:
        r = EVENT_COMM_COMMON_PollChoice((void **)((u8 *)c + 0x10));
        flag = 0;
        switch (r) {
        case 0:
            EVENT_COMM_COMMON_DeleteChoice((u8 *)c + 0x10);
            if (h[1] > BEACON_GetMoney(GAME_DATA_GetMiscSave(x))) {
                flag = 1;
                *state = 5;
            } else if (func_02007E3C(GAME_DATA_GetMyItem(x), h[0], 1, 0x15) == 0) {
                flag = 1;
                *state = 6;
            } else {
                *state = 4;
            }
            break;
        case 1:
            EVENT_COMM_COMMON_DeleteChoice((u8 *)c + 0x10);
            flag = 1;
            *state = 7;
            break;
        }
        if (flag == 1) {
            INTRUDE_COMM_PickEntryForKind(GAME_DATA_GetLastBattleRecSlot(x), 3);
        }
        break;
    case 4:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 7, v[0x158]) == 1) {
            BEACON_SubMoney(GAME_DATA_GetMiscSave(x), h[1]);
            func_02007E50(GAME_DATA_GetMyItem(x), h[0], 1, 0x15);
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[5][c->b42]);
            *state = 8;
        }
        break;
    case 5:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 9, v[0x158]) == 1) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[3][c->b42]);
            *state = 8;
        }
        break;
    case 6:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 10, v[0x158]) == 1) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[4][c->b42]);
            *state = 8;
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 8, v[0x158]) == 1) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839A4[2][c->b42]);
            *state = 8;
        }
        break;
    case 8:
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 10;
        }
        break;
    case 10:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        return 1;
    }
    return 0;
}
