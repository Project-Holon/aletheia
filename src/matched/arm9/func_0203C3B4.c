/*
 * function: GFL_NET_STATE_WifiEnterLoginDefault
 * address:  0x0203C3B4
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   str_0203C238   0x0203C238  data
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;
extern const char str_0203C238[];

typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_WifiEnterLoginDefault(void)
{
    _pNetState->flag = -1;
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)_pNetState, (void *)str_0203C238, 0, 0x60d);
}
