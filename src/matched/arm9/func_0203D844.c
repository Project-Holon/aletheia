/*
 * function: GFL_NET_CopyInitParam
 * address:  0x0203D844
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies 0x70 bytes from the net context into the destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_CopyInitParam.c \
 *       --func GFL_NET_CopyInitParam --addr 0x0203D844 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

void GFL_NET_CopyInitParam(void *dst)
{
    MI_CpuCopy8(dst, GFL_NET_GetSession(), 0x70);
}
