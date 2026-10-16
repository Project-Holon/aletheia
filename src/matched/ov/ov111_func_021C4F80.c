/*
 * function: VIEWER_MAIN_InitBrightness
 * address:  0x021C4F80
 * packet:   pkt_ov111_021C4F80
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_Inv  0x0207C778  arm
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef int fx32;
typedef unsigned int u32;

struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};

typedef struct {
    u8 pad0[0x303C];
    fx32 scaleX;
    fx32 scaleY;
    u8 pad3044[0x304C - 0x3044];
    u32 cx;
    u32 cy;
    u32 x;
    u32 y;
    u8 pad305C[0x32CA - 0x305C];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
} Work;

extern fx32 FX_Inv(fx32 v);
extern void G2x_SetBGyAffine_(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);

void VIEWER_MAIN_InitBrightness(Work *p)
{
    struct Mtx m;

    m._00 = FX_Inv(p->scaleX);
    m._01 = 0;
    m._10 = 0;
    m._11 = FX_Inv(p->scaleY);
    G2x_SetBGyAffine_((void *)0x04001020, &m, p->cx, p->cy, p->x, p->y);
    G2x_SetBGyAffine_((void *)0x04001030, &m, p->cx, p->cy, p->x, p->y);
    p->dirty = 0;
}
