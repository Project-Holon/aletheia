/*
 * function: GFL_NET_STATE_ExitWait
 * address:  0x0203BEC8
 * packet:   pkt_0203BEC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   GFL_NET_STATE_FreeWork   0x0203AEEC  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ExitWait.c \
 *       --func GFL_NET_STATE_ExitWait --addr 0x0203BEC8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern void GFL_NET_STATE_FreeWork(u8 *p);

void GFL_NET_STATE_ExitWait(u8 *p)
{
    u8 *s;

    func_0203D798();
    s = GFL_NET_GetSession();

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x78))() != 0) {
        if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
            return;
        GFL_NET_STATE_FreeWork(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x6C))() != 0)
        return;
    if ((*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0) == 0)
        return;
    GFL_NET_STATE_FreeWork(p);
}
