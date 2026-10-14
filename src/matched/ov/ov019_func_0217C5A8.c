/*
 * function: UNION_ONESELF_TalkChildMain
 * address:  0x0217C5A8
 * packet:   pkt_ov019_0217C5A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_MSG_GetTalkChildBusyMsg  0x0217EC34  thumb ov019
 *   UNION_MSG_GetTalkChildOfferMsg  0x0217EC68  thumb ov019
 *   UNION_MSG_GetTalkChildDeclineMsg  0x0217EC78  thumb ov019
 *   UNION_MSG_GetBadEggNoticeMsg  0x0217ECD0  thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   UNION_ONESELF_IsBattleStatus  0x0217B9BC  thumb ov019
 *   UNION_ONESELF_LoadRegulation  0x0217BA10  thumb ov019
 *   UNION_ONESELF_GetRegulationFlag  0x0217B974  thumb ov019
 *   UNION_ONESELF_CheckEntryParties  0x0217BAA8  thumb ov019
 *   UNION_MSG_SetupRegulationWindow  0x0217F640  thumb ov019
 *   UNION_MSG_CheckRegulationPrintEnd  0x0217F794  thumb ov019
 *   UNION_MSG_DeleteRegulationWindow  0x0217F7B8  thumb ov019
 *   UNION_MSG_SetupYesNo  0x0217F22C  thumb ov019
 *   UNION_MSG_SelectYesNo  0x0217F268  thumb ov019
 *   UNION_MSG_DeleteYesNo  0x0217F24C  thumb ov019
 *   UNION_COMMAND_SendPartnerSelectB  0x02173A48  thumb ov012
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   POKEPARTY_GetNonEggCount  0x0201AA1C  thumb
 *   POKEPARTY_GetBadEggCount  0x0201AAD4  thumb
 *   POKEPARTY_GetEggCount  0x0201AA88  thumb
 *   KEY_GetTrg  0x020362DC  arm
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad[7];
    u8 lo : 3;
    u8 flag : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
    u8 pad2f[0x64 - 0x2f];
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys;

typedef struct {
    Sys *sys;
} Ctx;

struct Self;
int UNION_ONESELF_CheckNetError(char *p);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
typedef unsigned short u16;
struct BigObj;
u16 UNION_MSG_GetTalkChildBusyMsg(int i);
u16 UNION_MSG_GetTalkChildOfferMsg(int i);
u16 UNION_MSG_GetTalkChildDeclineMsg(int i);
u16 UNION_MSG_GetBadEggNoticeMsg(void ***ctx);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
int UNION_ONESELF_IsBattleStatus(unsigned int x);
void UNION_ONESELF_LoadRegulation(char *p, int x);
int UNION_ONESELF_GetRegulationFlag(int id);
int UNION_ONESELF_CheckEntryParties(int a, int b, int *p, int *q);
void UNION_MSG_SetupRegulationWindow(struct Self *self, u32 a1, u32 mask, int mode, int msg);
u32 UNION_MSG_CheckRegulationPrintEnd(char *p, u32 a);
void UNION_MSG_DeleteRegulationWindow(char *p);
void UNION_MSG_SetupYesNo(u8 *p, u32 a);
int UNION_MSG_SelectYesNo(char *p, u32 *out);
void UNION_MSG_DeleteYesNo(u8 *p);
int UNION_COMMAND_SendPartnerSelectB(int a, ...);
void *GAME_DATA_GetMyParty(const struct BigObj *p);
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u32 POKEPARTY_GetNonEggCount(void *p);
u32 POKEPARTY_GetBadEggCount(void *p);
u32 POKEPARTY_GetEggCount(void *p);
u32 KEY_GetTrg(void);

int UNION_ONESELF_TalkChildMain(Ctx *ctx, Obj *obj, u8 *a2, u8 *state)
{
    int flag;
    void *h;

    if (UNION_ONESELF_CheckNetError((char *)ctx) == 1)
        return 1;
    if (UNION_MSG_CheckTalkPrintEnd((u8 *)ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 9);
        (*state)++;
        break;
    case 1:
        if (obj->f2d == 0xff)
            break;
        if (obj->f2d == 0) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, UNION_MSG_GetTalkChildBusyMsg(obj->f14->flag));
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x27);
            return 1;
        }
        if (obj->f2d < 0x1b) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, UNION_MSG_GetTalkChildOfferMsg(obj->f2d));
            if (UNION_ONESELF_IsBattleStatus(obj->f2d) == 1) {
                UNION_ONESELF_LoadRegulation((char *)ctx, obj->f2d);
                UNION_MSG_SetupRegulationWindow((struct Self *)ctx, (u32)a2, 0, UNION_ONESELF_GetRegulationFlag(obj->f2d), 0);
                *state = 2;
            } else {
                *state = 3;
            }
        } else if (UNION_COMMAND_SendPartnerSelectB(0) == 1) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 0x13d);
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x27);
            return 1;
        }
        break;
    case 2:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx, (u32)a2) == 1)
            *state = 3;
        break;
    case 3:
        UNION_MSG_DeleteRegulationWindow((char *)ctx);
        UNION_MSG_SetupYesNo((u8 *)ctx, (u32)a2);
        (*state)++;
        break;
    case 4:
        obj->f6e = 0;
        if (UNION_MSG_SelectYesNo((char *)ctx, (u32 *)(&flag)) != 1)
            break;
        h = GAME_DATA_GetMyParty((void *)ctx->sys->f8);
        UNION_MSG_DeleteYesNo((u8 *)ctx);
        if (UNION_ONESELF_CheckEntryParties((int)ctx, obj->f2d, &obj->f64, &obj->f68) == 0) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 0x13e);
            flag = 0;
        } else if (obj->f2d == 0x18 && flag == 1) {
            GAMESYSTEM_GetGameData((const struct Ctx *)ctx->sys->fc);
            if ((int)POKEPARTY_GetNonEggCount(h) < 2) {
                flag = 0;
                obj->f6e = 1;
            }
        } else if (obj->f2d == 0x19 && flag == 1) {
            if ((int)POKEPARTY_GetBadEggCount(h) > 0) {
                flag = 0;
                obj->f6e = 3;
            } else if (POKEPARTY_GetEggCount(h) == 0) {
                flag = 0;
                obj->f6e = 2;
            }
        }
        obj->f2e = flag;
        (*state)++;
        break;
    case 5:
        if (UNION_COMMAND_SendPartnerSelectB(obj->f2e) == 1) {
            if (obj->f64 != 0 && obj->f68 != 0)
                *state = 6;
            else
                *state = 10;
        }
        break;
    case 6:
        UNION_MSG_SetupRegulationWindow((struct Self *)ctx, (u32)a2, obj->f64, UNION_ONESELF_GetRegulationFlag(obj->f2d), 1);
        (*state)++;
        break;
    case 7:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx, (u32)a2) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow((char *)ctx);
            if (obj->f68 == -1)
                *state = 10;
            else
                (*state)++;
        }
        break;
    case 8:
        UNION_MSG_SetupRegulationWindow((struct Self *)ctx, (u32)a2, obj->f64, UNION_ONESELF_GetRegulationFlag(obj->f2d), 2);
        (*state)++;
        break;
    case 9:
        if (UNION_MSG_CheckRegulationPrintEnd((char *)ctx, (u32)a2) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow((char *)ctx);
            *state = 10;
        }
        break;
    case 10:
        if (obj->f2e == 0) {
            if (obj->f6e == 1)
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 0x28);
            else if (obj->f6e == 2)
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, 0x2f);
            else if (obj->f6e == 3)
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, UNION_MSG_GetBadEggNoticeMsg((void ***)ctx));
            else
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, UNION_MSG_GetTalkChildDeclineMsg(obj->f2d));
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 0x27);
            return 1;
        }
        UNION_ONESELF_SetNextPlayCategory((char *)ctx, obj->f2d + 11);
        *state = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}
