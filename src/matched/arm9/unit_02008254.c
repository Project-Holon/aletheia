/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008254
 * packet:   pkt_02007B54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008254, sub_02008270, sub_02008284, sub_02008288,
 *           sub_02008298, sub_0200829C, sub_020082B0, sub_020082B4,
 *           sub_020082B8, sub_020082D4
 *
 * symbols:
 *   sub_02008254_File  0x020A708C  data
 *   func_02030734      0x02030734  arm
 *
 * "myitem_savedata.c".  sub_02008254 passes 0x020A708C to the debug allocator
 * at 0x02030734 with the line number 0x342, and the bytes at 0x020A708C spell
 * "myitem_savedata.c", so this range is the head of that file.  The string is
 * named by one pool word in the whole image and it is this function's own, so
 * the `literal` class discards its only witness; the `string` class closes it,
 * because "perapvoice.c" ends with its NUL at 0x020A7088 and three bytes of
 * padding put the next string at 0x020A708C by construction.
 *
 * The object the constructor allocates is 0x2C bytes, and the nine accessors
 * after it account for every byte of it bar the two at +0x16: two parallel
 * five element `s16` arrays at +0 and +0xA, a `u16` at +0x14, two parallel
 * four element `s16` arrays at +0x18 and +0x20, and two `u16`s at +0x28 and
 * +0x2A.  Nine of the ten functions carry no label, because only the
 * constructor saves lr.
 *
 * Every one of the four array reads is an `ldrsh` with a register offset,
 * which per docs/idioms/ldrsh-register-offset-is-signedness.md is the only
 * evidence that those elements are signed; the writers use plain `strh` and
 * say nothing.
 *
 * The near miss this range stops short of is 0x020082DC, the six byte tail
 * call that ends the packet:
 *
 *     020082DC  ldr r0, =0x0209DD64
 *     020082DE  ldr r3, =0x020362A4      NHTTP_CleanupAsync
 *     020082E0  bx  r3
 *
 * Both of its pool words are unattestable and the reason is the evidence
 * rather than the C.  0x020362A4 does carry a `func_020362A4` label, but
 * nothing anywhere in the image branches to it, so the `label` class has no
 * call site to point at; the only word in the 3.9 MB image holding the value
 * is the pool word at 0x020082E8, which is inside the range under test, so
 * `literal` discards its only witness.  0x0209DD64 is the same census exactly:
 * one witness image wide, the pool word at 0x020082E4, and it is data with no
 * label it could ever acquire.  Neither is a veneer and neither is a string.
 * Shrinking the range cannot help, because for both sites the sole witness is
 * the pool word of the very function that needs it.  It closes the day
 * anything else in the image names either address.
 */

typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MyItemSave {
    s16 unk00[5];
    s16 unk0A[5];
    u16 unk14;
    u16 unk16;
    s16 unk18[4];
    s16 unk20[4];
    u16 unk28;
    u16 unk2A;
};

extern const char sub_02008254_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *sub_02008254(u32 heap)
{
    return func_02030734(heap, sizeof(struct MyItemSave), 1,
                         sub_02008254_File, 0x342);
}

void sub_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b)
{
    *a = p->unk0A[i];
    *b = p->unk00[i];
}

u16 sub_02008284(const struct MyItemSave *p)
{
    return p->unk14;
}

void sub_02008288(struct MyItemSave *p, int i, s16 a, s16 b)
{
    p->unk0A[i] = a;
    p->unk00[i] = b;
}

void sub_02008298(struct MyItemSave *p, u16 v)
{
    p->unk14 = v;
}

void sub_0200829C(const struct MyItemSave *p, int i, s16 *a, s16 *b)
{
    *a = p->unk20[i];
    *b = p->unk18[i];
}

u16 sub_020082B0(const struct MyItemSave *p)
{
    return p->unk28;
}

u16 sub_020082B4(const struct MyItemSave *p)
{
    return p->unk2A;
}

void sub_020082B8(struct MyItemSave *p, const s16 *a, const s16 *b)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        p->unk20[i] = a[i];
        p->unk18[i] = b[i];
    }
}

void sub_020082D4(struct MyItemSave *p, u16 a, u16 b)
{
    p->unk28 = a;
    p->unk2A = b;
}
