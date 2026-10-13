/*
 * function: GFL_NET_IRC_WIRELESS_CopyMacAddress
 * address:  0x0203DBB0
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 * blocker:  str_020A7D48 (string) -- no witness outside 0203DBB0..0203DC04;
 *           the file string at 0x020A7D34 is 16 bytes and the message string
 *           is 3 bytes past its terminator, so the `string` class refuses.
 *           Every concrete byte of the body reproduces.
 * symbols:
 *   gNetIrcWirelessLink    0x021469F0  data
 *   str_020A7D34  0x020A7D34  data
 *   str_020A7D48  0x020A7D48  data
 *   func_02034714 0x02034714  arm
 *   MI_CpuCopy8 0x02082D44  arm
 */

#include "../include/G_Ctx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ctx *gNetIrcWirelessLink;
extern const u8 str_020A7D34[];
extern const u8 str_020A7D48[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

void GFL_NET_IRC_WIRELESS_CopyMacAddress(const void *src, u32 i)
{
    u8 *g = ((u8 *)gNetIrcWirelessLink);

    if (g != 0) {
        MI_CpuCopy8(g + 0x94 + i * 8, src, 6);
    } else {
        func_02034714((const char *)str_020A7D34, 0x109, (const char *)str_020A7D48);
    }
}
