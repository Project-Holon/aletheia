#ifndef BTL_RECORDS_TYPES_H
#define BTL_RECORDS_TYPES_H
/*
 * ov093 battle records kept inside the server flow: the move history, the faint
 * history and the position table. The functions that work on them live in
 * ov095 (btl_wazarec.c, btl_deadrec.c, btl_pospoke.c).
 */

#include "../types.h"

/* One used move: the move id, the turn it was used in, the user, and whether it took effect. */
typedef struct BtlWazaRecEntry {
    u32 turn;       /* 0x00 */
    u16 wazaId;     /* 0x04: 0 marks the end of the history */
    u8 pokeId;      /* 0x06 */
    u8 effective;   /* 0x07 */
} BtlWazaRecEntry;

/* Ring buffer of the moves used in battle, newest entry last written. */
typedef struct BtlWazaRec {
    u32 writeIndex;
    BtlWazaRecEntry entry[120];
} BtlWazaRec;

#define BTL_DEADREC_TURNS 4
#define BTL_DEADREC_MAX 24
#define BTL_DEADREC_NONE 31

/* The pokemon that fainted in one turn. */
typedef struct BtlDeadRecTurn {
    u8 count;
    u8 reported[BTL_DEADREC_MAX];   /* set once the faint was handled */
    u8 pokeId[BTL_DEADREC_MAX];     /* BTL_DEADREC_NONE when unset */
} BtlDeadRecTurn;

/* Faint history of the last four turns, newest turn first. */
typedef struct BtlDeadRec {
    BtlDeadRecTurn turn[BTL_DEADREC_TURNS];
} BtlDeadRec;

#define BTL_POSPOKE_COUNT 6
#define BTL_POSPOKE_NO_POKE 0x1f    /* pokeId of an empty position */
#define BTL_POSPOKE_NO_POS 6        /* position of a poke that is not on the field */

/* One battle position. */
typedef struct BtlPosPokeEntry {
    u8 valid;       /* the position exists in this battle */
    u8 clientId;    /* client that owns the position */
    u8 pokeId;      /* poke standing there, BTL_POSPOKE_NO_POKE when empty */
} BtlPosPokeEntry;

/* Which poke stands on which battle position, and the reverse lookup. */
typedef struct BtlPosPoke {
    BtlPosPokeEntry entry[BTL_POSPOKE_COUNT];
    u8 posOfPoke[BTL_POSPOKE_COUNT];    /* position by poke id */
} BtlPosPoke;

#endif
