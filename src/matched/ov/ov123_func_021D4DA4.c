/*
 * function: GSYNC_MENU_OpenYesNoMenu
 * address: 0x021D4DA4
 * packet: pkt_ov123_021D4DA4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00626.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
extern void STRBUF_Delete(struct U16Vec *vec);
void GSYNC_MENU_OpenYesNoMenu(char *p)
{
    Descriptor desc;
    desc.heap = ((struct Obj00626 *)p)->fC;
    desc.mode = 2;
    desc.data = p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    ((struct Obj00626 *)p)->f23C = STRBUF_Create(100, ((struct Obj00626 *)p)->fC);
    MSGDATA_ReadString(((struct Obj00626 *)p)->f24, 4, ((struct Obj00626 *)p)->f23C);
    ((struct Obj00626 *)p)->f240 = 0x39e0;
    ((struct Obj00626 *)p)->f248 = STRBUF_Create(100, ((struct Obj00626 *)p)->fC);
    MSGDATA_ReadString(((struct Obj00626 *)p)->f24, 5, ((struct Obj00626 *)p)->f248);
    ((struct Obj00626 *)p)->f24C = 0x39e0;
    ((struct Obj00626 *)p)->f238 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&desc), ((struct Obj00626 *)p)->f254);
    APP_TASKMENU_SetDisableKey((int)(((struct Obj00626 *)p)->f238), 1);
    STRBUF_Delete(((struct Obj00626 *)p)->f23C);
    STRBUF_Delete(((struct Obj00626 *)p)->f248);
}
