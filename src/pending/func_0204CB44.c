/*
 * function: func_0204CB44
 * address:  0x0204CB44
 * packet:   pkt_0204CB44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 108 concrete bytes
 * are right, but every one of the six callees has exactly one branch
 * reference image-wide and it is the call in this function, so none of the
 * six can be witnessed and no cut frees any of them:
 *
 *   func_02066748  0x02066748   12 bytes
 *   func_02065BD0  0x02065BD0  168 bytes
 *   func_0204CBB0  0x0204CBB0  188 bytes
 *   func_0204BA7C  0x0204BA7C  112 bytes
 *   func_0204CC6C  0x0204CC6C  584 bytes (multi-function extent)
 *   func_02065C78  0x02065C78  108 bytes
 *
 * Reaching EXACT here therefore needs all six decompiled to EXACT first,
 * roughly 1.2 KB of ARM code.  This function is itself the sole blocker for
 * src/pending/func_0204C944.c, which is the sole blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for src/pending/func_0204BB8C.c:
 * the chain is three deep and widens to six at this level.
 *
 * Per-element teardown.  Guarded by bit 26 of the flag word at +0x60; the
 * two values handed to func_0204BA7C are bits 12-15 (narrowed to u8, which
 * is what the otherwise redundant `and r1, r1, #0xff` after the shift pair
 * records) and bit 31 of the same word, read through one load.
 *
 * symbols:
 *   func_02066748  0x02066748  arm
 *   func_02065BD0  0x02065BD0  arm
 *   func_0204CBB0  0x0204CBB0  arm
 *   func_0204BA7C  0x0204BA7C  arm
 *   func_0204CC6C  0x0204CC6C  arm
 *   func_02065C78  0x02065C78  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204CB44.c \
 *       --func func_0204CB44 --addr 0x0204CB44 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Elem {
    u8  pad00[0x1c]; /* 0x00 */
    u8  unk1c[0x24]; /* 0x1c */
    u8  unk40[0x20]; /* 0x40 */
    u32 pad60_0 : 12;
    u32 unk60_c : 4;  /* 0x60, bits 12-15 */
    u32 pad60_1 : 10;
    u32 enabled : 1;  /* 0x60, bit 26 */
    u32 pad60_2 : 4;
    u32 unk60_1f : 1; /* 0x60, bit 31 */
};

extern void func_02066748(u32 arg, void *a, void *b);
extern void func_02065BD0(u32 arg);
extern void func_0204CBB0(struct Elem *e, u32 arg);
extern void func_0204BA7C(void *a, u8 b, u32 c);
extern u32  func_0204CC6C(struct Elem *e);
extern void func_02065C78(u32 a);

void func_0204CB44(struct Elem *e, u32 arg)
{
    if (e->enabled == 0)
        return;

    func_02066748(arg, e->unk1c, e->unk40);
    func_02065BD0(arg);
    func_0204CBB0(e, arg);
    func_0204BA7C(e->unk40, (u8)e->unk60_c, e->unk60_1f);
    func_02065C78(func_0204CC6C(e));
}
