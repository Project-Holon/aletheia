/*
 * function: IRCBATTLEMENU_VBlankTask
 * address:  0x021978D4
 * packet:   pkt_021978D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: tail call into the ARM9 image.
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CLACT_VBlankSystem(void);

void IRCBATTLEMENU_VBlankTask(void)
{
    CLACT_VBlankSystem();
}
