/*
 * function: GFL_NET_StartChangeoverEx
 * address:  0x0203D060
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x0203DA7C, whose only caller in the image is this function, and
 * 0x0203DA7C lies past this packet (another lane's), so it cannot be matched
 * from here.
 *
 * The trailing `*` is the usual unlabelled-follower case and not a byte
 * difference: the inferred extent runs on to 0x0203D0D0 because the three
 * eight-byte ARM long-branch veneers at 0x0203D0AC, 0x0203D0B8 and 0x0203D0C4
 * save no `lr` and so carry no label.  They want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *   blocker: `bl` to 0x0203DA7C has no witness outside this range (single
 *            caller, address outside this packet)
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_StartChangeover  0x0203BA98  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_IRC_WIRELESS_IsActive  0x0203DA4C  arm
 *   GFL_NET_IRC_WIRELESS_SetCallbacks  0x0203DA7C  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_StartChangeoverEx.c \
 *       --func GFL_NET_StartChangeoverEx --addr 0x0203D060 --cc 1.1p1 --arm
 */
#include "../include/Obj15978.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern int GFL_NET_IRC_WIRELESS_IsActive(void);
extern void *GFL_NET_IRC_WIRELESS_SetCallbacks(void *a0, void *a1, void *a2);
extern void GFL_NET_STATE_StartChangeover(u16 a0, u32 a1, u8 a2);

void GFL_NET_StartChangeoverEx(u32 a, u32 b, u32 c)
{
    u8 *s = GFL_NET_GetSession();
    u32 v = a;

    if (GFL_NET_IRC_WIRELESS_IsActive() == 1)
        v = (u32)GFL_NET_IRC_WIRELESS_SetCallbacks((void *)a, (void *)b, (void *)c);

    GFL_NET_STATE_StartChangeover(((struct Obj15978 *)s)->f56, v, 1);
}
