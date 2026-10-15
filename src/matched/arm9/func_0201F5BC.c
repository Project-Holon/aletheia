/*
 * function: BMP_MENUWORK_LoadCharAndPltt
 * address:  0x0201F5BC
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards one five-argument call to two four-argument workers, dropping the
 * second argument from the first call and the third from the second.  The
 * fifth argument arrives on the caller's stack and is re-read with `ldrh`
 * through a cached frame pointer (r7 = sp + 0x18) both times, once per call,
 * which is what fixes it as u16 rather than a word.
 *
 * symbols:
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   BMP_MENUWORK_LoadPltt  0x0201F57C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_LoadCharAndPltt.c \
 *       --func BMP_MENUWORK_LoadCharAndPltt --addr 0x0201F5BC --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
extern void BMP_MENUWORK_LoadPltt(u32 a, u32 b, u32 c, u16 d);

void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    BMP_MENUWORK_LoadChar(a, b, d, e);
    BMP_MENUWORK_LoadPltt(a, c, d, e);
}
