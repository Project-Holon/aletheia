/*
 * unit:     no
 * function: sub_0204D4B4
 * address:  0x0204D4B4
 * packet:   pkt_0204D478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     promoted 2026-09-21: the blocker named below, 0x02064AB4, was
 *           filed EXACT as src/matched/func_02064AB4.c (pin ../2.0/sp2) by the
 *           pkt_02064934 lane, so the sole ABS32 site now resolves `matched`.
 *
 * symbols:
 *   sub_02064AB4  0x02064AB4  arm
 *
 * The third row-0 handler of the table at 0x020A1394 (row map in
 * src/matched/func_0204D324.c).  Same shape as the two in
 * src/matched/unit_0204D494.c, tail calling the +0xc subobject through a pool
 * word, but to a different target.  It saves nothing, so disasm.py gives it
 * no label.
 *
 * Was blocked on: no evidence class at all.  `--suggest-split` reported zero
 * witnesses image-wide for 0x02064AB4: nothing branches to it (so no `label`),
 * no other pool holds the word (so no `literal`), and it is inside the G2D
 * block that has no matched entry yet.  The address is reachable only through
 * this table row, which is why it never appears as a branch target.  It will
 * resolve as `matched` once the G2D function at 0x02064AB4 is decompiled, or
 * as `label` if an overlay turns out to call it directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D4B4.c \
 *       --func sub_0204D4B4 --addr 0x0204D4B4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj0204D4B4 {
    u32 kind;
    u8  pad_04[8];
    u8  unk_0c;
};

extern void sub_02064AB4(void *p, u32 i);

void sub_0204D4B4(struct Obj0204D4B4 *o, u32 i)
{
    sub_02064AB4(&o->unk_0c, i);
}
