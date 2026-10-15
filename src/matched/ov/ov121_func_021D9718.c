/*
 * function: MYSTERY_GRAPHIC_Draw
 * address:  0x021D9718
 * packet:   pkt_021D9718
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_GRAPHIC_DrawClact  0x021D98E0  thumb
 *   MYSTERY_GRAPHIC_Dummy  0x021D9860  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MYSTERY_GRAPHIC_DrawClact(void *);
extern void MYSTERY_GRAPHIC_Dummy(void *);

void MYSTERY_GRAPHIC_Draw(u8 *p)
{
    MYSTERY_GRAPHIC_DrawClact(p + 4);
    MYSTERY_GRAPHIC_Dummy(p);
}
