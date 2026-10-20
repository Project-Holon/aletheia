#ifndef HAND_COMMON_PROTOS_H
#define HAND_COMMON_PROTOS_H
/*
 * ov093 ability and move handlers: the one prototype of each battle service that
 * several handler files call.
 */
#include "../ov093/hand_common_types.h"

struct BtlServerFlow;
struct BtlParty;
struct BtlHitRecord;

/* Services of the event variable stack and of the event factors. */
#include "../ov093/btl_event.h"

/* Services of the battle main object. */
#include "../ov093/btl_main.h"

/* Services of the battle server flow. */
#include "../ov093/btl_server_flow.h"

/* Services of the move data. */
#include "../arm9/waza_tool.h"

/* Services of the volatile condition records and of the battle viewer slots. */
#include "../ov093/btl_sickcont.h"
#include "../ov093/btl_typepair.h"
#include "../ov093/btl_calc.h"

/* Services of the poke parameter. */
#include "../ov093/btl_pokeparam.h"

/* Services declared by several handler files (kept identical so the files can be merged). */
#include "../ov093/btl_action_word.h"
#include "../ov095/btl_id_sets.h"

/* Item tests of overlay 095 (Arceus plates and Genesect drives). */

/* Shared helpers of the ability, item and move handlers (hand_common.c). */
#include "../ov093/hand_common.h"

#endif
