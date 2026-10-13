/*
 * file:     unit_0219E264.c
 * unit:     yes
 * function: SBServerSetNext, SBServerGetNext
 * address:  0x0219E264
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "unit_0219E1EC_types.h"

void SBServerSetNext(SBServer *server, SBServer *next);
SBServer *SBServerGetNext(const SBServer *server);

/*
 * Sets the next server in a list.
 */
void SBServerSetNext(SBServer *server, SBServer *next)
{
    server->next = next;
}

/*
 * Next server in a list.
 */
SBServer *SBServerGetNext(const SBServer *server)
{
    return server->next;
}
