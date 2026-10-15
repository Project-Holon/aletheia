/*
 * function: STA_ACT_SCRIPT_SkipArg
 * address: 0x021FAF1C
 * packet: pkt_ov132_021FAF1C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj23249.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
int STA_ACT_SCRIPT_SkipArg(void *a, char *p)
{
    VM_GetU32(((struct Obj23249 *)p)->f4);
    return 0;
}
