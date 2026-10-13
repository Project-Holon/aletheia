/*
 * function: BTL_CLIENT_StepSetMonVisibility
 * address:  0x021D20BC
 * packet:   pkt_ov093_021D20BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfPoke  0x021B8DC0  thumb  ov093
 *   BTLV_CORE_SetMonShown  0x021EA354  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
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

extern unsigned char BTL_MAIN_GetViewPosOfPoke(unsigned char *p, void *a, unsigned int b);
extern void BTLV_CORE_SetMonShown(void *ctx, int a, int b);
extern int func_021F7EB4(void);

int BTL_CLIENT_StepSetMonVisibility(Seq *s, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)BTL_MAIN_GetViewPosOfPoke((unsigned char *)s->unk00, (void *)s->unk04, (u8)a[0]);
        BTLV_CORE_SetMonShown(s->win, t, a[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}
