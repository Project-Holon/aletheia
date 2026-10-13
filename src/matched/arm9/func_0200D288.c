/*
 * function: ZUKAN_SAVE_GetSpindaPersonality
 * address:  0x0200D288
 * packet:   pkt_0200D144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 16-byte leaf that follows ZUKAN_SAVE_HasSeenGenderForm inside its listing extent
 * (0x0200D288..0x0200D298): `cmp r1, #0 / bne / movs r1, #0x4d / lsls r1,
 * #4 / ldr r0, [r0, r1] / bx lr / movs r0, #0 / bx lr`.  It saves nothing,
 * so disasm.py never labels it (docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md); filed as its own compiled witness in wave 13.  It reads
 * struct Blk37's +0x4D0 word, the first-write-wins species-0x147 cache that
 * ZUKAN_SAVE_RegisterCaught/ZUKAN_SAVE_RegisterSeen fill (docs/families/musical_dist_save.h), and
 * answers 0 for any selector but 0.  Wants seeding into
 * layout/function_starts.txt.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Blk37 {
    u32 unk00;
    u32 unk04;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which)
{
    if (which == 0) {
        return p->unk4D0;
    }
    return 0;
}
