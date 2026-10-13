/*
 * function: func_021BA018
 * address: 0x021BA018
 * packet: pkt_ov214_021BA018
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Both packed halves of +74 are narrowed to u16 at 021BA03A..42;
 * the caller extern follows those truncations despite the callee's u32s.
 * extent-tail: 021BA056 alignment padding (two zero bytes).
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj00636.h"
typedef unsigned short u16;
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
void func_021BA018(int unused,char*p)
{
    if(*(void* *)&((struct Obj00636 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj00636 *)p)->f5C);
    if(*(void* *)&((struct Obj00636 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj00636 *)p)->f78);
    TCBL_Destroy(*(void* *)&((struct Obj00636 *)p)->f68);
    func_0203FB44(1,(u16)(((struct Obj00636 *)p)->f74),(u16)(((struct Obj00636 *)p)->f74>>16));
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f6C);
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f70);
}
