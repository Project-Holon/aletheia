/*
 * function: GFL_NET_SYSTEM_ProcessChildRecv
 * address:  0x020390BC
 * packet:   pkt_020390BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetSys      0x021469D0  data
 *   GFL_NET_GetChildSendSize   0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum   0x0203D680  arm
 *   GFL_NET_RING_BUFF_EndChange   0x0203666C  arm
 *   GFL_NET_RING_BUFF_GetDataSize   0x020365E8  arm
 *   GFL_NET_SYSTEM_ProcessRecvRing   0x02038DF0  arm
 *
 * n slots of 0x10 bytes at g+0x4c, each prepared by GFL_NET_RING_BUFF_EndChange and then
 * offered to GFL_NET_SYSTEM_ProcessRecvRing up to four times, with the record at g+0x11c and
 * the frame returned by GFL_NET_GetChildSendSize handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * _pNetSys itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = GFL_NET_GetMaxConnectNum();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ProcessChildRecv.c \
 *       --func GFL_NET_SYSTEM_ProcessChildRecv --addr 0x020390BC --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

extern struct LinkState *_pNetSys;

extern u32 GFL_NET_GetChildSendSize(void);
extern u32 GFL_NET_GetMaxConnectNum(void);
extern void GFL_NET_RING_BUFF_EndChange(u8 *p);
extern int GFL_NET_RING_BUFF_GetDataSize(char *p);
extern void GFL_NET_SYSTEM_ProcessRecvRing(u8 *p, s32 i, u32 v, u8 *q, u8 *s);

void GFL_NET_SYSTEM_ProcessChildRecv(void)
{
    s32 i, j, n;
    u8 *s;

    s = (u8 *)GFL_NET_GetChildSendSize();
    if (((u8 *)_pNetSys) == 0)
        return;

    n = GFL_NET_GetMaxConnectNum();

    for (i = 0; i < n; i++) {
        GFL_NET_RING_BUFF_EndChange(((u8 *)_pNetSys) + 0x4C + (i << 4));
        for (j = 0; j < 4; j++) {
            if (GFL_NET_RING_BUFF_GetDataSize((char *)(((u8 *)_pNetSys) + 0x4C + (i << 4))) > 0)
                GFL_NET_SYSTEM_ProcessRecvRing(((u8 *)_pNetSys) + 0x4C + (i << 4), i,
                              *(u32 *)(((u8 *)_pNetSys) + 0x18),
                              ((u8 *)_pNetSys) + 0x11C + (i << 4), s);
        }
    }
}
