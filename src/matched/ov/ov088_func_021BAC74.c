/*
 * function: STARTMENU_CreateTextSystem
 * address:  0x021BAC74
 * packet:   pkt_ov088_021BAC74
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 */
#include "../include/Obj00014.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);

void STARTMENU_CreateTextSystem(char *p)
{
    *(u32 *)&((struct Obj00014 *)p)->f5C = (u32)func_02045B38(0, 2, 0xb3, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f58 = (u32)GF_FONT_Create(0x17, 0, 0, 0, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f60 = (u32)func_0201EC64(0xb);
    *(u32 *)&((struct Obj00014 *)p)->f68 = func_0201C440((void *)0xb);
    *(u32 *)&((struct Obj00014 *)p)->f64 = (u32)STRBUF_Create(0x400, 0xb);
    ((struct Obj00014 *)p)->f70 = (u32)TCBL_Create(0xb, 0xb, 1, 4);
    ((struct Obj00014 *)p)->f74 = func_02028590(0xf, 1, 0, 0xb);
}
