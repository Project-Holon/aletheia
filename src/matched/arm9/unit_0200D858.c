/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D858
 * packet:   pkt_0200D6D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200D858, func_0200D85C, func_0200D868, func_0200D87C,
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
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj03045.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

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

u32  func_0200D884(struct Blk3C *p, u32 id, void *out);
void func_0200D914(struct Blk3C *p, u32 id, const void *src);

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
