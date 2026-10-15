/*
 * function: IRC_COMPATIBLE_MENU_InitWindow
 * address: 0x021B7D38
 * packet: pkt_ov102_021B7D38
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow c parameter places its reload immediately before the call.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj03230.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MI_CpuFill8(void *, int, int);
typedef unsigned int   u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
void IRC_COMPATIBLE_MENU_InitWindow(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap)
{
    int win;
    MI_CpuFill8(p, 0, 20);
    ((struct Obj03230 *)p)->f10 = g;
    ((struct Obj03230 *)p)->f0 = BMP_WIN_Create(a, b, c, d, e, f, h);
    ((struct Obj03230 *)p)->fC = (int)STRBUF_Create(255, heap);
    ((struct Obj03230 *)p)->f4 = ((struct Obj03230 *)p)->f0;
    p[8] = 0;
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03230 *)p)->f0)), ((struct Obj03230 *)p)->f10);
    win = ((struct Obj03230 *)p)->f0;
    BMP_WIN_TransferChars((struct Descriptor *)win);
    BMP_WIN_MakeScreen((struct Cfg *)win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)win));
}
