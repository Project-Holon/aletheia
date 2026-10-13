/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D368
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200D368, func_0200D3C0
 *
 * 172 bytes, 0x0200D368..0x0200D414, 2 functions, one of which carries a label
 * in the generated listing.
 *
 * The tail of the save block with id 0x37, whose head is
 * src/matched/unit_0200C9EC.c.  func_0200D368 counts the species this block
 * records as seen that the id table has an entry for and that func_0200C7A0
 * accepts; func_0200D3C0 reads a bit out of the flat 0x1B0-byte bitmap at
 * +0x320, indexed by `(b - 1) + (a - 1) * 7` over a range of 0x1ED rows.
 *
 * func_0200D3C0 saves `r4` without saving `lr`, so `disasm.py` does not label
 * it and it arrives in the listing as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Its second selector is rejected above 8 and at exactly 6, and then
 * decremented above 6, so the seven live values 1..5, 7, 8 map onto 0..6; the
 * hole at 6 and the shift around it are in the original and are what the two
 * compares and the `subs` encode.
 *
 * This range starts at 0x0200D368 rather than at the head of the group because
 * func_0200C7A0 is reached from exactly two places in the image, 0x0200D33A in
 * func_0200D310 and 0x0200D392 here, so a range holding both has no witness
 * left for it.  Cut between them and this half closes.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The other
 * half does not close, because func_0200C780 is reached only from
 * func_0200D2D8; it is parked in src/pending/unit_0200D288.c.
 *
 * Near miss in the same original file: func_0200D144, 322 bytes at
 * 0x0200D144, the five-way reader over the same bitmaps.  It reaches the right
 * size and the right control flow, and sixteen bytes in its last arm differ in
 * register numbers alone: the original keeps the shifted id in one register and
 * masks it into a scratch, and mwccarm masks in place and allocates the bit and
 * the loaded byte the other way round.  Adding a named local for the mask
 * fixes the arm before it, which is where the original also spends a register
 * copy, and adding one here costs an instruction the original does not have;
 * all 120 permutations of the five locals and every spelling of the two
 * operands rank flat at sixteen.
 *
 * symbols:
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
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

extern int func_0200C780(u32 v);
extern int func_0200C7A0(u32 v);
extern u32   func_0200CED4(struct Blk37 *p, u16 id);
extern u32   func_0200D064(struct Blk37 *p, u16 id);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);

u16 func_0200D2D8(void *a0);
int func_0200D310(void *a0, int a1);
u16 func_0200D368(struct Blk37 *p, u32 heap);

u16 func_0200D368(struct Blk37 *p, u32 heap);

u16 func_0200D368(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (func_0200D064(p, i) == 1 && t[i] != 0x3E7 && func_0200C7A0(i) == 1) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}

u32 func_0200D3C0(struct Blk37 *p, u32 a, u32 b)
{
    s32 x;
    u32 r;

    if (b > 8 || b == 6) {
        return 0;
    }
    if (a > 0x1ED) {
        return 0;
    }
    if (b >= 7) {
        b--;
    }
    a--;
    x = (u16)((b - 1) + a * 7);
    r = 1;
    if ((p->unk320[x >> 3] & (1 << (x & 7))) == 0) {
        r = 0;
    }
    return r;
}
