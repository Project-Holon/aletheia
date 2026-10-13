/*
 * function: SCRCMD_PROC_FLD_PrepareMessageWindow
 * address:  0x021B4878
 * packet:   pkt_021B4878
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
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F73C(u32, u32, u32, u32);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);

int SCRCMD_PROC_FLD_PrepareMessageWindow(u32 a)
{
BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)a)), 15);
return func_0201F73C(a, 0, 228, 9);
}

