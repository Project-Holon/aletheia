/*
 * function: POKETRADE_PROC_InitDisplay
 * address: 0x021DC458
 * packet: pkt_ov119_021DC458
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   POKETRADE_2D_InitDisplayAndClact 0x021E53F8 thumb ov119
 *   POKETRADE_2D_SetupMainBgs 0x021E5430 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 */
#include "../include/Obj22734.h"
typedef unsigned short u16;
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(unsigned short);
extern void POKETRADE_2D_InitDisplayAndClact(char *p);
extern void POKETRADE_2D_SetupMainBgs(void *);
extern void POKETRADE_2D_SetupSubBgs(char *p);
void POKETRADE_PROC_InitDisplay(char *p)
{
    func_0203F8F4(0x91);
    BMP_WIN_Init(((struct Obj22734 *)p)->f5F4);
    POKETRADE_2D_InitDisplayAndClact(p);
    POKETRADE_2D_SetupMainBgs(p);
    POKETRADE_2D_SetupSubBgs(p);
}
