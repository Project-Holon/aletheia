/*
 * function: MONOLITH_TOOL_LIST_ShowMessage
 * address:  0x021B9798
 * packet:   pkt_ov071_021B9798
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021BABFC     0x021BABFC  data  a4
 */
#include "../include/Obj00044.h"
#include "../include/Obj09896.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BABFC[];
struct Cfg;
struct MsgBank;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GF_FONT_SetTextColor(u32 a, u32 b, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *a0, u32 a1, u32 a2, void *a3, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);

void MONOLITH_TOOL_LIST_ShowMessage(char *a, char *b, u32 c)
{
    if (((struct Obj00044 *)a)->f294 != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    GF_FONT_SetTextColor(1, 2, 0xf);
    ((struct Obj00044 *)a)->f290 = func_02045EC0(((struct Obj09896 *)b)->f28, c);
    ((struct Obj00044 *)a)->f294 = PRINTSYS_PrintStream(((struct Obj00044 *)a)->f280, 0, 0, ((struct Obj00044 *)a)->f290, ((struct Obj09896 *)b)->fC, MSG_SPEED_GetWait(), ((struct Obj09896 *)b)->f18, 0xa, 0x61, 0xf);
    BMP_WIN_MakeScreen(((struct Obj00044 *)a)->f280);
    func_0201F73C(((struct Obj00044 *)a)->f280, 1, 1, 0xb);
}
