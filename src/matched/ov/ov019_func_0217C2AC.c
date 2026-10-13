/*
 * function: UNION_ONESELF_TalkParentMain
 * address:  0x0217C2AC
 * packet:   pkt_ov019_0217C2AC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb ov019
 *   func_0217EC1C  0x0217EC1C  thumb ov019
 *   func_0217EC88  0x0217EC88  thumb ov019
 *   func_0217EC28  0x0217EC28  thumb ov019
 *   func_0217ECA0  0x0217ECA0  thumb ov019
 *   func_0217ECAC  0x0217ECAC  thumb ov019
 *   func_0217ECB8  0x0217ECB8  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 *   UNION_MSG_SetupMainMenu  0x0217F360  thumb ov019
 *   UNION_MSG_DeleteMainMenu  0x0217F378  thumb ov019
 *   UNION_MSG_SelectMainMenu  0x0217F380  thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 */

typedef unsigned char u8;
typedef short s16;

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
    u8 pad2e[0x5c - 0x2e];
    u8 f5c;
    u8 pad5d[0x6e - 0x5d];
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

int UNION_ONESELF_CheckNetError(char *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
u16 func_0217EC1C(int i);
u16 func_0217EC88(int i);
u16 func_0217EC28(int i);
u16 func_0217ECA0(int i);
u16 func_0217ECAC(int i);
u16 func_0217ECB8(void ***ctx);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupMainMenu(char *p, u32 a);
void UNION_MSG_DeleteMainMenu(void *p);
int UNION_MSG_SelectMainMenu(void *ctx, int a);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
void *GAME_DATA_GetMyParty(const struct BigObj *p);
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u32 func_0201AA1C(void *p);
u32 func_0201AAD4(void *p);
u32 func_0201AA88(void *p);

int UNION_ONESELF_TalkParentMain(Ctx *ctx, Obj *obj, u8 *a2, u8 *state)
{
    void *h;
    int r;

    if (UNION_ONESELF_CheckNetError((char *)ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f6e == 1) {
            obj->f6e = 0;
        } else if (obj->f5c == 0) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217EC1C(obj->f14->flag));
            obj->f5c++;
        } else {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217EC88(obj->f14->flag));
        }
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd((u8 *)ctx) == 1)
            (*state)++;
        break;
    case 2:
        UNION_MSG_SetupMainMenu((char *)ctx, (u32)a2);
        (*state)++;
        break;
    case 3:
        h = GAME_DATA_GetMyParty((void *)ctx->sys->f8);
        r = UNION_MSG_SelectMainMenu(ctx, (int)a2);
        if (r == -1)
            break;
        UNION_MSG_DeleteMainMenu(ctx);
        if (r == -2 || r == 0) {
            UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217EC28(obj->f14->flag));
            obj->f2d = 0;
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 8);
            return 1;
        }
        if (r == 0x18) {
            GAMESYSTEM_GetGameData((const struct Ctx *)ctx->sys->fc);
            if ((int)func_0201AA1C(h) < 2) {
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217ECA0(obj->f14->flag));
                *state = 4;
                break;
            }
        } else if (r == 0x19) {
            if ((int)func_0201AAD4(h) > 0) {
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217ECB8((void ***)ctx));
                *state = 4;
                break;
            } else if (func_0201AA88(h) == 0) {
                UNION_MSG_SetupPrintTalkMsg((u8 *)ctx, a2, func_0217ECAC(obj->f14->flag));
                *state = 4;
                break;
            }
        }
        if (r == 0x1b) {
            UNION_ONESELF_SetNextPlayCategory((char *)ctx, 10);
            return 1;
        }
        obj->f2d = r;
        UNION_ONESELF_SetNextPlayCategory((char *)ctx, 8);
        return 1;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd((u8 *)ctx) == 1)
            *state = 0;
        break;
    }
    return 0;
}
