/*
 * function: BTL_CLIENT_StepPlayHitEffect
 * address:  0x021D2930
 * packet:   pkt_ov093_021D2930
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
 *   BTL_CALC_SummarizeTypeAffinity  0x021D7AD4  thumb  ov093
 *   BTLV_CORE_StartHitAnim  0x021EA1B8  thumb  ov093
 *   BTLV_CORE_WaitHitAnim  0x021EA1F0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern int BTL_CALC_SummarizeTypeAffinity(int a);
struct S;
extern void BTLV_CORE_StartHitAnim(struct S *s, u32 a, int b, int c);
struct S;
extern int BTLV_CORE_WaitHitAnim(struct S *s);

int BTL_CLIENT_StepPlayHitEffect(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)a) == 0) {
            t = BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], (u8)c[0]);
            BTLV_CORE_StartHitAnim((struct S *)a[0x15], (u16)c[2], t, BTL_CALC_SummarizeTypeAffinity(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (BTLV_CORE_WaitHitAnim((struct S *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
