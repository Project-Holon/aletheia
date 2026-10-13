/*
 * function: UNION_ONESELF_BattleMenuMain
 * address:  0x0217C88C
 * packet:   pkt_ov019_0217C88C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 *   UNION_MSG_SetupTitleWindow  0x0217F5E0  thumb ov019
 *   UNION_MSG_DeleteTitleWindow  0x0217F624  thumb ov019
 *   UNION_MSG_SetupSubMenu  0x0217F388  thumb ov019
 *   UNION_MSG_SelectSubMenu  0x0217F4B4  thumb ov019
 *   UNION_MSG_DeleteSubMenu  0x0217F4AC  thumb ov019
 *   UNION_ONESELF_LoadRegulation  0x0217BA10  thumb ov019
 *   UNION_ONESELF_CheckEntryParties  0x0217BAA8  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   UNION_ONESELF_GetRegulationFlag  0x0217B974  thumb ov019
 *   UNION_MSG_SetupRegulationWindow  0x0217F640  thumb ov019
 *   UNION_MSG_CheckRegulationPrintEnd  0x0217F794  thumb ov019
 *   UNION_MSG_DeleteRegulationWindow  0x0217F7B8  thumb ov019
 *   func_0217EC88  0x0217EC88  thumb ov019
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
    u8 pad2e[0x60 - 0x2e];
    int f60;
    int f64;
    int f68;
    u8 pad6c[0x6e - 0x6c];
    s16 f6e;
} Obj;

typedef unsigned short u16;
int UNION_ONESELF_CheckNetError(char *p);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_SetupTitleWindow(char *p, u32 a1);
void UNION_MSG_DeleteTitleWindow(char *p);
void UNION_MSG_SetupSubMenu(char *p, int a1, int kind, u8 *arg);
struct Self;
int UNION_MSG_SelectSubMenu(char *p, int *hit, u8 *st, int *flag, u32 a4);
void UNION_MSG_DeleteSubMenu(void *ctx);
void UNION_ONESELF_LoadRegulation(char *p, int x);
int UNION_ONESELF_CheckEntryParties(int a, int b, int *p, int *q);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
int UNION_ONESELF_GetRegulationFlag(int id);
void UNION_MSG_SetupRegulationWindow(struct Self *self, u32 a1, u32 mask, int mode, int msg);
u32 UNION_MSG_CheckRegulationPrintEnd(char *p, u32 a);
void UNION_MSG_DeleteRegulationWindow(char *p);
u16 func_0217EC88(int i);
u32 KEY_GetTrg(void);

int UNION_ONESELF_BattleMenuMain(void *ctx, Obj *obj, u8 *a2, u8 *state)
{
    int f0c;
    int f08;
    int r;

    if (UNION_ONESELF_CheckNetError(ctx) == 1)
        return 1;
    if (UNION_MSG_CheckTalkPrintEnd(ctx) == 0)
        return 0;

    switch (*state) {
    case 0:
        obj->f6e = 0;
        (*state)++;
        break;
    case 1:
        if (obj->f6e == 5)
            UNION_MSG_SetupTitleWindow(ctx, (u32)a2);
        else if (obj->f6e == 0)
            UNION_MSG_DeleteTitleWindow(ctx);
        UNION_MSG_SetupSubMenu(ctx, (int)a2, obj->f6e, (u8 *)(&obj->f60));
        (*state)++;
        break;
    case 2:
        r = UNION_MSG_SelectSubMenu(ctx, &f0c, (u8 *)(&obj->f60), &f08, (u32)a2);
        if (f0c == 1) {
            obj->f6e = r;
            UNION_MSG_DeleteSubMenu(ctx);
            (*state)--;
        } else if (r == -2 || r == 0) {
            UNION_MSG_DeleteSubMenu(ctx);
            if (obj->f6e > 0) {
                obj->f6e = 0;
                (*state)--;
            } else {
                UNION_MSG_DeleteTitleWindow(ctx);
                UNION_ONESELF_SetNextPlayCategory(ctx, 7);
                return 1;
            }
        } else if (f08 == 1) {
            UNION_MSG_DeleteTitleWindow(ctx);
            UNION_MSG_DeleteSubMenu(ctx);
            UNION_ONESELF_LoadRegulation(ctx, r);
            obj->f2d = r;
            *state = 3;
        } else if (r != -1) {
            UNION_MSG_DeleteTitleWindow(ctx);
            UNION_MSG_DeleteSubMenu(ctx);
            if (UNION_ONESELF_CheckEntryParties((int)ctx, r, &obj->f64, &obj->f68) == 0) {
                UNION_MSG_SetupPrintTalkMsg(ctx, a2, 0x13e);
                *state = 5;
            } else {
                obj->f2d = r;
                UNION_ONESELF_SetNextPlayCategory(ctx, 8);
                return 1;
            }
        }
        break;
    case 3:
        UNION_MSG_SetupRegulationWindow(ctx, (u32)a2, 0, UNION_ONESELF_GetRegulationFlag(obj->f2d), 0);
        (*state)++;
        break;
    case 4:
        if (UNION_MSG_CheckRegulationPrintEnd(ctx, (u32)a2) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(ctx);
            *state = 1;
        }
        break;
    case 5:
        UNION_MSG_SetupRegulationWindow(ctx, (u32)a2, obj->f64, UNION_ONESELF_GetRegulationFlag(obj->f2d), 1);
        (*state)++;
        break;
    case 6:
        if (UNION_MSG_CheckRegulationPrintEnd(ctx, (u32)a2) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(ctx);
            if (obj->f68 == -1)
                *state = 9;
            else
                (*state)++;
        }
        break;
    case 7:
        UNION_MSG_SetupRegulationWindow(ctx, (u32)a2, obj->f64, UNION_ONESELF_GetRegulationFlag(obj->f2d), 2);
        (*state)++;
        break;
    case 8:
        if (UNION_MSG_CheckRegulationPrintEnd(ctx, (u32)a2) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_DeleteRegulationWindow(ctx);
            *state = 9;
        }
        break;
    case 9:
        UNION_MSG_SetupPrintTalkMsg(ctx, a2, func_0217EC88(obj->f14->flag));
        *state = 0;
        break;
    }
    return 0;
}
