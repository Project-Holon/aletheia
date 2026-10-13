/*
 * function: IRC_RESULT_ExitScreen
 * address: 0x021B78A0
 * packet: pkt_ov105_021B78A0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   IRC_RESULT_ExitBackgrounds 0x021B7A3C thumb ov105
 *   IRC_RESULT_ExitActorSystem 0x021B7BC0 thumb ov105
 */
#include "../include/Obj22240.h"
struct Node; extern void func_02030EAC(struct Node *); extern void IRC_RESULT_ExitBackgrounds(unsigned int *); extern void IRC_RESULT_ExitActorSystem(void **);
void IRC_RESULT_ExitScreen(unsigned char *p) { func_02030EAC(*(struct Node * *)&((struct Obj22240 *)p)->fAC); IRC_RESULT_ExitBackgrounds((unsigned int *)p); IRC_RESULT_ExitActorSystem((void **)(p+4)); }
