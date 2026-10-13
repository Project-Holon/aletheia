/*
 * function: FLDEFF_SPLASH_DeleteModelRes
 * address:  0x021C4B50
 * packet:   pkt_021C4B50
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
 *   FLDEFF_SPLASH_UnloadModel  0x021C4BC4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_SPLASH_UnloadModel(void *p);
extern u32 func_020307B0(void *p);

void FLDEFF_SPLASH_DeleteModelRes(u32 a, u8 *p)
{
    FLDEFF_SPLASH_UnloadModel(p);
    func_020307B0(p);
}
