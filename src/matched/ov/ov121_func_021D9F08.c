/*
 * function: MYSTERY_UTIL_SetMenuMessage
 * address:  0x021D9F08
 * packet:   pkt_021D9F08
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MYSTERY_UTIL_SetMenuMode  0x021D9F24  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00236.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void MYSTERY_UTIL_SetMenuMode(u8 *p, int mode);

void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d)
{
    MSGDATA_ReadString((struct MsgBank *)b, c, ((struct Obj00236 *)a)->f14);
    MYSTERY_UTIL_SetMenuMode(a, d);
}
