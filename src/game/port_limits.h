#ifndef GAME_PORT_LIMITS_H
#define GAME_PORT_LIMITS_H

/*
 * Named game limits.  The DS build keeps the original number.  The port
 * answers the same name at run time, so a mod can raise the limit.
 */

#include "types.h"

enum BwLimitId {
    BW_LIMIT_ITEM_LAST,
    BW_LIMIT_MOVE_LAST,
    BW_LIMIT_BTLV_EFFECT_MOVE_END,
    BW_LIMIT_FLDMMDL_OBJCODE_TABLE_COUNT,
    BW_LIMIT_SPECIES_LAST /* append only, the port mirrors these numbers */
};

#ifdef __MWERKS__
#define BW_LIMIT(name, ds_value) (ds_value)
#else
#define BW_LIMIT(name, ds_value) ((u32)bw_limit_get(BW_LIMIT_##name))
u32 bw_limit_get(int id); /* provided by the port */
#endif

#endif
