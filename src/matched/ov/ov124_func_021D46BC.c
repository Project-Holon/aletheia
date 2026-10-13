/*
 * function: func_021D46BC
 * address: 0x021D46BC
 * packet: pkt_ov124_021D46BC
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 text; u16 color; u16 pad; u32 flag; } Request;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern u8 func_0201F548(int);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Cfg;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *, int, int, int);
extern void func_020409B4(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32, u32, u32, u32, u8, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *);
void func_021D46BC(char *p)
{
    Request req;
    ((struct Obj00068 *)p)->f28 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    GF_FONT_SetTextColor(15, 2, 0);
    ((struct Obj00068 *)p)->f2C = func_02045B38(0, 2, 21, ((struct Obj00068 *)p)->f0);
    func_02049B40(23, 5, 4, 480, 32, ((struct Obj00068 *)p)->f0);
    func_0201F5BC(5, 1, 13, 0, ((struct Obj00068 *)p)->f0);
    func_02049B40(5, func_0201F548(0), 4, 416, 64, ((struct Obj00068 *)p)->f0);
    GF_FONT_SetDefaultTextColor();
    *(u32 *)&((struct Obj00068 *)p)->f30 = PRINTSYS_QUE_Create((void *)(u32)((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f34 = APP_TASKMENU_RES_Create(4, 11, *(u32 *)&((struct Obj00068 *)p)->f28, *(u32 *)&((struct Obj00068 *)p)->f30, ((struct Obj00068 *)p)->f0);
    *(u32 *)&((struct Obj00068 *)p)->f24 = BMP_WIN_Create(5, 2, 4, 28, 4, 15, 1);
    *(u32 *)&((struct Obj00068 *)p)->f20 = BMP_WIN_Create(5, 2, 9, 28, 12, 15, 1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f24), 1);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f24);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f24));
    func_0201F73C(((struct Obj00068 *)p)->f24, 1, 1, 14);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00068 *)p)->f20), 0);
    BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f20);
    BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f20));
    func_020409B4(5);
    func_020409B4(4);
    ((struct Obj00068 *)p)->f1C = 0;
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 24);
    req.color = 0x39e3;
    req.flag = 0;
    ((struct Obj00068 *)p)->f3C = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 11, 21, 11, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 26);
    *(u32 *)&((struct Obj00068 *)p)->f38 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 0, 21, 11, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 25);
    req.flag = 1;
    ((struct Obj00068 *)p)->f40 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 22, 21, 10, ((struct Obj00068 *)p)->f0);
    STRBUF_Delete((void *)req.text);
    APP_TASKMENU_WIN_ClearScreen(*(u8 * *)&((struct Obj00068 *)p)->f38);
    *(u16 *)0x050005e2 = 0;
}
