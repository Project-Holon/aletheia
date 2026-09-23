/*
 * function: func_0204F044
 * address:  0x0204F044
 * packet:   pkt_0204F044
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0204EE0C  0x0204EE0C  arm
 *   func_0204EEC8  0x0204EEC8  arm
 *
 * billboard.c: take a free slot and fill it from caller-supplied texture
 * sizes, then hand it to func_0204EEC8.  The pure register residue of the
 * earlier notes (52 bytes, stride constant in ip instead of r0) was the
 * spelling of the two size fields: `(u32)(u16)f20 << 3` gives the same
 * instructions but a different allocation; the sibling func_0204EE64's
 * `(u32)(f20 << 16) >> 13` is what the image has.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 f00;
    u8  pad04[0xc - 4];
    u32 f0c;
    u32 f10;
    u8  pad14[0x20 - 0x14];
    u32 f20;
    u32 f24;
};

struct Board {
    u8           pad00[4];
    struct Slot *ptr0;
};

extern int  func_0204EE0C(struct Board *b, u32 *outIdx);
extern void func_0204EEC8(struct Slot *s, int a1, u32 a2, u8 a3, u8 a4);

int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6)
{
    u32 idx;

    if (func_0204EE0C(b, &idx) == 1) {
        b->ptr0[idx].f00 = 0;
        b->ptr0[idx].f20 = w;
        b->ptr0[idx].f24 = h;
        b->ptr0[idx].f0c = (u32)(b->ptr0[idx].f20 << 16) >> 13;
        b->ptr0[idx].f10 = (u32)(b->ptr0[idx].f24 << 16) >> 13;
        func_0204EEC8(&b->ptr0[idx], a3, a4, a5, a6);
    }
    return idx;
}
