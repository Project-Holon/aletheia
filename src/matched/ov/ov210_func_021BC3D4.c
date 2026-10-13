/*
 * function: func_021BC3D4
 * address:  0x021BC3D4
 * packet:   pkt_ov210_021BC3D4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021C0754  0x021C0754  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 d_021C0754[];
extern void BG_SYS_ClearGraphicsMemory(u32 a);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);

void func_021BC3D4(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C0754);
}
