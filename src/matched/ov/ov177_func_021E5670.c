/*
 * function: WIFIBATTLEMATCH_GRAPHIC_VBlankClact
 * address:  0x021E5670
 * packet:   pkt_ov177_021E5670
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void CLACT_VBlankSystem(void);

void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *a0)
{
    CLACT_VBlankSystem();
}
