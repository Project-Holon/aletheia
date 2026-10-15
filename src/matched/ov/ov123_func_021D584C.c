/*
 * function: GSYNC_MESSAGE_ClearStream
 * address: 0x021D584C
 * packet: pkt_ov123_021D584C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
#include "../include/Obj03265.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Rec3;
extern void TIME_ICON_Delete(u8 *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
void GSYNC_MESSAGE_ClearStream(char *p)
{
    if (((struct Obj03265 *)p)->f7C) {
        TIME_ICON_Delete(((struct Obj03265 *)p)->f7C);
        ((struct Obj03265 *)p)->f7C=0;
    }
    if (((struct Obj03265 *)p)->f80) {
        PRINTSYS_PrintStreamDelete(((struct Obj03265 *)p)->f80);
        ((struct Obj03265 *)p)->f80=0;
    }
    if (((struct Obj03265 *)p)->f44) {
        BMP_MENUWORK_DrawWindowBorder(((struct Obj03265 *)p)->f44,2);
        BMP_WIN_ClearScreen(((struct Obj03265 *)p)->f44);
        func_02041B6C(5);
    }
}
