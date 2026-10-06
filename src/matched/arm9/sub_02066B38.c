/*
 * unit:     no
 * function: sub_02066B38
 * address:  0x02066B38
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_02148B20  0x02148B20  data
 *   sub_020640B0   0x020640B0  arm
 *
 * Release one 0x30-byte cell of the bank whose array pointer lives at
 * +8 of the global at 0x02148B20: hand it to sub_020640B0, then clear the
 * nine words from +0xc to +0x2c.
 *
 * The element address is one `mla`, not a shift and an add, because 0x30 is
 * not a power of two: the size goes into r1, the array base into r2, and
 * the multiply-accumulate produces the cell pointer in one instruction.
 *
 * Nine separate `str` of the same register rather than a fill loop or a
 * call: the zero is materialised once in r0 after the call returns and
 * reused at all nine sites, which is what a run of plain field assignments
 * gives at this size.  The neighbouring cell fields at +0 to +8 are left
 * alone, so this is field-by-field clearing in the source, not a
 * `MI_CpuFill8` over a sub-range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02066B38.c \
 *       --func sub_02066B38 --addr 0x02066B38 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Cell {
    u8  pad_00[0x0c];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
};

struct Bank {
    u8           pad_00[8];
    struct Cell *cells;
};

extern struct Bank gUnk_02148B20;
typedef signed int     s32;
extern void sub_020640B0(s32 *tbl);

void sub_02066B38(u32 idx)
{
    struct Cell *c = &gUnk_02148B20.cells[idx];

    sub_020640B0((s32 *)c);
    c->unk_0c = 0;
    c->unk_10 = 0;
    c->unk_14 = 0;
    c->unk_18 = 0;
    c->unk_1c = 0;
    c->unk_20 = 0;
    c->unk_24 = 0;
    c->unk_28 = 0;
    c->unk_2c = 0;
}
