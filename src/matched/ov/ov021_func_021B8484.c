/*
 * function: FIELD_RAIL_WORK_SetLineLocation
 * address:  0x021B8484
 * packet:   pkt_ov021_021B8484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb  ov021
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_GetSpotPos  0x021B91F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03135.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c, d; } Q;
typedef struct { int x, y, z; } V;

void FIELD_RAIL_WORK_GetLocation(u8 *p, Q *q);
void FIELD_RAIL_WORK_SetLocation(u8 *p, Q *q);
void FIELD_RAIL_WORK_GetSpotPos(u8 *p, V *v);

void FIELD_RAIL_WORK_SetLineLocation(u8 *p, u32 a, u32 b, int c)
{
    Q q;

    FIELD_RAIL_WORK_GetLocation(p, &q);
    q.a = a;
    q.c = 0;
    q.d = b;
    FIELD_RAIL_WORK_SetLocation(p, &q);
    q.c = c - ((struct Obj03135 *)p)->f18 / 16;
    FIELD_RAIL_WORK_GetSpotPos(p, (V *)(p + 0x38));
    ((struct Obj03135 *)p)->f5C = q.a;
    ((struct Obj03135 *)p)->f5E = q.b;
    ((struct Obj03135 *)p)->f60 = q.c;
    ((struct Obj03135 *)p)->f62 = q.d;
    ((struct Obj03135 *)p)->f64 = q.a;
    ((struct Obj03135 *)p)->f66 = q.b;
    ((struct Obj03135 *)p)->f68 = q.c;
    ((struct Obj03135 *)p)->f6A = q.d;
    *(V *)(p + 0x44) = *(V *)(p + 0x38);
}
