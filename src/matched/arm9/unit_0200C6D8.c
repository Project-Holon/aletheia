/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200C6D8
 * packet:   pkt_0200C52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MUSICAL_DIST_SAVE_GetPayload, MUSICAL_DIST_SAVE_GetPayloadSize, MUSICAL_DIST_SAVE_GetBlockSize, MUSICAL_DIST_SAVE_NoOp,
 *           MUSICAL_DIST_SAVE_IsFooterSet, ZUKAN_SAVE_IsInvalidSpecies
 *
 * 96 bytes, 0x0200C6D8..0x0200C738, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * alias: this range is inside "musical_dist_save.c".  The constructor of the
 * file, MUSICAL_DIST_SAVE_Create, loads 0x020A71D4 as the file-name argument to the
 * debug allocator at 0x02030734, and the bytes at 0x020A71D4 spell
 * "musical_dist_save.c"; the string before it is "battle_rec.c", whose
 * terminator at 0x020A71DF fixes that start.  That is the fourth original
 * source file name this project has recovered, after "playtime.c",
 * "box_savedata.c" and "battle_rec.c".  The functions keep their
 * `func_<address>` names, because the file identity is attested and the
 * individual entry points are not.
 *
 * The two getters at the top reach the 0x2C-byte object MUSICAL_DIST_SAVE_Create
 * allocates; MUSICAL_DIST_SAVE_IsFooterSet works on a 0x2000-byte buffer instead, comparing
 * the 0x20 bytes at +0x1FE0 against a cleared stack copy of the same length,
 * which is a "is this record still blank" test.  MUSICAL_DIST_SAVE_NoOp is `bx lr` and
 * nothing else, a hook that was never filled in.
 *
 * ZUKAN_SAVE_IsInvalidSpecies is the shape docs/idioms/the-fall-through-arm-is-the-source-order.md
 * warns about, read the other way: the `beq` jumps **into** the `return 1`
 * block and the `bls` jumps **past** it, which is the short-circuit `||` of
 * one `if`, not two statements.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

struct Blk2C {
    u8   unk00[0x20];
    u32 *unk20;
    u32  unk24;
    u32  unk28;
};

struct Buf2000 {
    u8 unk0000[0x1FE0];
    u8 unk1FE0[0x20];
};

u32 MUSICAL_DIST_SAVE_GetPayload(struct Blk2C *p)
{
    return p->unk24;
}

u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct Blk2C *p)
{
    return *p->unk20;
}

u32 MUSICAL_DIST_SAVE_GetBlockSize(void)
{
    return 0x2600;
}

void MUSICAL_DIST_SAVE_NoOp(void)
{
}

u32 MUSICAL_DIST_SAVE_IsFooterSet(struct Buf2000 *p)
{
    u8 blank[0x20];
    u32 r = 0;

    MI_CpuFill8(blank, 0, sizeof(blank));
    if (func_0203EFC8(blank, p->unk1FE0, sizeof(blank)) != 0) {
        r = 1;
    }
    return r;
}

u32 ZUKAN_SAVE_IsInvalidSpecies(u32 v)
{
    if (v == 0 || v > 0x289) {
        return 1;
    }
    return 0;
}
