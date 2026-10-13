/*
 * unit:     yes
 * function: OPTION_MENU_IsRunnerFinished, OPTION_MENU_SetRunnerCallback, OPTION_MENU_FinishRunner
 * address:  0x021BB134
 * packet:   pkt_ov068_021BB134
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter and two small setters.
 */
#include "../include/Obj13146.h"
#include "../include/Obj20651.h"
#include "../include/Obj20652.h"

int OPTION_MENU_IsRunnerFinished(void *p)
{
    return ((struct Obj20651 *)p)->f4;
}

void OPTION_MENU_SetRunnerCallback(void *p, int v)
{
    ((struct Obj13146 *)p)->f0 = v;
    ((struct Obj13146 *)p)->f8 = 0;
}

void OPTION_MENU_FinishRunner(void *p)
{
    ((struct Obj20652 *)p)->f4 = 1;
}
