/*
 * function: WIFIBATTLEMATCH_UTIL_PrintMessage
 * address:  0x021E8738
 * packet:   pkt_021E8738
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WIFIBATTLEMATCH_UTIL_SetMode  0x021E8754  thumb  ov177
 */
#include "../include/Obj24449.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WIFIBATTLEMATCH_UTIL_SetMode(int *, int);

void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c)
{
    MSGDATA_ReadString((struct MsgBank *)a, b, (void *)(((struct Obj24449 *)p)->f18));
    WIFIBATTLEMATCH_UTIL_SetMode(p, c);
}
