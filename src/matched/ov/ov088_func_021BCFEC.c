/*
 * function: STARTMENU_SaveEraseAllocResources
 * address:  0x021BCFEC
 * packet:   pkt_ov088_021BCFEC
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   func_020461E4  0x020461E4  arm
 *   func_020461D4  0x020461D4  arm
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 */
#include "../include/Obj04350.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_020461E4(void);
extern void func_020461D4(u8);
struct GfFont;
struct MsgBank;
struct Tcbl;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);

void STARTMENU_SaveEraseAllocResources(u8 *p)
{
    p[0xc] = func_020461E4();
    func_020461D4(0);
    ((struct Obj04350 *)p)->f8 = func_02045B38(0, 2, 1, 0x81);
    ((struct Obj04350 *)p)->f4 = GF_FONT_Create(0x17, 0, 0, 0, 0x81);
    ((struct Obj04350 *)p)->f10 = STRBUF_Create(0x400, 0x81);
    ((struct Obj04350 *)p)->f18 = TCBL_Create(0x81, 0x81, 1, 4);
    ((struct Obj04350 *)p)->f24 = func_02028590(0xf, 1, 0, 0x81);
}
