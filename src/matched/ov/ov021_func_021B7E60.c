/*
 * function: FIELD_RAIL_WORK_QueryStep
 * address:  0x021B7E60
 * packet:   pkt_ov021_021B7E60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;
typedef struct { u16 a, b, c, d; } Rect4;

struct Cam {
    u8 pad00[0x50];
    VecFx32 f50;
    Rect4 f5C;
    u8 pad64[8];
    Rect4 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

extern u8 FIELD_RAIL_TryStepLocation(void *m, Rect4 *r, u8 key, Rect4 *out);
extern void FIELD_RAIL_GetLocationPos(void *m, Rect4 *r, VecFx32 *out);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u8 FIELD_RAIL_WORK_QueryStep(struct Cam *c, u8 key, Rect4 *out, VecFx32 *pos)
{
    if (c->f74 == 0 || key != c->f76) {
        c->f75 = FIELD_RAIL_TryStepLocation(c->f78, &c->f5C, key, &c->f6C);
        FIELD_RAIL_GetLocationPos(c->f78, &c->f6C, &c->f50);
        c->f74 = 1;
        c->f76 = key;
    }
    if (out != 0)
        MI_CpuCopy8(&c->f6C, out, 8);
    if (pos != 0)
        *pos = c->f50;
    return c->f75;
}
