/*
 * unit: yes
 * function: PSEL_ShowTaskRes, PSEL_DeleteTaskRes, PSEL_UpdateTaskResWin
 * address: 0x021BB3BC
 * packet: pkt_ov223_021BB3BC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 * The lead's EXACT* ends at BB404; two complete 16-byte load/tail-call
 * followers cover the remaining extent. Parent cleared both starts.
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
struct Item { void *text; u16 color; unsigned value; };
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned APP_TASKMENU_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u16);
extern void STRBUF_Delete(struct U16Vec *);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern void APP_TASKMENU_WIN_Update(u8 *);
void PSEL_ShowTaskRes(char *p)
{
    struct Item item;
    item.text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, 21);
    item.color = 0x39E3;
    item.value = 0;
    *(unsigned *)&((struct Obj00084 *)p)->f260 = APP_TASKMENU_WIN_Create(*(unsigned *)&((struct Obj00084 *)p)->f25C, (unsigned)&item, 9, 21, 14, ((struct Obj00084 *)p)->f0);
    STRBUF_Delete(item.text);
}
void PSEL_DeleteTaskRes(char *p)
{
    APP_TASKMENU_WIN_Delete(*(u8 * *)&((struct Obj00084 *)p)->f260);
}
void PSEL_UpdateTaskResWin(char *p)
{
    APP_TASKMENU_WIN_Update(*(u8 * *)&((struct Obj00084 *)p)->f260);
}
