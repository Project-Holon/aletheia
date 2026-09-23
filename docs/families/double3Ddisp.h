/*
 * docs/families/double3Ddisp.h -- the double3Ddisp.c family, from
 * 0x0204E8C0 (first reference to the __FILE__ string 0x020A7F94); ARM code.
 * The block below it is fade.c (string 0x020A7F8C, singleton 0x02146A7C).
 *
 * REFERENCE DOCUMENT ONLY; nothing includes it.  Written 2026-09-23 (wave 15
 * tail lane) from docs/notes/func_0204E914.c.txt and
 * src/pending/func_0204E8C0.c.  No member is EXACT yet: func_0204E8C0 is
 * byte-correct MATCH, blocked only on 0x0204E914 (one branch reference
 * image-wide), and 0x0204E914 is a 35-byte allocator residue (15 bytes
 * since wave 16: locals declared i, x, y, k, oam; the inner-loop oam
 * base is the rest, docs/notes/func_0204E914.c.txt).
 */

#ifndef DOUBLE3DDISP_H
#define DOUBLE3DDISP_H

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

/* One OAM entry, written as attr0|attr1 in one word plus attr2 as a
 * halfword; cleared as two words.  The union is what gives both. */
union OamEntry {
    u32 w[2];
    struct { u32 attr01; u16 attr2; u16 attr3; } f;
};

struct Double3Ddisp {
    u16 heap;
    u16 pad02;
    s32 unk04;
    s32 unk08;
    union OamEntry oam[12];      /* +0x0c: 4 x 3 grid of 64x64 sprites */
};

extern struct Double3Ddisp *g_02146A80;
extern void func_020862F0(void *p, u32 n);            /* cache flush */
extern void func_0207E708(void *p, u32 off, u32 n);   /* sub OAM load */

extern void func_0204E914(void);   /* build the 12 sprites, sub DISPCNT OBJ mode 0x20 */

#endif /* DOUBLE3DDISP_H */
