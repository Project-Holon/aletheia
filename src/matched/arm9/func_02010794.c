/*
 * function: WIH_DWC_CreateFilterBuffer
 * address:  0x02010794
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihDwc        0x021461E0  data
 *   sWihDwcAssertArg           0x020A7240  data
 *   sWihDwcFile       0x020A7244  data
 *   func_02034714     0x02034714  arm
 *   GFL_NET_AllocAligned     0x0203D7C8  arm
 *
 * wih_dwc.c: (re)build the second field of the object at 0x021461E0.  The
 * guard is the same file-name call the rest of this file makes - here the
 * polarity is inverted, so it fires when the pointer is ALREADY set (a
 * re-initialisation warning rather than an uninitialised one).
 *
 * The tail calls GFL_NET_AllocAligned(heap, 0xA00, "wih_dwc.c", 0x1C0), which is the
 * debug/allocator shape this SDK uses: a heap ID, a size, a __FILE__
 * string and a line number.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIH_DWC_CreateFilterBuffer.c \
 *       --func WIH_DWC_CreateFilterBuffer --addr 0x02010794 --cc 1.1p1 --thumb
 */

#include "../include/G_WihCtx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct WihCtx gWihDwc;
extern u8 sWihDwcAssertArg;
extern u8 sWihDwcFile[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *GFL_NET_AllocAligned(u32 heap, u32 a, const char *file, unsigned short line);

void WIH_DWC_CreateFilterBuffer(u32 heap)
{
    if (gWihDwc.f4 != 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    gWihDwc.f4 = GFL_NET_AllocAligned(heap, 0xA00, (const char *)sWihDwcFile, 0x1C0);
}
