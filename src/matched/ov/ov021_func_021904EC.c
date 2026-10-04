/*
 * function: func_021904EC
 * address:  0x021904EC
 * packet:   pkt_ov021_021904EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Slot {
    u32 *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);

Slot *func_021904EC(u32 *p, u32 a, u32 b)
{
    Slot *e;
    int i;

    i = 0;
    e = (Slot *)((u8 *)p + 0x10);
    for (; i < 4; i++, e++) {
        if (e->f0c == 0) {
            e->f00 = p;
            e->f14 = b;
            e->f04 = 1;
            e->f08 = p[2];
            e->f0c = p[3];
            e->f18 = (u32)func_020457B0(0xa0, *(u16 *)p);
            e->f10 = a;
            e->f1c = b;
            e->f20 = 0;
            return e;
        }
    }
    return 0;
}
