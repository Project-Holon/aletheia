/*
 * function: GFL_NET_SYSTEM_SetDeviceOption
 * address:  0x0203778C
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *
 * 32-byte hook dispatcher: GFL_NET_GetSession returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_SetDeviceOption.c \
 *       --func GFL_NET_SYSTEM_SetDeviceOption --addr 0x0203778C --cc 1.1p1 --arm
 */
#include "../include/Obj15915.h"

typedef unsigned int u32;

extern void *GFL_NET_GetSession(void);

u32 GFL_NET_SYSTEM_SetDeviceOption(u32 p)
{
    char *c = GFL_NET_GetSession();
    u32 (*f)(u32) = *(u32 (**)(u32))(*(char * *)&((struct Obj15915 *)c)->f340 + 0x90);

    return f(p);
}
