/*
 * function: func_021C4A48
 * address: 0x021C4A48
 * packet: pkt_ov208_021C4A48
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10908.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys; struct Descriptor; struct U16Vec; struct Rec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);
void func_021C4A48(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+0x568)=0;
        PRINTSYS_QUE_Clear(*(struct PrintSys **)(p+i*4+0x57c));
        BMP_WIN_Delete(*(struct Descriptor **)(p+i*4+0x554));
    }
    for(i=0;i<6;i++)STRBUF_Delete(*(struct U16Vec **)(p+i*4+0x59c));
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj10908 *)p)->f590);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj10908 *)p)->f598);
    func_020307B0(((struct Obj10908 *)p)->f594);
}
