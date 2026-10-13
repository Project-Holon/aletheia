/*
 * function: GFL_NET_STATE_WifiErrorWait
 * address:  0x0203C068
 * packet:   pkt_0203C068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through GFL_NET_STATE_ChangeStateDebug when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiErrorWait.c  *       --func GFL_NET_STATE_WifiErrorWait --addr 0x0203C068 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_WifiErrorWait(void)
{
    if (((int (*)(u32))*(u32 *)(*(u32 *)((char *)GFL_NET_GetSession() + 0x340) + 0xC))(0) < 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203C05C, 0, (int)0x52C);
}
