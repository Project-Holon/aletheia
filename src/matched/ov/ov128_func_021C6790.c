/*
 * function: func_021C6790
 * address:  0x021C6790
 * packet:   pkt_021C6790
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020403F4  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020403F4(u32 i);
extern void BG_SYS_Delete(void);

void func_021C6790(u8 *a0)
{
    int i;
    for (i = 0; i < 5; i++)
        func_020403F4((u8)i);
    BG_SYS_Delete();
}
