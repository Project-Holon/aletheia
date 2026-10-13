/*
 * function: PLIST_MENU_CreateButtonWindow
 * address:  0x021BBDEC
 * packet:   pkt_ov091_021BBDEC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj00009.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    short b;
    int flag;
} S;

typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void STRBUF_Delete(struct U16Vec *vec);

int PLIST_MENU_CreateButtonWindow(int p, int unused, int id, int r3, u8 a4, int a5)
{
    S s;
    int r;
    s.a = (int)func_02045EC0((struct MsgBank *)(((struct Obj00009 *)p)->f134), id);
    s.b = 0x39e3;
    if (a5 == 0) {
        s.flag = 0;
    } else {
        s.flag = 1;
    }
    r = APP_TASKMENU_WIN_Create(((struct Obj00009 *)p)->f254, (u32)(&s), r3, a4, 10, ((struct Obj00009 *)p)->f0);
    STRBUF_Delete((struct U16Vec *)s.a);
    return r;
}
