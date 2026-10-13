/*
 * function: FRAME_LIST_LoadPalettes
 * address: 0x021B7A4C
 * packet: pkt_ov067_021B7A4C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B7A62.
 * symbols:
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 */
#include "../include/Obj20621.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct CodeIn;
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *, u8 *, u32, u32, u32);
void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    BLINK_PALANM_LoadPalettes(*(struct CodeIn * *)&((struct Obj20621 *)p)->f30, a, b, c << 4, d << 4);
}
