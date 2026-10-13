/*
 * function: func_021B9A80
 * address: 0x021B9A80
 * packet: pkt_ov218_021B9A80
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02264.h"
struct Rec3;
struct Descriptor;
struct U16Vec;
struct Rec;
struct PrintSys;
struct S02031140;
struct WordSet;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021B9A80(char *p)
{
    if (*(struct Rec3 * *)&((struct Obj02264 *)p)->f20 != 0) {
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj02264 *)p)->f20);
        *(struct Rec3 * *)&((struct Obj02264 *)p)->f20 = 0;
    }
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj02264 *)p)->f28);
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj02264 *)p)->f24);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02264 *)p)->f18);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02264 *)p)->f1C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj02264 *)p)->f8);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj02264 *)p)->f10);
    GF_FONT_Delete(((struct Obj02264 *)p)->fC);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj02264 *)p)->f4);
    func_0201ED04(*(struct WordSet * *)&((struct Obj02264 *)p)->f14);
    func_020307B0(p);
}
