/*
 * file:     wifilist_p03.c
 * unit:     yes
 * function: func_020097C4, func_020097F0, func_02009800, func_02009860, func_02009864
 * address:  0x020097C4
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
 *   g_020A7198      0x020A7198  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02157138  0x02157138  thumb ov009
 *   ov_id_09       0x00000009  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0D       0x0000000D  data
 *   DWC_IsValidFriendData 0x020596D8  arm
 *   func_02045994         0x02045994  arm
 *   func_02045A38         0x02045A38  arm
 */
struct Strbuf;
struct U16Vec;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

struct Sub020097BCObj_020097F0 {
    u8 unk000[0x7C4];
};

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

struct Sub020097BCObj_02009860 {
    u8 unk000[0x40];
    struct Sub020097BCFriend unk040[0x20];
    struct Sub020097BCEnt    unk1C0[32];
    u8 unk7C0[4];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02009800(void *p);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_02082BCC(void *dst, int val, unsigned n);
extern void func_02034A5C(int handle);
extern int func_02034AC4(int id);
extern void func_02157138(void *p);
extern int  DWC_IsValidFriendData(const void *friendData);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
void *func_020097C4(int a0);
void sub_020097F0(const struct Sub020097BCObj_020097F0 *src, struct Sub020097BCObj_020097F0 *dest);
extern char g_020A7198[];
extern unsigned char ov_id_09[];
extern unsigned char ov_id_0A[];
extern unsigned char ov_id_0B[];
extern unsigned char ov_id_0D[];


void *func_020097C4(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x7c4, 1, g_020A7198, 0x39);
    func_02009800(p);
    return p;
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: wifilist.c's whole-record copy.  Twelve bytes with no prologue and no
 * label: two pool loads and a `bx`, which is the ARM tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md with the size constant in the
 * same pool.  It sits between the allocator at 0x020097C4 and the constructor
 * at 0x02009800, so its range is its own.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020097F0.c \
 *       --addr 0x020097F0 --thumb
 */
void sub_020097F0(const struct Sub020097BCObj_020097F0 *src, struct Sub020097BCObj_020097F0 *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Sub020097BCObj_020097F0));
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_0D (13) and ov_id_09 (9) resolve as `overlay_id` (a layout
 *           overlay index, loaded by a pc-relative load of this function,
 *           reaching the id register of a known overlay loader), which was
 *           the last blocker.
 *
 * The wifilist constructor, diagnosed in the header of
 * src/matched/unit_02009860.c under "NEAR MISS, 0x02009800".  The only
 * branch to func_02157138 (ov009) in the image is the call in this
 * function; since seed round 9 it resolves as `sole-ref` on the seeded
 * ov009 start.
 *
 * The four ids arrive from literal pool words holding 0x09, 0x0A, 0x0B and
 * 0x0D rather than as `movs`, so they are relocations against absolute
 * symbols, not integer literals: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  With
 * the four declared as extern data symbols all four sites resolve and every
 * concrete byte reproduces.
 */
void sub_02009800(void *p)
{
    func_02082BCC(p, 0, 0x7c4);
    func_02034A5C((int)ov_id_0A);
    func_02034A5C((int)ov_id_0B);
    func_02034AC4((int)ov_id_0D);
    func_02034AC4((int)ov_id_09);
    func_02157138(p);
    func_02034A5C((int)ov_id_09);
    func_02034A5C((int)ov_id_0D);
    func_02034AC4((int)ov_id_0A);
    func_02034AC4((int)ov_id_0B);
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_020099D4, sub_020099E4, sub_02009A00, sub_02009A1C
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
struct Sub020097BCObj_02009860 *sub_02009860(struct Sub020097BCObj_02009860 *obj)
{
    return obj;
}

u32 sub_02009864(const struct Sub020097BCObj_02009860 *obj, u32 i, u32 field)
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

void sub_02009918(struct Sub020097BCObj_02009860 *obj, u32 i, u32 field, u32 value)
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

struct Sub020097BCFriend *sub_020099C8(struct Sub020097BCObj_02009860 *obj, int i)
{
    return &obj->unk040[i];
}

struct Sub020097BCEnt *sub_020099D4(struct Sub020097BCObj_02009860 *obj, int i)
{
    return &obj->unk1C0[i];
}

void sub_020099E4(struct Sub020097BCObj_02009860 *obj, int i, void *dest)
{
    func_02045994(dest, (const u16 *)&obj->unk1C0[i], 0x10);
}

void sub_02009A00(struct Sub020097BCObj_02009860 *obj, int i, void *dest)
{
    func_02045A38(dest, (u16 *)(&obj->unk1C0[i]), 0x10);
}

int sub_02009A1C(struct Sub020097BCObj_02009860 *obj, u32 i)
{
    if (i >= 0x20) {
        return 0;
    }
    return DWC_IsValidFriendData(&obj->unk040[i]);
}
