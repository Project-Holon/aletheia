/*
 * function: BTL_CLIENT_StepSetAbilityWithPopup
 * address:  0x021D324C
 * packet:   pkt_ov093_021D324C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_SetAbility  0x021D66D0  thumb  ov093
 *   BTLV_CORE_ShowPortrait  0x021EA768  thumb  ov093
 *   BTLV_CORE_UpdatePortraitSlideIn  0x021EA778  thumb  ov093
 *   BTLV_CORE_ReloadPortrait  0x021EA7A8  thumb  ov093
 *   BTLV_CORE_UpdatePortraitMosaic  0x021EA7B8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct QJ;
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern void BTLV_CORE_ShowPortrait(u32 *p, u32 a2, u32 a3);
extern int BTLV_CORE_UpdatePortraitSlideIn(u32 *p, u32 a2);
extern void BTLV_CORE_ReloadPortrait(u32 *p, u32 a2);
extern int BTLV_CORE_UpdatePortraitMosaic(u32 *p, u32 a2);

int BTL_CLIENT_StepSetAbilityWithPopup(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;

    u = (u8)c[0];
    s = BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], u);
    switch (*b) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)a) != 0) {
            BTL_POKEPARAM_SetAbility((struct QJ *)BTL_SIDE_GetPokeByIdThunk((char *)a[1], u), c[1]);
            return 1;
        }
        BTLV_CORE_ShowPortrait((u32 *)a[0x15], s, 0);
        (*b)++;
        break;
    case 1:
        if (BTLV_CORE_UpdatePortraitSlideIn((u32 *)a[0x15], s) != 0) {
            BTL_POKEPARAM_SetAbility((struct QJ *)BTL_SIDE_GetPokeByIdThunk((char *)a[1], u), c[1]);
            BTLV_CORE_ReloadPortrait((u32 *)a[0x15], s);
            (*b)++;
        }
        break;
    case 2:
        if (BTLV_CORE_UpdatePortraitMosaic((u32 *)a[0x15], s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
