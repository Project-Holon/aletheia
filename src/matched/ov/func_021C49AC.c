/*
 * function: FLDEFF_SPLASH_DeleteBoardRes
 * address:  0x021C49AC
 * packet:   pkt_021C49AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLDEFF_SPLASH_UnloadBoardImage  0x021C4A00  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_SPLASH_UnloadBoardImage(void *p);
extern u32 func_020307B0(void *p);

void FLDEFF_SPLASH_DeleteBoardRes(u32 a, u8 *p)
{
    FLDEFF_SPLASH_UnloadBoardImage(p);
    func_020307B0(p);
}
