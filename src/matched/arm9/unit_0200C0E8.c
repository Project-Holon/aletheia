/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200C0E8
 * packet:   pkt_0200C0E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200C0E8, func_0200C0F0, func_0200C0FC, func_0200C104,
 *           func_0200C10C, func_0200C11C, func_0200C164, func_0200C184,
 *           func_0200C18C, func_0200C1A4, func_0200C1B0, func_0200C1C4,
 *           func_0200C1C8, func_0200C1DC, func_0200C1E0, func_0200C1F4,
 *           func_0200C1F8, func_0200C20C, func_0200C210, func_0200C224,
 *           func_0200C22C, func_0200C234, func_0200C248, func_0200C258,
 *           func_0200C274, func_0200C278, func_0200C29C, func_0200C2B0,
 *           func_0200C2D0, func_0200C2F0, func_0200C308, func_0200C31C,
 *           func_0200C324, func_0200C32C, func_0200C334, func_0200C33C,
 *           func_0200C344, func_0200C34C, func_0200C358, func_0200C364,
 *           func_0200C37C, func_0200C384, func_0200C38C, func_0200C39C,
 *           func_0200C3B0, func_0200C3B8, func_0200C3C0, func_0200C3E0,
 *           func_0200C3EC
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: func_0200C0F0 is the whole of
 * its lookup, `func_020071CC(sys, 0x34)`, and func_0200C0E8 is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - func_0200C164 takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - func_0200C3C0 goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: func_0200C37C returns the
 *    64-bit value and func_0200C384 stores the two halves from two register
 *    arguments.
 *
 * symbols:
 *   STRBUF_ToChars  0x02045A38  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

struct Ent58 {
    u16 v[6];
};

struct Bits0A {
    u8 f0 : 6;
    u8 f6 : 1;
    u8 f7 : 1;
};

union U64Pair {
    unsigned long long q;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct Blk34 {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    struct Bits0A unk0A;
    u8  unk0B;
    u8  unk0C[8];
    u32 f14_0  : 28;
    u32 f14_28 : 4;
    u32 unk18;
    u32 unk1C;
    u16 unk20[9];
    u16 unk32[9];
    u8  unk44;
    u8  unk45;
    u8  unk46;
    u8  unk47[3];
    u16 unk4A[3];
    union U64Pair unk50;
    struct Ent58 unk58[8];
    u32 unkB8[8];
    u32 unkD8;
    u32 unkDC;
    volatile u16 unkE0;
    u16 unkE2;
};

void *func_0200C0F0(void *sys);

void *func_0200C0E8(void *sys)
{
    return func_0200C0F0(sys);
}

void *func_0200C0F0(void *sys)
{
    return func_020071CC(sys, 0x34);
}

void func_0200C0FC(struct Blk34 *p, u32 i, u8 v)
{
    p->unk0C[i] = v;
}

u8 func_0200C104(struct Blk34 *p, u32 i)
{
    return p->unk0C[i];
}

void func_0200C10C(struct Blk34 *p)
{
    MI_CpuFill8(p->unk0C, 0, sizeof(p->unk0C));
}

void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d)
{
    p->unk08 = a;
    p->unk0A.f0 = b;
    p->unk0A.f6 = c;
    p->unk0A.f7 = (d == 1);
}

void func_0200C164(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d)
{
    *a = p->unk08;
    *b = p->unk0A.f0;
    *c = p->unk0A.f6;
    *d = p->unk0A.f7;
}

u32 func_0200C184(struct Blk34 *p)
{
    return p->f14_0;
}

void func_0200C18C(struct Blk34 *p, u32 v)
{
    p->f14_0 = v;
}

u8 func_0200C1A4(struct Blk34 *p)
{
    return p->f14_28;
}

void func_0200C1B0(struct Blk34 *p, u32 v)
{
    p->f14_28 = v;
}

u32 func_0200C1C4(struct Blk34 *p)
{
    return p->unk18;
}

u32 func_0200C1C8(struct Blk34 *p)
{
    if (p->unk18 < 99999) {
        p->unk18++;
    }
    return p->unk18;
}

u32 func_0200C1DC(struct Blk34 *p)
{
    return p->unk1C;
}

u32 func_0200C1E0(struct Blk34 *p)
{
    if (p->unk1C < 99999) {
        p->unk1C++;
    }
    return p->unk1C;
}

u16 *func_0200C1F4(struct Blk34 *p)
{
    return p->unk20;
}

void func_0200C1F8(struct Blk34 *p, const u16 *src)
{
    STRBUF_ToChars((struct U16Vec *)src, p->unk20, 9);
}

u16 *func_0200C20C(struct Blk34 *p)
{
    return p->unk32;
}

void func_0200C210(struct Blk34 *p, const u16 *src)
{
    STRBUF_ToChars((struct U16Vec *)src, p->unk32, 9);
}

u8 func_0200C224(struct Blk34 *p)
{
    return p->unk44;
}

void func_0200C22C(struct Blk34 *p, u8 v)
{
    p->unk44 = v;
}

u32 func_0200C234(struct Blk34 *p, u32 bit)
{
    return (p->unk04 & (1 << bit)) != 0;
}

void func_0200C248(struct Blk34 *p, u32 bit)
{
    p->unk04 |= 1 << bit;
}

u32 func_0200C258(struct Blk34 *p)
{
    u32 n = 0;
    u32 v;

    for (v = p->unk04; v != 0; v >>= 1) {
        if (v & 1) {
            n++;
        }
    }
    return n;
}

u32 func_0200C274(struct Blk34 *p)
{
    return p->unk00;
}

u32 func_0200C278(struct Blk34 *p, u32 v)
{
    if (v > 9999999) {
        p->unk00 = 9999999;
    } else {
        p->unk00 += v;
    }
    if (p->unk00 > 9999999) {
        p->unk00 = 9999999;
    }
    return p->unk00;
}

u32 func_0200C29C(struct Blk34 *p, u32 v)
{
    if (p->unk00 < v) {
        p->unk00 = 0;
    } else {
        p->unk00 -= v;
    }
    return p->unk00;
}

void func_0200C2B0(struct Blk34 *p, u32 i, const u16 *src)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        p->unk58[i].v[j] = src[j];
    }
}

void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        dest[j] = p->unk58[i].v[j];
    }
}

void func_0200C2F0(struct Blk34 *p, u32 i, u8 v)
{
    p->unk45 |= (u8)(v << (i * 2));
}

u8 func_0200C308(struct Blk34 *p, u32 i)
{
    return (u8)((p->unk45 >> (i * 2)) & 3);
}

u8 func_0200C31C(struct Blk34 *p)
{
    return p->unk45;
}

void func_0200C324(struct Blk34 *p, u8 v)
{
    p->unk45 = v;
}

u8 func_0200C32C(struct Blk34 *p)
{
    return p->unk46;
}

void func_0200C334(struct Blk34 *p, u8 v)
{
    p->unk46 = v;
}

int func_0200C33C(struct Blk34 *p, u32 i)
{
    return p->unk47[i];
}

void func_0200C344(struct Blk34 *p, u8 i, u8 v)
{
    p->unk47[i] = v;
}

u16 func_0200C34C(struct Blk34 *p, u32 i)
{
    return p->unk4A[i];
}

void func_0200C358(struct Blk34 *p, u32 i, int v)
{
    p->unk4A[i] = v;
}

void func_0200C364(struct Blk34 *p, u8 i, int v)
{
    u32 n = p->unk4A[i];

    n += v;
    if (n > 0xFFFF) {
        n = 0xFFFF;
    }
    p->unk4A[i] = n;
}

unsigned long long func_0200C37C(struct Blk34 *p)
{
    return p->unk50.q;
}

void func_0200C384(struct Blk34 *p, u32 lo, u32 hi)
{
    p->unk50.w.lo = lo;
    p->unk50.w.hi = hi;
}

void func_0200C38C(struct Blk34 *p, s32 i, u32 v)
{
    if (i < 8) {
        p->unkB8[i] = v;
    }
}

u32 func_0200C39C(struct Blk34 *p, s32 i)
{
    if (i >= 8) {
        return 0;
    }
    return p->unkB8[i];
}

u16 func_0200C3B0(struct Blk34 *p)
{
    return p->unkE0;
}

void func_0200C3B8(struct Blk34 *p, u16 v)
{
    p->unkE0 = v;
}

void func_0200C3C0(struct Blk34 *p, u16 v)
{
    if (v <= p->unkE0) {
        p->unkE0 = p->unkE0 - v;
    } else {
        p->unkE0 = 0;
    }
}

u8 func_0200C3E0(struct Blk34 *p)
{
    return p->unkDC;
}

void func_0200C3EC(struct Blk34 *p, u32 v)
{
    p->unkDC = v;
}
