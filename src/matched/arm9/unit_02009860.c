/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x02009860
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009860, sub_02009864, sub_02009918, sub_020099C8,
 *           sub_020099D4, sub_020099E4, sub_02009A00, sub_02009A1C
 *
 * symbols:
 *   DWC_IsValidFriendData 0x020596D8  arm
 *   func_02045994         0x02045994  arm
 *   func_02045A38         0x02045A38  arm
 *
 * alias: wifilist.c, the body of the record whose size and copy are in
 * src/matched/unit_020097BC.c and src/matched/unit_020097F0.c.  The record is
 *
 *   +0x000  u8[0x40]
 *   +0x040  Friend[0x20]   0x0C bytes each, DWC friend data
 *   +0x1C0  Entry[32]      0x30 bytes each
 *   +0x7C0  u8[4]
 *
 * NEAR MISS, 0x02009800, 72 bytes, skipped, and for two independent reasons.
 * It is the constructor: it clears the 0x7C4 bytes with MI_CpuFill8, brackets a
 * call to func_02157138 with four pairs of calls on the ids 9, 10, 11 and 13
 * (two of one function on the way in and two of the other on the way out, and
 * the reverse afterwards), and returns.
 *
 *  - func_02157138 lives in ov009, and the only branch to it anywhere in the
 *    image is this one.  The overlay-label rule needs a witness outside the
 *    compared range and there is none, so the site stays wildcarded whatever
 *    the C says, and no cut can help: shrinking the range to this one function
 *    keeps the call in it.
 *  - independently of that, 44 of its 72 bytes are wrong in every spelling
 *    tried.  Each of the four ids is materialised by the original with
 *    `ldr rN, [pc, #n]` out of its own literal pool word holding 0x0A, 0x0B,
 *    0x0D and 0x09, and then moved into r0 with an `adds`; plain arguments,
 *    `u32` locals holding them, an enum and pointer-typed constants all give
 *    `movs r0, #0xa` instead, which is shorter and changes the register
 *    allocation of the whole function.  A small constant that costs a pool
 *    word is not something the source has been made to say yet.
 *
 * sub_02009864 and sub_02009918 are the getter and the setter over the entry's
 * ten fields, both through a PC-relative halfword table.  The tables disagree
 * in the middle rather than at the bottom: the getter reads all ten, the
 * setter's entries 2, 3 and 4 point at its exit, and since entries 0 and 1 are
 * real the table exists without them, so those three really are case labels
 * the source does not have.  That is the ordinary gap reading of
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md, and the
 * contrasting case is in src/matched/unit_020095C8.c.
 *
 * Both tables also put case 9 in front of case 8: the displacement for 9 names
 * an earlier address than the one for 8 in each, and the arms only line up when
 * the source lists `case 9:` before `case 8:`.  A jump table fixes the case
 * *values*, and the order the bodies are emitted in is still source order, so
 * the two together recover the order the arms were written in.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009800.c \
 *       --addr 0x02009800 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  DWC_IsValidFriendData(const void *friendData);
struct Strbuf;
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
struct U16Vec;
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);

struct Sub020097BCFriend {
    u8 unk00[0xC];
};

struct Sub020097BCEnt {
    u8  unk00[0x1C];
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u8  unk2C;
    u8  unk2D;
    u8  unk2E;
    u8  unk2F_0 : 2;
    u8  unk2F_2 : 6;
};

struct Sub020097BCObj {
    u8 unk000[0x40];
    struct Sub020097BCFriend unk040[0x20];
    struct Sub020097BCEnt    unk1C0[32];
    u8 unk7C0[4];
};

struct Sub020097BCObj *sub_02009860(struct Sub020097BCObj *obj)
{
    return obj;
}

u32 sub_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field)
{
    u32 value = 0;

    switch (field) {
    case 0:
        value = obj->unk1C0[i].unk20;
        break;
    case 1:
        value = obj->unk1C0[i].unk1C;
        break;
    case 2:
        value = obj->unk1C0[i].unk24;
        break;
    case 3:
        value = obj->unk1C0[i].unk26;
        break;
    case 4:
        value = obj->unk1C0[i].unk28;
        break;
    case 5:
        value = obj->unk1C0[i].unk2A;
        break;
    case 6:
        value = obj->unk1C0[i].unk2C;
        break;
    case 7:
        value = obj->unk1C0[i].unk2D;
        break;
    case 9:
        value = obj->unk1C0[i].unk2F_0;
        break;
    case 8:
        value = obj->unk1C0[i].unk2E;
        break;
    }
    return value;
}

void sub_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value)
{
    switch (field) {
    case 0:
        obj->unk1C0[i].unk20 = value;
        break;
    case 1:
        obj->unk1C0[i].unk1C = value;
        break;
    case 5:
        obj->unk1C0[i].unk2A = value;
        break;
    case 6:
        obj->unk1C0[i].unk2C = value;
        break;
    case 7:
        obj->unk1C0[i].unk2D = value;
        break;
    case 9:
        obj->unk1C0[i].unk2F_0 = value;
        break;
    case 8:
        obj->unk1C0[i].unk2E = value;
        break;
    }
}

struct Sub020097BCFriend *sub_020099C8(struct Sub020097BCObj *obj, int i)
{
    return &obj->unk040[i];
}

struct Sub020097BCEnt *sub_020099D4(struct Sub020097BCObj *obj, int i)
{
    return &obj->unk1C0[i];
}

void sub_020099E4(struct Sub020097BCObj *obj, int i, void *dest)
{
    func_02045994(dest, (const u16 *)&obj->unk1C0[i], 0x10);
}

void sub_02009A00(struct Sub020097BCObj *obj, int i, void *dest)
{
    func_02045A38(dest, (u16 *)(&obj->unk1C0[i]), 0x10);
}

int sub_02009A1C(struct Sub020097BCObj *obj, u32 i)
{
    if (i >= 0x20) {
        return 0;
    }
    return DWC_IsValidFriendData(&obj->unk040[i]);
}
