/*
 * function: func_0204F428
 * address:  0x0204F428
 * packet:   pkt_0204F428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * billboard.c: allocate a free 0x1c-byte element (id field 0x3FFF = free)
 * and initialise it.  Every earlier residue came from spelling the two
 * packed halfwords as hand masks; the source is plain bitfield assignment
 * (14/2 at +0x00, 5/4/1/1/1/4 at +0x18), in the image's store order.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Vec3 { s32 a, b, c; };

struct Elem {
    u16 id   : 14;
    u16 mode : 2;
    u16 f02;
    struct Vec3 f04;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 k    : 5;
    u16 b5   : 4;
    u16 b9   : 1;
    u16 b10  : 1;
    u16 b11  : 1;
    u16 w    : 4;
    u16 f1a;
};

struct Board {
    u8 pad00[8];
    struct Elem *ptr1;
    u16 count0;
    u16 count1;
};

s32 func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode)
{
    s32 i;

    for (i = 0; i < b->count1; i++) {
        if (b->ptr1[i].id == 0x3FFF) {
            b->ptr1[i].id = (u16)id;
            b->ptr1[i].mode = (u16)mode;
            b->ptr1[i].f12 = v12;
            b->ptr1[i].f14 = v14;
            b->ptr1[i].f16 = 0;
            b->ptr1[i].f04 = *src;
            b->ptr1[i].k = k;
            b->ptr1[i].b5 = 0;
            b->ptr1[i].b9 = 0;
            b->ptr1[i].w = (u16)w;
            b->ptr1[i].b10 = 0;
            b->ptr1[i].b11 = 0;
            b->ptr1[i].f10 = 0;
            return i;
        }
    }
    return 0;
}

