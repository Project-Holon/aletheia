/*
 * file:     unit_0219E264.c
 * unit:     yes
 * function: func_0219E264, func_0219E26C
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

void func_0219E264(SBServer *server, SBServer *next);
SBServer *func_0219E26C(const SBServer *server);

/*
 * Sets the next server in a list.
 */
void func_0219E264(SBServer *server, SBServer *next)
{
    server->next = next;
}

/*
 * Next server in a list.
 */
SBServer *func_0219E26C(const SBServer *server)
{
    return server->next;
}
