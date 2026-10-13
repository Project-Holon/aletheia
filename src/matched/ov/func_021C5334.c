/*
 * function: SHORTCUT_MENU_RunPrint
 * address:  0x021C5334
 * packet:   pkt_021C5334
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
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   SHORTCUT_MENU_FinishPrint  0x021C56F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18304.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int SHORTCUT_MENU_FinishPrint(int *a);

int SHORTCUT_MENU_RunPrint(u32 a)
{
PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj18304 *)((u8 *)(a)))->f6C));
return SHORTCUT_MENU_FinishPrint((int *)a);
}

