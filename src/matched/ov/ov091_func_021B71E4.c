/*
 * function: POKELIST_CreateFonts
 * address:  0x021B71E4
 * packet:   pkt_ov091_021B71E4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 */
#include "../include/Obj02767.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct MsgBank;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern void GF_FONT_SetDefaultTextColor(void);

void POKELIST_CreateFonts(char *p)
{
    ((struct Obj02767 *)p)->f138 = GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f13C = GF_FONT_Create(0x17, 3, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f134 = func_02045B38(0, 2, 0x9d, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f140 = PRINTSYS_QUE_CreateEx(0x1800, ((struct Obj02767 *)p)->f0);
    GF_FONT_SetDefaultTextColor();
}
