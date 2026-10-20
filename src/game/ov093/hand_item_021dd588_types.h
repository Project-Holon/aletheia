#ifndef HAND_ITEM_021DD588_TYPES_H
#define HAND_ITEM_021DD588_TYPES_H
#include "../ov093/hand_common_types.h"
/*
 * ov093 held item handlers (berries): the effect records a handler pushes to
 * the battle flow and the event variable numbers the handlers read.
 *
 * A handler asks the flow for a record of one kind (HANDEX_KIND_*), fills the
 * fields that kind uses and hands it back. Every record starts with the
 * 32-bit header the flow writes.
 */

#include "../ov093/btl_pokeparam_types.h"

struct BtlEventFactor;

/* Record kinds that the item handlers push. */

/* Event variables the item handlers read with the event variable getter. */

/* Type affinity values above this are super effective. */

/* Value ids of the poke parameter getter. */

/* Status ids. */

/* Stat ids of the rank (stat stage) records; also the numbers the stat berries use. */

/* Pokemon type ids (a dense list: there is no unused slot between steel and fire). */

/* Condition flag that the critical-rate berry sets. */

/* Slots of the per-item work words the handlers share. */








/* Deprecated names of event variable keys, kept for files not yet cleaned. */

#endif
