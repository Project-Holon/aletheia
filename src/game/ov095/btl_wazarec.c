/*
 * file:     btl_wazarec.c
 * unit:     yes
 * function: BTL_WAZAREC_Init, BTL_WAZAREC_Add, BTL_WAZAREC_SetEffectiveLast, BTL_WAZAREC_IsUsedWaza, BTL_WAZAREC_GetUsedWazaCount, BTL_WAZAREC_GetEffectiveWaza
 * address:  0x0689CFF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../ov093/btl_records_types.h"

extern void MI_CpuFill8(void *, int, u32);
void BTL_WAZAREC_Init(BtlWazaRec *p);
void BTL_WAZAREC_Add(BtlWazaRec *p, u32 wazaId, u32 turn, u32 pokeId);
void BTL_WAZAREC_SetEffectiveLast(BtlWazaRec *p);
int BTL_WAZAREC_IsUsedWaza(BtlWazaRec *p, u32 wazaId, u32 turn);
int BTL_WAZAREC_GetUsedWazaCount(BtlWazaRec *p, u32 wazaId, u32 turn);
u16 BTL_WAZAREC_GetEffectiveWaza(BtlWazaRec *p, u32 turn);

/* Clear the whole record. */
void BTL_WAZAREC_Init(BtlWazaRec *p)
{
    u32 i;
    MI_CpuFill8(p, 0, 964);
    p->writeIndex = 0;
    for (i = 0; i < 120; i++) {
        p->entry[i].wazaId = 0;
    }
}

/* Write a new entry at the ring position and advance it. */
void BTL_WAZAREC_Add(BtlWazaRec *p, u32 wazaId, u32 turn, u32 pokeId)
{
    p->entry[p->writeIndex].wazaId = wazaId;
    p->entry[p->writeIndex].turn = turn;
    p->entry[p->writeIndex].pokeId = pokeId;
    p->entry[p->writeIndex].effective = 0;
    p->writeIndex++;
    if (p->writeIndex >= 120)
        p->writeIndex = 0;
}

/* Mark the newest entry as having taken effect. */
void BTL_WAZAREC_SetEffectiveLast(BtlWazaRec *p)
{
    int i;
    i = p->writeIndex - 1;
    if (i < 0) i = 119;
    p->entry[i].effective = 1;
}

/* Walk back from the newest entry: was this move used in this turn? */
int BTL_WAZAREC_IsUsedWaza(BtlWazaRec *p, u32 wazaId, u32 turn)
{
    int i;
    int end;
    end = p->writeIndex;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->entry[i].wazaId == 0)
            break;
        if (wazaId == p->entry[i].wazaId && turn == p->entry[i].turn)
            return 1;
    }
    return 0;
}

/* Walk back from the newest entry: how many times was this move used in this turn? */
int BTL_WAZAREC_GetUsedWazaCount(BtlWazaRec *p, u32 wazaId, u32 turn)
{
    int i;
    int count;
    int end;
    end = p->writeIndex;
    count = 0;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->entry[i].wazaId == 0)
            break;
        if (wazaId == p->entry[i].wazaId && turn == p->entry[i].turn)
            count++;
    }
    return count;
}

/* The move that took effect in this turn (newest first), or 0. */
u16 BTL_WAZAREC_GetEffectiveWaza(BtlWazaRec *p, u32 turn)
{
    int i;
    int end;
    u16 wazaId;
    end = p->writeIndex;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end)
            break;
        wazaId = p->entry[i].wazaId;
        if (wazaId == 0)
            break;
        if (p->entry[i].effective != 0 && turn == p->entry[i].turn)
            return wazaId;
    }
    return 0;
}
