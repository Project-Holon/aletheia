/*
 * function: sub_0200AC14
 * address:  0x0200AC14
 * packet:   pkt_0200AC14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *
 * The Entry constructor of the family (see docs/families/mystery_data.h):
 * clear the 0x1C-byte record, copy 8 halfwords from `src` into the first
 * 16 bytes with sub_0201F41C, then fill the packed word at +0x10, the key at
 * +0x14, the halfword at +0x18, the byte at +0x1A and the two bit-packed
 * fields of +0x1B, and finally set the top bit of +0x10 and bit 7 of +0x1B.
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200AC14.c.txt had this row at DIFF
 * with three independent residue groups, "no recoverable source in this note"
 * on the 2026-09-21 re-verify).  The note read the eight stack words at
 * sp+0x18..sp+0x34 as ONE 0x20-byte parameter block passed BY VALUE, because
 * the function takes its address once (`add r0, sp, #0x18`) and then reads
 * fields off it with `ldrb r1, [r0, #4]`, `ldrh r1, [r0, #0xc]` and so on.
 * That reading is wrong, and it is what produced all three residues.
 *
 * They are EIGHT SEPARATE SCALAR PARAMETERS of narrow types:
 *
 *     u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7
 *
 * Each occupies its own word of the incoming argument area (the ABI passes
 * every stack argument in a word slot regardless of width), so the OFFSETS
 * are identical to the struct reading and the disassembly cannot tell the two
 * apart by offset alone.  What tells them apart is the LOAD WIDTH: a struct
 * member of declared type u8 and a u8 parameter both read `ldrb`, but only
 * the scalar form lets the compiler base every one of them off a single
 * `add r0, sp, #0x18` while keeping p3 as a plain `ldr r0, [sp, #0x24]`
 * scheduled ahead of the +0x10 store -- which is residue 1 of the note,
 * unreachable from the struct form.  Residues 2 and 3 fall out with it: the
 * a3 insert accumulates into the keep register and the bit-6 insert keeps its
 * explicit `& 1` and `(u8)` cast, both of which the struct form folded.
 *
 * The permuter confirms the struct form is a dead end rather than a spelling
 * problem: on the 188-byte, 10-concrete-bytes-out struct version,
 *   --mode hill  --budget 800  --types: 158 single mutations, no improvement
 *   --mode anneal --budget 3000 --types: 3000 compiles in 204s, completely
 *   flat at asm=400 bytes-out=10 the whole way, never once leaving the
 *   plateau.
 * A residue no mutation of the statement shape can reach is a residue in the
 * DECLARATIONS, and re-reading the parameter list was what closed it.
 *
 * The bitfield widths of Self are the ones src/matched/unit_0200A864.c
 * already evidences for this family's Entry record (7 / 10 / 1 at +0x10,
 * 6 / 1 / 1 at +0x1B); the four extra sub-fields between them (4 / 4 / 5)
 * are read off this function's own mask pool words 0xFFFDFFFF, 0xFFC3FFFF
 * and 0xFC3FFFFF at 0x0200ACC0..0x0200ACCC.
 *
 * The top bit at the end must be written `(f10 & 0x7FFFFFFF) | 0x80000000`
 * -- which is what the `b6 : 1` bitfield assignment compiles to -- and not
 * `f10 |= 0x80000000`, which loses the `ldr r0, =0x7FFFFFFF / adds r0, r0, #1`
 * pair at +0x96.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AC14.c \
 *       --func sub_0200AC14 --addr 0x0200AC14 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 w0[8];
    u32 b0 : 7;
    u32 b1 : 10;
    u32 b2 : 1;
    u32 b3 : 4;
    u32 b4 : 4;
    u32 b5 : 5;
    u32 b6 : 1;
    u32 f14;
    u16 f18;
    u8  f1a;
    u8  c0 : 6;
    u8  c1 : 1;
    u8  c2 : 1;
} Self;

extern void MI_CpuFill8(void *p, int c, u32 n);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);

void sub_0200AC14(Self *self, const void *src, u32 a2, u32 a3,
                  u8 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7)
{
    MI_CpuFill8(self, 0, 0x1c);
    sub_0201F41C(src, self->w0, 8);
    self->b0 = a2;
    self->f14 = p3;
    self->b2 = p0;
    self->b3 = p1;
    self->b4 = p2;
    self->b1 = a3;
    self->f18 = p4;
    self->f1a = p5;
    self->c0 = p6;
    self->c1 = (u8)(p7 & 1u);
    self->b6 = 1;
    self->c2 = 1;
}
