/*
 * function: PMSIV_WORDWIN_Delete
 * address: 0x021BF8BC
 * packet: pkt_ov110_021BF8BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03755.h"
typedef unsigned char u8;
struct Obj;
struct U16Vec;
struct Descriptor;
typedef unsigned int   u32;
extern void CLACT_DeleteActor(struct Obj *);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
void PMSIV_WORDWIN_Delete(u8 *p) {
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f14) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03755 *)p)->f14);
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f1C) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj03755 *)p)->f1C);
    if(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48) STRBUF_Delete(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48);
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj03755 *)p)->f10);
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj03755 *)p)->fC);
    func_020307B0(p);
}
