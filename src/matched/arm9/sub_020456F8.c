/*
 * unit:     no
 * address:  0x020456F8
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020456F8
 *
 * symbols:
 *   sub_02041300  0x02041300  arm
 *
 * A seven-argument forwarder over the descriptor object whose leaf
 * accessor bank is src/matched/unit_02045730.c: it unpacks six u8 fields
 * and a constant zero out of the descriptor and hands them to
 * sub_02041300, which is where the actual work happens.
 *
 *   sub_02041300(d->unk2, 0, d->unk3, d->unk4, d->unk5, d->unk6, 0)
 *
 * Register arguments are r0..r3, and the remaining three ride the 12-byte
 * stack frame the prologue carves out with `sub sp, sp, #0xc`. The
 * compiler spots that the last two stack slots are adjacent and writes
 * d->unk5 (already in r0) and the zero (already in r1) with a single
 * `stmib sp, {r0, r1}` rather than two stores, which is what makes the
 * second and third stack argument order legible: had the zero been
 * anywhere but last, the store pair would not have fused.
 *
 * The single-register prologue is `stmdb sp!, {lr}` / `ldm sp!, {pc}`
 * rather than push/pop of a pair, because nothing here needs a
 * callee-saved register: every field load feeds its argument slot
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020456F8.c \
 *       --func sub_020456F8 --addr 0x020456F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Descriptor {
    u16   unk0;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

extern void sub_02041300(int a, int b, int c, int d, int e, int f, int g);

void sub_020456F8(struct Descriptor *d)
{
    sub_02041300(d->unk2, 0, d->unk3, d->unk4, d->unk5, d->unk6, 0);
}
