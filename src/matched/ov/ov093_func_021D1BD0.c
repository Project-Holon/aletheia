/*
 * function: BTL_CLIENT_StepShowRecallMessage
 * address:  0x021D1BD0
 * packet:   pkt_ov093_021D1BD0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_PickRecallMessageId  0x021D1C40  thumb  ov093
 *   BTLV_SCU_InitMessage  0x021EAF18  thumb  ov093
 *   BTLV_SCU_AppendMessageArg  0x021EAF50  thumb  ov093
 *   BTLV_CORE_BuildAndPrintMessage  0x021EA614  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
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

extern int BTL_CLIENT_PickRecallMessageId(BattleSeq *s, u8 x, int *out);
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
struct H;
struct L;
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);

int BTL_CLIENT_StepShowRecallMessage(BattleSeq *s, int *state, int *pp)
{
    int t;

    switch (*state) {
    case 0:
        BTLV_SCU_InitMessage((struct L *)s->msg, 1, BTL_CLIENT_PickRecallMessageId(s, pp[0], &t));
        if (t != 0)
            BTLV_SCU_AppendMessageArg((struct L *)s->msg, pp[0]);
        BTLV_SCU_AppendMessageArg((struct L *)s->msg, pp[1]);
        BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}
