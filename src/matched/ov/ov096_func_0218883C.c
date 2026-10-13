/*
 * function: TR_AI_CmdIfHasMajorStatus
 * address: 0x0218883C
 * packet: pkt_ov096_0218883C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareMajorStatus 0x0218885C thumb ov096
 */
#include "../include/Obj21924.h"
struct Cursor;
extern int TR_AI_CompareMajorStatus(struct Cursor *a, int b, int c);
int TR_AI_CmdIfHasMajorStatus(struct Cursor *a, int b)
{
    TR_AI_CompareMajorStatus(a, b, 3);
    return ((struct Obj21924 *)((unsigned int)b))->fC4;
}
