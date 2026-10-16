/*
 * function: ISS_3DS_SYS_ApplySourcePan
 * address:  0x0202BE00
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Signals one record's +0x3c halfword to GFL_USE_SetBgmTrackParams with the +0x224
 * context pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_ApplySourcePan.c \
 *       --func ISS_3DS_SYS_ApplySourcePan --addr 0x0202BE00 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_SetBgmTrackParams  0x02005EE0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_SetBgmTrackParams(u32 a, u32 b, u32 c, u32 d);

void ISS_3DS_SYS_ApplySourcePan(u8 *p, u32 i)
{
    GFL_USE_SetBgmTrackParams(*(u16 *)(p + i * 0x1c + 0x3c), 0x100, 0,
                  *(u32 *)(p + i * 4 + 0x224));
}
