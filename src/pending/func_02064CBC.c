/*
 * function: func_02064CBC
 * address:  0x02064CBC
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_0206469C   0x0206469C  arm
 *   func_020643A4   0x020643A4  arm
 *
 * Rebuilds every node's SRT block in one pass: clears the counter at +0x30,
 * re-derives the current frame through func_0206469C, marks the node active at
 * +0x0C, then restarts each node's cell animation from frame 0 through
 * func_020643A4 in the same two layouts the other walks use (kind 1 is the
 * 0x5C-stride node array with its count at header +2, anything else the
 * 0x28-stride cell array with its count at header +0).
 *
 * The kind and header this function dispatches on are the +0x3C / +0x34 pair,
 * not the +0x08 / +0x00 pair func_02064934 reads, and func_0206469C is called
 * with the object's +0x1C field as a second argument.
 *
 * Residue, twelve bytes / three instructions, all register allocation.  The
 * original clears +0x30 with a fresh zero (`mov r1, #0`), keeps the counter in
 * r4 and the base in r5, and loads the kind before the header; this C reuses
 * the loop's zero (`mov r5, #0`), keeps the counter in r5 and the base in r4,
 * and hoists the base load above the kind test.  Every field offset and both
 * loops are byte-identical once the struct padding is right (`hdr2` at +0x34,
 * `kind2` at +0x3C with four bytes of padding between them); getting that
 * padding wrong costs 135 bytes, not twelve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064CBC.c \
 *       --func func_02064CBC --addr 0x02064CBC --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct NodeHdr02064CBC {
    u16 pad_00;
    u16 count;
};

struct CellHdr02064CBC {
    u16 count;
};

struct Obj02064CBC {
    u8    pad_00[0x0c];
    u32   unk_0c;   /* +0x0C */
    u8    pad_10[0x0c];
    void *unk_1c;   /* +0x1C */
    u8    pad_20[0x10];
    u16   unk_30;   /* +0x30 */
    u8    pad_32[2];
    void *hdr2;     /* +0x34 */
    u8    pad_38[4];
    u32   kind2;    /* +0x3C */
    void *base;     /* +0x40 */
};

extern void func_0206469C(void *o, void *frame);
extern void func_020643A4(void *anim);

void func_02064CBC(struct Obj02064CBC *x)
{
    u16 i;

    x->unk_30 = 0;
    func_0206469C(x, x->unk_1c);
    x->unk_0c = 1;

    if (x->kind2 == 1) {
        void *base = x->base;

        for (i = 0; i < ((struct NodeHdr02064CBC *)x->hdr2)->count; i++) {
            func_020643A4((u8 *)base + i * 0x5c);
        }
    } else {
        void *base = x->base;

        for (i = 0; i < ((struct CellHdr02064CBC *)x->hdr2)->count; i++) {
            func_020643A4(*(void **)((u8 *)base + i * 0x28));
        }
    }
}
