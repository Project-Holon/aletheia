/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_DeleteText
 * address:  0x0217AF9C
 * packet:   pkt_0217AF9C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8628  0x021E8628  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 */
#include "../include/Obj03869.h"
typedef unsigned int u32;

extern void func_021E8628(u32 a);
struct PrintSys;
struct Rec;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);

void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(int *p)
{
    func_021E8628(((struct Obj03869 *)p)->f8);
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03869 *)p)->f14));
    MSGDATA_Delete((struct Rec *)(((struct Obj03869 *)p)->f10));
    GF_FONT_Delete((void *)(((struct Obj03869 *)p)->fC));
}
