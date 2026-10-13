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
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
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
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
struct S;
extern int func_021EA120(struct S *s);

int BTL_CLIENT_StepPlayMonTaskAnim(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA0F4(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
