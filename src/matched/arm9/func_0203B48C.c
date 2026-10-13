/*
 * function: GFL_NET_STATE_ChangeoverStopParent
 * address:  0x0203B48C
 * packet:   pkt_0203B48C
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
 * The same +0x10 virtual call as GFL_NET_STATE_ChangeoverStopParentRetry, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopParent.c \
 *       --func GFL_NET_STATE_ChangeoverStopParent --addr 0x0203B48C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_ChangeoverStopParent(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)GFL_NET_GetSession() + 0x340) + 0x10))(1, 0) != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B448, 0, 0x265);
}
