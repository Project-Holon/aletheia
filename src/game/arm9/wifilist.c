/*
 * file:     wifilist.c
 * unit:     yes
 * function: sub_02009448, sub_02009454, sub_0200945C, func_02009470, func_0200947C, func_0200949C, func_020094D8, func_0200952C, func_02009584, func_02009590, sub_020095C8, sub_020095E8, sub_020095FC, sub_0200960C,, sub_020097BC, func_020097C4, func_020097F0, func_02009800, func_02009860, func_02009864
 * address:  0x02009448
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
 *   sub_020071CC    0x020071CC  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02009584  0x02009584  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02009794  0x02009794  thumb
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
#define BLOCK_ID 0x23
struct Sub020071CCCtrl;
struct Sub0200852CObj;
struct Sub02009470Obj_02009448;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Sub02009448Obj {
    u8 unk0000[0x1338];
};

struct Sub02009470Obj_02009448 {
    u8 unk000[0x344];
    u8 unk344;
    u8 unk345;
    u8 unk346[2];
    u8 unk348[0xFF0];
};

typedef unsigned short u16;

struct Sub02009470Ent {
    u8  unk00[0x20];
    u16 unk20;
    u16 unk22;
    u8  unk24;
    u8  unk25;
    u8  unk26_0 : 3;
    u8  unk26_3 : 1;
    u8  unk26_4 : 1;
    u8  unk26_5 : 3;
    u8  unk27;
};

struct Sub02009470Obj_020095C8 {
    struct Sub02009470Ent unk000[20];
    u8 unk320[0x1D];
    u8 unk33D[7];
    u8 unk344;
    u8 unk345;
    u8 unk346;
    u8 unk347;
    u8 unk348[0xFF0];
};

struct Sub020097BCObj {
    u8 unk000[0x7C4];
};

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

extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void sub_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern u8 func_02009584(const struct Sub02009470Obj_02009448 *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u32 func_02009794(const struct Sub02009470Obj_02009448 *obj, u32 n);
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
struct Sub02009448Obj *sub_02009448(void *sys);
u32 sub_02009454(void);
void sub_0200945C(struct Sub02009448Obj *obj);
struct Sub02009470Obj_02009448 *sub_02009470(void *sys);
void sub_0200947C(struct Sub02009470Obj_02009448 *obj, struct Sub0200852CObj *p, u8 row, u8 col);
u32 sub_0200949C(const struct Sub02009470Obj_02009448 *obj, int row, int col);
void sub_020094D8(struct Sub02009470Obj_02009448 *obj, int row, int col, int value);
u8 sub_02009524(const struct Sub02009470Obj_02009448 *obj);
void sub_0200952C(struct Sub02009470Obj_02009448 *obj);
u8 sub_02009584(const struct Sub02009470Obj_02009448 *obj);
u8 func_02009590(void *a, u32 b, u32 c);
u8 sub_020095C8(const struct Sub02009470Obj_020095C8 *obj);
void sub_020095E8(struct Sub02009470Obj_020095C8 *obj);
void sub_020095FC(struct Sub02009470Obj_020095C8 *obj, int value);
u8 sub_0200960C(const struct Sub02009470Obj_020095C8 *obj);
void sub_02009618(struct Sub02009470Obj_020095C8 *obj, int value);
u8 sub_02009628(const struct Sub02009470Obj_020095C8 *obj);
u32 sub_02009634(const struct Sub02009470Obj_020095C8 *obj, u32 i, u32 field);
void sub_02009698(struct Sub02009470Obj_020095C8 *obj, int i, u32 field, u32 value);
struct Sub02009470Ent *sub_0200973C(struct Sub02009470Obj_020095C8 *obj, int i);
void sub_0200974C(void);
u32 sub_02009750(struct Sub02009470Obj_020095C8 *obj, u32 n);
u32 sub_02009794(const struct Sub02009470Obj_020095C8 *obj, u32 n);
u32 sub_020097BC(void);
void *func_020097C4(int a0);
void sub_020097F0(const struct Sub020097BCObj_020097F0 *src, struct Sub020097BCObj_020097F0 *dest);
void sub_02009800(void *p);
struct Sub020097BCObj_02009860 *sub_02009860(struct Sub020097BCObj_02009860 *obj);
u32 sub_02009864(const struct Sub020097BCObj_02009860 *obj, u32 i, u32 field);
void sub_02009918(struct Sub020097BCObj_02009860 *obj, u32 i, u32 field, u32 value);
struct Sub020097BCFriend *sub_020099C8(struct Sub020097BCObj_02009860 *obj, int i);
struct Sub020097BCEnt *sub_020099D4(struct Sub020097BCObj_02009860 *obj, int i);
void sub_020099E4(struct Sub020097BCObj_02009860 *obj, int i, void *dest);
void sub_02009A00(struct Sub020097BCObj_02009860 *obj, int i, void *dest);
int sub_02009A1C(struct Sub020097BCObj_02009860 *obj, u32 i);
extern char g_020A7198[];
extern unsigned char ov_id_09[];
extern unsigned char ov_id_0A[];
extern unsigned char ov_id_0B[];
extern unsigned char ov_id_0D[];





static inline void MI_CpuClear32(void *dest, u32 size)
{
    MIi_CpuClear32(0, dest, size);
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * alias: the whole of the save block with id 0x23, 0x1338 bytes: the getter,
 * the size and a constructor that clears it and does nothing else.  Three
 * functions, forty bytes, and not one of them carries a label.
 *
 * sub_02009454 is `ldr r0, [pc, #0]; bx lr` over its own pool word: 0x1338 is
 * past every Thumb immediate and past `movs` plus one `lsls`, so the constant
 * costs a word.  sub_0200945C loads the same constant into its own pool rather
 * than calling sub_02009454, so the source spells the size out in both, which
 * is what `sizeof` does.
 *
 * `MI_CpuClear32` is the SDK header's inline wrapper over MIi_CpuClear32 with
 * a zero fill value, and it is the last statement of a void function, so it
 * comes out as the pool word and `bx` of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md rather than as a `blx`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009448.c \
 *       --addr 0x02009448 --thumb
 */
struct Sub02009448Obj *sub_02009448(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}





u32 sub_02009454(void)
{
    return sizeof(struct Sub02009448Obj);
}





void sub_0200945C(struct Sub02009448Obj *obj)
{
    MI_CpuClear32(obj, sizeof(struct Sub02009448Obj));
}





/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_02009524, sub_0200952C, sub_02009584
 *
 * alias: the save block with id 0x1D.  Its bulk is a 0xFF0-byte array of
 * two-bit fields at +0x348, sixteen bytes (sixty-four fields) per row, and
 * every function here is an access into it.
 *
 * The index arithmetic is the same five instructions in the getter and the
 * setter: `b / 4` is the signed divide-by-four `asrs #1` / `lsrs #30` / `adds`
 * / `asrs #2`, and `b % 4` is the `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * / `adds` sequence.  Both are signed, so the column index is a signed `int`;
 * `& 3` and `>> 2` would each be one instruction and are not what is there.
 * The row term is added second, `b / 4 + (a - 1) * 16`, which is the operand
 * order of the `adds`.
 *
 * sub_020094D8 clears and sets in two separate read-modify-writes with a
 * `ldrb` in each, because the destination is a `u8` array element rather than
 * a bitfield.  Two spellings are load bearing there.  The mask is `0xFF ^
 * (3 << sh)` and not `~(3 << sh)`: the second gives a single `mvns`, two bytes
 * shorter, and the whole file after it shifts.  And the element is reached
 * through a pointer computed once, `u8 *p = &obj->unk348[i]`, not through an
 * index into the array: with the index spelling the compiler evaluates the
 * column modulo before the base address and twenty-four bytes are in the wrong
 * order with every register renumbered.
 *
 * NEAR MISS, 0x02009590, 56 bytes, 2 bytes wrong, skipped.  It is
 *
 *   u8 sub_02009590(const struct Sub02009470Obj *obj,
 *                   const struct Sub0200852CObj *p, int flag)
 *   {
 *       u8 v = sub_02009584(obj);
 *
 *       if (flag == 0) {
 *           u8 t = sub_0200856C(p);
 *
 *           if (t == 0) {
 *               v = 0;
 *           } else if (sub_02009794(obj) != 0 && v != 0) {
 *               v = v - 1;
 *           }
 *       }
 *       return v;
 *   }
 *
 * which reproduces 54 of its 56 bytes: same size, same schedule, same branch
 * targets.  The one instruction that differs is the test of the second call's
 * result, where the original has `adds r1, r0, #0` (a register move that sets
 * the flags) and every spelling tried gives `cmp r0, #0`.  Twenty-seven source
 * shapes were swept: six types for the temporary crossed with `== 0` and `!`,
 * the nested and the else-if arm shapes, early returns instead of the common
 * exit, a second temporary, reassigning each of the three parameters instead
 * of declaring a local, and a fourth dead parameter.  All of them are exactly
 * these two bytes out and nothing else moves, so this is register allocation
 * of a dead temporary and not a shape the source can state.
 *
 * sub_0200952C is the same field written as a rewrite pass: for every one of
 * the 0xFF0 bytes it walks the four fields and turns every 1 into a 2, keeping
 * the byte in a register across the inner loop and storing it once.  The four
 * constants it needs are hoisted out of both loops, 3 twice because one is the
 * read mask and the other the shift base.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009470.c \
 *       --addr 0x02009470 --thumb
 */
struct Sub02009470Obj_02009448 *sub_02009470(void *sys)
{
    return sub_020071CC(sys, 0x1D);
}






void sub_0200947C(struct Sub02009470Obj_02009448 *obj, struct Sub0200852CObj *p,
                  u8 row, u8 col)
{
    sub_02008574(p, row, col);
    sub_020094D8(obj, row, col, 3);
}



u32 sub_0200949C(const struct Sub02009470Obj_02009448 *obj, int row, int col)
{
    if (row == 0) {
        return 0;
    }
    return (obj->unk348[col / 4 + (row - 1) * 16] >> ((col % 4) * 2)) & 3;
}



void sub_020094D8(struct Sub02009470Obj_02009448 *obj, int row, int col, int value)
{
    u8 *p;
    int sh;

    if (row == 0) {
        return;
    }
    p = &obj->unk348[col / 4 + (row - 1) * 16];
    sh = (col % 4) * 2;
    *p &= 0xFF ^ (3 << sh);
    *p |= value << sh;
}



u8 sub_02009524(const struct Sub02009470Obj_02009448 *obj)
{
    return obj->unk344;
}



void sub_0200952C(struct Sub02009470Obj_02009448 *obj)
{
    int i;
    int j;
    u8 v;

    for (i = 0; i < 0xFF0; i++) {
        v = obj->unk348[i];
        for (j = 0; j < 8; j += 2) {
            if (((v >> j) & 3) == 1) {
                v &= 0xFF ^ (3 << j);
                v |= 2 << j;
            }
        }
        obj->unk348[i] = v;
    }
}



u8 sub_02009584(const struct Sub02009470Obj_02009448 *obj)
{
    return obj->unk345;
}




/*
 * Checks mode and validity flags, adjusting count when active.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009590.c \
 *       --addr 0x02009590 --thumb
 */
u8 func_02009590(void *a, u32 b, u32 c)
{
    u8 res = func_02009584(a);

    if (c == 0) {
        int r = func_0200856C((const struct Sub0200852CObj *)b);
        if (r == 0) {
            res = 0;
        } else if (func_02009794(a, r) && res != 0) {
            res--;
        }
    }

    return res;
}




/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           sub_02009618, sub_02009628, sub_02009634, sub_02009698,
 *           sub_0200973C, sub_0200974C, sub_02009750, sub_02009794
 *
 * alias: the rest of the save block with id 0x1D whose first half is
 * src/matched/unit_02009470.c.  This half is the twenty 0x28-byte records at
 * the front of the block, the 0xE9-bit flag array at +0x320, and the four
 * scalars at +0x344..+0x347 that sit between them.
 *
 * sub_02009634 and sub_02009698 are the getter and the setter over the record
 * fields, both dispatched through a PC-relative halfword table; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The two tables
 * are the interesting part, because they disagree.  The getter's seven entries
 * all point at real bodies, so the source has `case 0` through `case 6`.  The
 * setter's first four point at the function's exit, and those four are still
 * case labels in the source: with only `case 4`, `case 5` and `case 6` this
 * compiler abandons the table and emits a three-way `cmp` / `beq` chain, eight
 * bytes longer and a completely different function.  Four empty arms in front
 * of the real ones are what bring the table back.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * The setter also has to reach the record through a pointer,
 * `e = &obj->unk000[i]`, while the getter's `obj->unk000[i].field` spelling
 * would do: written with the index in each arm the multiply by 0x28 is
 * recomputed inside every case instead of being hoisted in front of the
 * switch, and seventy bytes move.
 *
 * The record's byte at +0x26 is three fields, and the getter is the only place
 * that says so: `lsls #0x1D` / `lsrs #0x1D` for the low three bits, then
 * `lsls #0x1C` / `lsrs #0x1F` and `lsls #0x1B` / `lsrs #0x1F` for the two bits
 * above them.  The setter writes the three-bit field as one masked assignment
 * and the two single bits as `orrs #8` / `bics #8` and `orrs #0x10` /
 * `bics #0x10`, which is an `if (value) f = 1; else f = 0;` on a one-bit
 * bitfield and not an assignment of the value itself.
 *
 * The index bound is checked unsigned in the getter (`blo`) and signed in the
 * setter and in sub_0200973C (`bge`, `blt`), so the three functions do not
 * agree about the type of their index and the source says so.
 *
 * sub_02009750 seeds its result from a literal pool word holding zero rather
 * than from a `movs`, which costs four bytes and is what the compiler does
 * here for a value initialised before a conditional; the `bne` that follows
 * reads the flags of the `adds r5, r1, #0` that moved the argument, so there
 * is no `cmp` for the first test at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020095C8.c \
 *       --addr 0x020095C8 --thumb
 */
u8 sub_020095C8(const struct Sub02009470Obj_020095C8 *obj)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (obj->unk000[i].unk26_4 == 0) {
            break;
        }
    }
    return i;
}



void sub_020095E8(struct Sub02009470Obj_020095C8 *obj)
{
    if (obj->unk345 < 0xE9) {
        obj->unk345++;
    }
}



void sub_020095FC(struct Sub02009470Obj_020095C8 *obj, int value)
{
    if (value < 5) {
        obj->unk347 = value;
    }
}



u8 sub_0200960C(const struct Sub02009470Obj_020095C8 *obj)
{
    return obj->unk347;
}



void sub_02009618(struct Sub02009470Obj_020095C8 *obj, int value)
{
    if (value < 9) {
        obj->unk346 = value;
    }
}



u8 sub_02009628(const struct Sub02009470Obj_020095C8 *obj)
{
    return obj->unk346;
}



u32 sub_02009634(const struct Sub02009470Obj_020095C8 *obj, u32 i, u32 field)
{
    const struct Sub02009470Ent *e;

    if (i >= 20) {
        return 0;
    }
    e = &obj->unk000[i];
    switch (field) {
    case 0:
        return e->unk20;
    case 1:
        return e->unk22;
    case 2:
        return e->unk24;
    case 3:
        return e->unk25;
    case 4:
        return e->unk26_0;
    case 5:
        return e->unk26_3;
    case 6:
        return e->unk26_4;
    }
    return 0;
}



void sub_02009698(struct Sub02009470Obj_020095C8 *obj, int i, u32 field, u32 value)
{
    struct Sub02009470Ent *e;

    if (i >= 20) {
        return;
    }
    e = &obj->unk000[i];
    switch (field) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (value < 5) {
            e->unk26_0 = value;
        }
        break;
    case 5:
        if (value) {
            e->unk26_3 = 1;
        } else {
            e->unk26_3 = 0;
        }
        break;
    case 6:
        if (value) {
            e->unk26_4 = 1;
        } else {
            e->unk26_4 = 0;
        }
        break;
    }
}



struct Sub02009470Ent *sub_0200973C(struct Sub02009470Obj_020095C8 *obj, int i)
{
    if (i >= 20) {
        return 0;
    }
    return &obj->unk000[i];
}



void sub_0200974C(void)
{
}



u32 sub_02009750(struct Sub02009470Obj_020095C8 *obj, u32 n)
{
    u32 ret = 0;

    if (n == 0) {
        return ret;
    }
    if (n < 0xE9) {
        if (sub_02009794(obj, n) == 0) {
            ret = 1;
        }
        obj->unk320[n >> 3] |= (u8)(1 << (u8)(n & 7));
    }
    return ret;
}



u32 sub_02009794(const struct Sub02009470Obj_020095C8 *obj, u32 n)
{
    if (n < 0xE9) {
        u8 bit = (obj->unk320[n >> 3] >> (u8)(n & 7)) & 1;

        if (bit != 0) {
            return 1;
        }
    }
    return 0;
}



u32 sub_020097BC(void)
{
    return sizeof(struct Sub020097BCObj);
}



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
