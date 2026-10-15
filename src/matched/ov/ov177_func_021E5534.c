/*
 * function: WIFIBATTLEMATCH_GRAPHIC_Draw
 * address:  0x021E5534
 * packet:   pkt_ov177_021E5534
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_DrawClact  0x021E5668  thumb  ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Noop  0x021E5600  thumb  ov177
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void WIFIBATTLEMATCH_GRAPHIC_DrawClact(void *p);
extern void WIFIBATTLEMATCH_GRAPHIC_Noop(void *p);

void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p)
{
    WIFIBATTLEMATCH_GRAPHIC_DrawClact(p + 4);
    WIFIBATTLEMATCH_GRAPHIC_Noop(p);
}
