/*
 * function: GFL_NET_SYSTEM_ProcessParentRecv
 * address:  0x02039050
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   _pNetSys     0x021469D0  data
 *   GFL_NET_RING_BUFF_GetDataSize  0x020365E8  arm
 *   GFL_NET_RING_BUFF_EndChange  0x0203666C  arm
 *   GFL_NET_SYSTEM_GetSendSize  0x02037258  arm
 *   GFL_NET_SYSTEM_ProcessRecvRing  0x02038DF0  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ProcessParentRecv.c \
 *       --func GFL_NET_SYSTEM_ProcessParentRecv --addr 0x02039050 --cc 1.1p1 --arm
 */
#include "../include/Obj15938.h"
#include "../include/G_LinkState.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct LinkState *_pNetSys;
extern void GFL_NET_RING_BUFF_EndChange(u32 a);
struct Src;
struct St;
extern int GFL_NET_RING_BUFF_GetDataSize(char *p);
extern u32 GFL_NET_SYSTEM_GetSendSize(void);
extern void GFL_NET_SYSTEM_ProcessRecvRing(struct Src *src, u32 a1, u8 *buf, struct St *st, u32 n);

void GFL_NET_SYSTEM_ProcessParentRecv(void)
{
    int i;
    u8 *p;

    if (((u8 *)_pNetSys) == 0)
        return;

    GFL_NET_RING_BUFF_EndChange((u32)(((u8 *)_pNetSys) + 0x2C));

    for (i = 0; i < 4; i++) {
        if ((int)GFL_NET_RING_BUFF_GetDataSize((char *)((u32)(((u8 *)_pNetSys) + 0x2C))) <= 0)
            return;

        p = ((u8 *)_pNetSys);
        GFL_NET_SYSTEM_ProcessRecvRing((struct Src *)((u32)(p + 0x2C)), 0xFF, (u8 *)(((struct Obj15938 *)p)->f18),
                      (struct St *)((u32)(p + 0x19C)), GFL_NET_SYSTEM_GetSendSize());
    }
}
