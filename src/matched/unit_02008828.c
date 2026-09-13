/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008828
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008828, sub_0200882C, sub_02008844, sub_02008848,
 *           sub_0200884C, sub_02008850, sub_02008854, sub_02008860,
 *           sub_020088B8, sub_0200890C
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   sub_020071CC  0x020071CC  thumb
 *
 * alias: the save block with id 0x1C, 0x9C bytes, and its accessors.  The
 * range is closed the same way unit_02008700.c is: it opens with the four
 * bytes that return the block size (0x9C, which is what sub_0200882C clears)
 * and ends where the next such function returns 0x658, at 0x020089A8.  Of that
 * 384-byte, twenty-four function range this file covers the first ten,
 * 0x02008828..0x0200892C; unit_0200894C.c covers the last twelve.  The two
 * functions between them, 0x0200892C and 0x0200893C, cannot be verified and
 * are recorded as a near miss in docs/MATCHING.md.
 *
 * Layout, from the accessors:
 *
 *   +0x00  0x38     untouched here
 *   +0x38  0x1C     handed out by sub_02008848
 *   +0x54  0x1C     handed out by sub_0200884C
 *   +0x70  2        handed out by sub_02008850
 *   +0x72  u8       written and read by the two unverifiable functions
 *   +0x73  u8
 *   +0x74  u8
 *   +0x76  u16      the only field sub_0200882C seeds, with 0x1AB
 *   +0x78  u32
 *   +0x7C  u16
 *   +0x7E  u16
 *   +0x80  0x1C     a record, copied in and out field by field by
 *                   sub_02008860 and sub_020088B8 and copied whole by
 *                   sub_0200890C
 *
 * Four of the ten carry no label in the generated listing: they are
 * two-instruction accessors with no register-saving prologue, so disasm.py's
 * sweep never fires on them and the listing emits them as data words.  They
 * were read out of the bytes.
 *
 * Three details pinned this one:
 *
 *  - the record at +0x80 and the buffer sub_02008860 fills it from are not the
 *    same type, even though their first 0x1C bytes line up.  Two fields cross
 *    over: the record's +0x1A comes from the buffer's +0x1B, and the record's
 *    +0x1B comes from the buffer's +0x40, a word truncated to a byte.  Writing
 *    it as one struct assignment collapses the whole function to an ldm/stm
 *    run and is 80 bytes short.
 *  - the twelve bytes at +0x04 of the record are a nested struct, for the same
 *    reason as in unit_02008700.c: they move as one ldm/stm pair plus a
 *    trailing word while the halfwords around them move one at a time.
 *  - the record's +0x18 is signed and the buffer's is not.  sub_020088B8 reads
 *    it with `movs r0, #0x98; ldrsh r0, [r2, r0]` where every other read in the
 *    function is an immediate-offset ldrh; ldrsh has no immediate form, so the
 *    signedness of one field is what costs that instruction its extra
 *    register.  sub_02008860, going the other way, uses a plain ldrh.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008828.c \
 *       --addr 0x02008828 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *sub_020071CC(void *sys, u32 id);

#define BLOCK_ID 0x1C

/* The twelve bytes that move as one unit. */
struct Sub02008860Inner {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

/* The 0x1C-byte record the block keeps at +0x80. */
struct Sub02008828Rec {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    s16 unk18;
    u8  unk1A;
    u8  unk1B;
};

/* The buffer the record is exchanged with.  Its first 0x1C bytes line up with
 * the record but the last two fields do not; see the header. */
struct Sub02008860Buf {
    u16 unk00;
    struct Sub02008860Inner unk04;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u8  unk1C[0x24];
    u32 unk40;
};

struct Sub02008828Obj {
    u8  unk00[0x38];
    u8  unk38[0x1C];
    u8  unk54[0x1C];
    u8  unk70[2];
    u8  unk72;
    u8  unk73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u32 unk78;
    u16 unk7C;
    u16 unk7E;
    struct Sub02008828Rec unk80;
};

u32 sub_02008828(void)
{
    return sizeof(struct Sub02008828Obj);
}

void sub_0200882C(struct Sub02008828Obj *obj)
{
    MI_CpuFill8(obj, 0, sizeof(struct Sub02008828Obj));
    obj->unk76 = 0x1AB;
}

void sub_02008844(void)
{
}

void *sub_02008848(struct Sub02008828Obj *obj)
{
    return obj->unk38;
}

void *sub_0200884C(struct Sub02008828Obj *obj)
{
    return obj->unk54;
}

void *sub_02008850(struct Sub02008828Obj *obj)
{
    return obj->unk70;
}

struct Sub02008828Obj *sub_02008854(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

void sub_02008860(void *sys, const struct Sub02008860Buf *src)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    obj->unk80.unk00 = src->unk00;
    obj->unk80.unk04 = src->unk04;
    obj->unk80.unk10 = src->unk10;
    obj->unk80.unk12 = src->unk12;
    obj->unk80.unk14 = src->unk14;
    obj->unk80.unk16 = src->unk16;
    obj->unk80.unk18 = src->unk18;
    obj->unk80.unk1A = src->unk1B;
    obj->unk80.unk1B = src->unk40;
}

void sub_020088B8(void *sys, struct Sub02008860Buf *dest)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    dest->unk00 = obj->unk80.unk00;
    dest->unk04 = obj->unk80.unk04;
    dest->unk10 = obj->unk80.unk10;
    dest->unk12 = obj->unk80.unk12;
    dest->unk14 = obj->unk80.unk14;
    dest->unk16 = obj->unk80.unk16;
    dest->unk18 = obj->unk80.unk18;
    dest->unk1B = obj->unk80.unk1A;
    dest->unk40 = obj->unk80.unk1B;
}

void sub_0200890C(void *sys, struct Sub02008828Rec *dest)
{
    struct Sub02008828Obj *obj = sub_02008854(sys);

    *dest = obj->unk80;
}
