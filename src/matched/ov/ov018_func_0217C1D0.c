/*
 * function: INTRUDE_FIELD_AddSymbolMonMmdl
 * address:  0x0217C1D0
 * packet:   pkt_ov018_0217C1D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   func_0202A188  0x0202A188  thumb
 *   INTRUDE_FIELD_gSymbolMonMoveParams     0x0218360C  data   a4
 *   INTRUDE_FIELD_gSymbolMonMmdlHeader     0x0218362C  data   a4
 */
#include "../include/Obj12484.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    u16 h[14];
    T t;
} S;

typedef struct {
    u32 x : 11;
    u32 gap : 10;
    u32 y : 2;
    u32 z : 6;
    u32 e : 3;
} B;

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
} O;

extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FLDMMDL_AddMmdl(int a, int b, int c);
extern u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3);
extern const E INTRUDE_FIELD_gSymbolMonMoveParams[];
extern const S INTRUDE_FIELD_gSymbolMonMmdlHeader;

void INTRUDE_FIELD_AddSymbolMonMmdl(const O *o, const B *p, u16 a2, u16 a3, T x)
{
    const E *e;
    int v;
    u16 c;
    S s;
    T *t;

    e = &INTRUDE_FIELD_gSymbolMonMoveParams[p->e];
    v = (int)FIELDMAP_GetMmdlSys((u8 *)o->f4);
    c = FIELDMAP_GetZoneId((u8 *)o->f4);
    s = INTRUDE_FIELD_gSymbolMonMmdlHeader;
    s.h[0] = a2;
    s.h[1] = func_0202A188((u8 *)o->f0, (u16)p->x, (u16)p->y, (u16)p->z);
    s.h[2] = e->h0;
    s.h[10] = e->b2;
    s.h[11] = e->b3;
    s.h[7] = o->f8 + a2;
    s.h[8] = ((struct Obj12484 *)p)->f0;
    s.h[9] = ((struct Obj12484 *)p)->f0 >> 16;
    t = &s.t;
    t->h0 = a3;
    t->h2 = x.h0;
    t->w4 = x.w4;
    FLDMMDL_AddMmdl(v, (int)(&s), c);
}
