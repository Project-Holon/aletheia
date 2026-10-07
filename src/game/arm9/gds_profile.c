/*
 * file:     gds_profile.c
 * unit:     yes
 * function: func_0200D59C, func_0200D5C8, func_0200D5D0, func_0200D6D0
 * address:  0x0200D59C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020307B0       0x020307B0  arm
 *   func_0200D59C_File  0x020A71E8  data
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_02045A98    0x02045A98  arm
 *   func_0203F1FC    0x0203F1FC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 */
struct Sub020071CCCtrl;
struct Big;
struct Blk34;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct Rec0200E6FC;
struct U16Vec;
struct Strbuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct GdsEnt {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
};

struct Blk38 {
    u16 unk00;
    u16 unk02;
    struct GdsEnt unk04[2];
    u8  unk2C[2];
    u8  unk2E[2];
    u8  unk30;
    volatile u8 unk31;
    u8  unk32[2];
};

struct Bits1B {
    u8 f0 : 1;
    u8 f1 : 6;
    u8 f7 : 1;
};

struct GdsProfile {
    u8  unk00[0x10];
    u32 unk10;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    struct Bits1B unk1B;
    u16 unk1C;
    u8  unk1E;
    u8  unk1F;
    u16 unk20[0x28];
    u8  unk70[0x0C];
    u16 unk7C;
    u16 unk7E;
};

typedef signed int     s32;

struct OwnerInfo {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03[0x51];
};

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct GdsProfile *func_0200D59C(u32 heap);
extern void OS_GetOwnerInfo(void *info);
extern u16   func_02045A98(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void *func_02012F08(int *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0200C164(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
void *func_0200D6D0(const void *src, u32 tag);
extern const char func_0200D59C_File[];


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 52 bytes, 0x0200D59C..0x0200D5D0, 2 functions, one of which carries no
 * label in the generated listing.
 *
 * alias: 0x020A71E8 spells "gds_profile.c", the sixth original source file
 * name this project has recovered, attested by the `string` class off the
 * terminator of "musical_dist_save.c" at 0x020A71E6.  The constructor at
 * 0x0200D59C passes it to the debug allocator at 0x02030734 with line 0x50,
 * and the rest of the file is src/matched/unit_0200D6D0.c,
 * src/matched/unit_0200D6EC.c and src/matched/unit_0200D74C.c, with
 * func_0200D5D0 the one function of it left out; see below.
 *
 * The record is 0x80 bytes, which is what the constructor allocates and
 * clears, and which src/matched/unit_0200D5D0.c fills field by field.
 *
 * The heap id is a full word cast to `u16` at the call, not a `u16`
 * parameter: this front end assumes an incoming `u16` parameter is already
 * zero extended and emits nothing, so the `lsls #0x10` / `lsrs #0x10` pair at
 * 0x0200D5A2 is a narrowing the source wrote.  The same reading applies to
 * the tag parameters of func_0200D6D0 and func_0200D774.
 *
 * func_0200D5C8 is the destructor and is eight bytes: a pool word and a `bx`,
 * with no argument set-up at all; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Left out of this range: func_0200D5D0, 256 bytes, which builds the whole
 * record.  Every concrete byte of it reproduces and it is capped at MATCH,
 * because 0x0200C164 is the target of exactly one branch in the image, its
 * own call at 0x0200D610, so the `label` class has no witness outside the
 * compared range and no cut helps.  The source is parked in
 * src/matched/unit_0200D5D0.c.
 */
struct GdsProfile *func_0200D59C(u32 heap)
{
    struct GdsProfile *p = func_02030734((u16)heap, sizeof(struct GdsProfile),
                                         0, func_0200D59C_File, 0x50);

    MI_CpuFill8(p, 0, sizeof(struct GdsProfile));
    return p;
}


void func_0200D5C8(struct GdsProfile *p)
{
    func_020307B0(p);
}


/*
 * 0x0200D5D0..0x0200D6D0, 256 bytes, one function.
 *
 * The record builder of "gds_profile.c"; see src/matched/unit_0200D59C.c for
 * the file name and the record.
 *
 * What held it open, and what closed it: 0x0200C164 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200D610 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule, and `tu --suggest-split` could only answer by leaving this function
 * out.  0x0200C164 is part of src/matched/unit_0200C0E8.c, and that entry is
 * now evidence rather than a bare lookup: the `matched` class reads it as our
 * own byte-verified proof of what lives at that address, proved over a range
 * this file does not touch.  This header used to say a matched address is a
 * lookup and not evidence; the distinction it was missing is that an EXACT
 * entry is a comparison against the original bytes, not a name in a table.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200D5D0.c \
 *       --addr 0x0200D5D0 --thumb
 *
 * Three details are worth having.
 *
 *  - the three bitfield writes at +0x1B each cast the source value to `u8`
 *    before the assignment, which is the `lsls #0x18` / `lsrs #0x18` pair in
 *    front of each mask; without the cast the pair is gone.  The widths come
 *    off the second pair: `lsls #0x1A` / `lsrs #0x19` is bits 1..6, `ands #1`
 *    is bit 0 and `lsls #0x1F` / `lsrs #0x18` is bit 7.
 *  - the four out-parameters of func_0200C164 are declared in the order the
 *    call passes them, so the first lands at sp+0x14 and the last at sp+8;
 *    declared the other way round every offset is mirrored and nothing else
 *    moves.  See docs/idioms/local-declaration-order-is-stack-order.md.
 *  - the byte of owner information is read as `add r0, sp, #8` /
 *    `ldrb r0, [r0, #0x12]` rather than off the OSOwnerInfo frame slot,
 *    because `sp + 8` is already a common subexpression: it is the fifth
 *    argument func_0200C164 took a few instructions earlier.
 */
void func_0200D5D0(struct GdsProfile *p, void *sys)
{
    struct OwnerInfo info;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    void *blk;
    void *save = func_02012EBC(sys);
    void *rec = func_02012944(sys);
    void *env;
    s32 i;

    func_02009470(save);
    blk = func_02012F08(sys);
    env = func_0200E6E8((u32)save);
    OS_GetOwnerInfo(&info);
    func_0200C164(blk, &a, &b, &c, &d);

    MI_CpuFill8(p, 0, sizeof(struct GdsProfile));
    func_0201F41C(func_020084F4(rec), (u16 *)p, 8);
    p->unk10 = func_02008530(rec);
    p->unk14 = func_02008550(rec);
    p->unk1C = a;
    p->unk1B.f1 = (u8)b;
    p->unk1B.f0 = (u8)c;
    p->unk1B.f7 = (u8)d;
    p->unk17 = func_0200856C(rec);
    p->unk18 = func_02008570(rec);
    for (i = 0; i < 0x28; i++) {
        p->unk20[i] = func_02045A98();
    }
    func_0200E6FC(env, 0, (struct Rec0200E6FC *)p->unk20);
    p->unk15 = info.unk02;
    p->unk16 = func_02008554(rec);
    p->unk19 = 0x15;
    p->unk1A = 2;
    p->unk7C = func_0203F1FC((const u8 *)p, 0x7C);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 28 bytes, 0x0200D6D0..0x0200D6EC, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "gds_profile.c"; see src/matched/unit_0200D59C.c for how the
 * name is attested and why the range in front of this one is cut here.
 *
 * A fifteen-byte copy into a freshly allocated block: the same
 * func_020457B0 / func_02045994 pair func_0200D774 uses for the 0x28-byte
 * record.  The size is materialised twice, once as the allocation size and
 * once as the copy length, because both are caller-saved argument registers.
 */
void *func_0200D6D0(const void *src, u32 tag)
{
    void *h = func_020457B0(0xF, (u16)tag);

    func_02045994(h, src, 0xF);
    return h;
}
