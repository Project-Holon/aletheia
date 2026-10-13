/*
 * function: GFL_NET_STATE_WifiEnterFriendMatch
 * address:  0x0203C35C
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_ResetAll  0x02037D78  arm
 *   GFL_NET_HANDLE_ExitWork  0x020398B4  arm
 *   GFL_NET_HANDLE_InitWork  0x02039834  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5FD, returning success.  The twin at 0x0203C304 is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiEnterFriendMatch.c  *       --func GFL_NET_STATE_WifiEnterFriendMatch --addr 0x0203C35C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_SYSTEM_ResetAll(void);
extern void GFL_NET_HANDLE_ExitWork(u8 *h);
extern void GFL_NET_HANDLE_InitWork(u8 *h);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

u32 GFL_NET_STATE_WifiEnterFriendMatch(void)
{
    u8 *h = GFL_NET_GetSession();

    *(signed char *)(*(u32 *)((char *)(0x21469DC)) + 0x48) = -2;
    GFL_NET_SYSTEM_ResetAll();
    GFL_NET_HANDLE_ExitWork(h);
    GFL_NET_HANDLE_InitWork(h);
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203C0F4, 0, (int)0x5FD);
    return 1;
}
