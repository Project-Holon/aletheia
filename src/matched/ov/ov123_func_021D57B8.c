/*
 * function: GSYNC_MESSAGE_PrintStreamId
 * address:  0x021D57B8
 * packet:   pkt_021D57B8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   GSYNC_MESSAGE_PrintStream  0x021D56FC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01933.h"

typedef unsigned int u32;

struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void GSYNC_MESSAGE_PrintStream(char *, int);

void GSYNC_MESSAGE_PrintStreamId(char *p, int a)
{
    MSGDATA_ReadString(((struct Obj01933 *)p)->f20, a, ((struct Obj01933 *)p)->f2C);
    GSYNC_MESSAGE_PrintStream(p, 0);
}
