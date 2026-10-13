/*
 * function: GFL_NET_SYSTEM_GetSendSize
 * address:  0x02037258
 * packet:   pkt_02037234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_GetSendSize.c \
 *       --func GFL_NET_SYSTEM_GetSendSize --addr 0x02037258 --cc 1.1p1 --arm
 */
#include "../include/Obj08828.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern u32  GFL_NET_GetChildSendSize(void);
extern u32  GFL_NET_GetMaxConnectNum(void);

u32 GFL_NET_SYSTEM_GetSendSize(void)
{
    u8 *p;

    p = GFL_NET_GetSession();
    if (p[0x64] != 0 && ((struct Obj08828 *)p)->f6C != 0)
        return ((struct Obj08828 *)p)->f6C;
    return GFL_NET_GetChildSendSize() * GFL_NET_GetMaxConnectNum();
}
