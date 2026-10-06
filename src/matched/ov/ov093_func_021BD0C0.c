/*
 * function: func_021BD0C0
 * address:  0x021BD0C0
 * packet:   pkt_ov093_021BD0C0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCA08  0x021BCA08  thumb  ov093
 *   func_021BCA50  0x021BCA50  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021BDE48  0x021BDE48  thumb  ov093
 *   func_021BD138  0x021BD138  thumb  ov093
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_021BCCE0  0x021BCCE0  thumb  ov093
 */
#include "../include/Obj09960.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021BCA08(u8 *p, u8 x);
extern u8 *func_021BCA50(u8 *p, u8 *cur, u32 x);
extern u32 func_021D8454(u8 *p);
struct Unk021BDE48;
extern u16 func_021BDE48(void *p, struct Unk021BDE48 *m);
extern int func_021BD138(u8 *p, u32 k);
struct Unk021D82FC;
extern void func_021D82FC(struct Unk021D82FC *p, int sub);
extern void func_021BCCE0(u8 *p, u8 *e);

int func_021BD0C0(u8 *p, u8 x, u32 y)
{
    u8 *e = func_021BCA08(p, x);
    if (e) {
        if (e[0xd] != 0 && func_021D8454(e + 4) == 6) {
            e = func_021BCA50(p, e, x);
        }
        if (e[0xd] == 0) {
            if (func_021BDE48(((struct Obj09960 *)e)->f0, (struct Unk021BDE48 *)(e + 4))) return 0;
            if (func_021D8454(e + 4) == 6) return 0;
            func_021D82FC((struct Unk021D82FC *)(e + 4), func_021BD138(p + 0x1ab8, y));
            func_021BCCE0(p, e);
            return 1;
        }
    }
    return 0;
}
