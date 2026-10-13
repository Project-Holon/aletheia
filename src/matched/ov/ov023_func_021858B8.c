/*
 * function: OEKAKI_StepCheckMembers
 * address:  0x021858B8
 * packet:   pkt_ov023_021858B8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_GetJoinedCount  0x0218654C  thumb  ov023
 */
#include "../include/Obj20355.h"

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 GFL_NET_IsConnectMember(u32 index);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void OEKAKI_ApplyRemoteStrokes(char *p);
extern int  OEKAKI_GetJoinedCount(char *p);

int OEKAKI_StepCheckMembers(char *p, int a1)
{
    int h;
    int i;
    int mask;

    h = (int)GFL_NET_HANDLE_GetCurrentHandle();
    mask = 0;
    for (i = 0; i < 5; i++) {
        if (GFL_NET_IsConnectMember((unsigned char)i) == 1)
            mask |= 1 << i;
    }
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)h, 0xc8, 0x29) != 0 || OEKAKI_GetJoinedCount(p) == 1
        || mask != ((struct Obj20355 *)p)->f1B0) {
        WIPE_SYS_Start(0, 8, 8, 0, 0x10, 1, 0x28);
        a1 = 3;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
