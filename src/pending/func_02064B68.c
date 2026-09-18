/*
 * function: func_02064B68
 * address:  0x02064B68
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_020643C4   0x020643C4  arm
 *
 * Hands every node of the renderer to func_020643C4 with the caller's argument,
 * in the two layouts the kind word at +0x3C discriminates (kind 1: 0x5C-byte
 * records at the base, count at header +2; otherwise the pointer in each
 * 0x28-byte record's word 0, count at header +0).  The argument is stashed at
 * +0x14 and the header pointer at +0x34 must be `volatile`, otherwise the two
 * arms' opening load is common-subexpression-eliminated and hoisted above the
 * branch, four bytes shorter.
 *
 * Residue, fifteen bytes: one field load scheduled after a field store instead
 * of before it.  The original reads the array base at +0x40 (L) before storing
 * the argument at +0x14 (S); every spelling tried stores first, and the
 * conservative order for two accesses through the same pointer is store-last,
 * which is what this C produces.  Everything from +0x20 on is byte-identical.
 * See docs/notes/sub_02064B68.c.txt for the four spellings tried and for the
 * file this entry unblocks once it is EXACT (src/pending/sub_0204D500.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02064B68.c \
 *       --func func_02064B68 --addr 0x02064B68 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct NodeHdr02064B68 { u16 pad_00; u16 count; };
struct CellHdr02064B68 { u16 count; };

struct Node02064B68 { u8 pad_00[0x5c]; };
struct Cell02064B68 { void *unk_00; u8 pad_04[0x24]; };

union Hdr02064B68 {
    struct NodeHdr02064B68 *nodes;
    struct CellHdr02064B68 *cells;
};

struct Renderer02064B68 {
    u8                 pad_00[0x14];
    void              *unk_14;
    u8                 pad_18[0x1c];
    union Hdr02064B68 volatile unk_34;
    u8                 pad_38[4];
    u32                unk_3c;
    void              *unk_40;
};

extern void func_020643C4(void *p, void *arg);

void func_02064B68(struct Renderer02064B68 *r, void *arg)
{
    u16 i = 0;
    void *base = r->unk_40;

    r->unk_14 = arg;

    if (r->unk_3c == 1) {
        for (i = 0; i < r->unk_34.nodes->count; i++) {
            func_020643C4(&((struct Node02064B68 *)base)[i], arg);
        }
    } else {
        for (i = 0; i < r->unk_34.cells->count; i++) {
            func_020643C4(((struct Cell02064B68 *)base)[i].unk_00, arg);
        }
    }
}
