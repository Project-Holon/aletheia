/*
 * function: GFL_NET_HANDLE_Main
 * address:  0x02039D94
 * packet:   pkt_02039D94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pBaseWork     0x021469D4  data
 *   file_020A7A68  0x020A7A68  data
 *   msg_020A7A94   0x020A7A94  data
 *   GFL_NET_SYSTEM_ClampNetId  0x020395E0  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   GFL_NET_HANDLE_SendNegotiation  0x02039A5C  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SendTimingSyncAll  0x02039CD8  arm
 *   GFL_NET_HANDLE_IsBitSet  0x0203A2F0  arm
 *   GFL_NET_HANDLE_SetBitMask  0x0203A28C  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_IsHandleReady  0x0203D394  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *
 * The net_handle.c tick (docs/families/net_handle.h).  Closed from the
 * 652-byte / 14-out source of docs/notes/pkt_02039D94.c.txt with two
 * changes:
 *   1. The two owner callbacks at g+0x14 / g+0x10 each TAKE GFL_NET_GetUserArg's
 *      result as their argument: `a = g->get_a(GFL_NET_GetUserArg())`.  That is
 *      why the image calls through r1 (`ldr r1, [r4, #0x14]; blx r1`):
 *      r0 is holding the argument.  Called with no argument the compile
 *      goes through r0 (4 bytes out).
 *   2. Phases 2 and 4 reuse the entry pointer `e` for the own entry
 *      (GFL_NET_HANDLE_GetNetHandle(0xff)); there is no separate `own` local.  With a
 *      separate local the own pointer and the loop index swap sb/sl in
 *      phase 2 (or r6/r7 in phase 4).
 */
#include "../include/Obj04750.h"
#include "../include/Obj08835.h"
#include "../include/G_Votes.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int GFL_NET_SYSTEM_ClampNetId(int slot);
typedef signed int     s32;
struct Entry;
struct NetEntry;
struct Obj;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_SYSTEM_IsConnectMember(u16 mode);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *e);
extern void GFL_NET_HANDLE_SendNegotiation(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_HANDLE_SendTimingSyncAll(struct Obj *p);
extern u32 GFL_NET_HANDLE_IsBitSet(u32 a0, u32 a1);
extern u16 GFL_NET_HANDLE_SetBitMask(u16 mask, u32 idx, u32 set);
extern u32 GFL_NET_IsParentAid(void);
extern u32 GFL_NET_IsHandleReady(struct NetEntry *e);
extern u32 GFL_NET_SendDataMask(u8 *e, u32 a, u32 b, u32 c, void *d, u32 e2, u32 f, u32 g2);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 GFL_NET_GetUserArg(void);
extern void *GFL_NET_GetInitParam(void);
extern void func_02034714(const char *file, u32 line, const char *msg);

extern struct Votes *_pBaseWork;
extern const char file_020A7A68[];
extern const char msg_020A7A94[];

void GFL_NET_HANDLE_Main(void)
{
    u8 *e;
    u8 *g;
    int i;

    for (i = 0; i < 8; i++) {
        u32 s = GFL_NET_SYSTEM_ClampNetId(i);
        e = (u8 *)GFL_NET_HANDLE_GetNetHandle(s);
        if (GFL_NET_SYSTEM_IsConnectMember((u16)s) == 0)
            GFL_NET_HANDLE_IsNegotiationDone(e);
    }

    GFL_NET_HANDLE_SendNegotiation();

    if (GFL_NET_IsParentAid() != 0) {
        e = (u8 *)GFL_NET_HANDLE_GetNetHandle(0xff);
        for (i = 0; i < 9; i++) {
            u8 *r = ((u8 *)_pBaseWork) + i;
            if (r[0x18] != 1)
                continue;
            if (GFL_NET_SendDataMask(e, r[0x10], 8, 2,
                              ((u8 *)_pBaseWork) + i * 2, 0, 0, 0) == 0)
                continue;
            if ((((u8 *)_pBaseWork) + i)[0x10] == 0)
                func_02034714(file_020A7A68, 0x29a, msg_020A7A94);
            (((u8 *)_pBaseWork) + i)[0x18] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        u8 *p;
        p = (u8 *)GFL_NET_HANDLE_GetNetHandle(GFL_NET_SYSTEM_ClampNetId(i));
        if (GFL_NET_IsHandleReady((struct NetEntry *)p) == 0)
            continue;
        if (p[0x49] == 0)
            continue;
        if (GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p) == 0xff)
            continue;
        if (GFL_NET_SendToHandle((struct Entry *)p, (u16)7, (u16)4, (u32)(p + 0x46)) != 0)
            p[0x49] = 0;
    }

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        e = (u8 *)GFL_NET_HANDLE_GetNetHandle(0xff);
        if (e != 0) {
            for (i = 0; i < 8; i++) {
                u8 *s = *(u8 **)(e + i * 4 + 8);
                if (s == 0 || s[0xd] == 0)
                    continue;
                if (GFL_NET_HANDLE_IsBitSet(((struct Obj04750 *)e)->f40, i) != 0)
                    continue;
                if (GFL_NET_HANDLE_SendTimingSyncAll((struct Obj *)e) != 0)
                    ((struct Obj04750 *)e)->f40 =
                        GFL_NET_HANDLE_SetBitMask(((struct Obj04750 *)e)->f40, i, 1);
            }
        }
    }

    g = GFL_NET_GetInitParam();
    if (g[0x65] == 4)
        return;

    e = (u8 *)GFL_NET_HANDLE_GetCurrentHandle();
    if (e[0x4e] != 1)
        return;

    if (((struct Obj08835 *)g)->f10 != 0 && ((struct Obj08835 *)g)->f14 != 0) {
        u32 a;
        u32 b;
        a = (*(u32 (**)(u32))(g + 0x14))(GFL_NET_GetUserArg());
        b = (*(u32 (**)(u32))(g + 0x10))(GFL_NET_GetUserArg());
        if (GFL_NET_SendToHandle((struct Entry *)e, (u16)0xa, (u16)a, (u32)((void *)b)) != 0)
            e[0x4e] = 0;
    } else {
        e[0x4e] = 0;
    }
}

