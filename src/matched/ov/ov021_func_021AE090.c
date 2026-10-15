/*
 * function: FLDEFF_FISHING_Draw
 * address:  0x021AE090
 * packet:   pkt_ov021_021AE090
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFishingDrawStatus  0x021D92FC  data
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm  arm9
 *   MTX_Identity33_  0x0207ADC4  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct M33 { int m[9]; } M33;
typedef struct Xf { V3 pos; V3 scale; M33 rot; } Xf;
typedef struct Q { u32 f0; u32 f4; u32 f8; u32 fc; } Q;

extern void MTX_Identity33_(M33 *m);
extern void FIELD_EFFECT_GetObjectPos(u32 a, V3 *out);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);
extern Xf sFishingDrawStatus;

void FLDEFF_FISHING_Draw(u32 a, Q **pq)
{
    Q *q = *pq;
    Xf x = sFishingDrawStatus;

    MTX_Identity33_(&x.rot);
    FIELD_EFFECT_GetObjectPos(a, &x.pos);
    G3D_SYSTEM_DrawObjectCulling((void *)q->fc, (struct Arg *)(&x));
}
