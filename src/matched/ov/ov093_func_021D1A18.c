/*
 * function: BTL_CLIENT_StepShowFixedMessage
 * address:  0x021D1A18
 * packet:   pkt_ov093_021D1A18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAF18  0x021EAF18  thumb  ov093
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

struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
struct H;
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);

int BTL_CLIENT_StepShowFixedMessage(BattleSeq *s, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0xb7);
        BTLV_CORE_BuildAndPrintMessage(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(s->msgWin) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
