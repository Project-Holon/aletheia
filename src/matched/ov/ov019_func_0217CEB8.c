/*
 * function: UNION_ONESELF_TalkPlayingChildMain
 * address:  0x0217CEB8
 * packet:   pkt_ov019_0217CEB8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_CHARA_GetSexByObjId  0x0217AF04  thumb ov019
 *   UNION_CHARA_GetBeaconIndex  0x0217AEFC  thumb ov019
 *   UNION_MSG_GetPartnerBusyMsg  0x0217ED04  thumb ov019
 *   UNION_MSG_GetTrainerCardChatMsg  0x0217ED10  thumb ov019
 *   UNION_MSG_GetBattleChatMsg  0x0217ECE8  thumb ov019
 *   UNION_MSG_GetSpinTradeChatMsg  0x0217ED64  thumb ov019
 *   UNION_MSG_GetDrawChatMsg  0x0217ED2C  thumb ov019
 *   UNION_MSG_GetTradeChatMsg  0x0217ED48  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 *   KEY_GetTrg  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x58];
    u16 f58;
} Obj;

int UNION_CHARA_GetSexByObjId(u8 *a, u16 key);
u16 UNION_CHARA_GetBeaconIndex(unsigned int x);
u16 UNION_MSG_GetPartnerBusyMsg(int i);
u16 UNION_MSG_GetTrainerCardChatMsg(int i);
u16 UNION_MSG_GetBattleChatMsg(int i);
u16 UNION_MSG_GetSpinTradeChatMsg(int i);
u16 UNION_MSG_GetDrawChatMsg(int i);
u16 UNION_MSG_GetTradeChatMsg(int i);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
u32 KEY_GetTrg(void);

int UNION_ONESELF_TalkPlayingChildMain(void *ctx, Obj *obj, u8 *a2, u8 *state)
{
    int r;

    switch (*state) {
    case 0:
        r = UNION_CHARA_GetSexByObjId(ctx, obj->f58);
        switch (((u8 *)ctx + UNION_CHARA_GetBeaconIndex(obj->f58) * 0x8c)[0x291b]) {
        case 1:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetPartnerBusyMsg(r));
            break;
        case 2:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetTrainerCardChatMsg(r));
            break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetBattleChatMsg(r));
            break;
        case 25:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetSpinTradeChatMsg(r));
            break;
        case 3:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetDrawChatMsg(r));
            break;
        case 24:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, UNION_MSG_GetTradeChatMsg(r));
            break;
        case 0:
        default:
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, 0x151);
            break;
        }
        UNION_ONESELF_SetNextPlayCategory(ctx, 0);
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1 && (KEY_GetTrg() & 0xf3))
            return 1;
        break;
    }
    return 0;
}
