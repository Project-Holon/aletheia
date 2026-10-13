/*
 * function: func_021BB224
 * address:  0x021BB224
 * packet:   pkt_ov099_021BB224
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 */
#include "../include/Obj01706.h"

struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_021BB4D0(char *p);
extern void func_021BB42C(void *p);
extern int APP_KEYCURSOR_Delete(int a0);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

void func_021BB224(char *p)
{
    func_021BB4D0(p);
    func_021BB42C(p);
    APP_KEYCURSOR_Delete((int)(((struct Obj01706 *)p)->f9B0));
    STRBUF_Delete(((struct Obj01706 *)p)->fF8);
    STRBUF_Delete(((struct Obj01706 *)p)->fF4);
    STRBUF_Delete(((struct Obj01706 *)p)->fFC);
    if (((struct Obj01706 *)p)->f1BC != 0) {
        PRINTSYS_PrintStreamDelete(((struct Obj01706 *)p)->f1BC);
        ((struct Obj01706 *)p)->f1BC = 0;
    }
    STRBUF_Delete(((struct Obj01706 *)p)->fF0);
    TCBL_Destroy(((struct Obj01706 *)p)->f1C0);
    PRINTSYS_QUE_Clear(((struct Obj01706 *)p)->f1B8);
    PRINTSYS_QUE_Clear(((struct Obj01706 *)p)->f1B4);
    PRINTSYS_QUE_Delete(((struct Obj01706 *)p)->f1B8);
    PRINTSYS_QUE_Delete(((struct Obj01706 *)p)->f1B4);
    ((struct Obj01706 *)p)->f1B8 = 0;
}
