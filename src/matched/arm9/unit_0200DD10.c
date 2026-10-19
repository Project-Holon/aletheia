/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200DD10
 * packet:   pkt_0200D6D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BSUBWAY_WIFIDATA_GetSize, BSUBWAY_WIFIDATA_Init
 *
 * 24 bytes, 0x0200DD10..0x0200DD28, the size getter and the constructor of
 * the save block this file belongs to: 0xB90 bytes, of which the first four
 * are a packed stamp and the next 250 are a bitmap of 2000 bits.  Neither
 * function carries a label in the generated listing.
 *
 * Near miss, and the reason this unit stops at 0x0200DD28: BSUBWAY_WIFIDATA_SetTrainerBit,
 * 104 bytes, which sets one bit of that bitmap and then packs four bytes
 * into the stamp word.  It is
 *
 *     void BSUBWAY_WIFIDATA_SetTrainerBit(struct BlkB90 *p, u32 a, u32 b,
 *                        const struct Stamp *q)
 *     {
 *         u16 idx;
 *         u8 sh;
 *
 *         if (b == 0 || b > 200 || a == 0 || a > 10) {
 *             return;
 *         }
 *         idx = (a - 1) * 200 + (b - 1);
 *         sh = idx % 8;
 *         p->unk04[(u8)(idx / 8)] |= (u8)(1 << sh);
 *         p->unk00 = (q->unk00 << 24) | ((q->unk04 << 24) >> 8)
 *                  | ((q->unk08 << 24) >> 16) | q->unk0C;
 *     }
 *
 * and that reproduces the size to the byte and every instruction, in the
 * same order bar one, with a different register assignment throughout.  The
 * original keeps the block pointer in r0 and moves the stamp pointer out of
 * r3 into r4, saving three registers; this source moves both, saves four,
 * and schedules the `lsls #0x15` that forms the byte index twenty-two bytes
 * early, which is the one live value that costs it r7.  Sixteen spellings
 * were tried: the modulo and the division as `%`/`/` and as shifts, the
 * byte index as a `u8` cast, an `& 0xFF` and a named `u8` local, the bit as
 * a named local and at the use, the guard positive and negative, the two
 * statements in both orders, the stamp as a struct pointer and as a `u32 *`,
 * and `const` on either pointer.  Every one of them produces the same 104
 * bytes with the same allocation, so the shift-amount truncation and the
 * cast at the use (docs/idioms, sub_0200A6BC) are already right and what is
 * left is not reachable from the source shape.  Forty bytes differ and every
 * one of them is a register number.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

struct BlkB90 {
    u32 unk00;
    u8  unk04[250];
    u8  unkFE[0xA92];
};

u32 BSUBWAY_WIFIDATA_GetSize(void)
{
    return sizeof(struct BlkB90);
}

void BSUBWAY_WIFIDATA_Init(struct BlkB90 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct BlkB90));
}
