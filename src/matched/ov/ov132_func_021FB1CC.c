/*
 * function: SCRIPT_COMMAND_CmdShowButton
 * address:  0x021FB1CC
 * packet:   pkt_021FB1CC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STA_ACTING_ShowButton  0x021F9D80  thumb
 *   STA_ACTING_ScheduleActions  0x021F9AD8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14100.h"

extern void STA_ACTING_ShowButton(char *p);
typedef unsigned char  u8;
extern void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);

int SCRIPT_COMMAND_CmdShowButton(int a, char **pp)
{
    char *p = *pp;

    STA_ACTING_ShowButton(((struct Obj14100 *)p)->f34);
    STA_ACTING_ScheduleActions(((struct Obj14100 *)p)->f34, 0, 0);
    return 0;
}
