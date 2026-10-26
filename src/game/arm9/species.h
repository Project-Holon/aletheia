#ifndef GAME_ARM9_SPECIES_H
#define GAME_ARM9_SPECIES_H

#include "../port_limits.h"

/* Highest valid species id: 1..649. The egg is 650 and the bad egg is 651. */
#define SPECIES_LAST BW_LIMIT(SPECIES_LAST, 649)

#endif
