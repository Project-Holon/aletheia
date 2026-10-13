/*
 * function: func_021F6114
 * address: 0x021F6114
 * packet: pkt_ov215_021F6114
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj02926.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
void func_021F6114(void *unused,char *p)
{
    if(((struct Obj02926 *)p)->f50) func_0201CE48(((struct Obj02926 *)p)->f50);
    if(((struct Obj02926 *)p)->f68) STRBUF_Delete(((struct Obj02926 *)p)->f68);
    TCBL_Destroy(((struct Obj02926 *)p)->f54);
    MSGDATA_Delete(((struct Obj02926 *)p)->f64);
    func_0203FB44(1,(u16)((struct Obj02926 *)p)->f60,(u16)(((struct Obj02926 *)p)->f60>>16));
    func_020452E8(((struct Obj02926 *)p)->f58);
    func_020452E8(((struct Obj02926 *)p)->f5C);
}
