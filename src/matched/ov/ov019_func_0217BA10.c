/*
 * function: UNION_ONESELF_LoadRegulation
 * address: 0x0217BA10
 * packet: pkt_ov019_0217BA10
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0201A364 has no witness outside this caller range.
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. the integrator owns it.
 * symbols:
 *   UNION_ONESELF_GetRegulationId 0x0217B908 thumb ov019
 *   UNION_ONESELF_GetRegulationFlag 0x0217B974 thumb ov019
 *   POKE_REGULATION_LoadInto 0x0201A364 thumb
 *   REGULATION_SetRuleValue 0x0200AEE8 thumb
 */
extern int UNION_ONESELF_GetRegulationId(int);
extern int UNION_ONESELF_GetRegulationFlag(int);
extern void POKE_REGULATION_LoadInto(int a, unsigned int b);
typedef signed int     s32;
typedef unsigned int   u32;
struct Reg;
extern void REGULATION_SetRuleValue(struct Reg *p, u32 id, s32 value);
void UNION_ONESELF_LoadRegulation(char *p, int x)
{
    POKE_REGULATION_LoadInto(UNION_ONESELF_GetRegulationId(x), (unsigned int)(*(void **)(p + 0x352c)));
    if (UNION_ONESELF_GetRegulationFlag(x) == 1) REGULATION_SetRuleValue(*(void **)(p + 0x352c), 13, 1);
    else REGULATION_SetRuleValue(*(void **)(p + 0x352c), 13, 0);
}
