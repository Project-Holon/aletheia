/*
 * function: GFL_NET_SYSTEM_ParentConnectHook
 * address:  0x0203781C
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_SYSTEM_ResetRecvBuffer   0x02037680  arm
 *
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_ParentConnectHook.c \
 *       --func GFL_NET_SYSTEM_ParentConnectHook --addr 0x0203781C --cc 1.1p1 --arm
 */
#include "../include/Obj15920.h"

typedef unsigned int u32;

extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern void GFL_NET_SYSTEM_ResetRecvBuffer(int i);

void GFL_NET_SYSTEM_ParentConnectHook(u32 arg)
{
    char *a = func_0203D798();
    char *b = GFL_NET_GetSession();
    void (*hook)(u32, u32);

    GFL_NET_SYSTEM_ResetRecvBuffer(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15920 *)b)->f34C, arg);
}
