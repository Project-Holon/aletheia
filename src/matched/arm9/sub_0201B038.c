/*
 * function: POKERUS_TryInfectParty
 * address:  0x0201B038
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/POKERUS_TryInfectParty.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 * symbols:
 *   _ull_mul       0x0209C054  arm
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   POKERUS_GetInfectedMask   0x0201B220  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
extern u32   POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void  POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32   POKERUS_GetInfectedMask(void *party);
extern u32   GF_STANDARD_Rand(void);
void POKERUS_TryInfectParty(void *party)
{
    u32 mask;
    u32 r;
    u32 slot;
    void *mon;
    u32 v;
    u32 w;
    u32 n;

    n = POKEPARTY_GetCount(party);
    r = (u16)((u64)GF_STANDARD_Rand() * 0x10000 >> 32);
    mask = POKERUS_GetInfectedMask(party);
    if (r == 0x4000 || r == 0x8000 || r == 0xC000) {
        do {
            slot = GF_STANDARD_Rand();
            if (n != 0) {
                slot = (u32)(((u64)slot * n) >> 32);
            }
            mon = POKEPARTY_GetMember(party, slot);
        } while (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0
                 || POKE_TOOL_GetPartyValue(mon, 0x4C, 0) != 0);
        if ((mask & (1 << slot)) != 0) {
            return;
        }
        do {
            v = (u8)((u64)GF_STANDARD_Rand() * 0x100 >> 32);
        } while ((v & 7) == 0);
        if ((v & 0xF0) != 0) {
            v = v & 7;
        }
        w = v; w |= (u8)(v << 4);
        POKE_TOOL_SetPartyValue(mon, 0x97, (u8)((u8)(w & 0xF3) + 1));
    }
}
