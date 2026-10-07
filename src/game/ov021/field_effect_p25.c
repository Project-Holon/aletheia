/*
 * file:     field_effect_p25.c
 * unit:     yes
 * function: func_021AB070, func_021AB0AC, func_021AB0D4, func_021AB0F0, func_021AB0F8, func_021AB100, func_021AB11C, func_021AB140, func_021AB158, func_021AB164, func_021AB170, func_021AB17C, func_021AB188, func_021AB194, func_021AB1A0, func_021AB1AC, func_021AB1B8, func_021AB1C4, func_021AB1D0, func_021AB1DC, func_021AB1E8, func_021AB1F4, func_021AB200, func_021AB20C, func_021AB218, func_021AB224, func_021AB230, func_021AB23C, func_021AB250, func_021AB264, func_021AB270, func_021AB27C
 * address:  0x021AB070
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
 *   func_02005728  0x02005728  thumb
 *   _u32_div_f  0x0209C2B0  arm
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb
 *   func_0218DAEC  0x0218DAEC  thumb
 */
typedef unsigned short u16;

typedef unsigned int u32_021AB070;

typedef unsigned int u32_021AB0AC;

typedef struct {
    char pad[0x5bc];
    u16 h5bc;
} D;

typedef struct {
    u32_021AB0AC f0;
    void *f4;
    int pad[2];
    D *f10;
} S;

typedef unsigned char  u8;

typedef unsigned int   u32_021AB0D4;

typedef signed short   s16;

typedef unsigned long u32_021AB0F0;

typedef unsigned long u32_021AB0F8;

typedef int BOOL;

typedef unsigned long u32_021AB100;

typedef unsigned long u32_021AB11C;

typedef unsigned int   u32_021AB140;

typedef signed char    s8;

typedef signed int     s32;

typedef unsigned long u32_021AB158;

typedef unsigned long u32_021AB164;

typedef unsigned long u32_021AB170;

typedef unsigned long u32_021AB17C;

typedef unsigned long u32_021AB188;

typedef unsigned long u32_021AB194;

typedef unsigned long u32_021AB23C;

typedef unsigned long u32_021AB250;

typedef unsigned long u32_021AB264;

typedef unsigned long u32_021AB270;

typedef unsigned long u32_021AB27C;

extern u32_021AB070 func_02005728(u32_021AB070 n);
extern u16 func_02188C84(u8 *p);
extern int func_02158768(void *a0, u32_021AB0AC a1, int a2, u16 a3);
extern int func_0218DAEC(void *a, void *b, u32_021AB0D4 *out);
u16 func_021AB070(void);
void func_021AB0AC(S *s, u16 v);
int func_021AB0D4(void *a, void *b);
u16 func_021AB0F0(u32_021AB0F0 attr);
u16 func_021AB0F8(u32_021AB0F8 attr);
BOOL func_021AB100(u32_021AB100 attr);
BOOL func_021AB11C(u32_021AB11C attr);
int func_021AB140(int x);
BOOL func_021AB158(u16 id);
BOOL func_021AB164(u16 id);
BOOL func_021AB170(u16 id);
BOOL func_021AB17C(u16 id);
BOOL func_021AB188(u16 id);
BOOL func_021AB194(u16 id);
int func_021AB1A0(int x);
BOOL sub_021AB1AC(u16 id);
BOOL sub_021AB1B8(u16 id);
BOOL sub_021AB1C4(u16 id);
BOOL sub_021AB1D0(u16 id);
BOOL sub_021AB1DC(u16 id);
BOOL sub_021AB1E8(u16 id);
BOOL sub_021AB1F4(u16 id);
BOOL sub_021AB200(u16 id);
BOOL sub_021AB20C(u16 id);
BOOL sub_021AB218(u16 id);
BOOL sub_021AB224(u16 id);
BOOL sub_021AB230(u16 id);
BOOL func_021AB23C(u16 id);
BOOL func_021AB250(u16 id);
BOOL func_021AB264(u16 id);
BOOL func_021AB270(u16 id);
BOOL func_021AB27C(u16 id);


u16 func_021AB070(void)
{
    if ((u16)func_02005728(1000) < 900) {
        return (u16)(func_02005728(600) / 100) + 565;
    }
    return 571;
}


void func_021AB0AC(S *s, u16 v)
{
    s->f10->h5bc = v;
    func_02158768(s->f4, 0x2795, 0, func_02188C84((u8 *)s->f0));
}


/*
 * Runs the lookup func_0218DAEC into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB0D4(void *a, void *b)
{
    u32_021AB0D4 buf[4];

    if (func_0218DAEC(a, b, buf) == 1)
        return buf[2];
    return -1;
}


/*
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * func_021D14C4, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; func_021AB0F8 is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */
u16 func_021AB0F0(u32_021AB0F0 attr)
{
    return (u16)attr;
}




/*
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (func_021AB11C), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in func_021AB504.
 */
u16 func_021AB0F8(u32_021AB0F8 attr)
{
    return (u16)(attr >> 16);
}



/*
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 */
BOOL func_021AB100(u32_021AB100 attr)
{
    u16 id;

    id = func_021AB0F0(attr);

    if (attr == 0xFFFFFFFF || id == 0xFF) {
        return 0;
    }

    return 1;
}



/*
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (func_021AB100) or when bit 0 of the flag half is set.
 */
BOOL func_021AB11C(u32_021AB11C attr)
{
    u16 flags;

    flags = func_021AB0F8(attr);

    if (!func_021AB100(attr) || (flags & 1)) {
        return 1;
    }

    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021AB140(int x)
{
    if ((u16)(x + 0xFFF8) <= 1)
        return 1;
    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x74.
 */
BOOL func_021AB158(u16 id)
{
    if (id == 0x74) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x75.
 */
BOOL func_021AB164(u16 id)
{
    if (id == 0x75) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x73.
 */
BOOL func_021AB170(u16 id)
{
    if (id == 0x73) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x72.
 */
BOOL func_021AB17C(u16 id)
{
    if (id == 0x72) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x7c.
 */
BOOL func_021AB188(u16 id)
{
    if (id == 0x7c) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0xd4.
 */
BOOL func_021AB194(u16 id)
{
    if (id == 0xd4) {
        return 1;
    }

    return 0;
}

int func_021AB1A0(int x)
{
    return x == 0xD6;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1AC(u16 id)
{
    if (id == 0xd7) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd8.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1B8(u16 id)
{
    if (id == 0xd8) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe2.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1C4(u16 id)
{
    if (id == 0xe2) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xd9.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1D0(u16 id)
{
    if (id == 0xd9) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xda.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1DC(u16 id)
{
    if (id == 0xda) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdb.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1E8(u16 id)
{
    if (id == 0xdb) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdc.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB1F4(u16 id)
{
    if (id == 0xdc) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdd.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB200(u16 id)
{
    if (id == 0xdd) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xde.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB20C(u16 id)
{
    if (id == 0xde) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xdf.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB218(u16 id)
{
    if (id == 0xdf) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe0.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB224(u16 id)
{
    if (id == 0xe0) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for id 0xe1.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL sub_021AB230(u16 id)
{
    if (id == 0xe1) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x4, 0x21, 0x5.
 */
BOOL func_021AB23C(u16 id)
{
    if (id == 0x4 || id == 0x21 || id == 0x5) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x6, 0x22, 0x7.
 */
BOOL func_021AB250(u16 id)
{
    if (id == 0x6 || id == 0x22 || id == 0x7) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x8.
 */
BOOL func_021AB264(u16 id)
{
    if (id == 0x8) {
        return 1;
    }

    return 0;
}


/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for id 0x9.
 */
BOOL func_021AB270(u16 id)
{
    if (id == 0x9) {
        return 1;
    }

    return 0;
}



/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL func_021AB27C(u16 id)
{
    if (func_021AB23C(id) == 1 || func_021AB264(id) == 1) {
        return 1;
    }

    return 0;
}
