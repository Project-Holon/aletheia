/*
 * function: UNION_ONESELF_ColosseumPartySelectMain
 * address:  0x0217E188
 * packet:   pkt_ov019_0217E188
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_ONESELF_CheckMyParty  0x0217BA48  thumb  ov019
 *   UNION_ONESELF_CheckBattleTeamParty  0x0217BA6C  thumb  ov019
 *   UNION_ONESELF_CreateBattleTeamParty  0x0217B9CC  thumb  ov019
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   PARTY_SELECT_LIST_Create  0x021CC720  thumb  ov021
 *   PARTY_SELECT_LIST_Main  0x021CC810  thumb  ov021
 *   PARTY_SELECT_LIST_Delete  0x021CC7B4  thumb  ov021
 *   UNION_ONESELF_DeleteParty  0x0217B9F4  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_MSG_SetupTalkWindow  0x0217F098  thumb  ov019
 *   UNION_ONESELF_GetRegulationFlag  0x0217B974  thumb  ov019
 *   UNION_MSG_SetupRegulationWindow  0x0217F640  thumb  ov019
 *   UNION_MSG_CheckRegulationPrintEnd  0x0217F794  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 *   UNION_MSG_DeleteRegulationWindow  0x0217F7B8  thumb  ov019
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj;

typedef struct {
    u8 pad00[8];
    int f8;
} Sys;

typedef struct {
    Sys *sys;
    u8 pad04[0x3534 - 4];
    int f3534;
    int f3538;
    u8 pad353c[0x355c - 0x353c];
    u8 *w;
} Ctx;

struct Obj;
struct Self;
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
typedef unsigned short u16;
struct Big;
struct Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *p);
extern u32 func_0200BBA8(void *a);
struct BigObj;
extern void UNION_MSG_CloseAllWindows(void *p);
extern int UNION_ONESELF_CheckMyParty(char *p, unsigned int *mask);
extern int UNION_ONESELF_CheckBattleTeamParty(char *p, unsigned int *mask);
extern void *UNION_ONESELF_CreateBattleTeamParty(char *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern struct Obj *PARTY_SELECT_LIST_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int PARTY_SELECT_LIST_Main(struct Obj *p);
extern u32 PARTY_SELECT_LIST_Delete(struct Obj *p, u32 *out);
extern void UNION_ONESELF_DeleteParty(void *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void UNION_MSG_SetupTalkWindow(unsigned char *base, u8 *x);
extern int UNION_ONESELF_GetRegulationFlag(int id);
extern void UNION_MSG_SetupRegulationWindow(struct Self *self, u32 a1, u32 mask, int mode, int msg);
extern u32 UNION_MSG_CheckRegulationPrintEnd(char *p, u32 a);
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern u32 func_020362DC(void);
extern void UNION_MSG_DeleteRegulationWindow(char *p);

int UNION_ONESELF_ColosseumPartySelectMain(Ctx *ctx, Obj *obj, u8 *a2, u8 *state)
{
    u8 *w = ctx->w;
    int o1c;
    int o18;
    int o14;
    int o10;
    int f1;
    int f2;
    int r;

    if (UNION_MSG_CheckTalkPrintEnd((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
    case 1:
        if (func_0200BBA8(func_0200BAC8(GAME_DATA_GetSaveControl((struct Big *)ctx->sys->f8))) == 1) {
            (*state)++;
        } else {
            w[0x16d] = 0;
            obj->f6e++;
            *state = 4;
        }
        break;
    case 2:
        UNION_MSG_CloseAllWindows(ctx);
        UNION_ONESELF_CheckMyParty((char *)ctx, (unsigned int *)(&o1c));
        UNION_ONESELF_CheckBattleTeamParty((char *)ctx, (unsigned int *)(&o18));
        f1 = o1c != 0;
        f2 = o18 != 0;
        ctx->f3538 = (int)UNION_ONESELF_CreateBattleTeamParty((char *)ctx);
        ctx->f3534 = (int)PARTY_SELECT_LIST_Create((u32)a2, (u32)GAME_DATA_GetMyParty((void *)ctx->sys->f8), ctx->f3538, f1, f2, 0x15);
        (*state)++;
        break;
    case 3:
        if (PARTY_SELECT_LIST_Main((struct Obj *)ctx->f3534) == 1) {
            r = PARTY_SELECT_LIST_Delete((struct Obj *)ctx->f3534, (u32 *)(&o14));
            ctx->f3534 = 0;
            if (r == 2) {
                UNION_ONESELF_DeleteParty((void *)ctx->f3538);
                ctx->f3538 = 0;
                UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x2c);
                return 1;
            }
            switch (r) {
            case 0:
                w[0x16d] = 0;
                break;
            case 1:
                w[0x16d] = 1;
                break;
            }
            UNION_ONESELF_DeleteParty((void *)ctx->f3538);
            ctx->f3538 = 0;
            (*state)++;
        }
        break;
    case 4:
        o10 = 0;
        if (w[0x16d] == 0) {
            UNION_ONESELF_CheckMyParty((char *)ctx, (unsigned int *)(&o10));
            f1 = 1;
        } else {
            UNION_ONESELF_CheckBattleTeamParty((char *)ctx, (unsigned int *)(&o10));
            f1 = 2;
        }
        if (o10 != 0) {
            UNION_MSG_SetupTalkWindow((unsigned char *)ctx, a2);
            UNION_MSG_SetupRegulationWindow((struct Self *)ctx, (u32)a2, o10, UNION_ONESELF_GetRegulationFlag(obj->f00), f1);
            *state = 5;
        } else {
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx, (u32)a2) == 1) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, (u8 *)a2, 0x115);
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 3) {
            UNION_MSG_DeleteRegulationWindow((char *)ctx);
            if (obj->f6e == 0) {
                *state = 0;
            } else {
                UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}
