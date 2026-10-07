/*
 * file:     unit_0200D70C_p01.c
 * unit:     yes
 * function: func_0200D6EC, func_0200D6FC, func_0200D70C, func_0200D72C,, func_0200D74C, func_0200D760, func_0200D774, func_0200D82C, func_0200D85C, func_0200D868, func_0200D884, func_0200D914, func_0200DA14, func_0200DA28, func_0200DA54, func_0200DA64, func_0200DA6C, func_0200DA80, func_0200DA98,
 * address:  0x0200D6EC
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
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj03045.h"

struct U16Vec;
struct Strbuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct RecGet {
    u8  unk00[0x14];
    u8  unk14;
    u8  unk15[6];
    u8  b0 : 1;
    u8  b1 : 6;
    u8  b7 : 1;
    u16 unk1C;
};

typedef signed int     s32;

struct GdsRecord {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u8  unk08[0x20];
};

struct GdsProfile {
    u8  unk00[0x15];
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B[3];
    u8  unk1E;
    u8  unk1F;
    struct GdsRecord unk20;
};

struct Blk3C {
    u16 f0  : 1;
    u16 f1  : 1;
    u16 f2  : 4;
    u16 f6  : 3;
    u16 f9  : 1;
    u16 f10 : 1;
    u16 f11 : 5;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
    u8  unk08[4];
    u8  unk0C[0x1C];
    u8  unk28[0x14];
};

typedef signed short   s16;

struct Blk1AC {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u16 unk08[9];
    u16 unk1A[9];
    u16 unk2C[9];
    u16 unk3E;
    u32 unk40;
    u8  unk44[0xB4];
    u8  unkF8[0xB4];
};

struct Src {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
};

extern int func_02019D58(u16 a, int b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern int func_020248D8(u32 v, u32 *a1, u32 *a2);
extern void  func_020242A4(void *rec, u32 n);
extern u16 func_02024888(u32 idx, u16 add);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
u32 func_0200D82C(struct GdsProfile *p);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
u32  func_0200D884(struct Blk3C *p, u32 id, void *out);
void func_0200D914(struct Blk3C *p, u32 id, const void *src);
u32 func_0200D858(void);
u32 func_0200DAC0(u32 i);
u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
u32 func_0200DA64(void);



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D73C
 *
 * 96 bytes, 0x0200D6EC..0x0200D74C, 5 functions, none of which carries a
 * label in the generated listing.
 *
 * Five validating getters on one record: a byte at +0x14, three bitfields
 * packed into the byte at +0x1B and a halfword at +0x1C.  Each one reads the
 * field and substitutes a safe value when it is out of range, and the shape
 * of the guard is what says how the source was written.
 *
 * func_0200D6EC and func_0200D72C both test the value against 0 and then
 * against 1 with two `beq` to the same address, which is one `if` with `&&`
 * and not two statements; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 * That the test survives at all in func_0200D72C is the interesting part: the
 * field there is one bit wide, so `v != 0 && v != 1` is provably false and
 * the compiler still emits both compares, which is the same reading as
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md.
 *
 * func_0200D73C clamps rather than zeroes, and the branch is `bls` over a
 * `movs r0, #1`, so its guard is `if (v > 1) v = 1;` and the fall-through arm
 * is the assignment.
 *
 * The bitfield widths are read off the shift pairs: `lsls #0x1F` / `lsrs
 * #0x1F` is bit 0, `lsls #0x18` / `lsrs #0x1F` is bit 7, and `lsls #0x19` /
 * `lsrs #0x1A` is the six bits between them, which is what func_0200D70C
 * passes as the second argument of func_02019D58.
 */
u32 func_0200D6EC(struct RecGet *p)
{
    u32 v = p->unk14;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 func_0200D6FC(struct RecGet *p)
{
    u32 v = p->unk1C;

    if (v >= 0x28B) {
        v = 0;
    }
    return v;
}

u32 func_0200D70C(struct RecGet *p)
{
    if (p->unk1C >= 0x28B) {
        return 0;
    }
    return func_02019D58(p->unk1C, p->b1);
}

u32 func_0200D72C(struct RecGet *p)
{
    u32 v = p->b7;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 func_0200D73C(struct RecGet *p)
{
    u32 v = p->b0;

    if (v > 1) {
        v = 1;
    }
    return v;
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D820, func_0200D82C
 *
 * 268 bytes, 0x0200D74C..0x0200D858, 6 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: the tail of "gds_profile.c"; the constructor at 0x0200D59C names
 * 0x020A71E8, see src/matched/unit_0200D59C.c.
 */
u32 func_0200D74C(struct GdsProfile *p)
{
    return func_02025C1C(p->unk17, p->unk18, func_0200D82C(p));
}

u32 func_0200D760(struct GdsProfile *p)
{
    return func_02025C30(p->unk17, p->unk18, func_0200D82C(p));
}

void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag)
{
    u32 a;
    u32 b;
    s32 n = 0;

    if (p->unk1E == 0) {
        out->unk00 = p->unk20.unk00;
        out->unk02 = p->unk20.unk02;
        out->unk04 = p->unk20.unk04;
        out->unk06 = p->unk20.unk06;
        if (out->unk00 >= 5) {
            n++;
            goto chk;
        }
        if (out->unk02 > 0x13) {
            n++;
            goto chk;
        }
        if ((out->unk04 != 0xFFFF && func_020248D8(out->unk04, &a, &b) == 0)
            || (out->unk06 != 0xFFFF
                && func_020248D8(out->unk06, &a, &b) == 0)) {
            n++;
        }
    chk:
        if (n > 0) {
            func_020242A4(out, 4);
            out->unk02 = 0;
            out->unk04 = func_02024888(0x95, 0x1D);
            out->unk06 = 0xFFFF;
        }
        return 0;
    } else {
        void *h = func_020457B0(0x28, (u16)tag);

        func_02045994(h, (const u16 *)&p->unk20, sizeof(p->unk20));
        return h;
    }
}

u32 func_0200D810(struct GdsProfile *p)
{
    u32 v = p->unk15;

    if (v < 1 || v > 0xC) {
        v = 1;
    }
    return v;
}

u32 func_0200D820(struct GdsProfile *p)
{
    u32 v = p->unk16;

    if (v > 0xF) {
        v = 0;
    }
    return v;
}

u32 func_0200D82C(struct GdsProfile *p)
{
    u32 v = p->unk1A;

    switch (v) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return v;
    }
    return 2;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200D884, func_0200D914, func_0200D9E8, func_0200DA14,
 *           func_0200DA28, func_0200DA54
 *
 * 524 bytes, 0x0200D858..0x0200DA64, 10 functions, eight of which carry no
 * label in the generated listing.
 *
 * A 0x3C-byte record reached almost entirely through one pair of dispatchers.
 * func_0200D858 returns 0x3C and func_0200D85C clears exactly that many bytes
 * as a bare tail call, which is the block-file opening this region keeps
 * producing.
 *
 * The first halfword is seven bitfields and the widths come off the shift
 * pairs rather than a guess: `lsls #0x1A` / `lsrs #0x1C` is bits 2..5,
 * `lsls #0x17` / `lsrs #0x1D` is bits 6..8, and the three single-bit fields
 * at 0, 9 and 10 are `lsls #k` / `lsrs #0x1F`.  The setter arm for each is the
 * mirror image, and the three masks that need a literal pool word
 * (0xFFFFFE3F, 0xFFFFFDFF, 0xFFFFFBFF) are exactly the complements of those
 * fields, which is the independent check.
 *
 * Both dispatchers carry twelve dense case labels from zero and both tables
 * are complete, so no arm is a gap; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The three
 * arms that move a block of bytes return 0 like the default does, and the
 * default is reached by the `bhi` in the preamble, so there is one `return 0`
 * after the switch and not a `default:` label.
 *
 * func_0200D868 truncates its value to `u16` before extracting the bit, which
 * a `u16` parameter does not produce: the parameter is wider and the source
 * casts at the use, the same shape as func_0200BBC8 in
 * src/matched/unit_0200BBC8.c.
 *
 * func_0200D9E8 adds three deltas into three counters, each guarded against
 * its own type's maximum, and each sum is computed once and reused by both
 * the compare and the store; the two halfword guards share one literal pool
 * word holding 0xFFFF.
 *
 * func_0200DA28 reads the counter at id 1 through the getter, increments it
 * in a stack byte and writes it back through the setter, reloading the byte
 * after storing it because its address escapes into the setter call.
 */
u32 func_0200D858(void)
{
    return sizeof(struct Blk3C);
}


void func_0200D85C(struct Blk3C *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk3C));
}

void func_0200D868(struct Blk3C *p, u32 v)
{
    p->f1 = (u16)v;
}

u32 func_0200D87C(struct Blk3C *p)
{
    return p->f1;
}

u32 func_0200D884(struct Blk3C *p, u32 id, void *out)
{
    switch (id) {
    case 0:
        return p->f2;
    case 1:
        return p->unk02;
    case 2:
        return p->unk03;
    case 3:
        return p->unk04;
    case 4:
        return p->unk06;
    case 5:
        MI_CpuCopy8(p->unk08, out, sizeof(p->unk08));
        return 0;
    case 6:
        MI_CpuCopy8(p->unk28, out, sizeof(p->unk28));
        return 0;
    case 7:
        return p->f0;
    case 8:
        MI_CpuCopy8(p->unk0C, out, sizeof(p->unk0C));
        return 0;
    case 9:
        return p->f6;
    case 10:
        return p->f9;
    case 11:
        return p->f10;
    }
    return 0;
}

void func_0200D914(struct Blk3C *p, u32 id, const void *src)
{
    switch (id) {
    case 0:
        p->f2 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 1:
        p->unk02 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 2:
        p->unk03 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 3:
        p->unk04 = *(const u16 *)src;
        break;
    case 4:
        p->unk06 = *(const u16 *)src;
        break;
    case 5:
        MI_CpuCopy8(src, p->unk08, sizeof(p->unk08));
        break;
    case 6:
        MI_CpuCopy8(src, p->unk28, sizeof(p->unk28));
        break;
    case 7:
        p->f0 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 8:
        MI_CpuCopy8(src, p->unk0C, sizeof(p->unk0C));
        break;
    case 9:
        p->f6 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 10:
        p->f9 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    case 11:
        p->f10 = *(const u8 *)&((struct Obj03045 *)src)->f0;
        break;
    }
}

void func_0200D9E8(struct Blk3C *p, s32 a, s32 b, s32 c)
{
    if (p->unk03 + a < 255) {
        p->unk03 = p->unk03 + a;
    }
    if (p->unk04 + b < 0xFFFF) {
        p->unk04 = p->unk04 + b;
    }
    if (p->unk06 + c < 0xFFFF) {
        p->unk06 = p->unk06 + c;
    }
}

void func_0200DA14(struct Blk3C *p)
{
    u8 v = 0;

    func_0200D914(p, 1, &v);
}

void func_0200DA28(struct Blk3C *p)
{
    u8 v = func_0200D884(p, 1, 0);

    if (v < 255) {
        v++;
    }
    func_0200D914(p, 1, &v);
}

u16 func_0200DA54(struct Blk3C *p)
{
    return func_0200D884(p, 1, 0);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200DABC, func_0200DAC0, func_0200DAC4, func_0200DAD8,
 *           func_0200DAEC, func_0200DB08, func_0200DB1C, func_0200DB30,
 *           func_0200DB44, func_0200DB60, func_0200DB80, func_0200DBA0,
 *           func_0200DBF0, func_0200DBFC, func_0200DC08, func_0200DC0C,
 *           func_0200DC50, func_0200DC74, func_0200DC94, func_0200DCF8,
 *           func_0200DCFC
 *
 * 684 bytes, 0x0200DA64..0x0200DD10, 25 functions, eighteen of which carry no
 * label in the generated listing.
 *
 * A 0x1AC-byte save record of counters: one clamped total at +0x00, a streak
 * byte at +0x02, a level byte at +0x03 that the constructor seeds with 1, a
 * word of eleven flag bits at +0x04, three nine-entry `u16` arrays at +0x08,
 * +0x1A and +0x2C, a derived score at +0x3E, and two 0xB4-byte blobs at +0x44
 * and +0xF8.  The size getter and the constructor's `MI_CpuFill8(p, 0, 0x1AC)`
 * agree with 0xF8 + 0xB4, which is what pins the last field's length.
 *
 * Five things here are worth naming.
 *
 *  - func_0200DAC0 is `bx lr` and nothing else, and it is a function, not
 *    padding: eight of the accessors `bl` it with the index in r0 and use
 *    the result.  It is `u32 f(u32 i) { return i; }`, an id-to-slot mapping
 *    that was never filled in, and the calls to it are what make the three
 *    arrays indexed rather than direct.
 *  - func_0200DBA0 takes a **signed** index, which the `blt` on the range
 *    check says and the `blo` inside the shift loop does not contradict: the
 *    loop counter is unsigned, so the comparison against it is unsigned too.
 *    Its switch bodies are emitted in the order 2, 1, 0, which is the order
 *    the source wrote them in; written 0, 1, 2 the case-2 body stops being
 *    the fall-through and the function grows a branch.
 *  - the mask is cleared with `~(u32)0 ^ mask`, not `~mask`: the original
 *    materialises the all-ones word with `movs r1, #0; mvns r1, r1` and then
 *    `eors`, which is two instructions where `mvns r1, r4` would have been
 *    one.
 *  - func_0200DC0C's two arms both end in a call to func_0200DBA0 followed
 *    by a store to +0x02, and the compiler cross-jumps them into one copy
 *    that each arm sets up its arguments for and branches to.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - in func_0200DC94 the two products are each truncated to `u16` and their
 *    sum is not.  Holding the sum in a `u16` adds a `lsls`/`lsrs` pair the
 *    original does not have, which is the whole of the difference between
 *    that function and EXACT.
 */
u32 func_0200DA64(void)
{
    return sizeof(struct Blk1AC);
}


void func_0200DA6C(struct Blk1AC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk1AC));
    p->unk03 = 1;
}

void func_0200DA80(struct Blk1AC *p, s32 v)
{
    s32 n = p->unk00 + v;

    if (n > 9999) {
        p->unk00 = 9999;
    } else {
        p->unk00 = n;
    }
}

void func_0200DA98(struct Blk1AC *p, u16 v)
{
    s16 n = (s16)p->unk00 - (s16)v;

    if (n >= 0) {
        p->unk00 = p->unk00 - v;
    } else {
        p->unk00 = 0;
    }
}

u16 func_0200DABC(struct Blk1AC *p)
{
    return p->unk00;
}

u32 func_0200DAC0(u32 i)
{
    return i;
}

u16 func_0200DAC4(struct Blk1AC *p, u32 i)
{
    return p->unk08[func_0200DAC0(i)];
}

u16 func_0200DAD8(struct Blk1AC *p, u32 i)
{
    return p->unk1A[func_0200DAC0(i)];
}

void func_0200DAEC(struct Blk1AC *p, u32 i, u16 v)
{
    u32 k = func_0200DAC0(i);

    if (p->unk1A[k] < v) {
        p->unk1A[k] = v;
    }
}

void func_0200DB08(struct Blk1AC *p, u32 i, u16 v)
{
    p->unk08[func_0200DAC0(i)] = v;
}

void func_0200DB1C(struct Blk1AC *p, u32 i)
{
    p->unk2C[func_0200DAC0(i)] = 0;
}

void func_0200DB30(struct Blk1AC *p, u32 i)
{
    p->unk2C[func_0200DAC0(i)] = 1;
}

u32 func_0200DB44(struct Blk1AC *p, u32 i)
{
    if (p->unk2C[func_0200DAC0(i)] != 0) {
        return 1;
    }
    return 0;
}

void func_0200DB60(struct Blk1AC *p, u32 i)
{
    u32 k = func_0200DAC0(i);

    if (p->unk2C[k] < 0xFFFE) {
        p->unk2C[k] = p->unk2C[k] + 1;
    }
}

u16 func_0200DB80(struct Blk1AC *p, u32 i)
{
    u16 n = p->unk2C[func_0200DAC0(i)] - 1;

    if ((s16)n < 0) {
        n = 0;
    }
    return n;
}

u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op)
{
    u32 j;
    u32 mask = 1;

    if (i >= 11) {
        return 0;
    }
    for (j = 0; j < i; j++) {
        mask <<= 1;
    }
    switch (op) {
    case 2:
        p->unk04 &= ~(u32)0 ^ mask;
        break;
    case 1:
        p->unk04 |= mask;
        break;
    case 0:
        return (p->unk04 >> i) & 1;
    }
    return 0;
}

void func_0200DBF0(struct Blk1AC *p)
{
    if (p->unk03 < 10) {
        p->unk03 = p->unk03 + 1;
    }
}

void func_0200DBFC(struct Blk1AC *p)
{
    if (p->unk03 > 1) {
        p->unk03 = p->unk03 - 1;
    }
}

u8 func_0200DC08(struct Blk1AC *p)
{
    return p->unk03;
}

u8 func_0200DC0C(struct Blk1AC *p, u32 kind)
{
    switch (kind) {
    case 2:
        func_0200DBA0(p, 0, 2);
        p->unk02 = 0;
        break;
    case 3:
        if (func_0200DBA0(p, 0, 0)) {
            if (p->unk02 < 0xFF) {
                p->unk02 = p->unk02 + 1;
            }
        } else {
            func_0200DBA0(p, 0, 1);
            p->unk02 = 1;
        }
        break;
    }
    return p->unk02;
}

void func_0200DC50(struct Blk1AC *p, u32 which, const void *src)
{
    if (which == 0) {
        MI_CpuCopy8(src, p->unkF8, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(src, p->unk44, sizeof(p->unk44));
    }
}

void func_0200DC74(struct Blk1AC *p, u32 which, void *dest)
{
    if (which == 0) {
        MI_CpuCopy8(p->unkF8, dest, sizeof(p->unkF8));
    } else {
        MI_CpuCopy8(p->unk44, dest, sizeof(p->unk44));
    }
}

void func_0200DC94(struct Blk1AC *p, const struct Src *q)
{
    u16 a;
    u16 c;
    u16 d;
    s32 t;

    a = (q->unk02 - 1) * 1000;
    t = (u16)(q->unk04 * 10) + (u16)(q->unk03 * 20);
    if (t > 950) {
        c = 0;
    } else {
        c = 950 - t;
    }
    if (q->unk06 > 970) {
        d = 0;
    } else {
        d = (1000 - q->unk06) / 30;
    }
    p->unk3E = a + c + d;
}

u16 func_0200DCF8(struct Blk1AC *p)
{
    return p->unk3E;
}

u8 func_0200DCFC(struct Blk1AC *p)
{
    return p->unk3E / 1000;
}
