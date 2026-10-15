/*
 * function: FIELD_RAIL_TryStepLocation
 * address:  0x021B7CD8
 * packet:   pkt_ov021_021B7CD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The source parameter is `const Rect4 *`: with it mwcc hoists the last
 * halfword load of the `old = *r` copy above the third store into the
 * address-taken local (plain or __restrict r keeps source order).
 *
 * symbols:
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb
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

struct Mgr { u8 pad00[0x1C]; void *f1C; };

extern void FIELD_RAIL_WORK_SetLocation(void *p, const Rect4 *r);
extern void FIELD_RAIL_WORK_StartStep(void *p, int a, u8 key);
struct Sub;
extern void FIELD_RAIL_WORK_UpdateStep(struct Sub *o);
extern void FIELD_RAIL_WORK_GetLocation(void *p, Rect4 *out);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern u8 FIELD_RAIL_WORK_IsLocationValid(void *p, Rect4 *r);

u8 FIELD_RAIL_TryStepLocation(struct Mgr *m, const Rect4 *r, u8 key, Rect4 *out)
{
    Rect4 old = *r;

    FIELD_RAIL_WORK_SetLocation(m->f1C, r);
    FIELD_RAIL_WORK_StartStep(m->f1C, 4, key);
    FIELD_RAIL_WORK_UpdateStep(m->f1C);
    FIELD_RAIL_WORK_GetLocation(m->f1C, out);
    if (GF_STANDARD_CompareBytes((const u8 *)(&old), (const u8 *)out, 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(m->f1C, out);
}
