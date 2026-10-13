/*
 * function: BTL_CLIENT_StepShowTaggedMessage
 * address:  0x021D1F10
 * packet:   pkt_ov093_021D1F10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_CORE_PrintTaggedMessage  0x021EA694  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_CORE_PrintTaggedMessage(char *p, u16 k, int *c);
extern int BTLV_CORE_WaitMessage(u32 *p);

int BTL_CLIENT_StepShowTaggedMessage(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)s)) {
            return 1;
        }
        BTLV_CORE_PrintTaggedMessage(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitMessage(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
