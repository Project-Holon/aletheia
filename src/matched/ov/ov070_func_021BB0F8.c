/*
 * function: ITEMMENU_OpenYesNoList
 * address:  0x021BB0F8
 * packet:   pkt_ov070_021BB0F8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern void ITEMMENU_UpdateSideButtons(int, int);

void ITEMMENU_OpenYesNoList(int p)
{
    Desc s;
    int h;
    int r;

    h = ((struct Obj00002 *)p)->f544;
    s.a = h;
    s.b = 2;
    s.c = p + 0x780;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = (int)STRBUF_Create(0x64, h);
    ((struct Obj00002 *)p)->f780 = r;
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x84, (void *)r);
    ((struct Obj00002 *)p)->f784 = 0x39E0;
    ((struct Obj00002 *)p)->f788 = 0;
    r = (int)STRBUF_Create(0x64, ((struct Obj00002 *)p)->f544);
    ((struct Obj00002 *)p)->f78C = r;
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x85, (void *)r);
    ((struct Obj00002 *)p)->f790 = 0x39E0;
    ((struct Obj00002 *)p)->f794 = 0;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00002 *)p)->f780));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00002 *)p)->f78C));
    ITEMMENU_SetBackButtonAnim((char *)p, 0);
    ITEMMENU_UpdateSideButtons(p, 0);
}
