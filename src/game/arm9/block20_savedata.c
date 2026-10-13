/*
 * file:     block20_savedata.c
 * unit:     yes
 * function: sub_02009160, sub_020091AC, sub_020091FC, sub_02009200,, sub_02009210, sub_0200921C, sub_02009228, sub_02009230,
 * address:  0x02009160
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
 *   SAVE_CONTROL_GetBlock   0x020071CC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020173EC  0x020173EC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 */
struct Big;
struct Sub020071CCCtrl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29;
    u8  unk2A[2];
};

typedef signed int     s32;

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

extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 func_020173EC(void);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
void sub_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
u8   sub_02009330(const struct Sub02009210Obj *obj, int i);
void sub_020093CC(struct Sub02009210Obj *obj, u32 value);
struct Sub02009210Obj *sub_02009210(void *sys);
struct Sub02009210Obj *sub_0200921C(void *p);
u32 sub_02009228(void);


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02009208
 *
 * alias: the rest of the 0x2C-byte object of src/matched/unit_020090D8.c and
 * src/matched/unit_02009110.c.  None of these five carries a label: the first
 * two save registers without lr and the last three have no prologue at all, so
 * the whole 176-byte run arrives in the listing as `.word` data.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The 9 by 4 byte table at the front of the object is three fields per byte:
 * the low nibble is the count unit_02009110.c reads, bit 7 is the flag it
 * tests, and bits 4 to 6 are a three-valued mark that these two functions
 * read and write.  The mark is not a bit index computed from the kind: 1 maps
 * to 0x40, 3 to 0x20 and 2 to 0x10, in that source order, which no arithmetic
 * produces and which both functions spell out as the same three-armed chain.
 *
 * In sub_020091AC each arm of that chain assigns only the mask and the `orrs`
 * is emitted once, with the no-match path branching past it, so the `|=` is
 * inside the arms in the source; see
 * docs/idioms/switch-arms-tail-merge.md.
 *
 * `subs r5, r3, #1; cmp r5, #2; bhi` is the folded range check, and it has to
 * be written as `(u32)(kind - 1) <= 2`: `kind >= 1 && kind <= 3` on the signed
 * parameter is two compares and two branches, two bytes longer, exactly as
 * docs/MATCHING.md records for sub_0200A6BC.  The row and column checks next
 * to it do not fold, because they are written as two comparisons against a
 * signed index in the style of unit_02009110.c.
 *
 * In sub_02009160 the `movs r4, #0` sits *after* the range checks, so the mask
 * is declared without an initialiser and assigned once the guards have passed.
 * Written as `u32 mask = 0;` the compiler hoists it above the first `cmp` and
 * the whole prologue shifts by two bytes.
 *
 * sub_02009200 and sub_02009208 pay an `adds r0, #0x29` before the `strb` and
 * the `ldrb`, because the byte offset 0x29 is past the 31 that the Thumb
 * immediate form reaches; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009160.c \
 *       --addr 0x02009160 --thumb
 */
u32 sub_02009160(const struct Sub020090B0Obj *obj, int row, int col, int kind)
{
    u32 mask;

    if (row >= 9 || row < 0) {
        return 0;
    }
    if (col >= 4 || col < 0) {
        return 0;
    }
    mask = 0;
    if (kind == 1) {
        mask = 0x40;
    } else if (kind == 3) {
        mask = 0x20;
    } else if (kind == 2) {
        mask = 0x10;
    }
    if (obj->unk00[row][col] & mask) {
        return 1;
    }
    return 0;
}

void sub_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind,
                  int marked, int flagged)
{
    u32 value;

    if (kind >= 5) {
        return;
    }
    if (row >= 9 || row < 0) {
        return;
    }
    if (col >= 4 || col < 0) {
        return;
    }
    value = kind;
    if (marked == 1) {
        if ((u32)(kind - 1) <= 2) {
            value |= 0x80;
        }
    }
    if (flagged) {
        if (kind == 1) {
            value |= 0x40;
        } else if (kind == 3) {
            value |= 0x20;
        } else if (kind == 2) {
            value |= 0x10;
        }
    }
    obj->unk00[row][col] = value;
}

void sub_020091FC(void)
{
}

void sub_02009200(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk29 = value;
}

u8 sub_02009208(const struct Sub020090B0Obj *obj)
{
    return obj->unk29;
}


#define BLOCK_ID 0x20


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02009290, sub_02009294, sub_020092AC, sub_020092D0,
 *           sub_020092D8, sub_020092E0, sub_020092EC, sub_020092F8,
 *           sub_02009304, sub_02009310, sub_02009330, sub_02009348,
 *           sub_02009364, sub_02009370, sub_02009390, sub_020093A8,
 *           sub_020093C8, sub_020093CC, sub_020093D0, sub_020093D4,
 *           sub_020093D8, sub_020093F0, sub_02009418, sub_02009428
 *
 * alias: the head of the save block with id 0x20, 0x1AC bytes.  The file opens
 * the way every block file in this region does: a twelve byte thunk that is
 * `SAVE_CONTROL_GetBlock(sys, 0x20)`, a four byte function returning the block size, and
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
struct Sub02009210Obj *sub_02009210(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
}


struct Sub02009210Obj *sub_0200921C(void *p)
{
    return sub_02009210(GAME_DATA_GetSaveControl(p));
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
