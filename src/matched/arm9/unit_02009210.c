/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009210
 * packet:   pkt_02009210
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009210, sub_0200921C, sub_02009228, sub_02009230,
 *           sub_02009290, sub_02009294, sub_020092AC, sub_020092D0,
 *           sub_020092D8, sub_020092E0, sub_020092EC, sub_020092F8,
 *           sub_02009304, sub_02009310, sub_02009330, sub_02009348,
 *           sub_02009364, sub_02009370, sub_02009390, sub_020093A8,
 *           sub_020093C8, sub_020093CC, sub_020093D0, sub_020093D4,
 *           sub_020093D8, sub_020093F0, sub_02009418, sub_02009428
 *
 * symbols:
 *   sub_020071CC   0x020071CC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020173EC  0x020173EC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * alias: the head of the save block with id 0x20, 0x1AC bytes.  The file opens
 * the way every block file in this region does: a twelve byte thunk that is
 * `sub_020071CC(sys, 0x20)`, a four byte function returning the block size, and
 * a constructor that clears exactly that size.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md; only eight of
 * these twenty-eight functions carry a label.
 *
 * The block is
 *
 *   +0x000  u32         a stamp, 0xDA010100, written through sub_020093CC
 *   +0x004  s32         initialised to -1
 *   +0x008  u8[0xDC]    a blob copied in and out whole
 *   +0x0E4  u16[20]     paired with
 *   +0x10C  u8 [20]     ... one entry each
 *   +0x120  Entry[5]    0x1A bytes each, first halfword seeded to 0x7E
 *   +0x1A2  u8[8]       flags, two of them bitfields
 *
 * The bound on the two parallel arrays is off by one in the original and it is
 * off by one in both directions: the guard is `i > 20` on twenty entry arrays,
 * so index 20 writes the first byte of the array after it, while the counter
 * in sub_02009370 stops at 19.  Writing the guard as `i >= 20` costs nothing
 * in the C and changes the compare, so the off-by-one is part of the match.
 *
 * sub_020092AC is the signed-index bit test: `n >> 3` is a plain `lsrs` and
 * `n % 8` is the four instruction `lsrs #31` / `lsls #29` / `subs` / `rors #29`
 * sequence, which is the same split docs/MATCHING.md records for
 * sub_0200A6BC.  `& 7` would be two instructions and `/ 8` would add a rounding
 * correction, so the source really does spell the two halves differently.
 * The byte index is the one place a cast is needed: `n >> 3` on the signed
 * parameter is an `asrs`, and only `(u32)n >> 3` gives the original's `lsrs`.
 *
 * The byte at +0x1A6 is two bitfields, `u8 : 7` and `u8 : 1`, and the four
 * accessors on it say so: the getters end in `lsls #0x19` / `lsrs #0x19` and
 * `lsls #0x18` / `lsrs #0x1F`, widths that are not any integer type, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.  Both setters
 * take `int`, not `u8`: the `cmp #5` in sub_020093F0 is `blt` rather than
 * `blo`, and both carry a `lsls #0x18` / `lsrs #0x18` truncation to u8 in
 * front of the field mask that an already-u8 parameter does not produce.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009210.c \
 *       --addr 0x02009210 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Big;
struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02012EBC(struct Big *p);
extern u32 func_020173EC(void);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);

#define BLOCK_ID 0x20

struct Sub02009210Ent {
    u16 unk00;
    u8  unk02[0x18];
};

struct Sub02009210Obj {
    u32 unk000;
    s32 unk004;
    u8  unk008[0xDC];
    u16 unk0E4[20];
    u8  unk10C[20];
    struct Sub02009210Ent unk120[5];
    u8  unk1A2;
    u8  unk1A3;
    u8  unk1A4;
    u8  unk1A5;
    u8  unk1A6_0 : 7;
    u8  unk1A6_7 : 1;
    u8  unk1A7;
    u8  unk1A8;
    u8  unk1A9;
};

struct Sub02009210Obj *sub_02009210(void *sys);
u32  sub_02009228(void);
void sub_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
u8   sub_02009330(const struct Sub02009210Obj *obj, int i);
void sub_020093CC(struct Sub02009210Obj *obj, u32 value);

struct Sub02009210Obj *sub_02009210(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

struct Sub02009210Obj *sub_0200921C(void *p)
{
    return sub_02009210(func_02012EBC(p));
}

u32 sub_02009228(void)
{
    return sizeof(struct Sub02009210Obj);
}

void sub_02009230(struct Sub02009210Obj *obj)
{
    u8 i;

    MI_CpuFill8(obj, 0, sub_02009228());
    sub_020093CC(obj, 0xDA010100);
    obj->unk004 = -1;
    obj->unk1A7 = 0;
    obj->unk1A8 = 0;
    obj->unk1A9 = 0;
    obj->unk1A6_0 = 0x7F;
    for (i = 0; i < 5; i++) {
        obj->unk120[i].unk00 = 0x7E;
    }
}

u8 *sub_02009290(struct Sub02009210Obj *obj)
{
    return obj->unk008;
}

void sub_02009294(struct Sub02009210Obj *obj, const void *src)
{
    MI_CpuCopy8(src, obj->unk008, func_020173EC());
}

u32 sub_020092AC(const u8 *bits, int n)
{
    u32 ret = 1;

    if (!(bits[(u32)n >> 3] & (1 << (n % 8)))) {
        ret = 0;
    }
    return ret;
}

void sub_020092D0(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A4 = value;
}

u8 sub_020092D8(const struct Sub02009210Obj *obj)
{
    return obj->unk1A4;
}

void sub_020092E0(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A5 = value;
}

u8 sub_020092EC(const struct Sub02009210Obj *obj)
{
    return obj->unk1A5;
}

void sub_020092F8(struct Sub02009210Obj *obj, u8 value)
{
    obj->unk1A3 = value;
}

u8 sub_02009304(const struct Sub02009210Obj *obj)
{
    return obj->unk1A3;
}

u16 sub_02009310(const struct Sub02009210Obj *obj, int i)
{
    u16 value;

    if (i > 20) {
        return 0;
    }
    value = obj->unk0E4[i];
    if (value > 0x272) {
        value = 0;
    }
    return value;
}

u8 sub_02009330(const struct Sub02009210Obj *obj, int i)
{
    u8 value;

    if (i > 20) {
        return 0;
    }
    value = obj->unk10C[i];
    if (value > 20) {
        value = 0;
    }
    return value;
}

void sub_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b)
{
    if (i > 20) {
        return;
    }
    obj->unk0E4[i] = a;
    obj->unk10C[i] = b;
}

void sub_02009364(struct Sub02009210Obj *obj, int i)
{
    sub_02009348(obj, i, 0, 0);
}

u32 sub_02009370(const struct Sub02009210Obj *obj)
{
    u32 count = 0;
    int i;

    for (i = 0; i < 20; i++) {
        if (sub_02009330(obj, i) != 0) {
            count++;
        }
    }
    return count;
}

struct Sub02009210Ent *sub_02009390(struct Sub02009210Obj *obj, int i)
{
    if (i < 5) {
        return &obj->unk120[i];
    }
    return 0;
}

void sub_020093A8(struct Sub02009210Obj *obj, int i, const void *src)
{
    if (i < 5) {
        MI_CpuCopy8(src, &obj->unk120[i], sizeof(obj->unk120[0]));
    }
}

u32 sub_020093C8(const struct Sub02009210Obj *obj)
{
    return obj->unk000;
}

void sub_020093CC(struct Sub02009210Obj *obj, u32 value)
{
    obj->unk000 = value;
}

s32 sub_020093D0(const struct Sub02009210Obj *obj)
{
    return obj->unk004;
}

void sub_020093D4(struct Sub02009210Obj *obj, s32 value)
{
    obj->unk004 = value;
}

u32 sub_020093D8(const struct Sub02009210Obj *obj)
{
    u32 value = obj->unk1A6_0;

    if (value >= 5 && value != 0x7F) {
        value = 0x7F;
    }
    return value;
}

void sub_020093F0(struct Sub02009210Obj *obj, int value)
{
    if (value < 5 || value == 0x7F) {
        obj->unk1A6_0 = value;
    }
}

u32 sub_02009418(const struct Sub02009210Obj *obj)
{
    return obj->unk1A6_7;
}

void sub_02009428(struct Sub02009210Obj *obj, int value)
{
    obj->unk1A6_7 = value;
}
