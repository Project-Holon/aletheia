/*
 * function: GFL_NET_STATE_ChangeoverWaitDevice
 * address:  0x0203B448
 * packet:   pkt_0203B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverWaitDevice.c \
 *       --func GFL_NET_STATE_ChangeoverWaitDevice --addr 0x0203B448 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_ChangeoverWaitDevice(void)
{
    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)GFL_NET_GetSession() + 0x340) + 0x78))() != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B390, 0, (int)0x25D);
}
