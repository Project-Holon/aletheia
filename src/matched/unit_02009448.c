/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02009448
 * packet:   pkt_02009210
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02009448, sub_02009454, sub_0200945C
 *
 * symbols:
 *   sub_020071CC    0x020071CC  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * alias: the whole of the save block with id 0x23, 0x1338 bytes: the getter,
 * the size and a constructor that clears it and does nothing else.  Three
 * functions, forty bytes, and not one of them carries a label.
 *
 * sub_02009454 is `ldr r0, [pc, #0]; bx lr` over its own pool word: 0x1338 is
 * past every Thumb immediate and past `movs` plus one `lsls`, so the constant
 * costs a word.  sub_0200945C loads the same constant into its own pool rather
 * than calling sub_02009454, so the source spells the size out in both, which
 * is what `sizeof` does.
 *
 * `MI_CpuClear32` is the SDK header's inline wrapper over MIi_CpuClear32 with
 * a zero fill value, and it is the last statement of a void function, so it
 * comes out as the pool word and `bx` of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md rather than as a `blx`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009448.c \
 *       --addr 0x02009448 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_020071CC(void *sys, u32 id);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

static inline void MI_CpuClear32(void *dest, u32 size)
{
    MIi_CpuClear32(0, dest, size);
}

#define BLOCK_ID 0x23

struct Sub02009448Obj {
    u8 unk0000[0x1338];
};

struct Sub02009448Obj *sub_02009448(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

u32 sub_02009454(void)
{
    return sizeof(struct Sub02009448Obj);
}

void sub_0200945C(struct Sub02009448Obj *obj)
{
    MI_CpuClear32(obj, sizeof(struct Sub02009448Obj));
}
