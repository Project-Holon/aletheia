/*
 * function: BTLV_EFFECT_StartCameraMove
 * address:  0x021F8554
 * packet:   pkt_ov094_021F8554
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFECT_GetPokeSpriteCameraTarget  0x021F8628  thumb  ov094
 *   BTLV_CAMERA_SetEyeAndTarget  0x021F6EDC  thumb  ov094
 *   BTLV_CAMERA_StartMove  0x021F6F48  thumb  ov094
 *   BTLV_EFFECT_StartEffect  0x021F7998  thumb  ov094
 */
typedef unsigned int u32;
typedef struct { int x, y, z; } VecFx32;

typedef struct {
    char pad[0x19C];
    void *cam;          /* 0x19C */
    char pad2[0x1C];
    int mode;           /* 0x1BC */
} Work;

extern Work *gBtlvEff;

extern void BTLV_EFFECT_GetPokeSpriteCameraTarget(u32 a, int *out, int *p);
extern void BTLV_CAMERA_SetEyeAndTarget(int *p, int *a, int *b);
extern void BTLV_CAMERA_StartMove(void *cam, VecFx32 *a, VecFx32 *b, int n, int s, int t);
extern void BTLV_EFFECT_StartEffect(u32 a);

void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int n, int s, int t)
{
    VecFx32 a;
    VecFx32 b;

    if (flags & 1) {
        BTLV_EFFECT_GetPokeSpriteCameraTarget(flags, (int *)(&a), (int *)(&b));
        switch (kind) {
        case 0:
            BTLV_CAMERA_SetEyeAndTarget(gBtlvEff->cam, (int *)(&a), (int *)(&b));
            break;
        case 1:
            BTLV_CAMERA_StartMove(gBtlvEff->cam, &a, &b, n, s, t);
            break;
        }
        return;
    }
    switch (gBtlvEff->mode) {
    case 0:
        BTLV_EFFECT_StartEffect(0x23F);
        break;
    case 1:
        if (flags == 2) {
            BTLV_EFFECT_StartEffect(0x240);
        } else {
            BTLV_EFFECT_StartEffect(0x241);
        }
        break;
    case 2:
        if (flags == 2) {
            BTLV_EFFECT_StartEffect(0x242);
        } else if (flags == 4) {
            BTLV_EFFECT_StartEffect(0x23F);
        } else {
            BTLV_EFFECT_StartEffect(0x243);
        }
        break;
    case 3:
        BTLV_EFFECT_StartEffect(0x245);
        break;
    }
}
