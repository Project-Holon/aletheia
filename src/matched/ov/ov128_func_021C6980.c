/*
 * function: func_021C6980
 * address: 0x021C6980
 * packet: pkt_ov128_021C6980
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct WordSet;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
void func_021C6980(u8 *p)
{
    PRINTSYS_QUE_Clear(((struct Obj00725 *)p)->f34);
    PRINTSYS_QUE_Delete(((struct Obj00725 *)p)->f34);
    ((struct Obj00725 *)p)->f34=0;
    if (((struct Obj00725 *)p)->f2C) {
        PRINTSYS_PrintStreamDelete(((struct Obj00725 *)p)->f2C);
        ((struct Obj00725 *)p)->f2C=0;
    }
    TCBL_Destroy(((struct Obj00725 *)p)->f28);
    ((struct Obj00725 *)p)->f28=0;
    GF_FONT_Delete(((struct Obj00725 *)p)->f17C);
    MSGDATA_Delete(((struct Obj00725 *)p)->f4);
    WORDSET_DeleteStrbufED04(((struct Obj00725 *)p)->f0);
}
