/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x0200D5D0..0x0200D6D0, 256 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * The record builder of "gds_profile.c"; see src/matched/unit_0200D59C.c for
 * the file name and the record.
 *
 * Why it is capped: 0x0200C164 is the target of exactly one branch in the
 * whole image, the `bl` at 0x0200D610 inside this very function, so the
 * `label` class discards its only witness under the honesty rule.
 * `tu --suggest-split` confirms it: the best partition leaves this one
 * function out and matches the two pieces on either side of it.  0x0200C164
 * is itself already matched, as part of src/matched/unit_0200C0E8.c, but a
 * matched address is a lookup and not evidence.  It closes the day the image
 * acquires a second caller.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0200D5D0.c \
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
 *
 * symbols:
 *   MI_CpuFill8      0x02082BCC  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_02045A98    0x02045A98  arm
 *   func_0203F1FC    0x0203F1FC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void OS_GetOwnerInfo(void *info);

extern u16   func_02045A98(void);
extern u16   func_0203F1FC(const void *src, u32 size);

extern void *func_02012EBC(void *sys);
extern void *func_02012944(void *sys);
extern void *func_02012F08(void *sys);
extern void  func_02009470(void *a);
extern void *func_0200E6E8(void *a);
extern void  func_0200E6FC(void *a, u32 b, void *dest);
extern void *func_020084F4(void *a);
extern void  func_0201F41C(const void *src, void *dest, u32 size);
extern u32   func_02008530(void *a);
extern u8    func_02008550(void *a);
extern u8    func_02008554(void *a);
extern u8    func_0200856C(void *a);
extern u8    func_02008570(void *a);
extern void  func_0200C164(const void *blk, u32 *a, u32 *b, u32 *c, u32 *d);

struct OwnerInfo {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03[0x51];
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
    env = func_0200E6E8(save);
    OS_GetOwnerInfo(&info);
    func_0200C164(blk, &a, &b, &c, &d);

    MI_CpuFill8(p, 0, sizeof(struct GdsProfile));
    func_0201F41C(func_020084F4(rec), p, 8);
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
    func_0200E6FC(env, 0, p->unk20);
    p->unk15 = info.unk02;
    p->unk16 = func_02008554(rec);
    p->unk19 = 0x15;
    p->unk1A = 2;
    p->unk7C = func_0203F1FC(p, 0x7C);
}
