/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200C9EC
 * packet:   pkt_0200C9F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200C9EC, func_0200C9F4, func_0200CA10, func_0200CA1C,
 *           func_0200CA28, func_0200CA38, func_0200CA40, func_0200CA54,
 *           func_0200CA5C, func_0200CA70, func_0200CA78, func_0200CA8C
 *
 * 172 bytes, 0x0200C9EC..0x0200CA98, 12 functions, nine of which carry no
 * label in the generated listing.
 *
 * The opening of the save block with id 0x37: func_0200C9EC returns 0x4D4,
 * func_0200C9F4 clears exactly 0x4D4 bytes and stamps 0xBEEFCAFE into the
 * first word, and func_0200CA10 is the whole of the lookup
 * `func_020071CC(sys, 0x37)`.  The magic word is the tell that the record is
 * checked rather than merely zeroed; nothing in this range reads it back.
 *
 * The word at +0x04 is a packed set of bitfields, and the widths are read off
 * the shift pairs rather than guessed: `lsls #0x15` / `lsrs #0x16` is bits
 * 1..10 and `lsls #0x0A` / `lsrs #0x16` is bits 12..21, so the layout is
 * 1 + 10 + 1 + 10 bits with the top ten unused by anything in this range.
 * func_0200CA8C truncates its ten-bit field to `u16` on the way out, which is
 * the second shift pair in it and is a return type rather than a field width.
 *
 * This unit stops at 0x0200CA98 rather than running to the end of the
 * original file: func_0200CA98 is 376 bytes of bit-array maintenance over
 * three module-level tables and is not attempted here.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Big;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02012EBC(struct Big *p);

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk08[0x4CC];
};

void *func_0200CA10(void *sys);

u32 func_0200C9EC(void)
{
    return sizeof(struct Blk37);
}

void func_0200C9F4(struct Blk37 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk37));
    p->unk00 = 0xBEEFCAFE;
}

void *func_0200CA10(void *sys)
{
    return func_020071CC(sys, 0x37);
}

void *func_0200CA1C(void *a)
{
    return func_0200CA10(func_02012EBC(a));
}

void func_0200CA28(struct Blk37 *p)
{
    p->f0 = 1;
}

u32 func_0200CA38(struct Blk37 *p)
{
    return p->f0;
}

void func_0200CA40(struct Blk37 *p)
{
    p->f1 = 1;
}

u32 func_0200CA54(struct Blk37 *p)
{
    return p->f1;
}

void func_0200CA5C(struct Blk37 *p, u32 v)
{
    p->f11 = v;
}

u32 func_0200CA70(struct Blk37 *p)
{
    return p->f11;
}

void func_0200CA78(struct Blk37 *p, u32 v)
{
    p->f12 = v;
}

u16 func_0200CA8C(struct Blk37 *p)
{
    return p->f12;
}
