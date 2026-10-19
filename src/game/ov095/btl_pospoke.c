/*
 * file:     btl_pospoke.c
 * unit:     yes
 * function: BTL_POSPOKE_Init, BTL_POSPOKE_SetupPos, BTL_POSPOKE_RemovePoke, BTL_POSPOKE_SetPoke, BTL_POSPOKE_RotateInPoke, BTL_POSPOKE_RegisterFoughtPokes, BTL_POSPOKE_SwapPos, BTL_POSPOKE_UpdatePosOfPoke, BTL_POSPOKE_GetEmptyPosList, BTL_POSPOKE_IsPokeInside, BTL_POSPOKE_GetFieldPos, BTL_POSPOKE_SearchPosByPokeId, BTL_POSPOKE_GetPosByPokeId, BTL_POSPOKE_GetPokeIdAtPos
 * address:  0x0689D1FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note: BTL_POSPOKE_RemovePoke follows a non-C veneer at 0x0689D2E8; the callees at
 *   0x0689D408..0x0689D438 are linker veneers (int results).
 * note: BTL_POSPOKE_RotateInPoke stores through entry[i] after its loop (i == 6, one entry
 *   past the table): a bug of the original, reproduced. Its index list is a
 *   separate u8[5] local declared before the 3-byte temp (frame is 8 bytes; the
 *   original overwrites the pad slot when six entries match).
 *
 * symbols:
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb
 *   BTL_MAIN_GetSlotClientAndNth  0x021B8E28  thumb
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb
 *   BTL_SLOT_GetRotateDstIndex  0x021B9AC8  thumb
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb
 *   BTL_POKEPARAM_AddFoughtPoke  0x021D6DCC  thumb
 *   BTL_MAIN_CheckFrontPos  0x021B86A0  thumb
 */
#include "../ov093/btl_records_types.h"

extern u32 BTL_MAIN_GetRuleSlotSpan(int);
struct BtlMain;
extern void BTL_MAIN_GetSlotClientAndNth(struct BtlMain *main, u8 slot, u8 *outClientId, u8 *outNth);
struct BtlSide;
struct BtlPokeParam;
extern struct BtlPokeParam *BTL_SIDE_GetClientPoke(struct BtlSide *side, u32 clientId, u8 nth);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *pp);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pp);
extern int BTL_SLOT_GetRotateSrcIndex(int);
extern int BTL_SLOT_GetRotateDstIndex(int);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);
extern struct BtlPokeParam *BTL_SIDE_GetPokeByIdThunk(struct BtlSide *side, s32 pokeId);
extern void BTL_POKEPARAM_AddFoughtPoke(struct BtlPokeParam *poke, u32 pokeId);
extern int BTL_MAIN_CheckFrontPos(struct BtlMain *main, u32 posIdx);
void BTL_POSPOKE_Init(BtlPosPoke *a, int b, int c);
void BTL_POSPOKE_SetupPos(BtlPosPoke *a, int b, int c, u8 d);
void BTL_POSPOKE_RemovePoke(BtlPosPoke *p, int b);
void BTL_POSPOKE_SetPoke(BtlPosPoke *p, int b, int c, int d);
void BTL_POSPOKE_RotateInPoke(BtlPosPoke *p, u32 size, u32 category, int key, int extra);
void BTL_POSPOKE_RegisterFoughtPokes(BtlPosPoke *a, int b, int c);
void BTL_POSPOKE_SwapPos(BtlPosPokeEntry *p, int i, int j);
void BTL_POSPOKE_UpdatePosOfPoke(BtlPosPoke *a, int b);
u8 BTL_POSPOKE_GetEmptyPosList(BtlPosPoke *a, u8 clientId, u8 *out);
int BTL_POSPOKE_IsPokeInside(BtlPosPoke *p, u8 pokeId);
int BTL_POSPOKE_GetFieldPos(BtlPosPoke *p, void *q, u8 pokeId);
u8 BTL_POSPOKE_SearchPosByPokeId(BtlPosPoke *p, int pokeId);
int BTL_POSPOKE_GetPosByPokeId(BtlPosPoke *p, int i);
int BTL_POSPOKE_GetPokeIdAtPos(BtlPosPoke *p, u8 i);


/* Fill every position from the current battle state. */
void BTL_POSPOKE_Init(BtlPosPoke *a, int b, int c)
{
    u32 i;
    u32 n;

    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        a->entry[i].valid = 0;
        a->entry[i].pokeId = BTL_POSPOKE_NO_POKE;
    }
    for (i = 0; i < BTL_POSPOKE_COUNT; i++)
        a->posOfPoke[i] = BTL_POSPOKE_NO_POS;
    n = BTL_MAIN_GetRuleSlotSpan(b);
    for (i = 0; i <= n; i++)
        BTL_POSPOKE_SetupPos(a, b, c, i);
}


/* Fill one position: its owner client and the poke standing there, if alive. */
void BTL_POSPOKE_SetupPos(BtlPosPoke *a, int b, int c, u8 d)
{
    u8 clientId;
    u8 nth;
    int poke;
    int pokeId;

    BTL_MAIN_GetSlotClientAndNth((struct BtlMain *)b, d, &clientId, &nth);
    poke = (s32)BTL_SIDE_GetClientPoke((struct BtlSide *)c, clientId, nth);
    if (poke != 0 && (struct BtlPokeParam *)BTL_POKEPARAM_IsFainted((struct BtlPokeParam *)poke) == 0) {
        pokeId = BTL_POKEPARAM_GetPokeId((struct BtlPokeParam *)poke);
        a->entry[d].pokeId = pokeId;
        a->posOfPoke[pokeId] = d;
    } else {
        a->entry[d].pokeId = BTL_POSPOKE_NO_POKE;
    }
    a->entry[d].clientId = clientId;
    a->entry[d].valid = 1;
}



/* Empty the position that holds this poke. */
void BTL_POSPOKE_RemovePoke(BtlPosPoke *p, int b)
{
    u32 i;
    BtlPosPokeEntry *q;
    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        q = &p->entry[i];
        if (q->valid != 0 && b == q->pokeId) {
            q->pokeId = BTL_POSPOKE_NO_POKE;
            return;
        }
    }
}



/* Put a poke on a position, then register it against the other pokes on the field. */
void BTL_POSPOKE_SetPoke(BtlPosPoke *p, int b, int c, int d)
{
    p->entry[b].pokeId = c;
    p->posOfPoke[c] = b;
    BTL_POSPOKE_RegisterFoughtPokes(p, b, d);
}


/*
 * Rotate the pokes of one client's positions (the source and target picked from
 * the position count), then place the incoming poke on its first position.
 */
void BTL_POSPOKE_RotateInPoke(BtlPosPoke *p, u32 size, u32 category, int key, int extra)
{
    u32 n;
    u32 i;
    int first;
    int second;
    u8 idx[5];
    BtlPosPokeEntry tmp;
    if (size <= 1) return;
    n = 0;
    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        if (category == p->entry[i].clientId) idx[n++] = i;
    }
    first = BTL_SLOT_GetRotateSrcIndex(size);
    second = BTL_SLOT_GetRotateDstIndex(size);
    tmp = p->entry[idx[0]];
    p->entry[idx[first]] = p->entry[idx[second]];
    p->entry[idx[second]] = tmp;
    if ((struct BtlPokeParam *)BTL_POKEPARAM_IsFainted((struct BtlPokeParam *)key) == 0)
        BTL_POSPOKE_SetPoke(p, idx[0], BTL_POKEPARAM_GetPokeId((struct BtlPokeParam *)key), extra);
    else
        p->entry[i].pokeId = BTL_POSPOKE_NO_POKE;
    for (i = 0; i < n; i++) BTL_POSPOKE_UpdatePosOfPoke(p, idx[i]);
}


/* Tell the pokes of both sides that they have met the poke at position b. */
void BTL_POSPOKE_RegisterFoughtPokes(BtlPosPoke *a, int b, int c)
{
    u32 pokeId;
    u32 i;
    BtlPosPokeEntry *q;

    pokeId = a->entry[b].pokeId;
    if (pokeId == BTL_POSPOKE_NO_POKE)
        return;
    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        q = &a->entry[i];
        if (q->pokeId == BTL_POSPOKE_NO_POKE || pokeId == q->pokeId)
            continue;
        if (BTL_MAIN_IsPokeSamePair(q->pokeId, pokeId) != 0)
            continue;
        BTL_POKEPARAM_AddFoughtPoke(BTL_SIDE_GetPokeByIdThunk((struct BtlSide *)c, q->pokeId), pokeId);
        BTL_POKEPARAM_AddFoughtPoke(BTL_SIDE_GetPokeByIdThunk((struct BtlSide *)c, pokeId), q->pokeId);
    }
}


/* Swap two positions and refresh the reverse lookup. */
void BTL_POSPOKE_SwapPos(BtlPosPokeEntry *p, int i, int j)
{
    BtlPosPokeEntry tmp;

    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
    BTL_POSPOKE_UpdatePosOfPoke((BtlPosPoke *)p, i);
    BTL_POSPOKE_UpdatePosOfPoke((BtlPosPoke *)p, j);
}


/* Point the reverse lookup of the poke on position b back at b. */
void BTL_POSPOKE_UpdatePosOfPoke(BtlPosPoke *a, int b)
{
    u32 pokeId;

    pokeId = a->entry[b].pokeId;
    if (pokeId != BTL_POSPOKE_NO_POKE)
        a->posOfPoke[pokeId] = b;
}


/*
 * Unlabelled leaf (push {r3-r6}, no lr). Collects the positions of client `key`
 * that exist and are empty into out; returns how many.
 */
u8 BTL_POSPOKE_GetEmptyPosList(BtlPosPoke *a, u8 clientId, u8 *out)
{
    u32 n;
    u32 i;

    n = 0;
    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        if (a->entry[i].valid != 0 && clientId == a->entry[i].clientId && a->entry[i].pokeId == BTL_POSPOKE_NO_POKE)
            out[n++] = i;
    }
    return n;
}


/*
 * note: Two-byte zero alignment padding follows; contiguous scratch TU is EXACT.
 */
/* 1 when the poke stands on a position. */
int BTL_POSPOKE_IsPokeInside(BtlPosPoke *p, u8 pokeId)
{
    if (BTL_POSPOKE_SearchPosByPokeId(p, pokeId) != BTL_POSPOKE_NO_POS) return 1;
    return 0;
}


/* Map the position of this poke through BTL_MAIN_CheckFrontPos (0 when it is not on the field). */
int BTL_POSPOKE_GetFieldPos(BtlPosPoke *p, void *q, u8 pokeId)
{
    int pos;
    pos = BTL_POSPOKE_SearchPosByPokeId(p, pokeId);
    if (pos != BTL_POSPOKE_NO_POS) return BTL_MAIN_CheckFrontPos(q, pos);
    return 0;
}


/*
 * Scan the table: find the first existing position holding `pokeId`; return its
 * index (0..5), or BTL_POSPOKE_NO_POS.
 */
u8 BTL_POSPOKE_SearchPosByPokeId(BtlPosPoke *p, int pokeId)
{
    u32 i;

    for (i = 0; i < BTL_POSPOKE_COUNT; i++) {
        if (p->entry[i].valid != 0 && p->entry[i].pokeId == pokeId)
            return (u8)i;
    }
    return BTL_POSPOKE_NO_POS;
}


/*
 * ABI: reads r0 base and full-word r1 index; byte load returned in r0.
 */
int BTL_POSPOKE_GetPosByPokeId(BtlPosPoke *p, int i) { return p->posOfPoke[i]; }


/*
 * ABI: reads r0 base and r1 index; byte load returned in r0.
 * The index is u8: the ov093 caller at 021C50C4 narrows its loop counter
 * to a byte at the call. The body compiles the same as with int.
 */
int BTL_POSPOKE_GetPokeIdAtPos(BtlPosPoke *p, u8 i) { return p->entry[i].pokeId; }
