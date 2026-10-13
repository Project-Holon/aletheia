/*
 * file:     unit_021DA32C.c
 * function: func_021DA32C, func_021DA3CC
 * address:  0x021DA32C
 * packet:   pkt_ov093_021DA32C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F0970     0x021F0970  data   ov093  a4
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7D54   0x021C7D54  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */
#include "unit_021D9ADC_types.h"

extern int func_021D775C(int varId);
extern u8 func_021C7D54(u8 *flowWork, u8 *pokeId, u8 *outFoeIds);
extern void *func_021C7CF4(int *flowWork, int pokeId);
extern int func_021D59B4(u8 *pokeParam, int valueId);
/* The defense sums are u16 accumulators; a u8 third parameter keeps its reload
   after the +0xf store. */
extern void *func_021C88A4(char *flowWork, int kind, int pokeId);
extern void func_021C88C8(void *flowWork, void *record);

/* Download: on entering the field, compare the foes' total Defense and Special
   Defense and raise Attack or Special Attack by one stage accordingly. */
void func_021DA32C(int myHandle, int flowWork, u8 pokeId)
{
    u8 foeIds[4];
    u8 foeCount;
    u16 defenseSum;
    u16 spDefenseSum;
    u8 i;
    int rankKind;
    void *foe;
    struct HandExRankEffect *record;

    if (pokeId != func_021D775C(HANDVAR_POKE_ID))
        return;
    foeCount = func_021C7D54((u8 *)flowWork, (u8 *)pokeId, foeIds);
    if (foeCount == 0)
        return;
    defenseSum = 0;
    spDefenseSum = 0;
    for (i = 0; i < foeCount; i++) {
        foe = func_021C7CF4((int *)flowWork, foeIds[i]);
        defenseSum = defenseSum + (u16)func_021D59B4(foe, BPP_VALUE_DEFENSE);
        spDefenseSum = spDefenseSum + (u16)func_021D59B4(foe, BPP_VALUE_SP_DEFENSE);
    }
    if (defenseSum >= spDefenseSum)
        rankKind = BTL_RANK_SP_ATTACK;
    else
        rankKind = BTL_RANK_ATTACK;
    record = func_021C88A4((char *)flowWork, HANDEX_KIND_RANK_EFFECT, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeCount = 1;
    record->pokeId = pokeId;
    record->rankKind = rankKind;
    record->volume = 1;
    func_021C88C8((void *)flowWork, record);
}


extern int d_021F0970[];

int *func_021DA3CC(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F0970;
}
