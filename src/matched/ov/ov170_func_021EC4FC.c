/*
 * function: BOX2_SEQ_ShowPartyIcons
 * address: 0x021EC4FC
 * packet: pkt_ov170_021EC4FC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   BOX2_SEQ_LoadIconResource 0x021EC45C thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */
#include "../include/Obj06550.h"
#include "../include/Obj24004.h"
#include "../include/Obj24005.h"
extern unsigned POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *, unsigned);
extern void *POKE_TOOL_GetBoxParam(void *);
extern void BOX2_SEQ_LoadIconResource(unsigned char *, void *, int);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
void BOX2_SEQ_ShowPartyIcons(unsigned char *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24004 *)(*(char * *)&((struct Obj06550 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < n; i++) {
        BOX2_SEQ_LoadIconResource(p, POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(((struct Obj24005 *)(*(char * *)&((struct Obj06550 *)p)->f0))->f8, i)),
                       *(unsigned char *)(*(char * *)&((struct Obj06550 *)p)->f2C + i + 0x3DF0));
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj06550 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj06550 *)p)->f2C + i + 0x3DF0), 0);
    }
}
