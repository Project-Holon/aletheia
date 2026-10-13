/*
 * unit: yes
 * function: func_021BB450, func_021BB4D8, func_021BB4E8, func_021BB4F8
 * address: 0x021BB450
 * packet: pkt_ov223_021BB450
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 * Lead EXACT* ends at BB4D8; three 16-byte load/tail-call followers
 * complete the extent. Parent cleared these starts. The value local
 * assigns zero then conditionally one; a boolean expression reverses
 * the compare polarity. Template precedes items in declaration order.
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
typedef struct Obj Obj;
struct Item { void *text; u16 color; unsigned value; };
struct TaskMenuTmpl {
    unsigned heapId;
    u8 count;
    u8 pad05[3];
    const void *unk08;
    unsigned unk0c;
    u8 pad10[2];
    u8 unk12;
    u8 unk13;
};
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *, void *);
extern void STRBUF_Delete(struct U16Vec *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
extern void APP_TASKMENU_UpdateMenu(Obj *);
extern unsigned APP_TASKMENU_IsFinish(struct TaskMenu *);
void func_021BB450(char *p)
{
    struct TaskMenuTmpl tmpl;
    struct Item items[2];
    unsigned i;
    for (i = 0; i < 2; i++) {
        unsigned value;
        items[i].text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, i + 22);
        items[i].color = 0x39E3;
        value = 0;
        if (i != 0)
            value = 1;
        items[i].value = value;
    }
    tmpl.heapId = ((struct Obj00084 *)p)->f0;
    tmpl.count = 2;
    tmpl.unk0c = 1;
    tmpl.pad10[0] = 32;
    tmpl.pad10[1] = 17;
    tmpl.unk12 = 9;
    tmpl.unk13 = 3;
    tmpl.unk08 = items;
    *(struct TaskMenu * *)&((struct Obj00084 *)p)->f264 = APP_TASKMENU_OpenMenu(&tmpl, ((struct Obj00084 *)p)->f25C);
    for (i = 0; i < 2; i++)
        STRBUF_Delete(items[i].text);
}
void func_021BB4D8(char *p)
{
    APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj00084 *)p)->f264);
}
void func_021BB4E8(char *p)
{
    APP_TASKMENU_UpdateMenu(*(Obj * *)&((struct Obj00084 *)p)->f264);
}
unsigned func_021BB4F8(char *p)
{
    return APP_TASKMENU_IsFinish(*(struct TaskMenu * *)&((struct Obj00084 *)p)->f264);
}
