/*
 * function: FIELD_RAIL_ClampLocation
 * address:  0x021B8250
 * packet:   pkt_ov021_021B8250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of FIELD_RAIL_WORK_IsLocationValid. The first call adds a zero-valued local to off,
 * which gives the early multiply, the spilled offset and the
 * `adds r0,r3,#0` copy. `const Mgr *m` lets the base load schedule into the
 * struct copy (`ldr r7,[r6,#0x34]` between the stores to a).
 *
 * symbols:
 *   FIELD_RAIL_LINE_GetLength  0x021B9278  thumb  ov021
 *   FIELD_RAIL_LINE_GetWidthAt  0x021B9280  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg;
typedef struct Tbl { u16 f0; u16 f2; u8 pad4[0x10]; u8 *f14; } Tbl;

typedef struct Mgr {
    u8 pad00[0x20];
    Tbl tbl;
    u8 pad38[0x14];
    u32 f4C;
} Mgr;

extern int FIELD_RAIL_LINE_GetLength(u8 *a, u32 b, const Tbl *t);
extern int FIELD_RAIL_LINE_GetWidthAt(u8 *a, u32 arg2, u32 arg3, u8 *tbl);

void FIELD_RAIL_ClampLocation(const Mgr *m, const Arg *src, Arg *out)
{
    Arg a;
    u8 *base;
    s32 off;
    s32 x;
    s32 y;
    s32 v;
    s32 w;
    s32 pad;

    a = *src;
    base = m->tbl.f14;
    *out = a;
    off = a.h0 * 0x48;
    pad = 0;
    y = a.h6 << 4;
    x = a.h4 << 4;
    v = FIELD_RAIL_LINE_GetLength(base + (off + pad), m->f4C, &m->tbl);
    w = FIELD_RAIL_LINE_GetWidthAt(base + off, y, v, (u8 *)(&m->tbl));
    if (y >= v)
        out->h6 = (v - 1) / 16;
    if ((x < 0 ? -x : x) > w) {
        if (x > 0)
            out->h4 = w / 16;
        else
            out->h4 = -w / 16;
    }
}
