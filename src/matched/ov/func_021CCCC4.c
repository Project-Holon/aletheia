/*
 * function: PARTY_SELECT_LIST_FreeStatusIconResources
 * address:  0x021CCCC4
 * packet:   pkt_021CCCC4
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
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void CLACT_ReleaseCharacter(u32 i);
extern u32 CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32 i);

int PARTY_SELECT_LIST_FreeStatusIconResources(u32 a)
{
CLACT_ReleaseCharacter(*(u16 *)((u8 *)((a + 156))));
CLACT_ReleaseCellAnim(*(u16 *)((u8 *)((a + 154))));
return CLACT_ReleasePalette(*(u16 *)((u8 *)((a + 152))));
}

