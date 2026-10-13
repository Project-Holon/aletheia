/*
 * function: FIELD_TASK_UpdateCameraAngleTween
 * address:  0x021C71A4
 * packet:   pkt_ov021_021C71A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TASK_InitCameraAngleTween  0x021C7094  thumb  ov021
 *   FIELD_TASK_StepCameraAngleTween  0x021C70DC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W;
extern void FIELD_TASK_InitCameraAngleTween(u32 *p);
extern void FIELD_TASK_StepCameraAngleTween(W *w);
int FIELD_TASK_UpdateCameraAngleTween(W *w)
{
    switch (w->fC) {
    case 0:
        FIELD_TASK_InitCameraAngleTween((u32 *)w);
        w->fC++;
        break;
    case 1:
        FIELD_TASK_StepCameraAngleTween(w);
        if (w->f10 <= w->fE)
            return 1;
        break;
    }
    return 0;
}
