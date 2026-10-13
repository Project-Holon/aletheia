/*
 * function: GFL_NET_CheckError
 * address:  0x0203D880
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A bare tail-call thunk to GFL_NET_SYSTEM_CheckError.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_CheckError.c \
 *       --func GFL_NET_CheckError --addr 0x0203D880 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 */

typedef unsigned int   u32;
extern u32 GFL_NET_SYSTEM_CheckError(void);

u32 GFL_NET_CheckError(void)
{
    return GFL_NET_SYSTEM_CheckError();
}
