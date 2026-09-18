/*
 * function: func_02064934
 * address:  0x02064934
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_02064364   0x02064364  arm
 *
 * Dispatches the "advance one frame" call over every node of the multi-cell
 * bank in the two layouts the header discriminates: kind 1 is the node array
 * (0x5C-byte records, count at header +2, the record address passed), anything
 * else the cell array (0x28-byte stride, count at header +0, the pointer
 * stored in each record's word 0 passed).  func_02064364 takes one argument;
 * r1 carries the caller's own second parameter, which is why it is declared
 * and passed through here.
 *
 * Residue, four bytes, one instruction: the order in which the two locals and
 * the hoisted header load are set up.  The original emits `ldr r0, [r7]`
 * (header), `mov r4, #0` (counter), `ldr r5, [r7, #0xc]` (base); this C emits
 * base, counter, header.  Everything from the branch on is byte-identical,
 * including both loops.  Shape matters: the counter must be initialised at the
 * declaration and the loops written `for (; i < x->hdr->count; i++)` (nine
 * bytes of residue with the init in the `for`, sixteen with the base declared
 * first).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02064934.c \
 *       --func func_02064934 --addr 0x02064934 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct NodeHdr02064934 {
    u16 pad_00;
    u16 count;
};

struct CellHdr02064934 {
    u16 count;
};

struct Render02064934 {
    void *hdr;      /* +0x00 */
    u32   unk_04;
    u32   kind;     /* +0x08 */
    void *base;     /* +0x0C */
};

extern void func_02064364(void *anim, void *arg);

void func_02064934(struct Render02064934 *x, void *arg)
{
    u16 i = 0;
    void *base = x->base;

    if (x->kind == 1) {
        for (; i < ((struct NodeHdr02064934 *)x->hdr)->count; i++) {
            func_02064364((u8 *)base + i * 0x5c, arg);
        }
    } else {
        for (; i < ((struct CellHdr02064934 *)x->hdr)->count; i++) {
            func_02064364(*(void **)((u8 *)base + i * 0x28), arg);
        }
    }
}
