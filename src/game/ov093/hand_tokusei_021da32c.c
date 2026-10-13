/*
 * file:     hand_tokusei_021da32c.c
 * function: HAND_TOKUSEI_DownloadOnMemberIn, HAND_TOKUSEI_AddDownload
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
 *   gDownloadHandlers     0x021F0970  data   ov093  a4
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds   0x021C7D54  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 */
#include "hand_tokusei_021d9adc_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(u8 *flowWork, u8 *pokeId, u8 *outFoeIds);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flowWork, int pokeId);
extern int func_021D59B4(u8 *pokeParam, int valueId);
/* The defense sums are u16 accumulators; a u8 third parameter keeps its reload
   after the +0xf store. */
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flowWork, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flowWork, void *record);

/* Download: on entering the field, compare the foes' total Defense and Special
   Defense and raise Attack or Special Attack by one stage accordingly. */
void HAND_TOKUSEI_DownloadOnMemberIn(int myHandle, int flowWork, u8 pokeId)
{
    u8 foeIds[4];
    u8 foeCount;
    u16 defenseSum;
    u16 spDefenseSum;
    u8 i;
    int rankKind;
    void *foe;
    struct HandExRankEffect *record;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    foeCount = BTL_SERVER_FLOW_CollectOpponentPokeIds((u8 *)flowWork, (u8 *)pokeId, foeIds);
    if (foeCount == 0)
        return;
    defenseSum = 0;
    spDefenseSum = 0;
    for (i = 0; i < foeCount; i++) {
        foe = BTL_SERVER_FLOW_GetPokeParam((int *)flowWork, foeIds[i]);
        defenseSum = defenseSum + (u16)func_021D59B4(foe, BPP_VALUE_DEFENSE);
        spDefenseSum = spDefenseSum + (u16)func_021D59B4(foe, BPP_VALUE_SP_DEFENSE);
    }
    if (defenseSum >= spDefenseSum)
        rankKind = BTL_RANK_SP_ATTACK;
    else
        rankKind = BTL_RANK_ATTACK;
    record = BTL_SERVER_FLOW_AllocCmdRecord((char *)flowWork, HANDEX_KIND_RANK_EFFECT, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeCount = 1;
    record->pokeId = pokeId;
    record->rankKind = rankKind;
    record->volume = 1;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)flowWork, record);
}


extern int gDownloadHandlers[];

int *HAND_TOKUSEI_AddDownload(int *handlerCount)
{
    *handlerCount = 2;
    return gDownloadHandlers;
}
