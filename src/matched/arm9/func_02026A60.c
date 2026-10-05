/*
 * function: func_02026A60
 * address:  0x02026A60
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The duplicate/accept scan over the receive ring.  Closed 2026-09-23 by
 * writing the ring walk as the plain two-case shape: `if (lo <= hi)` one
 * loop over lo..hi, `else` a loop over lo..29 THEN a loop over 0..hi, each
 * hit doing `hit = 1; break;`.  The compiler itself cross-jumps loop 3's hit
 * block into loop 1's (both continue at the tail) and keeps loop 2's, whose
 * break lands on loop 3's `i = 0`; the earlier goto/label construction in
 * docs/notes/func_02026A60.c.txt only imitated that and left a duplicated
 * `blt`.  EXACT* because the follower at 0x02026BFC has no label.
 *
 * symbols:
 *   g_GameBeacon  0x02146940  data
 */
#include "../include/Obj00747.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8   pad00[0x60];
};

struct Payload {
    u32 w[23];
};

struct Req {
    u8   f00;
    u8   pad01[8 - 1];
    u32  f08;
    u8   pad0C[0x10 - 0x0C];
    u16  f10;
    u8   pad12[0x30 - 0x12];
    u16  f30;
    u8   pad32[0x3C - 0x32];
    u32  f3C;
    u8   pad40[0x46 - 0x40];
    u16  f46;
};

extern u8 *g_GameBeacon;
extern void func_0202685C(u8 *base, struct Req *r);
int func_02026A60(struct Req *r)
{
    u8 *base = g_GameBeacon;
    int hit = 0;
    int i;
    u16 kind;
    signed char hi;
    signed char lo;

    if ((r->f00 & 2) == 0) {
        return hit;
    }

    kind = r->f30;
    if (kind == 0 || kind >= 0x33) {
        return 0;
    }

    if (kind == 0x18) {
        if (((struct Obj00747 *)base)->f14 != r->f46) {
            return hit;
        }
    }

    hi = ((struct Obj00747 *)base)->fBAD;
    lo = ((struct Obj00747 *)base)->fBAC;

    if (lo <= hi) {
        for (i = lo; i <= hi; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    } else {
        for (i = lo; i < 0x1e; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
        for (i = 0; i <= hi; i++) {
            if (r->f10 == *(u16 *)(base + i * 0x60 + 0x74)) {
                if (kind == 1 ||
                    ((r->f08 << 10) >> 27) == ((*(u32 *)(base + i * 0x60 + 0x6c) << 10) >> 27)) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    }

    if (kind == 0x19) {
        if (r->f3C != 0x2932013A) return 0;
    } else if (kind == 0x1A) {
        if (r->f3C != 0x48841DC1) return 0;
    } else if (kind == 0x1B) {
        if (r->f3C != 0x701DDC92) return 0;
    } else if (kind == 0x32) {
        if (r->f3C != 0xFEE48201) return 0;
    }

    if (hit == 1) {
        u32 off = i * 0x60;
        *(struct Payload *)(base + off + 0x64) = *(struct Payload *)r;
        *(u16 *)(base + off + 0xC0) = 0;
        ((struct Obj00747 *)base)->fBA4 |= (u32)(1 << i);
    } else {
        func_0202685C(base, r);
        ((struct Obj00747 *)base)->fBA8 = ((struct Obj00747 *)base)->fBA8 + 1;
    }
    return 1;
}
