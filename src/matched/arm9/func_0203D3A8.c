/*
 * unit:     no
 * function: GFL_NET_SendToHandle
 * address:  0x0203D3A8
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_SYSTEM_SetSendQueue  0x02038C18  arm
 *
 * TU: net.c.
 *
 * Seven-argument send wrapper.  The leading GFL_NET_GetInitParam call is made for
 * effect only, its result is dead in the original, and the four incoming
 * arguments all have to survive it, which is what spends r4-r7.  Arguments
 * five to seven go on the stack, hence the `sub sp, sp, #0xc`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SendToHandle.c \
 *       --func GFL_NET_SendToHandle --addr 0x0203D3A8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;

extern void *GFL_NET_GetInitParam(void);
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern int   GFL_NET_SYSTEM_SetSendQueue(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d)
{
    GFL_NET_GetInitParam();
    return GFL_NET_SYSTEM_SetSendQueue(b, d, c, 0, GFL_NET_HANDLE_GetNetHandleID(a), 0xff, 0);
}
