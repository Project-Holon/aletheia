/*
 * file:     musical_dist_save.c
 * unit:     yes
 * function: func_0200C52C, func_0200C5A4, func_0200C5C8, func_0200C5F8, func_0200C6E4, func_0200C6F0, func_0200C720, func_0200C738, func_0200C780, func_0200C7A0
 * address:  0x0200C52C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   g_020A71D4     0x020A71D4  data  a1
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204913C  0x0204913C  arm
 *   func_0204A39C  0x0204A39C  arm
 *   func_02045C44  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02049238  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_0209DE2C      0x0209DE2C  data
 *   g_0209DE20      0x0209DE20  data
 */
struct Big;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;
struct MsgBank;
struct Rec;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct DistHdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct MusicalDist {
    u16 unk00;
    u32 unk04;
    u32 unk08;
    struct DistHdr unk0C;
    void *unk1C;
    void *unk20;
    u8   *unk24;
    void *unk28;
};

typedef signed int     s32;

struct Blk2C {
    u8   unk00[0x20];
    u32 *unk20;
    u32  unk24;
    u32  unk28;
};

struct Buf2000 {
    u8 unk0000[0x1FE0];
    u8 unk1FE0[0x20];
};

extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_020072CC(void *sv, u32 id, u32 heap, void *buf, u32 size);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern u32 func_020307B0(void *p);
extern void func_02012E4C(u8 *p, u32 id);
extern int func_02012E7C(char *p, int a1);
extern void *func_0200A5F8(void *save);
extern void func_0200A7EC(struct Big *p, u8 value);
extern u8 *func_0200A7F8(struct Big *p);
extern void *func_0204913C(void *a0, u32 a1, u32 heap);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  func_02045A38(struct U16Vec *a, u16 *b, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern void  func_02049238(void *a);
extern void func_0200C5A4(struct MusicalDist *p);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
struct MusicalDist *func_0200C52C(void *sys, u32 heap);
u32 func_0200C6D8(struct Blk2C *p);
void func_0200C6EC(void);
void func_0200C738(u8 *p, u32 a1, u32 a2);
int func_0200C780(u32 v);
int func_0200C7A0(u32 v);
extern const char g_020A71D4[];
extern u16 g_0209DE2C[];
extern u16 g_0209DE20[];


/*
 * musical_dist_save.c constructor: allocate the 0x2C-byte control block and
 * a 0x20000-byte buffer, load save block 6 into the buffer through the save
 * system, record heap/system, then attach the loaded block.
 *
 * Closed in wave 15.  The residue since wave 11 (image homes sys to the
 * stack and keeps sv in r6 and the id 6 in r7; every earlier shape did the
 * reverse) was not an allocation tie: the func_020073D8 call is written in
 * BOTH arms of the `r == 1` test and the compiler tail-merges the two
 * copies.  The merged call is what keeps 6 live in a callee-saved register
 * and lets the shared zero land in r2 as the third argument.
 */
struct MusicalDist *func_0200C52C(void *sys, u32 heap)
{
    void *sv;
    struct MusicalDist *p;
    u32 r;
    u8 *z;

    sv = func_02012EBC(sys);
    p = func_02030734(heap, 0x2C, 1, g_020A71D4, 0x4A);
    p->unk1C = func_02030734(heap, 0x20000, 1, g_020A71D4, 0x4C);
    r = func_020072CC(sv, 6, heap, p->unk1C, 0x20000);
    p->unk00 = heap;
    p->unk28 = sys;
    p->unk08 = 0;
    if (r == 1) {
        p->unk04 = 1;
        z = func_020073D8(sv, 6, 0);
    } else {
        p->unk04 = 0;
        z = func_020073D8(sv, 6, 0);
    }
    p->unk1C = z;
    p->unk20 = z;
    p->unk24 = z + 0x10;
    return p;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200C5A4..0x0200C5F8, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the file name at 0x020A71D4 is attested.  The record the file works on
 * is 0x2C bytes: a heap id at +0x00, a flag at +0x04, a state counter at
 * +0x08, a 0x10-byte header at +0x0C, the working buffer at +0x1C, the
 * buffer's base again at +0x20, the payload at base + 0x10 in +0x24, and the
 * system pointer at +0x28.  Every field is pinned by the constructor at
 * 0x0200C52C and by func_0200C5F8, neither of which is in this range; see the
 * two near misses below.
 *
 * func_0200C5A4 is the destructor.  The guard around the buffer free is
 * written as a plain `if`, and the fall-through arm is the free, so the test
 * in the source is `p->unk1C != 0` and not the inverse; see
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses bracket this range, and they are of different kinds.
 *
 *  - func_0200C52C, 118 bytes, the constructor.  It is a codegen miss and not
 *    an evidence one: 0x0200C52C is attested by one branch from an overlay,
 *    so it resolves here as `label`.  The original spends one instruction
 *    this source cannot buy, `movs r7, #6` at 0x0200C56C, which parks the
 *    save-block id in a callee-saved register so that the second use of it
 *    (the func_020073D8 call at 0x0200C560) is a register copy rather than a
 *    second `movs`.  Doing so costs the original a register, and the visible
 *    consequence is that the first parameter is homed to the stack at entry
 *    (`str r0, [sp, #4]`) while the func_02012EBC result keeps r6; every
 *    source shape tried here does the reverse and is 116 bytes against the
 *    original's 118.  Thirty-six shapes were compiled and ranked by diff
 *    count: six permutations of the three field stores crossed with four
 *    positions for the func_020072CC call, the result as a named local
 *    against the call written inline in the `if`, the id 6 as a literal
 *    against a local, five declaration orders for the locals, and a six
 *    argument reading of func_020072CC.  The ranking is flat at 57 to 80
 *    concrete bytes and every one of them is 116 bytes, so the missing
 *    instruction is not reachable by statement order.  All nine front ends
 *    agree, at every optimisation level.  Same class as the near misses at
 *    0x0200B2A4 and 0x0200B37C: a register the original spends and the source
 *    does not.
 *  - func_0200C5F8, 224 bytes, the state machine.  Every concrete byte of it
 *    reproduces; it is capped at MATCH because 0x0200A7F8 is branched to from
 *    exactly one instruction in the whole image, its own call at 0x0200C680,
 *    so the `label` class has no witness left once that call is inside the
 *    compared range and no cut helps.  The source is parked in
 *    src/matched/unit_0200C5F8.c.
 */
void func_0200C5A4(struct MusicalDist *p)
{
    func_020072A4(func_02012EBC(p->unk28), 6);
    if (p->unk1C != 0) {
        func_020307B0(p->unk1C);
    }
    func_020307B0(p);
}

struct MusicalDist *func_0200C5C8(void *sys, const void *src, u32 size,
                                  u32 heap)
{
    struct MusicalDist *p = func_0200C52C(sys, heap);

    if (p->unk1C != 0) {
        p->unk0C.unk00 = size;
        MI_CpuCopy8(&p->unk0C, p->unk1C, sizeof(p->unk0C));
        MI_CpuCopy8(src, p->unk24, size);
    }
    return p;
}


/*
 * 0x0200C5F8..0x0200C6D8, 224 bytes, one function.
 *
 * The state machine of "musical_dist_save.c"; see src/matched/unit_0200C5A4.c
 * for the record it works on and for how the file name is attested.
 *
 * What held it open, and what closed it: 0x0200A7F8 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200C680 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule and no cut helps, because shrinking the range to this one function
 * keeps the call in it.  The `matched` class carries it: 0x0200A7F8 is inside
 * src/matched/unit_0200A6F8.c, an EXACT entry verified against the original
 * bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200C5F8.c \
 *       --addr 0x0200C5F8 --thumb
 *
 * The tag the three service calls take is `(u16)((p->unk00 & 0x7FFF) |
 * 0x8000)` written out at each of the three sites: the original reloads the
 * halfword and redoes the mask each time while keeping 0x7FFF alive in r4,
 * and 0x8000 is reached as `adds rN, r4, #1` off that pool word rather than
 * from one of its own.
 */
u32 func_0200C5F8(struct MusicalDist *p)
{
    u32 loc;
    void *a;
    void *c;
    void *d;
    void *e;
    void *f;

    switch (p->unk08) {
    case 0:
        if (p->unk1C == 0) {
            func_0200C5A4(p);
            return 1;
        }
        a = func_0200A5F8(func_02012EBC(p->unk28));
        func_0200A7EC(a, 1);
        c = func_0204913C(p->unk24, p->unk0C.unk00,
                          (u16)((p->unk00 & 0x7FFF) | 0x8000));
        d = func_0204A39C(c, 1, 0, (u16)((p->unk00 & 0x7FFF) | 0x8000), &loc);
        e = func_02045C44(d, (u16)((p->unk00 & 0x7FFF) | 0x8000));
        f = func_02045EC0(e, 0);
        func_02045A38(f, (u16 *)func_0200A7F8(a), 0x25);
        func_02045808(f);
        func_02045C04(e);
        func_020307B0(d);
        func_02049238(c);
        func_02012E4C(p->unk28, 6);
        p->unk08++;
        break;
    case 1:
        if (func_02012E7C(p->unk28, 6) == 2) {
            func_0200C5A4(p);
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200C6F0, func_0200C720
 *
 * 96 bytes, 0x0200C6D8..0x0200C738, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * alias: this range is inside "musical_dist_save.c".  The constructor of the
 * file, func_0200C52C, loads 0x020A71D4 as the file-name argument to the
 * debug allocator at 0x02030734, and the bytes at 0x020A71D4 spell
 * "musical_dist_save.c"; the string before it is "battle_rec.c", whose
 * terminator at 0x020A71DF fixes that start.  That is the fourth original
 * source file name this project has recovered, after "playtime.c",
 * "box_savedata.c" and "battle_rec.c".  The functions keep their
 * `func_<address>` names, because the file identity is attested and the
 * individual entry points are not.
 *
 * The two getters at the top reach the 0x2C-byte object func_0200C52C
 * allocates; func_0200C6F0 works on a 0x2000-byte buffer instead, comparing
 * the 0x20 bytes at +0x1FE0 against a cleared stack copy of the same length,
 * which is a "is this record still blank" test.  func_0200C6EC is `bx lr` and
 * nothing else, a hook that was never filled in.
 *
 * func_0200C720 is the shape docs/idioms/the-fall-through-arm-is-the-source-order.md
 * warns about, read the other way: the `beq` jumps **into** the `return 1`
 * block and the `bls` jumps **past** it, which is the short-circuit `||` of
 * one `if`, not two statements.
 */
u32 func_0200C6D8(struct Blk2C *p)
{
    return p->unk24;
}

u32 func_0200C6DC(struct Blk2C *p)
{
    return *p->unk20;
}

u32 func_0200C6E4(void)
{
    return 0x2600;
}


void func_0200C6EC(void)
{
}


u32 func_0200C6F0(struct Buf2000 *p)
{
    u8 blank[0x20];
    u32 r = 0;

    MI_CpuFill8(blank, 0, sizeof(blank));
    if (func_0203EFC8(blank, p->unk1FE0, sizeof(blank)) != 0) {
        r = 1;
    }
    return r;
}

u32 func_0200C720(u32 v)
{
    if (v == 0 || v > 0x289) {
        return 1;
    }
    return 0;
}


/*
 * Leaf bitset setter.  Guard chain (a2 > 8, a2 == 6, a1 > 0x1ED all bail),
 * then a 7-wide row/column flattening into a u16 index, then a read-modify-
 * write of one bit in the 0x320-byte bitset that follows *p.  The 0x1ED bound
 * needs a pool word because it is not encodable as a Thumb movs immediate.
 *
 * The index shift is `asrs` because the u16 index promotes to signed int
 * before `>> 3`; the (u8) truncation of the one-hot mask is what the lsls/
 * lsrs #24 pair is.
 */
void func_0200C738(u8 *p, u32 a1, u32 a2)
{
    u16 v;
    u8 *q;

    if (a2 > 8)
        return;
    if (a2 == 6)
        return;
    if (a1 > 493)
        return;
    if (a2 >= 7)
        a2--;
    a1--;

    v = (u16)((a2 - 1) + a1 * 7);
    q = p + 0x320;
    q[v >> 3] |= (u8)(1 << (v & 7));
}


int func_0200C780(u32 v)
{
    u32 i;

    for (i = 0; i < 0xf; i++) {
        if (v == g_0209DE2C[i])
            return 0;
    }
    return 1;
}


int func_0200C7A0(u32 v)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209DE20[i])
            return 0;
    }
    return 1;
}
