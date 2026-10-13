/*
 * function: func_02175598
 * address:  0x02175598
 * packet:   pkt_ov011_02175598
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008550  0x02008550  thumb
 *   func_02175548  0x02175548  thumb  ov011
 *   INTRUDE_COMM_IsValidObjCode  0x021756B0  thumb  ov011
 */
#include "../include/Obj07332.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3);
extern int INTRUDE_COMM_IsValidObjCode(int value);

u16 func_02175598(u8 *o, u32 id)
{
    struct { u8 x; u8 y; u16 c; } s;
    u16 h;

    h = ((struct Obj07332 *)o)->f18;
    if (h == 0) {
        if (o[0x12] == 1) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 2 : 5;
        } else {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 1 : 4;
        }
    } else if (h == 0xFFFF) {
        func_02175548(id, &s.c, &s.y, &s.x);
    } else {
        s.c = h;
        if (INTRUDE_COMM_IsValidObjCode(s.c) == 0) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 10 : 14;
        }
    }
    if ((s.c >= 0xdf && s.c < 0x1000) || s.c >= 0x1236) {
        s.c = 10;
    }
    return s.c;
}
