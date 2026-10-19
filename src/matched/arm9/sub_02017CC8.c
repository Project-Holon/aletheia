/*
 * function: POKE_TOOL_UpdateGenderForSpecies
 * address:  0x02017CC8
 * packet:   pkt_02017CC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * verdict:  EXACT* (match.py: compiled 102, listing extent 104).  The two
 *           trailing bytes at 0x02017D2E are `00 00` padding after the `pop`
 *           and the follower at 0x02017D30 carries no label, so the inferred
 *           extent runs two bytes long.  Never a byte difference; the follower
 *           is reported for the integrator rather than seeded here
 *           (layout/function_starts.txt is not this lane's file).
 *
 * symbols:
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_IsFixedGender  0x0201AF6C  thumb
 *   POKE_TOOL_CalcGender  0x02017F50  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  POKE_TOOL_GetBoxValue(void *a0, u32 a1, u32 a2);
extern u32  POKE_TOOL_GetPersonalData(void *a0, u16 a1);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern u32  POKE_PERSONAL_IsFixedGender(u32 a0);
extern u8 POKE_TOOL_CalcGender(u32 a, u16 b, u32 c);
extern void POKE_TOOL_SetBoxValue(void *a0, u32 a1, u32 a2);

void POKE_TOOL_UpdateGenderForSpecies(void *a0, void *a1, void *a2)
{
    u32 v = POKE_TOOL_GetBoxValue(a0, 0x6f, 0);
    u32 t = POKE_PERSONAL_GetParam((const struct Personal *)POKE_TOOL_GetPersonalData(a1, v), 0x14);
    u32 w = POKE_PERSONAL_GetParam((const struct Personal *)POKE_TOOL_GetPersonalData(a2, v), 0x14);

    if (POKE_PERSONAL_IsFixedGender(t) == 1 && w != 0xff) {
        return;
    }
    POKE_TOOL_SetBoxValue(a0, 0x6e, POKE_TOOL_CalcGender((u32)a1, v, POKE_TOOL_GetBoxValue(a0, 0, 0)));
}
