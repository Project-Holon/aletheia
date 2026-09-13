/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009470
 * packet:   pkt_02009210
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009470, sub_0200947C, sub_0200949C, sub_020094D8,
 *           sub_02009524, sub_0200952C, sub_02009584
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub0200852CObj;

extern void *sub_020071CC(void *sys, u32 id);
extern void sub_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);

struct Sub02009470Obj {
    u8 unk000[0x344];
    u8 unk344;
    u8 unk345;
    u8 unk346[2];
    u8 unk348[0xFF0];
};

void sub_020094D8(struct Sub02009470Obj *obj, int row, int col, int value);
u8   sub_02009584(const struct Sub02009470Obj *obj);

struct Sub02009470Obj *sub_02009470(void *sys)
{
    return sub_020071CC(sys, 0x1D);
}

void sub_0200947C(struct Sub02009470Obj *obj, struct Sub0200852CObj *p,
                  u8 row, u8 col)
{
    sub_02008574(p, row, col);
    sub_020094D8(obj, row, col, 3);
}

u32 sub_0200949C(const struct Sub02009470Obj *obj, int row, int col)
{
    if (row == 0) {
        return 0;
    }
    return (obj->unk348[col / 4 + (row - 1) * 16] >> ((col % 4) * 2)) & 3;
}

void sub_020094D8(struct Sub02009470Obj *obj, int row, int col, int value)
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

u8 sub_02009524(const struct Sub02009470Obj *obj)
{
    return obj->unk344;
}

void sub_0200952C(struct Sub02009470Obj *obj)
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

u8 sub_02009584(const struct Sub02009470Obj *obj)
{
    return obj->unk345;
}

