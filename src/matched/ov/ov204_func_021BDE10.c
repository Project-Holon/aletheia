/*
 * function: func_021BDE10
 * address:  0x021BDE10
 * packet:   pkt_021BDE10
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm  arm9
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern void BG_SYS_ResetSlot(u32, u32, u32);

void func_021BDE10(u8 *a0)
{
    if (BG_SYS_GetMainVisiblePlanes() & 4) {
        BG_SYS_ResetSlot(2, 1, 1);
    }
}

