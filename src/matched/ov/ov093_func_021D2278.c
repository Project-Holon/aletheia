/*
 * function: BTL_CLIENT_StepPlaySubstituteAnim
 * address:  0x021D2278
 * packet:   pkt_ov093_021D2278
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021EA0A0  0x021EA0A0  thumb  ov093
 *   func_021EA0E4  0x021EA0E4  thumb  ov093
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

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
struct S;
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int arg);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);

int BTL_CLIENT_StepPlaySubstituteAnim(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)s) == 0) {
            t = BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            func_021EA0A0(s->win, t, t, 1, WAZA_TOOL_GetParam(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            t = BTL_MAIN_GetTrainerSlotOfPoke((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            if (BTL_CLIENT_IsMainStepActive((u8 *)s) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x564);
            }
            func_021EA0F4(s->win, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
