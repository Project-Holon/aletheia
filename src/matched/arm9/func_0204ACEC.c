/*
 * function: CLACT_RegisterPaletteCompressed
 * address:  0x0204ACEC
 * packet:   pkt_0204ACEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   lbl_02146A74   0x02146A74  data
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   CLACT_TransferPaletteDataEx  0x0204DEE8  arm
 *   func_020307B0  0x020307B0  arm
 *
 * The clact.c record-claim scan: walk the ClRes cell table for a free slot
 * (bit 31 of the element's +0x14 word), load the archive member into it and
 * return the index, or -1.
 *
 * TWO LEVERS, and it is their COMBINATION that closes it.  docs/notes/
 * pkt_0204ACEC.c.txt had each of them separately and measured each as a loss:
 *
 *  1. A named `Inner0204ACEC *in` local for the +0x104 sub-object.  Without it
 *     mwcc 1.1p1 splits the 0x11a count offset as base 0x100 + 0x1a (the ldrh
 *     8-bit immediate reaches 0x1a from 0x100) and reaches `arr` straight off
 *     the global at +0x110 (inside the ldr 12-bit immediate), so the two
 *     fields never share a base.  The image materialises `g + 0x104` once and
 *     reads both through it: `add r7, r2, #0x104` / `ldrh r2, [r7, #0x16]` /
 *     `ldr ip, [r7, #0xc]`.  Nested sub-structs and casts all fold back to the
 *     0x100 base; only a live local pointer emits the 0x104 add.  The note
 *     measured this alone at 109-138 bytes out, because it also hoists the
 *     loop bound and drops the image's back-edge count re-read.
 *  2. `volatile u16 count`, which restores that back-edge re-read
 *     (`ldrh r3, [r7, #0x16]` at +0x40).  The note measured THIS alone at
 *     188 bytes against 184 -- four bytes long -- because with the 0x100 base
 *     the volatile load costs an extra instruction it does not pay for.
 *
 * Together they are exact: the local pointer removes the base split, and the
 * volatile puts back the one load the local pointer's hoist removed.  Each
 * lever alone is a regression; the pair is EXACT.  tools/permuter.py could not
 * move the 17-byte no-local baseline at all (169 single mutations), which is
 * the declarations-not-allocation signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/CLACT_RegisterPaletteCompressed.c \
 *       --func CLACT_RegisterPaletteCompressed --addr 0x0204ACEC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Elem0204ACEC {
    u8 pad00[0x14];
    u32 f14;
} Elem0204ACEC;

typedef struct Inner0204ACEC {
    u8 pad00[0xc];
    u32 arr;
    u8 pad10[0x16 - 0x10];
    volatile u16 count;
} Inner0204ACEC;

typedef struct Outer0204ACEC {
    u32 padFFF[0x41];
    Inner0204ACEC in;
} Outer0204ACEC;

extern Outer0204ACEC *lbl_02146A74;
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
struct Holder;
extern void CLACT_TransferPaletteDataEx(struct Holder *h, int idx, void *src, void *sel, u32 size);
extern u32 func_020307B0(void *p);

int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    Inner0204ACEC *in = &lbl_02146A74->in;
    u32 i;
    void *v;
    Elem0204ACEC *arr;

    for (i = 0; i < in->count; i++) {
        arr = (Elem0204ACEC *)in->arr;
        if ((arr[i].f14 >> 31) != 0)
            goto found;
    }
    i = -1;
found:
    if (i == (u32)-1)
        return (int)i;
    v = ARC_TOOL_LoadHandleMember(a0, a1, (u16)((a4 & 0x7fff) | 0x8000));
    CLACT_TransferPaletteDataEx((struct Holder *)((Inner0204ACEC *)&lbl_02146A74->in), i, v, (void *)a2, a3);
    func_020307B0(v);
    return (int)i;
}
