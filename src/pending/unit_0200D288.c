/*
 * Byte-correct but MATCH-capped; see src/pending/README.md.
 *
 * unit:     yes
 * address:  0x0200D288
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_0200D288, func_0200D298, func_0200D2B0, func_0200D2C4,
 *           func_0200D2D8, func_0200D310
 *
 * 224 bytes, 0x0200D288..0x0200D368, 6 functions, four of which carry a label
 * in the generated listing.  Every concrete byte reproduces.
 *
 * Two sites keep it at MATCH and neither is reachable by a cut:
 *
 *   0x0200C780  reached only from 0x0200D2F4, inside func_0200D2D8
 *   0x0200D368  reached only from 0x0200D2C6, inside func_0200D2C4
 *
 * The second of those is the price of the cut that saved
 * src/matched/unit_0200D368.c: func_0200C7A0 has exactly two callers in the
 * image, one here and one there, so the two had to be separated, and once
 * func_0200D368 is outside this range its own single caller cannot attest it.
 * Both close the day the image acquires a second caller for either address.
 *
 * func_0200D288 is a two-arm accessor with no prologue, so the listing prints
 * it as data; it answers the word at +0x4D0 for selector 0 and nothing
 * otherwise.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

extern u32   func_0200C780(u16 id);
extern u32   func_0200C7A0(u16 id);
extern u32   func_0200CED4(struct Blk37 *p, u16 id);
extern u32   func_0200D064(struct Blk37 *p, u16 id);
extern u16  *func_0201AF80(u32 heap, u32 a);
extern void  func_020307B0(void *p);

u16 func_0200D2D8(struct Blk37 *p);
u16 func_0200D310(struct Blk37 *p, u32 heap);
u16 func_0200D368(struct Blk37 *p, u32 heap);

u16 func_0200D368(struct Blk37 *p, u32 heap);

u32 func_0200D288(struct Blk37 *p, u32 i)
{
    if (i == 0) {
        return p->unk4D0;
    }
    return 0;
}

u32 func_0200D298(struct Blk37 *p)
{
    if (func_0200D2D8(p) >= 0x27A) {
        return 1;
    }
    return 0;
}

u32 func_0200D2B0(struct Blk37 *p, u32 heap)
{
    if (func_0200D310(p, heap) >= 0x96) {
        return 1;
    }
    return 0;
}

u32 func_0200D2C4(struct Blk37 *p, u32 heap)
{
    if (func_0200D368(p, heap) >= 0x96) {
        return 1;
    }
    return 0;
}

u16 func_0200D2D8(struct Blk37 *p)
{
    s32 i;
    u16 n;

    n = 0;
    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(p, (u16)i) == 1 && func_0200C780((u16)i) == 1) {
            n = (u16)(n + 1);
        }
    }
    return n;
}

u16 func_0200D310(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = func_0201AF80(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(p, i) == 1 && t[i] != 0x3E7 && func_0200C7A0(i) == 1) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}

