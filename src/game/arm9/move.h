#ifndef GAME_ARM9_MOVE_H
#define GAME_ARM9_MOVE_H

#include "../port_limits.h"

/* Highest valid move id: a/0/2/1 has 560 members, 0..559 (0 is no move). */
#define MOVE_LAST BW_LIMIT(MOVE_LAST, 559)

#endif
