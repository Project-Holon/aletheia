/*
 * function: func_021B7EB0
 * address: 0x021B7EB0
 * packet: pkt_ov173_021B7EB0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: padding at 0x021B7F4E; separate follower func_021B7F50 at 0x021B7F50.
 * symbols:
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02026124 0x02026124 thumb
 *   func_0202614C 0x0202614C thumb
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 APP_TASKMENU_WIN_Create(u32, u32, u32, u32, u8, u16);
struct Sound;
extern void func_02028148(u8 *p);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_0202614C(struct Sound *obj, u32 idx);
extern void func_020409B4(u32);
void func_021B7EB0(char *p, int flag)
{
    if (flag == 1) {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 == 0) {
            *(u32 *)&((struct Obj00362 *)p)->f220 = APP_TASKMENU_WIN_Create(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1e4), 13, 21, 9, 0x4f);
            *(u32 *)&((struct Obj00362 *)p)->f224 = APP_TASKMENU_WIN_Create(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1f0), 22, 21, 9, 0x4f);
            func_0202614C(((struct Obj00362 *)p)->f1C8, 8);
            ((struct Obj00362 *)p)->f1CE = 1;
            return;
        }
    } else {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 != 0) {
            func_02028148(((struct Obj00362 *)p)->f220);
            func_02028148(((struct Obj00362 *)p)->f224);
            func_020409B4(4);
            *(u32 *)&((struct Obj00362 *)p)->f220 = 0;
            *(u32 *)&((struct Obj00362 *)p)->f224 = 0;
        }
        func_02026124(((struct Obj00362 *)p)->f1C8, 8);
        ((struct Obj00362 *)p)->f1CE = 0;
    }
}
