/*
 * function: WEATHER_LoadOverlay
 * address:  0x021A1BF8
 * packet:   pkt_021A1BF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word at +0x28, then tail calls on it.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern int func_02034AC4(s32 handle);

void WEATHER_LoadOverlay(u32 *p, u32 v)
{
    p[0xa] = v;
    func_02034AC4(v);
}
