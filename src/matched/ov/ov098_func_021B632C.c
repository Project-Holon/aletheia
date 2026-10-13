/*
 * function: PDC_MAIN_Delete
 * address: 0x021B632C
 * packet: pkt_ov098_021B632C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Destroy 0x02031140 arm
 *   PDC_MSG_Delete 0x021B68DC thumb ov098
 *   func_021F7808 0x021F7808 thumb ov094
 *   func_022021F4 0x022021F4 thumb ov094
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PDC_MAIN_ExitGraphics 0x021B6438 thumb ov098
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05258.h"
typedef unsigned char  u8;
struct Obj;
struct S02031140;
extern void TCBL_Destroy(struct S02031140 *p);
extern void PDC_MSG_Delete(u8 *p);
extern void func_021F7808(void);
extern void func_022021F4(struct Obj *p);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void PDC_MAIN_ExitGraphics(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void PDC_MAIN_Delete(unsigned p)
{
    TCBL_Destroy(((struct Obj05258 *)p)->f18);
    PDC_MSG_Delete(((struct Obj05258 *)p)->f14);
    func_021F7808();
    func_022021F4(((struct Obj05258 *)p)->f10);
    GF_FONT_Delete(((struct Obj05258 *)p)->f8);
    GF_FONT_Delete(((struct Obj05258 *)p)->fC);
    PDC_MAIN_ExitGraphics();
    func_020307B0(((struct Obj05258 *)p)->f70);
    func_020307B0((void *)p);
}
