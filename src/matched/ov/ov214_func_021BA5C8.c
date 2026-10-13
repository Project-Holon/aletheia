/*
 * function: func_021BA5C8
 * address: 0x021BA5C8
 * packet: pkt_ov214_021BA5C8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_021BA4E8 0x021BA4E8 thumb ov214
 */
#include "../include/Obj02552.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void*,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
struct S;
extern void func_021BA4E8(void *unused, struct S *p);
void func_021BA5C8(void*obj,char*p)
{
    void*h;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,19);
    PRINTSYS_PrintQueColor(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f8C),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    STRBUF_Delete(h);
    ((struct Obj02552 *)p)->f9C=0;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,((struct Obj02552 *)p)->f2A4);
    PRINTSYS_PrintQueColor(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)func_02045770(*(void* *)&((struct Obj02552 *)p)->f90),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    STRBUF_Delete(h);
    ((struct Obj02552 *)p)->fA0=0;
    func_021BA4E8(obj,(struct S *)p);
}
