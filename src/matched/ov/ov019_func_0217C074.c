/*
 * function: UNION_ONESELF_ConnectChildMain
 * address:  0x0217C074
 * packet:   pkt_ov019_0217C074
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb ov019
 *   gUnionEmptyString1     0x021807E4  data a1
 *   func_02034714  0x02034714  arm
 *   GFL_NET_SetChangeoverModeWrapper  0x0203D14C  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   UNION_COMM_RequestRestart  0x02172D20  thumb ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb ov012
 *   UNION_COMMAND_SendMyMac  0x02173A90  thumb ov012
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x1c];
    u8 *f1c;
    u8 pad20[0x5a - 0x20];
    u8 lo5a : 2;
    u8 mode : 2;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj;

extern char gUnionEmptyString1[];

int UNION_ONESELF_HandleNetError(char *p);
void func_02034714(const char *expr, u32 line, const char *file);
void GFL_NET_SetChangeoverModeWrapper(int a, int b, void *c);
int GFL_NET_GetNegotiationNum(void);
void GFL_NET_SetLoginOption(u8 a0);
u32 KEY_GetTrg(void);
void UNION_COMM_RequestRestart(u8 *p);
int UNION_COMM_IsResetting(u8 *p);
void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
int UNION_COMMAND_SendMyMac(void);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);

int UNION_ONESELF_ConnectChildMain(void *ctx, Obj *obj, u8 *a2, u8 *state)
{
    if (UNION_ONESELF_HandleNetError(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (obj->f1c == 0)
            func_02034714(gUnionEmptyString1, 0, gUnionEmptyString1);
        GFL_NET_SetChangeoverModeWrapper(2, 1, obj->f1c + 0x64);
        obj->f6c = 0;
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetNegotiationNum() > 1) {
            GFL_NET_SetLoginOption(1);
            *state = 3;
            break;
        }
        obj->f6c++;
        if (obj->f6c > 600 || (KEY_GetTrg() & 2)) {
            UNION_COMM_RequestRestart(ctx);
            UNION_ONESELF_SetNextPlayCategory(ctx, 0);
            UNION_COMM_SetSituationParam(ctx, 2, 0);
            if (obj->f6c > 600)
                UNION_MSG_SetupPrintTalkMsg(ctx, a2, 8);
            else
                UNION_MSG_SetupPrintTalkMsg(ctx, a2, 10);
            *state = 2;
        }
        break;
    case 2:
        if (UNION_COMM_IsResetting(ctx) == 0 && UNION_MSG_CheckTalkPrintEnd(ctx) == 1 && (KEY_GetTrg() & 0xf3))
            return 1;
        break;
    case 3:
        if (UNION_COMMAND_SendMyMac() == 1)
            *state = 4;
        break;
    case 4:
        switch (obj->mode) {
        case 1:
            UNION_COMM_SetSituationParam(ctx, 3, (u32)obj->f1c);
            UNION_COMM_SetSituationParam(ctx, 2, 0);
            UNION_ONESELF_SetNextPlayCategory(ctx, 9);
            return 1;
        case 2:
            UNION_COMM_SetSituationParam(ctx, 2, 0);
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, 8);
            UNION_COMM_RequestRestart(ctx);
            *state = 5;
            break;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(ctx) == 0 && UNION_MSG_CheckTalkPrintEnd(ctx) == 1 && (KEY_GetTrg() & 0xf3)) {
            UNION_ONESELF_SetNextPlayCategory(ctx, 0);
            return 1;
        }
        break;
    }
    return 0;
}
