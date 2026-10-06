/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008F80
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008F80, sub_02008F84, sub_02008F88, sub_02008F9C,
 *           sub_02008FA0, sub_02008FA4, sub_02008FA8, sub_02008FB0,
 *           sub_02008FB4, sub_02008FB8, sub_02008FBC, sub_02008FC0,
 *           sub_02008FC4, sub_02008FC8, sub_02008FD8, sub_02008FEC
 *
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *   sub_020071CC  0x020071CC  thumb
 *   sub_02012EBC  0x02012EBC  thumb
 *   sub_02024570  0x02024570  thumb
 *
 * The accessor tail of the 0x38-byte object the allocator at 0x02008F08 hands
 * out, plus the two functions after it.  The range is closed on the right by
 * 0x02008FFC, which is a four-byte function returning 0x460: the size-returning
 * opener of the next file, the same seam that separates the three save block
 * files before this one.  On the left it is closed by the end of sub_02008F48
 * at 0x02008F7E.
 *
 * Fourteen of the sixteen carry no label in the generated listing, because
 * disasm.py's prologue sweep only fires on a function that saves `lr` and a
 * two-instruction accessor saves nothing; the listing emits them as data words
 * and they were read out of the bytes.
 *
 * Object layout, from the accessors:
 *
 *   +0x00  u32   get by sub_02008F80, written by sub_02008F48
 *   +0x04  u8    get/set
 *   +0x05  u8    get/set
 *   +0x06  u8    get/set
 *   +0x07  u8    get by sub_02008F9C's neighbour; the setter refuses >= 0xC
 *   +0x08  0x10  a block copied in whole by sub_02008F88, address handed out
 *                by sub_02008F84
 *   +0x1E  u16   get/set
 *   +0x20  3 x 8 a small table, indexed with a range check that folds out of
 *                range to entry 0 rather than failing
 *
 * Two things worth naming:
 *
 *  - sub_02008F88 copies *into* the object, not out of it.  The argument
 *    shuffle says so: `adds r2, r0, #0` / `adds r2, #8` builds the field
 *    address in `r2`, then `adds r0, r1, #0` puts the caller's pointer in the
 *    source register and `adds r1, r2, #0` the field in the destination
 *    register.  Reading the `#8` as the first argument inverts the function.
 *  - sub_02008FC8 falls through to the in-range arm and puts the out of range
 *    arm at the end, so the source tests `i < 3` first and returns entry 0
 *    after it.  Written the other way round the compiler emits the same six
 *    instructions with the branch inverted and the two arms swapped, which is
 *    ten wrong bytes in a sixteen-byte function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008F80.c \
 *       --addr 0x02008F80 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
struct Big;
struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *sub_02012EBC(struct Big *p);
struct Rec8;
extern void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);

struct Sub02008F80Entry {
    u8 unk00[8];
};

struct Sub02008F80Obj {
    u32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08[0x10];
    u8  unk18[6];
    u16 unk1E;
    struct Sub02008F80Entry unk20[3];
};

u32 sub_02008F80(const struct Sub02008F80Obj *obj)
{
    return obj->unk00;
}

u8 *sub_02008F84(struct Sub02008F80Obj *obj)
{
    return obj->unk08;
}

void sub_02008F88(struct Sub02008F80Obj *obj, const void *src)
{
    MI_CpuCopy8(src, obj->unk08, sizeof(obj->unk08));
}

u8 sub_02008F9C(const struct Sub02008F80Obj *obj)
{
    return obj->unk04;
}

void sub_02008FA0(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk04 = value;
}

u8 sub_02008FA4(const struct Sub02008F80Obj *obj)
{
    return obj->unk07;
}

void sub_02008FA8(struct Sub02008F80Obj *obj, u32 value)
{
    if (value < 0xC) {
        obj->unk07 = value;
    }
}

u8 sub_02008FB0(const struct Sub02008F80Obj *obj)
{
    return obj->unk05;
}

void sub_02008FB4(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk05 = value;
}

u8 sub_02008FB8(const struct Sub02008F80Obj *obj)
{
    return obj->unk06;
}

void sub_02008FBC(struct Sub02008F80Obj *obj, u8 value)
{
    obj->unk06 = value;
}

u16 sub_02008FC0(const struct Sub02008F80Obj *obj)
{
    return obj->unk1E;
}

void sub_02008FC4(struct Sub02008F80Obj *obj, u16 value)
{
    obj->unk1E = value;
}

struct Sub02008F80Entry *sub_02008FC8(struct Sub02008F80Obj *obj, u32 i)
{
    if (i < 3) {
        return &obj->unk20[i];
    }
    return &obj->unk20[0];
}

void sub_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i)
{
    if (i < 3) {
        sub_02024570((struct Rec8 *)(&obj->unk20[i]), arg);
    }
}

struct Sub02008F80Obj *sub_02008FEC(void *sys)
{
    return sub_020071CC(sub_02012EBC(sys), 0x28);
}
