/*
 * function: FIELD_3DBG_DeleteBillboard
 * address:  0x021A15D4
 * packet:   pkt_021A15D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_3DBG_IsTextureLoaded  0x021A1780  thumb  ov021
 *   FIELD_3DBG_FreeTexture  0x021A1750  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern int FIELD_3DBG_FreeTexture(u32 a);
extern u32 FIELD_3DBG_IsTextureLoaded(u8 *p);

int FIELD_3DBG_DeleteBillboard(u32 a)
{
if (FIELD_3DBG_IsTextureLoaded((u8 *)(a + 32)) != 0) {
    FIELD_3DBG_FreeTexture((a + 32));
}
return func_020307B0(a);
}

