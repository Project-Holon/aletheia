/*
 * function: ITEMMENU_InitWindows
 * address:  0x021B9BDC
 * packet:   pkt_ov070_021B9BDC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Create  0x020450F0  arm
 *   ITEMMENU_PrintMenuTitle  0x021B9BA0  thumb  ov070
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_PrintToWindow  0x021BB6E0  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_DrawMoveInfo  0x021B9850  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

typedef signed int     s32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void ITEMMENU_PrintMenuTitle(char *);
struct Cfg;
struct Descriptor;
struct MsgBank;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_PrintToWindow(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern u8 func_020355C4(void);
extern void ITEMMENU_DrawMoveInfo(char *);

void ITEMMENU_InitWindows(char *p)
{
    void *bg;

    ((struct Obj00002 *)p)->f774 = BMP_WIN_Create(3, 0x12, 9, 0xc, 3, 3, 1);
    ITEMMENU_PrintMenuTitle(p);
    BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj00002 *)p)->f774));
    ((struct Obj00002 *)p)->f754 = BMP_WIN_Create(3, 0x11, 0xd, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f76C = BMP_WIN_Create(3, 0x11, 0xf, 0xb, 2, 3, 1);
    ((struct Obj00002 *)p)->f734 = BMP_WIN_Create(6, 0, 0x13, 0x20, 5, 0, 1);
    ((struct Obj00002 *)p)->f73C = BMP_WIN_Create(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&((struct Obj00002 *)p)->f744 = BMP_WIN_Create(6, 0x14, 8, 6, 3, 0, 1);
    ((struct Obj00002 *)p)->f74C = BMP_WIN_Create(6, 2, 0xc, 0x1d, 7, 0, 1);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00002 *)p)->f73C));
    BMP_WIN_MakeScreen((struct Cfg *)(*(int *)&((struct Obj00002 *)p)->f744));
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00002 *)p)->f74C));
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00002 *)p)->f734));
    bg = func_020490F4(0x19, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f550 = CLACT_RegisterCellAnim(bg, 1, 0, ((struct Obj00002 *)p)->f544);
    ARC_TOOL_DeleteHandle(bg);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x66, (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 4, 0x3DC0);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5d, (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 8, 0x18, 0x3DC0);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5b, (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 4, 0x3DC0);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5c, (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0x70, 0x18, 0x3DC0);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x5a, (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_PrintToWindow((int)p, (u32 *)(p + 0x734), ((struct Obj00002 *)p)->f524, 0xd0, 4, 0x3DC0);
    if (func_020355C4() == 0) {
        ITEMMENU_DrawMoveInfo(p);
    }
}
