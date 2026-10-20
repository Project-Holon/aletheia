/*
 * file:     btl_pokeset.c
 * unit:     yes
 * function: BTL_POKESET_Clear, BTL_POKESET_Add, BTL_POKESET_AddWithDamage, BTL_POKESET_Remove, BTL_POKESET_Get, BTL_POKESET_SeekStart, BTL_POKESET_SeekNext, BTL_POKESET_GetTotalDamage, BTL_POKESET_GetPlainDamage, BTL_POKESET_GetCount, BTL_POKESET_GetCountMax, BTL_POKESET_SetEmptyMarked, BTL_POKESET_IsRemovedAll, BTL_POKESET_CopyAlive, BTL_POKESET_CopyFriends, BTL_POKESET_CopyEnemies, BTL_POKESET_RemoveFainted, BTL_POKESET_SortBySpeed
 * address:  0x0689CB3C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * lever: in the sort (BTL_POKESET_SortBySpeed) the j-side element pointer is a named local
 * `(u16 *)p + j` (indexed as halfwords 12 and 27), which keeps p+2j live in r6
 * across the call; array indexing on j recomputes it after the call.
 *
 * symbols:
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb
 *   BTL_CALC_Random  0x021D78AC  thumb
 */
#include "../types.h"

#include "btl_pokeset_types.h"

#include "../arm9/mi_memory.h"
struct BtlPokeParam;
#include "../ov093/btl_pokeparam.h"
#include "../ov093/btl_main.h"
#include "../ov093/btl_server_flow.h"
#include "btl_pokeset.h"
#include "../ov093/btl_calc.h"

/* Empty the set. */
void BTL_POKESET_Clear(BtlPokeSet *p)
{
    MI_CpuFill8(p, 0, 0x48);
}

/* Append a pokemon unless it is already in the set or the set is full. */
void BTL_POKESET_Add(BtlPokeSet *p, struct BtlPokeParam *id)
{
    u32 i;
    u8 count = p->count;

    if (count < 6) {
        for (i = 0; i < count; i++) {
            struct BtlPokeParam *member = p->poke[i];
            if (member == id)
                return;
        }
        p->poke[count] = id;
        p->damageKind[p->count] = 0;
        p->damage[p->count] = 0;
        p->damageExtra[p->count] = 0;
        p->count = p->count + 1;
        if (p->count > p->countMax)
            p->countMax = p->count;
    }
}

/* Add the pokemon if needed, then add amt to its damage (extra when flag is set). */
void BTL_POKESET_AddWithDamage(BtlPokeSet *p, struct BtlPokeParam *id, u16 amt, int flag)
{
    u32 i;
    struct BtlPokeParam *member;

    BTL_POKESET_Add(p, id);
    for (i = 0; i < p->count; i++) {
        member = p->poke[i];
        if (member == id) {
            if (flag) {
                p->damageExtra[i] += amt;
                p->damageKind[i] = 2;
            } else {
                p->damage[i] += amt;
                p->damageKind[i] = 1;
            }
        }
    }
}

/* Remove a pokemon and close the gap; the seek cursor steps back with it. */
void BTL_POKESET_Remove(BtlPokeSet *p, struct BtlPokeParam *id)
{
    u32 i;
    u32 j;
    u8 count = p->count;
    struct BtlPokeParam *member;

    for (i = 0; i < count; i++) {
        member = p->poke[i];
        if (member == id) {
            for (j = i + 1; j < p->count; j++)
                p->poke[j - 1] = p->poke[j];
            p->count--;
            p->seekIndex--;
            return;
        }
    }
}

/* The pokemon at index i, or 0 when i is past the end. */
struct BtlPokeParam *BTL_POKESET_Get(BtlPokeSet *p, u32 i)
{
    if (i < p->count)
        return p->poke[i];
    return 0;
}

/* Reset the seek cursor. */
void BTL_POKESET_SeekStart(BtlPokeSet *p)
{
    p->seekIndex = 0;
}

/* Next pokemon of the walk, or 0 at the end. */
struct BtlPokeParam *BTL_POKESET_SeekNext(BtlPokeSet *p)
{
    u8 index = p->seekIndex;

    if (index < p->count) {
        p->seekIndex++;
        return p->poke[index];
    }
    return 0;
}

/*
 * Both lookups reload the count byte on every pass (no common-subexpression
 * reuse of p->count across the loop).
 */
#pragma opt_common_subs off

/* Total damage (both kinds) of a pokemon that took any; returns 1 when found. */
int BTL_POKESET_GetTotalDamage(BtlPokeSet *p, struct BtlPokeParam *id, u32 *out)
{
    u32 i;
    struct BtlPokeParam *member;
    for (i = 0; i < p->count; i++) {
        member = p->poke[i];
        if (member == id && p->damageKind[i] != 0) {
            *out = p->damage[i] + p->damageExtra[i];
            return 1;
        }
    }
    return 0;
}

/* Plain damage of a pokemon that took only plain damage; returns 1 when found. */
int BTL_POKESET_GetPlainDamage(BtlPokeSet *p, struct BtlPokeParam *id, u32 *out)
{
    u32 i;
    struct BtlPokeParam *member;
    for (i = 0; i < p->count; i++) {
        member = p->poke[i];
        if (member == id && p->damageKind[i] == 1) {
            *out = p->damage[i];
            return 1;
        }
    }
    return 0;
}

#pragma opt_common_subs reset

u32 BTL_POKESET_GetCount(BtlPokeSet *p)
{
    return p->count;
}

int BTL_POKESET_GetCountMax(BtlPokeSet *p)
{
    return p->countMax;
}

void BTL_POKESET_SetEmptyMarked(BtlPokeSet *p, u8 v)
{
    p->emptyMarked = v;
}

/* 1 when the set had members (or was marked) and is now empty. */
int BTL_POKESET_IsRemovedAll(BtlPokeSet *p)
{
    if (p->countMax != 0 || p->emptyMarked != 0) {
        if (p->count == 0)
            return 1;
        return 0;
    }
    return 0;
}

/* Copy the pokemon of p that are not fainted into q; returns the count. */
int BTL_POKESET_CopyAlive(BtlPokeSet *p, BtlPokeSet *q)
{
    u32 i;
    u32 count;
    struct BtlPokeParam *poke;

    BTL_POKESET_Clear(q);
    count = BTL_POKESET_GetCount(p);
    for (i = 0; i < count; i++) {
        poke = BTL_POKESET_Get(p, i);
        if (!BTL_POKEPARAM_IsFainted(poke))
            BTL_POKESET_Add(q, poke);
    }
    return BTL_POKESET_GetCount(q);
}

/* Copy the pokemon of p for which the pair test with a id holds into q. */
int BTL_POKESET_CopyFriends(BtlPokeSet *p, struct BtlPokeParam *a, BtlPokeSet *q)
{
    u32 i;
    u32 count;
    struct BtlPokeParam *poke;
    int pokeId;

    BTL_POKESET_Clear(q);
    pokeId = BTL_POKEPARAM_GetPokeId(a);
    count = BTL_POKESET_GetCount(p);
    for (i = 0; i < count; i++) {
        poke = BTL_POKESET_Get(p, i);
        if (BTL_MAIN_IsPokeSamePair(pokeId, BTL_POKEPARAM_GetPokeId(poke)))
            BTL_POKESET_Add(q, poke);
    }
    return BTL_POKESET_GetCount(q);
}

/* Copy the pokemon of p for which the pair test with a id fails into q. */
int BTL_POKESET_CopyEnemies(BtlPokeSet *p, struct BtlPokeParam *a, BtlPokeSet *q)
{
    u32 i;
    u32 count;
    struct BtlPokeParam *poke;
    int pokeId;

    BTL_POKESET_Clear(q);
    pokeId = BTL_POKEPARAM_GetPokeId(a);
    count = BTL_POKESET_GetCount(p);
    for (i = 0; i < count; i++) {
        poke = BTL_POKESET_Get(p, i);
        if (!BTL_MAIN_IsPokeSamePair(pokeId, BTL_POKEPARAM_GetPokeId(poke)))
            BTL_POKESET_Add(q, poke);
    }
    return BTL_POKESET_GetCount(q);
}

/* Remove every fainted pokemon from the set. */
void BTL_POKESET_RemoveFainted(BtlPokeSet *p)
{
    struct BtlPokeParam *poke;
    BTL_POKESET_SeekStart(p);
    poke = BTL_POKESET_SeekNext(p);
    while (poke) {
        if (BTL_POKEPARAM_IsFainted(poke))
            BTL_POKESET_Remove(p, poke);
        poke = BTL_POKESET_SeekNext(p);
    }
}

/* Sort by speed, fastest first; equal speeds are ordered by a coin flip. */
void BTL_POKESET_SortBySpeed(BtlPokeSet *p, struct BtlServerFlow *flow)
{
    u32 i;
    u32 j;
    struct BtlPokeParam *tmpPoke;
    u16 tmpDamage;
    u16 tmpSpeed;
    u16 *pj;

    if (p->count > 1) {
        for (i = 0; i < p->count; i++)
            p->speed[i] = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(flow, p->poke[i], 1);
        for (i = 0; i < p->count; i++) {
            for (j = i + 1; j < p->count; j++) {
                pj = (u16 *)p + j;
                if (pj[27] > p->speed[i] || (pj[27] == p->speed[i] && BTL_CALC_Random(2))) {
                    tmpPoke = p->poke[i];
                    tmpDamage = p->damage[i];
                    tmpSpeed = p->speed[i];
                    p->poke[i] = p->poke[j];
                    p->damage[i] = pj[12];
                    p->speed[i] = pj[27];
                    p->poke[j] = tmpPoke;
                    pj[12] = tmpDamage;
                    pj[27] = tmpSpeed;
                }
            }
        }
    }
}
