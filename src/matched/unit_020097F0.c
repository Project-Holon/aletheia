/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x020097F0
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020097F0
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
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

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

struct Sub020097BCObj {
    u8 unk000[0x7C4];
};

void sub_020097F0(const struct Sub020097BCObj *src, struct Sub020097BCObj *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Sub020097BCObj));
}
