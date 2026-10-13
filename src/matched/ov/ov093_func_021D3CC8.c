/*
 * function: func_021D3CC8
 * address: 0x021D3CC8
 * packet: pkt_ov093_021D3CC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: const source pointer restores the five-load acquisition order.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * Record byte 7 is uninitialized padding, preserved as in the listing.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_AddHitRecord 0x021D6848 thumb ov093
 */
#include "../include/Obj21201.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Rec { u16 a, b; u8 c, d, e; };
struct HalfRec { u16 a, b, c, d; };
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_AddHitRecord(u8 *p, struct Rec *r);
int func_021D3CC8(char *p, int unused, const unsigned int *a)
{
    struct Rec r;
    u8 *obj;
    u16 x, y;
    u8 z, w, v;
    obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21201 *)p)->f4, (u8)a[0]);
    x = a[4]; y = a[5]; z = a[3]; w = a[2]; v = a[1];
    r.a = x; r.b = y; r.c = z; r.d = v; r.e = w;
    BTL_POKEPARAM_AddHitRecord(obj, (struct Rec *)((struct HalfRec *)&r));
    return 1;
}
