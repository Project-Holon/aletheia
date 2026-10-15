/*
 * function: DIGITALCARDCHECK_SetBattleRecordValue
 * address:  0x0217D388
 * packet:   pkt_0217D388
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REGULATION_Card_GetValue  0x0200B078  thumb
 */
#include "../include/Obj24427.h"
#include "../include/Obj24428.h"

typedef signed int     s32;
typedef unsigned int   u32;
struct Reg2;
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);

void DIGITALCARDCHECK_SetBattleRecordValue(int *p, int *q)
{
    ((struct Obj24427 *)p)->f40 = REGULATION_Card_GetValue((struct Reg2 *)(((struct Obj24428 *)q)->f38), 2);
}
