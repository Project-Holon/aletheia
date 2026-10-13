/*
 * function: func_021BAC24
 * address: 0x021BAC24
 * packet: pkt_ov099_021BAC24
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_MENULIST_ResetCursorTile 0x02020CF8 thumb
 *   func_02041B6C 0x02041B6C arm
 * prototype-evidence: visibly supplied fifth F878 and second 20CF8 inputs
 *   are retained despite legacy bodies not reading them; caller truncations
 *   fix 450F0 x/y/width/height and F73C tile parameters as u8/u16.
 */
#include "../include/Obj00976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; } Pair;
typedef struct { u32 w[13]; } Desc;
struct PrintSys;
struct Slot;
struct Cfg;
struct Obj;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void GF_FONT_SetDefaultTextColor(void);
extern struct Slot *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *, u32, u32, u32, u32);
extern int func_021BA8BC(void *);
struct Src;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BMP_MENULIST_ResetCursorTile(struct Obj *p, int heap);
extern void func_02041B6C(u32);
void func_021BAC24(char *p, Desc *out, Pair *items, int count, int kind, u32 width)
{
    int i;
    int y;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
    GF_FONT_SetDefaultTextColor();
    *(struct Slot * *)&((struct Obj00976 *)p)->fB8 = BMP_MENUWORK_Create(count, 0x21);
    for (i = 0; i < count; i++)
        BMP_MENUWORK_AddMsgItem(*(struct Slot * *)&((struct Obj00976 *)p)->fB8, ((struct Obj00976 *)p)->fE0, items[i].a, items[i].b, 0x21);
    *(int *)&((struct Obj00976 *)p)->f1A4 = func_021BA8BC(((struct Obj00976 *)p)->f1A4);
    y = 5;
    if (kind == 5)
        y = 13;
    *(u32 *)&((struct Obj00976 *)p)->f1A4 = BMP_WIN_Create(2, (u8)(31 - width), (u8)y, (u8)width, (u32)count * 2, 15, 1);
    BMP_WIN_MakeScreen(*(struct Cfg * *)&((struct Obj00976 *)p)->f1A4);
    func_0201F73C(((struct Obj00976 *)p)->f1A4, 2, (u16)(((struct Obj00976 *)p)->f1330), 14);
    out->w[0] = *(u32 *)&((struct Obj00976 *)p)->fB8;
    out->w[3] = *(u32 *)&((struct Obj00976 *)p)->f1A4;
    out->w[11] = *(u32 *)&((struct Obj00976 *)p)->f1B4;
    out->w[10] = (u32)(p + 0x1ac);
    out->w[12] = ((struct Obj00976 *)p)->fE8;
    out->w[7] = (u32)p;
    *(struct Obj * *)&((struct Obj00976 *)p)->fBC = BMP_MENULIST_Create((struct Src *)out, 0, *(u16 *)(p + 0x234 + kind * 2), 0x21);
    if (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0) {
        do {
            PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
        } while (PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0);
    }
    BMP_MENULIST_ResetCursorTile(*(struct Obj * *)&((struct Obj00976 *)p)->fBC, 0x21);
    func_02041B6C(2);
}
