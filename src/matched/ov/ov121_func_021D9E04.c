/*
 * function: MYSTERY_UTIL_DeleteMenuWindow
 * address: 0x021D9E04
 * packet: pkt_ov121_021D9E04
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
#include "../include/Obj02180.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TIME_ICON_Delete(u8 *);
extern int APP_KEYCURSOR_Delete(int a0);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *, u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
void MYSTERY_UTIL_DeleteMenuWindow(u8 *p)
{
    if (((struct Obj02180 *)p)->f8) {
        PRINTSYS_PrintStreamDelete(((struct Obj02180 *)p)->f8);
        ((struct Obj02180 *)p)->f8 = 0;
    }
    if (((struct Obj02180 *)p)->f3C) {
        TIME_ICON_Delete(((struct Obj02180 *)p)->f3C);
        ((struct Obj02180 *)p)->f3C = 0;
    }
    if (((struct Obj02180 *)p)->f30) APP_KEYCURSOR_Delete((int)(((struct Obj02180 *)p)->f30));
    TCBL_Destroy(((struct Obj02180 *)p)->fC);
    BMP_MENUWORK_DrawWindowBorder(((struct Obj02180 *)p)->f10, 0);
    BMP_WIN_Delete(((struct Obj02180 *)p)->f10);
    STRBUF_Delete(((struct Obj02180 *)p)->f14);
    func_020307B0(p);
}
