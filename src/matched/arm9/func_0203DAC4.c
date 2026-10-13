/*
 * function: GFL_NET_IRC_WIRELESS_AddMacAddress
 * address:  0x0203DAC4
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Registers a peer MAC address: returns if it is
 * already in one of the four 8-byte slots at +0x94, otherwise copies it
 * into the first all-zero slot and records the slot index at +0x90; with
 * no free slot it reports error 1 (GFL_NET_STATE_SetErrorMode).  func_0203EFC8 is the
 * memcmp-style compare, MI_CpuCopy8 MI_CpuCopy8.
 *
 * The lever (docs/notes/pkt_0203DAC4.c.txt had 24 bytes out): the zero MAC
 * is a SIX-byte block-scope array with an initialiser, `u8 buf[6] = {0};`
 * spelled out.  The initialiser takes the array's address first (`add r8,
 * sp, #0`) and stores through it; six separate assignments to an 8-byte
 * array store off sp and sink the address.  Flat under 2000 permuter
 * compiles before the declaration change.
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 *   func_0203EFC8  0x0203EFC8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_STATE_SetErrorMode  0x0203C938  arm
 */

#include "../include/G_Ctx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Ctx *gNetIrcWirelessLink;
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 GFL_NET_STATE_SetErrorMode(u8 mode);

void GFL_NET_IRC_WIRELESS_AddMacAddress(const u8 *mac)
{
    int i;

    if (((u8 *)gNetIrcWirelessLink) == 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_0203EFC8(mac, ((u8 *)gNetIrcWirelessLink) + 0x94 + i * 8, 6) == 0)
            return;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 4; i++) {
            if (func_0203EFC8(buf, ((u8 *)gNetIrcWirelessLink) + 0x94 + i * 8, 6) == 0) {
                MI_CpuCopy8(mac, ((u8 *)gNetIrcWirelessLink) + 0x94 + i * 8, 6);
                *(u32 *)(((u8 *)gNetIrcWirelessLink) + 0x90) = i;
                return;
            }
        }
    }
    GFL_NET_STATE_SetErrorMode(1);
}
