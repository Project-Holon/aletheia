/*
 * function: FIELD_MSGBG_AddMenuItemStr
 * address:  0x02190A64
 * packet:   pkt_02190A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   BMP_MENUWORK_AddStrItem  0x0201F898  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 BMP_MENUWORK_AddStrItem(u32, u32, u32, u32);

int FIELD_MSGBG_AddMenuItemStr(u32 a, u32 b, u32 c, u32 d)
{
return BMP_MENUWORK_AddStrItem(a, b, c, d);
}

