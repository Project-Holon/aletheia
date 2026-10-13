/*
 * function: GFL_NET_GetChildSendSize
 * address:  0x0203D6BC
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the byte at +0x61 of the net context.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetChildSendSize.c \
 *       --func GFL_NET_GetChildSendSize --addr 0x0203D6BC --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *GFL_NET_GetSession(void);

u32 GFL_NET_GetChildSendSize(void)
{
    return GFL_NET_GetSession()[0x61];
}
