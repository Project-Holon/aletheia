/*
 * function: GFL_NET_SetGameKind
 * address:  0x0203D5AC
 * packet:   pkt_0203D5AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PROMOTED from src/pending/.  The `bl` to 0x0203A458 was this file's last
 * open site; it now resolves as `matched` against that function's own EXACT
 * shard entry, so the cap is gone.
 *
 * Sets the net context's +0x67 byte to the argument (after forcing the
 * context through GFL_NET_GetSession), then updates the channel with
 * GFL_NET_HANDLE_GetNetHandle(0xff) and GFL_NET_HANDLE_SetAllTimingValue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetGameKind.c \
 *       --func GFL_NET_SetGameKind --addr 0x0203D5AC --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_HANDLE_SetAllTimingValue  0x0203A458  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern void GFL_NET_HANDLE_SetAllTimingValue(u8 *a0, u32 a1);

void GFL_NET_SetGameKind(int a, int b)
{
    u8 *p;

    GFL_NET_GetSession();
    p = GFL_NET_GetInitParam();
    p[0x67] = (u8)a;
    GFL_NET_HANDLE_SetAllTimingValue((u8 *)GFL_NET_HANDLE_GetNetHandle(0xff), a);
}
