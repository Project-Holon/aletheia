/*
 * function: func_021BD280
 * address: 0x021BD280
 * packet: pkt_ov209_021BD280
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   func_021BC730 0x021BC730 thumb ov209
 */
#include "../include/Obj00088.h"
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, unsigned, unsigned, unsigned);
typedef unsigned char  u8;
extern void func_021BC730(char *p, u8 a, u8 b);
void func_021BD280(char *p)
{
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 3, 0, 512);
    func_021BC730(p, 16, 16);
}
