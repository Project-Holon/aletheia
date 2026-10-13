/*
 * function: FIELD_TASK_UpdateRepeatPlayerEffect
 * address:  0x021C7D78
 * packet:   pkt_ov021_021C7D78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDEFF_IWAKUDAKI_Start  0x021ADD7C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; } W;
extern void FLDEFF_IWAKUDAKI_Start(int a, int b);
int FIELD_TASK_UpdateRepeatPlayerEffect(W *w)
{
    if (w->fC == 0) {
        if (w->fE % w->f12 == 0)
            FLDEFF_IWAKUDAKI_Start(w->f8, w->f4);
        if (w->f10 <= w->fE++)
            return 1;
    }
    return 0;
}
