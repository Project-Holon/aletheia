/*
 * function: BTL_CLIENT_StepPlayRecallAnim
 * address:  0x021D1CAC
 * packet:   pkt_ov093_021D1CAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTLV_CORE_StartMonEffectTask  0x021EA458  thumb  ov093
 *   BTLV_CORE_WaitMonEffectTask  0x021EA478  thumb  ov093
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

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void BTLV_CORE_StartMonEffectTask(char *ctx, u16 a, u16 b);
extern int BTLV_CORE_WaitMonEffectTask(u32 *p);

int BTL_CLIENT_StepPlayRecallAnim(BattleSeq *s, int *state, int *pp)
{
    switch (*state) {
    case 0:
        BTLV_CORE_StartMonEffectTask(s->msgWin, BTL_MAIN_GetViewPosOfSlot(s->battle, (u8)pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonEffectTask(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}
