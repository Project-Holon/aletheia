/*
 * function: EFFECT_ENCOUNT_CollectCandidates
 * address:  0x021AACD4
 * packet:   pkt_ov021_021AACD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_G3D_MAPPER_GetFocusSlot  0x0218D168  thumb  ov021
 *   FIELD_G3D_MAPPER_CheckSlotReady  0x0218DBD4  thumb  ov021
 *   EFFECT_ENCOUNT_MakeSearchArea  0x021AABF4  thumb  ov021
 *   _s32_to_float  0x0209BDBC  arm
 *   __fadd  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   FIELD_G3D_MAPPER_QuerySlotPlane  0x0218DBAC  thumb  ov021
 *   MAP_ATTR_GetEncounterEffectKind  0x021AB504  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct Vec { int x, y, z; } Vec;

struct Area {
    s16 x;
    s16 y;
    s16 mx;
    s16 my;
    s16 bx;
    s16 by;
    u16 ox;
    u16 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
};

struct Cell {
    u8 pad00[8];
    u32 f08;
    u32 f0C;
};

struct Spot {
    u8 kind;
    u8 pad01;
    s16 x;
    u8 pad04[2];
    u16 y;
    u32 f08;
};

struct Enc {
    u8 pad00[4];
    u16 count;
    u8 pad06[2];
    struct Spot spots[121];
};

extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern int FIELD_G3D_MAPPER_GetFocusSlot(char *p);
extern int FIELD_G3D_MAPPER_CheckSlotReady(char *p, int i);
struct Ctx;
extern void EFFECT_ENCOUNT_MakeSearchArea(struct Ctx *ctx, void *unused, struct Area *a);
extern int _s32_to_float(int a);
extern int __fadd(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int FIELD_G3D_MAPPER_QuerySlotPlane(u8 *a, int idx, u32 c, u8 *d);
extern int MAP_ATTR_GetEncounterEffectKind(u32 attr);

void EFFECT_ENCOUNT_CollectCandidates(void **ctx, struct Enc *e)
{
    Vec v;
    struct Area a;
    struct Cell c;
    int idx;
    int xs;
    s16 y;
    s16 x;
    u32 m;
    int r;
    int k;

    m = FIELDMAP_GetG3dMapper(ctx[0]);
    MI_CpuFill8(&e->count, 0, 0x5B0);
    v.y = 0;
    idx = FIELD_G3D_MAPPER_GetFocusSlot((char *)m);
    if (FIELD_G3D_MAPPER_CheckSlotReady((char *)m, idx) == 0)
        return;
    EFFECT_ENCOUNT_MakeSearchArea((struct Ctx *)ctx, e, &a);
    y = a.y0;
    if ((y << 4) > 0)
        r = __fadd(0x3f000000, _s32_to_float(y << 16));
    else
        r = func_0209CB8C(_s32_to_float(y << 16), 0x3f000000);
    v.z = func_0209C494(r) + 0x8000;
    if ((a.x0 << 4) > 0)
        r = __fadd(0x3f000000, _s32_to_float(a.x0 << 16));
    else
        r = func_0209CB8C(_s32_to_float(a.x0 << 16), 0x3f000000);
    xs = func_0209C494(r) + 0x8000;
    for (; y <= a.y1; y++) {
        v.x = xs;
        for (x = a.x0; x <= a.x1; x++) {
            FIELD_G3D_MAPPER_QuerySlotPlane((u8 *)m, idx, (u32)(&v), (u8 *)(&c));
            k = MAP_ATTR_GetEncounterEffectKind(c.f08);
            if (k != 8) {
                e->spots[e->count].kind = k;
                e->spots[e->count].x = x;
                e->spots[e->count].y = y;
                e->spots[e->count++].f08 = c.f0C;
            }
            v.x += 0x10000;
        }
        v.z += 0x10000;
    }
}
