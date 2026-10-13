/*
 * function: BTL_CLIENT_StepShowTaggedMessageWithSound
 * address:  0x021D1F58
 * packet:   pkt_ov093_021D1F58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021EA694  0x021EA694  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021EA720  0x021EA720  thumb  ov093
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021EA694(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern int func_021EA720(u32 *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int arg);

int BTL_CLIENT_StepShowTaggedMessageWithSound(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            GFL_USE_PlaySeDefaultVolume(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
