/*
 * function: GFL_NET_STATE_WifiMatchStart
 * address:  0x0203C864
 * packet:   pkt_0203C65C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/GFL_NET_SYSTEM_InitDevice.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_SYSTEM_InitDevice  0x02037700  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchStart.c \
 *       --func GFL_NET_STATE_WifiMatchStart --addr 0x0203C864 --cc 1.1p1 --arm
 */
#include "../include/Obj15970.h"
#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetInitParam(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern int GFL_NET_SYSTEM_InitDevice(u32 a0, u32 a1);

void GFL_NET_STATE_WifiMatchStart(void)
{
    u8 *p = GFL_NET_GetInitParam();

    if (GFL_NET_SYSTEM_InitDevice(0x200, ((struct Obj15970 *)p)->f56) == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C7E0, 0, 0x74A);
}
