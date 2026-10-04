/*
 * unit:     yes
 * function: sub_0204AEC0
 * address:  0x0204AEC0
 * packet:   pkt_0204ADEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_02063800  0x02063800  arm
 *
 * A getter and its one caller.  sub_0204AEC0 copies the 0x14-byte record
 * out of slot `idx` of the 0x18-byte-stride table at +0x110 of the
 * singleton behind 0x02146A74; the copy is an inlined `ldm`/`stm` pair plus
 * a trailing word, which is what a whole-struct assignment of this size
 * compiles to (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 * sub_0204AEF4 takes that copy on its own stack and submits it to
 * func_02063800 under selector 1 or 2.
 *
 * Kept as one unit so the `bl` at sub_0204AEF4+0x1c is `local`:
 * sub_0204AEF4 is sub_0204AEC0's only caller image-wide, so split into two
 * files the site would have no witness of any class.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Record {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
};

struct Slot {
    struct Record record;
    u32           unk_14;
};

struct Ctx {
    u8           pad_00[0x110];
    struct Slot *slots;
};

extern struct Ctx *g_02146A74;

extern int func_02063800(char *p, int i);

void sub_0204AEC0(u32 idx, struct Record *dest)
{
    *dest = g_02146A74->slots[idx].record;
}

void sub_0204AEF4(u32 idx, u32 alternate)
{
    struct Record record;
    u32 selector;

    selector = 1;
    if (alternate != 0) {
        selector = 2;
    }

    sub_0204AEC0(idx, &record);
    func_02063800((char *)(&record), selector);
}
