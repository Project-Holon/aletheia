/*
 * function: GFL_NET_STATE_ChangeoverStopParentRetry
 * address:  0x0203B4DC
 * packet:   pkt_0203B4DC
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
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopParentRetry.c \
 *       --func GFL_NET_STATE_ChangeoverStopParentRetry --addr 0x0203B4DC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_ChangeoverStopParentRetry(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)GFL_NET_GetSession() + 0x340) + 0x10))(1, 0) != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B390, 0, (int)0x282);
}
