/*
 * function: FIELDMAP_ExitBgSystem
 * address:  0x02188E38
 * packet:   pkt_02188E38
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
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   func_0203F9B4  0x0203F9B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0203F9B4(u32);
extern u32 BG_SYS_SetLcdSwap(u32, u32, u32, u32);
extern u32 G3D_SYSTEM_Exit(u32);
extern u32 NNS_G3dGeFlushBuffer(u32);

int FIELDMAP_ExitBgSystem(u32 a, u32 b, u32 c, u32 d)
{
return func_0203F9B4(G3D_SYSTEM_Exit(NNS_G3dGeFlushBuffer(BG_SYS_SetLcdSwap(1, b, c, d))));
}

