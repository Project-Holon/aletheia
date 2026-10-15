/*
 * function: BMP_MENU_DeleteYesNo
 * address:  0x0201FEF4
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENU_Delete  0x0201F9E8  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 */
#include "../include/Obj02993.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 func_020307B0(void *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 BMP_MENUWORK_Delete(void *p);
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
struct Obj;
extern void BMP_MENU_Delete(struct Obj *o, u8 *out);

void BMP_MENU_DeleteYesNo(u8 *o)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj02993 *)o)->f18));
    func_020307B0(((struct Obj02993 *)o)->f14);
    BMP_MENUWORK_DrawWindowBorder(((struct Obj02993 *)o)->f4, 0);
    GF_FONT_Delete(((struct Obj02993 *)o)->f1C);
    BMP_MENUWORK_Delete(((struct Obj02993 *)o)->f0);
    BMP_WIN_Delete(((struct Obj02993 *)o)->f4);
    BMP_MENU_Delete((struct Obj *)o, 0);
}
