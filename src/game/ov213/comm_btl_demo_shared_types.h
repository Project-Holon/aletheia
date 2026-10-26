#ifndef COMM_BTL_DEMO_SHARED_TYPES_H
#define COMM_BTL_DEMO_SHARED_TYPES_H

/*
 * Types shared by the ov213 battle demo and its ov199 caller
 * (wifibattlematch_sys.c). The 0x58-byte setup record ov199 builds in
 * WIFIBATTLEMATCH_SYS_BuildSetupRecord is pushed to ov213 through
 * PROCSYS_Push(wk->f0, ov213_id, data_021BB0B0, pw->f8), where ov213 reads it
 * as struct CommBtlDemoArgs.
 */

#include "../types.h"

/* One side of the battle demo: the party list and the per-member flag bytes. */
struct CommBtlDemoSide {
    void *party;        /* 0x00 */
    void *textSys;      /* 0x04 */
    u8 pad08[2];        /* 0x08: ov199 writes the record version at 0x09, never read here */
    u8 flags[6];        /* 0x0A */
};

/* Setup record passed to COMM_BTL_DEMO_MAIN_Create. */
struct CommBtlDemoArgs {
    struct CommBtlDemoSide side[4]; /* 0x00 */
    u32 battleKind;     /* 0x40 */
    u32 partyMode;      /* 0x44 */
    s32 ruleId;         /* 0x48: setup rule id written by ov199, never read here */
    u8 pad4C[4];        /* 0x4C */
    u32 soundKind;      /* 0x50 */
    void *animTarget;   /* 0x54 */
};

#endif
