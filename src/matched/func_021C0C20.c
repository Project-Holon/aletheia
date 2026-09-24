/*
 * function: func_021C0C20
 * address:  0x021C0C20
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clear the word at +4 of g_021CADE4 and set the word at +0 to 8.
 *
 * symbols:
 *   g_021CADE4  0x021CADE4  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 g_021CADE4[];

void func_021C0C20(void)
{
    g_021CADE4[1] = 0;
    g_021CADE4[0] = 8;
}
