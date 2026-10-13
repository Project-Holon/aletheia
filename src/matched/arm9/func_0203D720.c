/*
 * function: GFL_NET_CallErrorStateFunc
 * address:  0x0203D720
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x28 callback with the GFL_NET_HANDLE_GetCurrentHandle result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_CallErrorStateFunc.c \
 *       --func GFL_NET_CallErrorStateFunc --addr 0x0203D720 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 */
#include "../include/Obj11378.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

void GFL_NET_CallErrorStateFunc(u32 a)
{
    u8 *p = GFL_NET_GetSession();

    if (((struct Obj11378 *)p)->f28 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) * (u32 *)(p + 0x28))(
        (u32)GFL_NET_HANDLE_GetCurrentHandle(), a, ((struct Obj11378 *)p)->f34C);
}
