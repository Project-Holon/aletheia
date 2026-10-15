/*
 * function: WIFILOGIN_COMMON_CheckLocalAid
 * address:  0x021D4270
 * packet:   pkt_ov115_021D4270
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: extent is 30 bytes (label gap said 56; the rest is data and two tiny leaves).
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

void WIFILOGIN_COMMON_CheckLocalAid(u32 a, u32 b, u32 c, u8 *p, u32 id)
{
    if (id == GFL_NET_HANDLE_GetCurrentHandle() && a != GFL_NET_SYSTEM_GetCurrentAid()) {
        *(u32 *)(p + 0x1c) = 1;
    }
}
