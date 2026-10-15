/*
 * function: SCRIPT_COMMAND_CmdInstallBgm
 * address:  0x021FC5A0
 * packet:   pkt_021FC5A0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   STA_ACTING_InstallBgm  0x021F9664  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14122.h"
#include "../include/Obj23263.h"

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void STA_ACTING_InstallBgm(char *p, int a);

int SCRIPT_COMMAND_CmdInstallBgm(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct Obj14122 *)pp)->f4));

    STA_ACTING_InstallBgm(((struct Obj23263 *)p)->f34, (unsigned short)x);
    return 0;
}
