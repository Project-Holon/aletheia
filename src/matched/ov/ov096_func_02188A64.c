/*
 * function: TR_AI_CmdIfValueGreater
 * address: 0x02188A64
 * packet: pkt_ov096_02188A64
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TR_AI_CompareValue 0x02188AB4 thumb ov096
 */
#include "../include/Obj21936.h"
struct Cursor;
extern int TR_AI_CompareValue(struct Cursor *a, unsigned char *b, int c);
int TR_AI_CmdIfValueGreater(int a, int b)
{
    TR_AI_CompareValue((struct Cursor *)a, (unsigned char *)b, 1);
    return ((struct Obj21936 *)b)->fC4;
}
