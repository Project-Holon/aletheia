/*
 * function: BTLV_EFFVM_CmdSetBgLayerEnable
 * address:  0x021FB550
 * packet:   pkt_ov094_021FB550
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: BG_SYS_SetPriority(3, arg) and sets flag bit 4.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BG_SYS_SetPriority 0x0204047C arm
 */
#include "../include/Obj13587.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void BG_SYS_SetPriority(int idx, unsigned short val);

int BTLV_EFFVM_CmdSetBgLayerEnable(void *a, char *s)
{
    BG_SYS_SetPriority(3, (unsigned char)VM_GetU32(a));
    ((struct Obj13587 *)s)->f0 |= 0x10;
    return ((struct Obj13587 *)s)->f23C;
}
