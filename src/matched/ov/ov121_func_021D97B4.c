/*
 * function: MYSTERY_GRAPHIC_VBlank
 * address:  0x021D97B4
 * packet:   pkt_021D97B4
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_GRAPHIC_UpdateBg  0x021D9864  thumb
 *   MYSTERY_GRAPHIC_VBlankClact  0x021D98E8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void MYSTERY_GRAPHIC_UpdateBg(void *);
extern void MYSTERY_GRAPHIC_VBlankClact(void *);

void MYSTERY_GRAPHIC_VBlank(void *a, u8 *q)
{
    MYSTERY_GRAPHIC_UpdateBg(q);
    MYSTERY_GRAPHIC_VBlankClact(q + 4);
}
