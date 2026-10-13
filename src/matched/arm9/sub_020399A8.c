/*
 * function: GFL_NET_HANDLE_GetCurrentHandle
 * address:  0x020399A8
 * packet:   pkt_020398B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_0203996C  0x0203996C  arm
 *
 * A two-call forwarder: the index func_02039338 returns goes straight to
 * func_0203996C through r0, and that entry is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_GetCurrentHandle.c  *       --func GFL_NET_HANDLE_GetCurrentHandle --addr 0x020399A8 --cc 1.1p1 --arm
 */

struct Entry;

typedef unsigned short u16;
extern u16 func_02039338(void);
extern struct Entry *func_0203996C(int idx);

struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void)
{
    return func_0203996C(func_02039338());
}
