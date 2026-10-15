/*
 * function: SCRIPT_COMMAND_CmdStartSeq
 * address:  0x021FC5BC
 * packet:   pkt_021FC5BC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   STA_ACTING_StartSeq  0x021F9680  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14123.h"
#include "../include/Obj23264.h"

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void STA_ACTING_StartSeq(char *p, int a);

int SCRIPT_COMMAND_CmdStartSeq(int a, char **pp)
{
    char *p = *pp;
    int x = VM_GetU32((struct Cursor *)(((struct Obj14123 *)pp)->f4));

    STA_ACTING_StartSeq(((struct Obj23264 *)p)->f34, (unsigned short)x);
    return 0;
}
