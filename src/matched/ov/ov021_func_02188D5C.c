/*
 * function: FIELDMAP_InitBgSystem
 * address:  0x02188D5C
 * packet:   pkt_ov021_02188D5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Create  0x0203F8F4  arm
 *   func_02040E78  0x02040E78  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   sClearPalette     0x021D3620  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

extern u16 sClearPalette[];
extern void BG_SYS_Create(u16 heap);
extern void func_02040E78(u32 a, void *b, u32 c, u32 d);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);

void FIELDMAP_InitBgSystem(u16 *p)
{
    BG_SYS_Create(p[0]);
    func_02040E78(0, sClearPalette, 0x20, 0);
    func_02040E78(4, sClearPalette, 0x20, 0);
    BG_SYS_SetLcdSwap(1);
    BG_SYS_ResetSubDisplay();
    REG_DISPCNT &= ~0xE000;
}
