/*
 * function: POKE_TOOL_AdjustPersonalRnd
 * address:  0x0201862C
 * packet:   pkt_0201862C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetGenderPersonalityByte  0x020185F8  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_IsFixedGender  0x0201AF6C  thumb
 *
 * Force a personality value's shininess against trainer id a0: with a5 set,
 * a fresh value from POKE_TOOL_GetGenderPersonalityByte whose high half is made to xor to the
 * id's key; otherwise an all-0xFF00 construction plus the species' stage
 * byte.  Bit 16 is then forced to a4.  Wave 11, 2026-09-23.
 *
 * The 9-byte residue of 2026-09-22 (permuter floor, `commute(^)`) closed by
 * naming the id key as a block-scoped local, `k = hi(a0) ^ (u16)a0`, and
 * writing `k ^ (u16)v`: the key is computed first into r2 and the chain
 * stays in r1/r2, as the image has it.  No inline form of the same xor
 * reached it (docs/notes/pkt_0201862C.c.txt).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 POKE_TOOL_GetGenderPersonalityByte(int a0, int a1, int a2);
struct Personal;
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern u32 POKE_PERSONAL_IsFixedGender(u32 v);

u32 POKE_TOOL_AdjustPersonalRnd(u32 a0, u16 a1, u16 a2, u8 a3, u8 a4, int a5)
{
    if (a5 != 0) {
        u32 v = POKE_TOOL_GetGenderPersonalityByte(a1, a2, a3);

        {
            u32 k = ((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0;

            a0 = v | ((k ^ (u16)v) << 16);
        }
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
    } else {
        u8 b = (u8)POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(a1, a2), 0x14);

        a0 = (0xFF00u ^ ((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) & 0xFF00u)) << 16;
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
        if (POKE_PERSONAL_IsFixedGender(b) == 1) {
            goto done;
        }
        a0 |= b;
        if (a3 == 1) {
            a0 -= 1;
        }
    }
done:
    return a0;
}
