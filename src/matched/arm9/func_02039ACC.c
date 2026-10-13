/*
 * function: GFL_NET_HANDLE_CheckNegotiation
 * address:  0x02039ACC
 * packet:   pkt_02039A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *
 * Seeds the current record's +0x4a state byte: state 2 re-arms the eight-slot
 * table through GFL_NET_SendToHandle with a 3-byte payload built in a 12-byte stack
 * buffer, any state below 2 is stepped up by one, anything else is left alone.
 * The early `beq` on GFL_NET_SYSTEM_IsConnectMember() is the R4 shared-tail lever: the first
 * exit branches to the function's last `return 0` instead of predicating
 * `moveq r0, #0` / `popeq` (which cost 12 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_CheckNegotiation.c \
 *       --func GFL_NET_HANDLE_CheckNegotiation --addr 0x02039ACC --cc 1.1p1 --arm
 */
#include "../include/Obj11357.h"
#include "../include/Obj11358.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 GFL_NET_SYSTEM_IsConnectMember(u32 mode);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern void OS_GetMacAddress(void *p);

int GFL_NET_HANDLE_CheckNegotiation(void)
{
    u8 buf[12];
    u8 *p;
    u8 v;
    u8 *q;
    u32 f;

    p = (u8 *)GFL_NET_HANDLE_GetCurrentHandle();
    v = (u8)GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p);
    GFL_NET_GetSession();
    q = GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_IsConnectMember(GFL_NET_SYSTEM_GetCurrentAid()) != 0) {
        f = ((struct Obj11357 *)p)->f4A;
        if (f == 2) {
            OS_GetMacAddress(buf);
            buf[6] = v;
            buf[7] = ((struct Obj11358 *)q)->f67;
            buf[8] = ((struct Obj11358 *)q)->f6E;
            return GFL_NET_SendToHandle((struct Entry *)p, 3, 9, (u32)buf);
        }
        if (f < 2)
            ((struct Obj11357 *)p)->f4A = f + 1;
    }
    return 0;
}
