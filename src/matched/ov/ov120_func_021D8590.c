/*
 * function: func_021D8590
 * address: 0x021D8590
 * packet: pkt_ov120_021D8590
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020355C4 0x020355C4 arm
 *   func_02045808 0x02045808 arm
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_02051B84 0x02051B84 arm
 *   d_021D8AF0 0x021D8AF0 data a4
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb  arm9
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 */
#include "../include/Obj02175.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void func_02045808(struct U16Vec *vec);
extern void func_021D7710(u8 *);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern const int d_021D8AF0[];
void func_021D8590(u8 *p, int a, int b)
{
    void *q = func_020457B0(100, ((struct Obj02175 *)p)->fC8);
    ((struct Obj02175 *)p)->fA8 = q;
    func_02045CAC(((struct Obj02175 *)p)->fC, 15, q);
    ((struct Obj02175 *)p)->fAC = 0x39e3;
    ((struct Obj02175 *)p)->fB0 = 0;
    ((struct Obj02175 *)p)->fC4 = APP_TASKMENU_WIN_CreateEx((u32)(((struct Obj02175 *)p)->fC0), (u32)(p + 0xa8), 10, 21, 12, 3, 0, 1, ((struct Obj02175 *)p)->fC8);
    if (!func_020355C4()) APP_TASKMENU_WIN_SetActive(((struct Obj02175 *)p)->fC4, 1);
    func_02045808(((struct Obj02175 *)p)->fA8);
    func_021D7710(p);
    ((struct Obj02175 *)p)->f8 = func_02051B84((u8 *)d_021D8AF0, a, b, ((struct Obj02175 *)p)->fC8);
}
