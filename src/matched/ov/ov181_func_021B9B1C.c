/*
 * function: func_021B9B1C
 * address: 0x021B9B1C
 * packet: pkt_ov181_021B9B1C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B9B6A, then the next function.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 */
#include "../include/Obj03327.h"
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
void func_021B9B1C(char *p)
{
    ((struct Obj03327 *)p)->fB0 = func_02045B38(0, 2, 0xB1, 0x8E);
    ((struct Obj03327 *)p)->fB4 = STRBUF_Create(0x80, 0x8E);
    ((struct Obj03327 *)p)->fA8 = GF_FONT_Create(0x17, 0, 1, 0, 0x8E);
    ((struct Obj03327 *)p)->fAC = GF_FONT_Create(0x17, 2, 1, 0, 0x8E);
}
