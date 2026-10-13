/*
 * unit:     yes
 * function: GFL_NET_STATE_Exit
 * address:  0x0203BF9C
 * packet:   pkt_0203BEC8
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
 *   GFL_NET_STATE_ExitStopDevice  0x0203BF4C  arm
 *
 * 116 bytes, three functions: the setter, the 28-byte leaf that clears the
 * same flag, and the four-byte `bx lr` stub the card task is handed as a
 * callback (src/pending/GFL_NET_STATE_EndDevice.c passes it at 0x0203C00C).
 *
 * The two leaves carry no label in the generated listing - neither saves `lr`
 * - so this range used to stop at 0x0203BF9C with an `EXACT*`, the inferred
 * extent running on to the next labelled function at 0x0203C010.  Writing
 * them as the unit's own functions is what closes the range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203BF9C.c \
 *       --addr 0x0203BF9C --arm --cc 1.1p1
 */
#include "../include/Obj11878.h"
#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_ExitStopDevice(void);

void GFL_NET_STATE_Exit(u32 v)
{
    u8 *p = ((u8 *)_pNetState);

    if (p != 0 && p[0x51] != 0)
        return;

    ((struct Obj11878 *)p)->f28 = v;
    ((u8 *)_pNetState)[0x51] = 1;
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)GFL_NET_STATE_ExitStopDevice, 5, 0x4B7);
}

void GFL_NET_STATE_ClearExitFlag(void)
{
    if (((u8 *)_pNetState) != 0)
        ((u8 *)_pNetState)[0x51] = 0;
}

void GFL_NET_STATE_Idle(void)
{
}
