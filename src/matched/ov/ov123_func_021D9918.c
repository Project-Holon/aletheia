/*
 * function: PDWACC_MESSAGE_DeleteNumberWindows
 * address: 0x021D9918
 * packet: pkt_ov123_021D9918
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
#include "../include/Obj03273.h"
typedef unsigned int   u32;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
void PDWACC_MESSAGE_DeleteNumberWindows(char *p)
{
    if (((struct Obj03273 *)p)->f40) {
        BMP_MENUWORK_DrawWindowBorder(((struct Obj03273 *)p)->f40,2);
        BMP_WIN_ClearScreen(((struct Obj03273 *)p)->f40);
        BMP_MENUWORK_DrawWindowBorder(((struct Obj03273 *)p)->f44,2);
        BMP_WIN_ClearScreen(((struct Obj03273 *)p)->f44);
        BMP_WIN_Delete(((struct Obj03273 *)p)->f40);
        BMP_WIN_Delete(((struct Obj03273 *)p)->f44);
        func_02041B6C(5);
        ((struct Obj03273 *)p)->f40=0;
        ((struct Obj03273 *)p)->f44=0;
    }
}
