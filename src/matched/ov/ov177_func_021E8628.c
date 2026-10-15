/*
 * function: WIFIBATTLEMATCH_UTIL_Delete
 * address: 0x021E8628
 * packet: pkt_ov177_021E8628
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01960.h"
struct Descriptor;
struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TIME_ICON_Delete(unsigned char *p);
extern int APP_KEYCURSOR_Delete(int p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WIFIBATTLEMATCH_UTIL_Delete(char *p)
{
    if (((struct Obj01960 *)p)->f8 != 0) {
        PRINTSYS_PrintStreamDelete(((struct Obj01960 *)p)->f8);
        ((struct Obj01960 *)p)->f8 = 0;
    }
    if (*(unsigned char * *)&((struct Obj01960 *)p)->f10 != 0) {
        TIME_ICON_Delete(*(unsigned char * *)&((struct Obj01960 *)p)->f10);
        ((struct Obj01960 *)p)->f10 = 0;
    }
    if (((struct Obj01960 *)p)->f34 != 0)
        APP_KEYCURSOR_Delete(((struct Obj01960 *)p)->f34);
    TCBL_Destroy(((struct Obj01960 *)p)->fC);
    BMP_MENUWORK_DrawWindowBorder(((struct Obj01960 *)p)->f14, 0);
    BMP_WIN_Delete(((struct Obj01960 *)p)->f14);
    STRBUF_Delete(((struct Obj01960 *)p)->f18);
    PRINTSYS_QUE_Delete(((struct Obj01960 *)p)->f28);
    func_020307B0(p);
}
