/*
 * function: func_0203D01C
 * address:  0x0203D01C
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_STATE_WifiEnterLoginDefault  0x0203C3B4  arm
 *   GFL_NET_STATE_InitParent  0x0203B2D0  arm
 */
#include "../include/Obj11372.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_STATE_WifiEnterLoginDefault(void);
extern void GFL_NET_STATE_InitParent(u32 a);

void func_0203D01C(void)
{
    u8 *s = GFL_NET_GetSession();

    switch (s[0x65]) {
    case 1:
    case 2:
        GFL_NET_STATE_WifiEnterLoginDefault();
        return;
    case 0:
    case 5:
        GFL_NET_STATE_InitParent(((struct Obj11372 *)s)->f56);
        return;
    default:
        return;
    }
}
