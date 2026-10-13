/*
 * function: GFL_NET_SYSTEM_GetConnectNum
 * address:  0x020392B8
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *
 * Counts the eight slots whose test function answers non-zero.  The slot
 * number goes in as a `u16` - the `lsl #16` / `lsr #16` pair in the loop is
 * that narrowing - so the callee is declared with a `u16` parameter and the
 * cast costs nothing at the call site.  The counter is in r4 and the index in
 * r5, which is the declaration order below.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_GetConnectNum.c \
 *       --func GFL_NET_SYSTEM_GetConnectNum --addr 0x020392B8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

extern u32 GFL_NET_SYSTEM_IsConnectMember(u16 slot);

u32 GFL_NET_SYSTEM_GetConnectNum(void)
{
    u32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 8; i++) {
        if (GFL_NET_SYSTEM_IsConnectMember((u16)i) != 0)
            count++;
    }
    return count;
}
