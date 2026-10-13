/*
 * function: SODATEYA_BuildEgg
 * address:  0x021C38F4
 * packet:   pkt_ov021_021C38F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Day-care offspring builder: runs every step of the 0x8C-byte work
 * record over the parent pair m and hands the result to SODATEYA_SetupEggMon.
 * Callee prototypes without a matched file are written from the call
 * site's argument registers.
 * symbols:
 *   SODATEYA_SortParentsByGender  0x021C3A00  thumb  ov021
 *   SODATEYA_PutDittoSecond  0x021C3A44  thumb  ov021
 *   SODATEYA_InitEgg  0x021C3A7C  thumb  ov021
 *   SODATEYA_SetBaseSpecies  0x021C3A90  thumb  ov021
 *   SODATEYA_RollNidoranSpecies  0x021C3AAC  thumb  ov021
 *   SODATEYA_RollVolbeatSpecies  0x021C3ADC  thumb  ov021
 *   SODATEYA_ApplyPhioneRule  0x021C3B0C  thumb  ov021
 *   SODATEYA_ApplyIncenseBabyRule  0x021C3B2C  thumb  ov021
 *   SODATEYA_ResetEggForm  0x021C3BCC  thumb  ov021
 *   SODATEYA_InheritFormShellos  0x021C3BD4  thumb  ov021
 *   SODATEYA_InheritFormBurmy  0x021C3C04  thumb  ov021
 *   SODATEYA_InheritFormBasculin  0x021C3C30  thumb  ov021
 *   SODATEYA_RollNature  0x021C3C78  thumb  ov021
 *   SODATEYA_ApplyEverstoneRule  0x021C3C88  thumb  ov021
 *   SODATEYA_RollAbilitySlot  0x021C3D1C  thumb  ov021
 *   SODATEYA_RollDittoAbilitySlot  0x021C3DA8  thumb  ov021
 *   SODATEYA_SetAbilityFromSlot  0x021C3DE4  thumb  ov021
 *   SODATEYA_SetBaseFriendship  0x021C3E38  thumb  ov021
 *   SODATEYA_ApplyPowerItemRule  0x021C3E64  thumb  ov021
 *   SODATEYA_RollRandomIvInheritance  0x021C3F60  thumb  ov021
 *   SODATEYA_CopyInheritedIvs  0x021C3FC0  thumb  ov021
 *   SODATEYA_SetOtId  0x021C4018  thumb  ov021
 *   SODATEYA_RollPersonalRnd  0x021C4024  thumb  ov021
 *   SODATEYA_ApplyMasudaMethod  0x021C4030  thumb  ov021
 *   SODATEYA_AddLevelUpMoves  0x021C4084  thumb  ov021
 *   SODATEYA_AddEggMoves  0x021C40F8  thumb  ov021
 *   SODATEYA_AddSharedMoves  0x021C4160  thumb  ov021
 *   SODATEYA_AddTmMoves  0x021C4238  thumb  ov021
 *   SODATEYA_AddVoltTackle  0x021C42BC  thumb  ov021
 *   SODATEYA_SetupEggMon  0x021C4340  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 w[0x23]; } S;

extern void SODATEYA_SortParentsByGender(u32 *m);
extern void SODATEYA_PutDittoSecond(void **p);
extern void SODATEYA_InitEgg(S *s);
extern void SODATEYA_SetBaseSpecies(void *a, u32 *out);
extern void SODATEYA_RollNidoranSpecies(void *a, u32 *out);
extern void SODATEYA_RollVolbeatSpecies(void *a, u32 *out);
extern void SODATEYA_ApplyPhioneRule(void *a, u32 *out);
extern void SODATEYA_ApplyIncenseBabyRule(u32 *p, u32 *q);
extern int SODATEYA_ResetEggForm(u32 a, u32 b);
extern void SODATEYA_InheritFormShellos(void *a, u32 *out);
extern void SODATEYA_InheritFormBurmy(void *a, u32 *out);
extern void SODATEYA_InheritFormBasculin(void *a, u32 *out);
extern void SODATEYA_RollNature(void *a, u32 *out);
extern void SODATEYA_ApplyEverstoneRule(u32 *p, u32 *q);
extern void SODATEYA_RollAbilitySlot(u32 *p, u32 *q, u32 d);
extern void SODATEYA_RollDittoAbilitySlot(void **p, u32 *out);
extern void SODATEYA_SetAbilityFromSlot(u32 *m, u32 *s, u32 heap);
extern void SODATEYA_SetBaseFriendship(u32 *p, u32 heap);
extern void SODATEYA_ApplyPowerItemRule(u32 *m, S *s);
extern void SODATEYA_RollRandomIvInheritance(int a, u32 *p);
extern void SODATEYA_CopyInheritedIvs(u32 *a, u32 *b);
extern void SODATEYA_SetOtId(int a, char *p);
extern void SODATEYA_RollPersonalRnd(int a, char *p);
extern void SODATEYA_ApplyMasudaMethod(u32 *p, u32 *q);
extern void SODATEYA_AddLevelUpMoves(u32 *p);
extern void SODATEYA_AddEggMoves(u32 *p, u32 *q, u32 heap);
extern void SODATEYA_AddSharedMoves(u32 *p, u32 *q);
extern void SODATEYA_AddTmMoves(u32 *a, u32 *b, u32 *c);
extern void SODATEYA_AddVoltTackle(void **p, u32 *q);
extern void SODATEYA_SetupEggMon(void *mon, S *s, void *b, void *c, u16 heap);

void SODATEYA_BuildEgg(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon)
{
    S s;
    u32 m[2];

    m[0] = m0;
    m[1] = m1;
    SODATEYA_SortParentsByGender(m);
    SODATEYA_PutDittoSecond((void **)m);
    SODATEYA_InitEgg(&s);
    SODATEYA_SetBaseSpecies(m, (u32 *)(&s));
    SODATEYA_RollNidoranSpecies(m, (u32 *)(&s));
    SODATEYA_RollVolbeatSpecies(m, (u32 *)(&s));
    SODATEYA_ApplyPhioneRule(m, (u32 *)(&s));
    SODATEYA_ApplyIncenseBabyRule(m, (u32 *)(&s));
    SODATEYA_ResetEggForm((u32)m, (u32)(&s));
    SODATEYA_InheritFormShellos(m, (u32 *)(&s));
    SODATEYA_InheritFormBurmy(m, (u32 *)(&s));
    SODATEYA_InheritFormBasculin(m, (u32 *)(&s));
    SODATEYA_RollNature(m, (u32 *)(&s));
    SODATEYA_ApplyEverstoneRule(m, (u32 *)(&s));
    SODATEYA_RollAbilitySlot(m, (u32 *)(&s), heap);
    SODATEYA_RollDittoAbilitySlot((void **)m, (u32 *)(&s));
    SODATEYA_SetAbilityFromSlot(m, (u32 *)&s, heap);
    SODATEYA_SetBaseFriendship((u32 *)(&s), heap);
    SODATEYA_ApplyPowerItemRule(m, &s);
    SODATEYA_RollRandomIvInheritance((int)m, (u32 *)(&s));
    SODATEYA_CopyInheritedIvs(m, (u32 *)(&s));
    SODATEYA_SetOtId((int)b, (char *)(&s));
    SODATEYA_RollPersonalRnd((int)m, (char *)(&s));
    SODATEYA_ApplyMasudaMethod(m, (u32 *)(&s));
    SODATEYA_AddLevelUpMoves((u32 *)(&s));
    SODATEYA_AddEggMoves(m, (u32 *)(&s), heap);
    SODATEYA_AddSharedMoves(m, (u32 *)(&s));
    SODATEYA_AddTmMoves(m, (u32 *)(&s), (u32 *)heap);
    SODATEYA_AddVoltTackle((void **)m, (u32 *)(&s));
    SODATEYA_SetupEggMon(mon, &s, b, c, heap);
}
