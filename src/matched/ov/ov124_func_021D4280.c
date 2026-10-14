/*
 * function: CG_HELP_Teardown
 * address: 0x021D4280
 * packet: pkt_ov124_021D4280
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   CG_HELP_FreeWindows 0x021D485C thumb ov124
 *   CG_HELP_FreeActorResources 0x021D4698 thumb ov124
 *   CG_HELP_ExitDisplay 0x021D4504 thumb ov124
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *);
extern void CG_HELP_FreeWindows(char *);
extern void CG_HELP_FreeActorResources(char *);
extern void CG_HELP_ExitDisplay(char *);
void CG_HELP_Teardown(char *p) {func_02030EAC(*(struct Node * *)&((struct Obj00991 *)p)->f14);CG_HELP_FreeWindows(p);CG_HELP_FreeActorResources(p);CG_HELP_ExitDisplay(p);}
