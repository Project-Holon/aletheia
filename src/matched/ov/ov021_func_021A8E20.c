/*
 * function: func_021A8E20
 * address:  0x021A8E20
 * packet:   pkt_ov021_021A8E20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021A9080  0x021A9080  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[0xC];
    struct Slot slots[7];
};

extern void func_021A9080(struct W *w, u32 a, u32 b);

void func_021A8E20(struct W *w, u32 v)
{
    u8 i;
    struct Slot *s;

    for (i = 0, s = w->slots; i < 7; i++) {
        if (w->slots[i].f00 == 1 && v == w->slots[i].f08) {
            w->f1E = i % 2;
            w->f1F = i / 2;
            w->f24 = 1;
            func_021A9080(w, s[w->f1E + w->f1F * 2].f14,
                          s[w->f1E + w->f1F * 2].f15);
        }
    }
}
