/*
 * function: BTL_CLIENT_StepStartEffectForMon
 * address:  0x021D2234
 * packet:   pkt_ov093_021D2234
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTLV_EFFECT_GaugeSetStatusIcon  0x021F81D0  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void BTLV_EFFECT_GaugeSetStatusIcon(u32 a, u32 b);

int BTL_CLIENT_StepStartEffectForMon(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        BTLV_EFFECT_GaugeSetStatusIcon(a[1], BTL_MAIN_GetViewPosOfSlot((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}
