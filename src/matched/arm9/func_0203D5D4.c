/*
 * function: GFL_NET_GetGameKind
 * address:  0x0203D5D4
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_GetGameKind.c \
 *       --func GFL_NET_GetGameKind --addr 0x0203D5D4 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetInitParam(void);

u32 GFL_NET_GetGameKind(void)
{
    u8 *p = GFL_NET_GetInitParam();

    return p != 0 ? p[0x67] : 0;
}
