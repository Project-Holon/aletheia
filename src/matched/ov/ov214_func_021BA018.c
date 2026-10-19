/*
 * function: BTL_REC_SEL_DeleteWindows
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
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00636.h"
typedef unsigned short u16;
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void BTL_REC_SEL_DeleteWindows(int unused,char*p)
{
    if(*(void* *)&((struct Obj00636 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj00636 *)p)->f5C);
    if(*(void* *)&((struct Obj00636 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj00636 *)p)->f78);
    TCBL_Destroy(*(void* *)&((struct Obj00636 *)p)->f68);
    BG_SYS_FreeTileRun(1,(u16)(((struct Obj00636 *)p)->f74),(u16)(((struct Obj00636 *)p)->f74>>16));
    BMP_WIN_Delete(*(void* *)&((struct Obj00636 *)p)->f6C);
    BMP_WIN_Delete(*(void* *)&((struct Obj00636 *)p)->f70);
}
