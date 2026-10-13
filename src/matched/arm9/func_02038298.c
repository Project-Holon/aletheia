/*
 * function: GFL_NET_SYSTEM_SendIrc
 * address:  0x02038298
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetSys     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_SYSTEM_BuildSendPacket  0x02038AE0  arm
 *
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes _pNetSys directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SendIrc.c \
 *       --func GFL_NET_SYSTEM_SendIrc --addr 0x02038298 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct LinkState *_pNetSys;
extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern u32 GFL_NET_GetChildSendSize(void);
typedef signed int     s32;
struct Conn;
struct Hdr;
extern s32 GFL_NET_SYSTEM_BuildSendPacket(struct Hdr *h, struct Conn *c, s32 len, u8 a3);

void GFL_NET_SYSTEM_SendIrc(void)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = GFL_NET_GetSession();
    v = GFL_NET_GetChildSendSize();

    if (*(u8 *)(((u8 *)_pNetSys) + 0x1E7) == 0)
        return;
    if (*(u8 *)(((u8 *)_pNetSys) + 0x1ED) == 0) {
        if (GFL_NET_SYSTEM_BuildSendPacket((struct Hdr *)(*(u32 *)((u8 *)_pNetSys)), (struct Conn *)(((u8 *)_pNetSys) + 0xCC),
                          GFL_NET_GetChildSendSize(),
                          *(u8 *)(((u8 *)_pNetSys) + 0x1D5)) != 0)
            *(u8 *)(((u8 *)_pNetSys) + 0x1ED) = 1;
    }

    if (*(u8 *)(((u8 *)_pNetSys) + 0x1ED) != 1)
        return;
    if (((u32 (*)(u32, u32, u32, u32))
             * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(*(u32 *)((u8 *)_pNetSys), v,
                                                    0, 0) == 0)
        return;
    *(u8 *)(((u8 *)_pNetSys) + 0x1ED) = 0;
}
