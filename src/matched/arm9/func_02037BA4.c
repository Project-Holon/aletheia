/*
 * function: GFL_NET_SYSTEM_CheckAutoFree
 * address:  0x02037BA4
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetSys      0x021469D0  data
 *   func_02039338   0x02039338  arm
 *   GFL_NET_SYSTEM_GetChildBitmap   0x020393A8  arm
 *   GFL_NET_SYSTEM_FreeWork   0x02037B08  arm
 *
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs GFL_NET_SYSTEM_FreeWork and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs GFL_NET_SYSTEM_FreeWork.  The two `bl GFL_NET_SYSTEM_FreeWork` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_CheckAutoFree.c \
 *       --func GFL_NET_SYSTEM_CheckAutoFree --addr 0x02037BA4 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;

extern struct LinkState *_pNetSys;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern int   GFL_NET_SYSTEM_GetChildBitmap(void);
extern void  GFL_NET_SYSTEM_FreeWork(void);

void GFL_NET_SYSTEM_CheckAutoFree(void)
{
    if (*(u8 *)(((char *)_pNetSys) + 0x1EC) == 0)
        return;
    if (func_02039338() == 0) {
        if (GFL_NET_SYSTEM_GetChildBitmap() == 0)
            GFL_NET_SYSTEM_FreeWork();
        return;
    }
    GFL_NET_SYSTEM_FreeWork();
}
