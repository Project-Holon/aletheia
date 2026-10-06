/*
 * function: func_021CE2BC
 * address:  0x021CE2BC
 * packet:   pkt_ov021_021CE2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE8B0  0x021CE8B0  thumb  ov021
 *   func_021CE8F4  0x021CE8F4  thumb  ov021
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_021CE84C  0x021CE84C  thumb  ov021
 *   func_021CE78C  0x021CE78C  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;

extern void func_021CE8B0(u8 *p, u8 *e, int i);
extern void func_021CE8F4(u8 *p, u8 *e, int i);
extern void func_021CE934(u8 *p, u8 *e, int i);
extern int func_021CE84C(u32 *p, int n);
extern int func_021CE78C(u8 *p);
extern void func_021CE9E4(u8 *p, int n);

void func_021CE2BC(u8 *p)
{
    u8 *e;
    int i;
    int n;

    n = 0;
    i = 0;
    e = p + 0x50;
    for (; i < 4; i++) {
        if (p[0x70 + i * 0x2c]) {
            func_021CE8B0(p, e + i * 0x2c, i);
            n++;
        } else {
            func_021CE8F4(p, e + i * 0x2c, i);
        }
    }
    if (n == 0) {
        func_021CE934(p, p + 0x30, 0);
        n++;
    }
    if (*(s8 *)&((struct Obj00011 *)p)->f572 != n) {
        if (func_021CE84C((u32 *)p, n) == 1) {
            p[0x572] = n;
            if (p[0x520] == 1 && n == 1) {
                p[0x579] = 1;
            }
        }
    }
    if (p[0x579] == 1) {
        if (func_021CE78C(p) == 1 && ((struct Obj00011 *)p)->f130 == 0) {
            if (n == 1) {
                func_021CE9E4(p, 8);
            }
            p[0x579] = 0;
        }
    }
}
