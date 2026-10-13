/*
 * function: BTL_CLIENT_StepUpdateMonGaugeThenMessage
 * address:  0x021D21D4
 * packet:   pkt_ov093_021D21D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_CORE_StartMonSpriteUpdate  0x021EA384  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteUpdate  0x021EA3A0  thumb  ov093
 *   BTLV_CORE_PrintSideMessage  0x021EA678  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTLV_CORE_StartMonSpriteUpdate(char *ctx, int a);
extern int BTLV_CORE_WaitMonSpriteUpdate(u32 *p);
extern void BTLV_CORE_PrintSideMessage(char *p, u16 k, int *c);
extern int BTLV_CORE_WaitMessage(u32 *p);

int BTL_CLIENT_StepUpdateMonGaugeThenMessage(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        BTLV_CORE_StartMonSpriteUpdate(s->win, BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteUpdate(s->win)) {
            BTLV_CORE_PrintSideMessage(s->win, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
