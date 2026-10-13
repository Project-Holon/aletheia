/*
 * function: TR_AI_CmdIfNotSickContKind
 * address: 0x02188914
 * packet: pkt_ov096_02188914
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareSickContKind 0x02188924 thumb ov096
 */
#include "../include/Obj21929.h"
struct Cursor;
extern int TR_AI_CompareSickContKind(struct Cursor *a, int b, int c);
int TR_AI_CmdIfNotSickContKind(struct Cursor *a, int b)
{
    TR_AI_CompareSickContKind(a, b, 3);
    return ((struct Obj21929 *)b)->fC4;
}
