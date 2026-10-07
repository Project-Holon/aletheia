/*
 * file:     fld_trade_p11.c
 * unit:     yes
 * function: func_021CE2BC, func_021CE36C, func_021CE3D8
 * address:  0x021CE2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CE8B0  0x021CE8B0  thumb  ov021
 *   func_021CE8F4  0x021CE8F4  thumb  ov021
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_021CE84C  0x021CE84C  thumb  ov021
 *   func_021CE78C  0x021CE78C  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_021CE3E8  0x021CE3E8  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"

typedef unsigned char u8;

typedef signed char   s8;

typedef unsigned int  u32;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry;

typedef struct {
    u8 pad0[0x70];
    Entry ent[4];
} Mgr;

extern void func_021CE8B0(u8 *p, u8 *e, int i);
extern void func_021CE8F4(u8 *p, u8 *e, int i);
extern void func_021CE934(u8 *p, u8 *e, int i);
extern int func_021CE84C(u32 *p, int n);
extern int func_021CE78C(u32 a);
extern void func_021CE9E4(u8 *p, int n);
extern int func_021CE3E8(u8 *p, u8 *e);
void func_021CE2BC(u8 *p);
void func_021CE36C(u8 *p);
void func_021CE3D8(Mgr *m, int i);


/*
 * Addresses are Black-image addresses.
 */
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
        if (func_021CE78C((u32)p) == 1 && ((struct Obj00011 *)p)->f130 == 0) {
            if (n == 1) {
                func_021CE9E4(p, 8);
            }
            p[0x579] = 0;
        }
    }
}


void func_021CE36C(u8 *p)
{
    u8 *e;
    u8 j;

    e = p + 0x50;
    for (j = 0; j < 4; j++, e += 0x2c) {
        switch (e[0x20]) {
        case 1:
            if (e[0x21] == 1) {
                e[0x20] = 4;
                p[0x521] |= 1 << j;
            } else {
                e[0x20] = 2;
            }
            break;
        case 2:
            if (func_021CE3E8(p, e) == 1) {
                e[0x20] = 3;
            }
            break;
        }
    }
}


/*
 * Clears the state byte of entry i of the four 0x2C-byte entries at +0x70.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE3D8(Mgr *m, int i)
{
    m->ent[i].state = 0;
}
