/*
 * function: RESEARCH_TOP_ExitBackgrounds
 * address:  0x021B990C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_ExitBackgrounds  0x021B990C  thumb  ov217
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 BG_SYS_Delete();
extern void func_020403F4(u32 i);
u32 RESEARCH_TOP_ExitBackgrounds(void)
{
    func_020403F4(1);
    func_020403F4(4);
    return BG_SYS_Delete();
}

