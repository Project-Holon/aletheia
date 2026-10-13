/*
 * function: GFL_NET_STATE_WifiDisconnectFinal
 * address:  0x0203C5C8
 * packet:   pkt_0203C494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   unk_021469DC   0x021469DC  data
 *
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiDisconnectFinal.c \
 *       --func GFL_NET_STATE_WifiDisconnectFinal --addr 0x0203C5C8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern u32  unk_021469DC;

void GFL_NET_STATE_WifiDisconnectFinal(void)
{
    GFL_NET_STATE_WifiDisconnect(1);
    ((u8 *)unk_021469DC)[0x4A] = 1;
}
