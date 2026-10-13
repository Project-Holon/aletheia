/*
 * function: ENCEFF_DrawRipple
 * address:  0x021F5800
 * packet:   pkt_ov078_021F5800
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: G3 geometry FIFO registers 0x04000444-0x04000504, written by the SDK inlines (stores only)
 *
 * Draws the 33 x 25 vertex grid ENCEFF_StartRipple / ENCEFF_StartRippleBurst build as
 * quad strips.
 * Levers: the six vertex fields are loaded into locals before the stores
 * (inline loads give an 0x30 frame); j declared before the row pointer
 * (slot order); the element pointer is spelled `w + j * 33 + i` with no
 * row local, so the scaled row base is hoisted and `i = 0` lands last in
 * the preheader (a row local or `&w[j * 33 + i]` schedules it early or
 * hoists j * 33 unscaled).
 *
 * symbols:
 *   gRippleTranslate     0x021F5BB0  data  a4
 *   gRippleScale     0x021F5BD4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef s16 fx16;
typedef volatile u32 vu32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    fx16 x, y, z;
} VecFx16;

#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_SCALE      (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_DIF_AMB        (*(vu32 *)0x040004C0)
#define REG_SPE_EMI        (*(vu32 *)0x040004C4)
#define REG_LIGHT_COLOR    (*(vu32 *)0x040004CC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)

extern const VecFx32 gRippleTranslate;
extern const VecFx32 gRippleScale;

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

void ENCEFF_DrawRipple(VecFx16 *w)
{
    VecFx32 trans;
    VecFx32 scale;
    int j;
    int i;
    VecFx16 *v;
    fx32 t;
    fx16 x0, x1, y0, y1, z0, z1;

    j = 0;
    REG_MTX_PUSH = j;
    REG_DIF_AMB = 0x7FFF7FFF;
    REG_SPE_EMI = 0x4210;
    REG_LIGHT_COLOR = 0x7FFF;
    REG_POLYGON_ATTR = 0x001F00C1;
    trans = gRippleTranslate;
    scale = gRippleScale;
    G3_Translate(trans.x, trans.y, trans.z);
    G3_Scale(scale.x, scale.y, scale.z);
    for (; j < 0x18; j++) {
        REG_BEGIN_VTXS = 3;
        t = j << 15;
        for (i = 0; i < 33; i++) {
            v = w + j * 33 + i;
            x0 = v[0].x;
            x1 = v[33].x;
            y0 = v[0].y;
            y1 = v[33].y;
            z0 = v[0].z;
            z1 = v[33].z;
            REG_NORMAL = 0x20000000;
            G3_TexCoord(i << 15, t);
            G3_Vtx(x0, -y0, z0);
            G3_TexCoord(i << 15, t + 0x8000);
            G3_Vtx(x1, -y1, z1);
        }
        REG_END_VTXS = 0;
    }
    REG_MTX_POP = 1;
}
