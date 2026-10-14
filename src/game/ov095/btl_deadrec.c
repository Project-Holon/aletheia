/*
 * file:     btl_deadrec.c
 * unit:     yes
 * function: BTL_DEADREC_ClearTurn, BTL_DEADREC_Init, BTL_DEADREC_StartTurn, BTL_DEADREC_Add, BTL_DEADREC_GetCount, BTL_DEADREC_GetPokeId, BTL_DEADREC_IsReported, BTL_DEADREC_SetReported, BTL_DEADREC_GetLastPokeId
 * address:  0x0689D0FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../ov093/btl_records_types.h"

void BTL_DEADREC_ClearTurn(BtlDeadRecTurn *t);
void BTL_DEADREC_Init(BtlDeadRec *p);
void BTL_DEADREC_StartTurn(BtlDeadRec *p);

/* Clear one turn. */
void BTL_DEADREC_ClearTurn(BtlDeadRecTurn *t)
{
    u32 i;
    t->count = 0;
    for (i = 0; i < BTL_DEADREC_MAX; i++) {
        t->pokeId[i] = BTL_DEADREC_NONE;
        t->reported[i] = 0;
    }
}

/* Clear every turn. */
void BTL_DEADREC_Init(BtlDeadRec *p)
{
    u32 i;
    for (i = 0; i < BTL_DEADREC_TURNS; i++) {
        BTL_DEADREC_ClearTurn(&p->turn[i]);
    }
}

/* Start a new turn: shift the older ones back and clear the newest. */
void BTL_DEADREC_StartTurn(BtlDeadRec *p)
{
    unsigned int i;
    for (i = 3; i != 0; i--) {
        p->turn[i] = p->turn[i - 1];
    }
    BTL_DEADREC_ClearTurn(&p->turn[0]);
}


/* Add a fainted pokemon to a turn (ignored when the turn is full). */
void BTL_DEADREC_Add(BtlDeadRecTurn *t, u8 pokeId)
{
    u8 *q;

    if (t->count < BTL_DEADREC_MAX) {
        q = (u8 *)t + t->count;
        q[25] = pokeId;
        q[1] = 0;
        t->count++;
    }
}


/* Number of faints recorded in turn i. */
u8 BTL_DEADREC_GetCount(BtlDeadRec *p, u32 i)
{
    if (i < BTL_DEADREC_TURNS)
        return p->turn[i].count;
    return 0;
}


/* Poke id of faint j in turn i, or BTL_DEADREC_NONE. */
u8 BTL_DEADREC_GetPokeId(BtlDeadRec *p, u32 i, u32 j)
{
    if (i < BTL_DEADREC_TURNS && j < p->turn[i].count)
        return p->turn[i].pokeId[j];
    return BTL_DEADREC_NONE;
}


/* Reported flag of faint j in turn i. */
u8 BTL_DEADREC_IsReported(BtlDeadRec *p, u32 i, u32 j)
{
    if (i < BTL_DEADREC_TURNS && j < p->turn[i].count)
        return p->turn[i].reported[j];
    return 0;
}


/* Mark faint j in turn i as reported. */
void BTL_DEADREC_SetReported(BtlDeadRec *p, u32 i, u32 j)
{
    if (i < BTL_DEADREC_TURNS && j < p->turn[i].count)
        p->turn[i].reported[j] = 1;
}


/* The most recently recorded faint of the newest turn that has one. */
u8 BTL_DEADREC_GetLastPokeId(BtlDeadRec *p)
{
    u32 i;

    for (i = 0; i < BTL_DEADREC_TURNS; i++) {
        if (p->turn[i].count != 0)
            return p->turn[i].pokeId[p->turn[i].count - 1];
    }
    return BTL_DEADREC_NONE;
}
