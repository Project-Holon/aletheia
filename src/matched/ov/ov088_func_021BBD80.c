/*
 * unit:     yes
 * function: STARTMENU_OpenInfoWindow, STARTMENU_CloseInfoWindow
 * address:  0x021BBD80
 * packet:   pkt_ov088_021BBD80
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021BBE3C is an unlabelled tail-call stub (function_starts seed).
 * Twin of STARTMENU_OpenConfirmWindow (same print_line inline).
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   STARTMENU_DrawFrameBox  0x021BBA64  thumb  ov088
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj06205.h"
#include "../include/Obj13235.h"
#include "../include/Obj20821.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void STARTMENU_DrawFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

static inline void print_line(char *p, u32 id, u32 y, u16 color)
{
    u32 s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06205 *)p)->f5C), id);
    u32 a = ((struct Obj06205 *)p)->f68;
    PRINTSYS_PrintQueColor((void *)a, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06205 *)p)->fF0), 0, y, s, ((struct Obj06205 *)p)->f58, color);
    ((struct Obj06205 *)p)->fF4 = 1;
    STRBUF_Delete((struct U16Vec *)s);
}

void STARTMENU_OpenInfoWindow(char *p)
{
    ((struct Obj13235 *)p)->fF0 = BMP_WIN_Create(4, 2, 3, 0x1e, 0x13, 5, 1);
    print_line(p, 0x14, 0, 0x14c0);
    print_line(p, 0x15, 0x18, 0x440);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj13235 *)p)->fF0));
    func_02041B6C(4);
    STARTMENU_DrawFrameBox(0, 1, 0x20, 0x16, 5);
}

void STARTMENU_CloseInfoWindow(char *p)
{
    BMP_WIN_Delete(((struct Obj20821 *)p)->fF0);
}
