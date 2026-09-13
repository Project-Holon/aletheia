/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x020079BC
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020079BC, sub_02007A18, sub_02007A68, sub_02007A80,
 *           sub_02007A9C
 *
 * symbols:
 *   sub_020079BC_File  0x020A7068  data
 *   sub_020074CC       0x020074CC  thumb
 *   sub_02007AF4       0x02007AF4  thumb
 *   sub_02017E88       0x02017E88  thumb
 *   func_02034714      0x02034714  arm
 *
 * The checked entry accessor in its two forms, the flag byte at 0x3DC, and
 * the size of one box page.
 *
 * The file identity is in the image and it is new: sub_02007AA4, the next
 * function after this range, passes 0x020A706C to the debug allocator at
 * 0x02030734, and the bytes at 0x020A706C spell "box_savedata.c".  That is
 * this code.  sub_02007B20, further down the same run, passes 0x020A707C
 * instead, and those bytes spell "perapvoice.c", so a translation unit
 * boundary falls between the two and the run 0x02007664..0x02007B54 is at
 * least two original files rather than one.  Neither name is used as a
 * source file name in this tree yet, because the boundary is bracketed
 * (somewhere in 0x02007AC8..0x02007B20) rather than located.
 *
 * The range stops at 0x02007AA4 for an evidence reason.  sub_02007AA4 is
 * reproduced byte for byte but caps at MATCH: 0x020A706C is named by
 * exactly one pool word in the image and it is that function's own, so the
 * `literal` class has no witness, and the `string` class cannot help either
 * because the nine NUL bytes between the end of "save_control.c" at
 * 0x020A7062 and 0x020A706C are more than the one terminator plus at most
 * three alignment bytes its rule allows.  See "The string class" in
 * docs/MATCHING.md; the neighbouring 0x020A707C does satisfy it, with two,
 * and resolves.
 *
 * sub_02007A9C carries no label because it saves nothing: `movs r0, #0xFF`,
 * `lsls r0, r0, #4`, `bx lr`.  0xFF0 is 30 entries of 0x88 bytes, which is
 * one box, and it never reaches a literal pool because a byte shifted left
 * costs two halfwords against a pool word plus its `ldr`.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020079BCEntry {
    u8 data[0x88];
};

struct Sub020079BCName {
    u8 data[0x28];
};

struct Sub020079BCHeader {
    u32 unk00;
    struct Sub020079BCName unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern const char sub_020079BC_File[];

extern struct Sub020079BCHeader *sub_020074CC(void *save);
extern struct Sub020079BCEntry  *sub_02007AF4(void **save, u32 box);
extern int  sub_02017E88(struct Sub020079BCEntry *entry, int field, int arg);
extern void func_02034714(const char *file, int line, const char *msg);

int sub_020079BC(void **save, u32 box, u32 slot, int field, int arg)
{
    struct Sub020079BCHeader *h = sub_020074CC(save);

    if (box >= 0x18 && box != -1) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (slot >= 30) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (box == -1) {
        box = h->unk00;
    }
    return sub_02017E88(&sub_02007AF4(save, box)[slot], field, arg);
}

struct Sub020079BCEntry *sub_02007A18(void **save, u32 box, u32 slot)
{
    struct Sub020079BCHeader *h = sub_020074CC(save);

    if (box >= 0x18 && box != -1) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (slot >= 30) {
        func_02034714(sub_020079BC_File, 0, sub_020079BC_File);
    }
    if (box == -1) {
        box = h->unk00;
    }
    return &sub_02007AF4(save, box)[slot];
}

void sub_02007A68(void *save, u32 bits)
{
    struct Sub020079BCHeader *h = sub_020074CC(save);

    h->unk3DC |= (u8)bits;
}

int sub_02007A80(void *save, u32 bits)
{
    struct Sub020079BCHeader *h = sub_020074CC(save);

    if (h->unk3DC & bits) {
        return 1;
    }
    return 0;
}

u32 sub_02007A9C(void)
{
    return 0xFF0;
}
