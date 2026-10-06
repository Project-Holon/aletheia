/*
 * function: func_021BA254
 * address: 0x021BA254
 * packet: pkt_ov214_021BA254
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA2B6 alignment padding (two zero bytes).
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_021BA2B8 0x021BA2B8 thumb ov214
 */
#include "../include/Obj01082.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct Rec3;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 func_021BA2B8(int unused, u8 *p);
void func_021BA254(void*obj,char*p,unsigned entry)
{
    func_02043B5C(func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01082 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj01082 *)p)->f5C);
    *(int *)&((struct Obj01082 *)p)->f5C=0;
    if(*(void* *)&((struct Obj01082 *)p)->f78)func_02045808(*(void* *)&((struct Obj01082 *)p)->f78);
    *(void* *)&((struct Obj01082 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01082 *)p)->f58,entry);
    *(int *)&((struct Obj01082 *)p)->f7C=0;
    func_0201C6FC(*(void* *)&((struct Obj01082 *)p)->fC,(unsigned)func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),0,0,*(void* *)&((struct Obj01082 *)p)->f78,((struct Obj01082 *)p)->f8);
    func_021BA2B8((int)obj,(u8 *)p);
}
