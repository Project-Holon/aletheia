/*
 * function: BTL_CLIENT_StepShowTrainerResult
 * address:  0x021D1410
 * packet:   pkt_021D1410
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_StepShowTrainerResult   0x021D1410  thumb
 *   BTL_MAIN_GetWinBgm   0x021B86DC  thumb ov093
 *   BTL_MAIN_GetOwnClientId   0x021B8FF4  thumb ov093
 *   BTL_MAIN_GetOwnOpponentClient   0x021B904C  thumb ov093
 *   BTL_MAIN_GetPrizeMoney   0x021B919C  thumb ov093
 *   BTL_MAIN_GetBonusMoney   0x021B9210  thumb ov093
 *   BTL_MAIN_CalcPenaltyMoney   0x021B9244  thumb ov093
 *   BTL_MAIN_GetTrainerId   0x021BA004  thumb ov093
 *   BTL_MAIN_GetTrainerType   0x021BA020  thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag   0x021BA1A8  thumb ov093
 *   BTL_CLIENT_GetOutcomeForClient   0x021D13A4  thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage   0x021EA614  thumb ov093
 *   BTLV_CORE_PrintTrainerMessage   0x021EA6B0  thumb ov093
 *   BTLV_CORE_WaitMessage   0x021EA710  thumb ov093
 *   func_021EAF18   0x021EAF18  thumb ov093
 *   func_021EAF50   0x021EAF50  thumb ov093
 *   BTLV_EFFECT_StartEffect   0x021F7998  thumb ov094
 *   BTLV_EFFECT_IsBusy   0x021F7EB4  thumb ov094
 *   BTLV_EFFECT_AddPokeSprite   0x021F7F58  thumb ov094
 *   BTLV_EFFECT_StopLowHpBgm   0x021F878C  thumb ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern int BTL_CLIENT_GetOutcomeForClient(BattleSeq *s);
extern u16 BTL_MAIN_GetWinBgm(void **p);
extern void BTLV_EFFECT_StopLowHpBgm(u32 a);
extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern unsigned short BTL_MAIN_GetTrainerType(char *p, int i);
extern u16 BTL_MAIN_GetTrainerId(char *p, int i);
extern u32 BTL_MAIN_GetPrizeMoney(u8 *p);
extern u32 BTL_MAIN_GetBonusMoney(u8 *p);
extern u32 BTL_MAIN_CalcPenaltyMoney(char *p);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
struct H;
extern void func_021EAF50(struct L *p, u32 val);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern int BTLV_CORE_PrintTrainerMessage(char *p, u16 a, u16 b);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_AddPokeSprite(int a, u32 b, u32 c, u32 d, u32 e);
extern void BTLV_EFFECT_StartEffect(u32 a);

int BTL_CLIENT_StepShowTrainerResult(BattleSeq *s, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (BTL_CLIENT_GetOutcomeForClient(s) == 1) {
            BTLV_EFFECT_StopLowHpBgm(BTL_MAIN_GetWinBgm(s->battle));
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 0);
            b = BTL_MAIN_GetOwnOpponentClient(s->battle, 1);
            if (a == b) {
                func_021EAF18((struct L *)s->msg, 1, 44);
                func_021EAF50((struct L *)s->msg, a);
            } else {
                func_021EAF18((struct L *)s->msg, 1, 45);
                func_021EAF50((struct L *)s->msg, a);
                func_021EAF50((struct L *)s->msg, b);
            }
            BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
            *state = 1;
        } else if (BTL_MAIN_CheckSetupStatusFlag(s->battle, 0x100) == 0) {
            a = BTL_MAIN_GetOwnClientId(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 54);
            func_021EAF50((struct L *)s->msg, a);
            func_021EAF50((struct L *)s->msg, a);
            BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(s->msgWin)) {
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 0);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(s->battle, a), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 0);
            BTLV_CORE_PrintTrainerMessage(s->msgWin, BTL_MAIN_GetTrainerId(s->battle, a), 1);
            *state = 3;
        }
        break;
    case 3:
        if (BTLV_CORE_WaitMessage(s->msgWin)) {
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 0);
            if (a != BTL_MAIN_GetOwnOpponentClient(s->battle, 1)) {
                BTLV_EFFECT_StartEffect(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (BTLV_EFFECT_IsBusy() == 0) {
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 1);
            BTLV_EFFECT_AddPokeSprite(BTL_MAIN_GetTrainerType(s->battle, a), 9, 0, 0, 0);
            BTLV_EFFECT_StartEffect(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_EFFECT_IsBusy() == 0) {
            a = BTL_MAIN_GetOwnOpponentClient(s->battle, 1);
            BTLV_CORE_PrintTrainerMessage(s->msgWin, BTL_MAIN_GetTrainerId(s->battle, a), 1);
            *state = 6;
        }
        break;
    case 6:
        if (BTLV_CORE_WaitMessage(s->msgWin))
            *state = 7;
        break;
    case 7:
        a = BTL_MAIN_GetPrizeMoney(s->battle);
        if (a) {
            b = BTL_MAIN_GetOwnClientId(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 58);
            func_021EAF50((struct L *)s->msg, b);
            func_021EAF50((struct L *)s->msg, a);
            BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
        }
        if (BTL_MAIN_GetBonusMoney(s->battle) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (BTLV_CORE_WaitMessage(s->msgWin)) {
            a = BTL_MAIN_GetBonusMoney(s->battle);
            if (a) {
                b = BTL_MAIN_GetOwnClientId(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 59);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
            }
            *state = 11;
        }
        break;
    case 9:
        if (BTLV_CORE_WaitMessage(s->msgWin)) {
            a = BTL_MAIN_CalcPenaltyMoney(s->battle);
            if (a) {
                func_021EAF18((struct L *)s->msg, 1, 56);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
            }
            *state = 10;
        }
        break;
    case 10:
        if (BTLV_CORE_WaitMessage(s->msgWin)) {
            func_021EAF18((struct L *)s->msg, 1, 57);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
            *state = 11;
        }
        break;
    case 11:
        if (BTLV_CORE_WaitMessage(s->msgWin))
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}
