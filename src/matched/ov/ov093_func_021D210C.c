/*
 * function: BTL_CLIENT_StepPlayMonTaskAnim
 * address:  0x021D210C
 * packet:   pkt_ov093_021D210C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTLV_CORE_StartDamageEffect  0x021EA0F4  thumb  ov093
 *   BTLV_CORE_WaitDamageEffect  0x021EA120  thumb  ov093
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
struct S;
extern void BTLV_CORE_StartDamageEffect(struct S *s, u32 a, u32 b, u32 c);
struct S;
extern int BTLV_CORE_WaitDamageEffect(struct S *s);

int BTL_CLIENT_StepPlayMonTaskAnim(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        BTLV_CORE_StartDamageEffect(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (BTLV_CORE_WaitDamageEffect(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
