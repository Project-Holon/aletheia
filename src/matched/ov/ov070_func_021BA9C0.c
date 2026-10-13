/*
 * function: ITEMMENU_OpenPopupList
 * address:  0x021BA9C0
 * packet:   pkt_ov070_021BA9C0
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
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *
 * Levers: the object pointer must be a byte pointer (as an int the
 * loop-invariant p+0x544 is not hoisted into its own stack slot), and the
 * 12-byte record pointer e is formed before the allocation call.
 */
#include "../include/Obj00002.h"
#include "../include/Obj09881.h"

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
extern void ITEMMENU_UpdateSideButtons(int p, int mode);

void ITEMMENU_OpenPopupList(u8 *p, int *tbl, int n)
{
    Desc s;
    int i;
    int r;
    u8 *e;

    s.a = ((struct Obj00002 *)p)->f544;
    s.b = n;
    s.c = (int)(p + 0x780);
    s.d = 1;
    s.e = 0x20;
    s.f = 0x18;
    s.g = 0xD;
    s.h = 3;
    for (i = 0; i < n; i++) {
        e = p + i * 0xC;
        r = (int)STRBUF_Create(0x64, ((struct Obj00002 *)p)->f544);
        ((struct Obj09881 *)e)->f780 = r;
        MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), tbl[i], (void *)r);
        ((struct Obj09881 *)e)->f784 = 0x39E0;
        ((struct Obj09881 *)e)->f788 = 0;
    }
    *(int *)(p + (i - 1) * 0xC + 0x788) = 1;
    *(int *)&((struct Obj00002 *)p)->f77C = (int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj00002 *)p)->f7E0));
    for (i = 0; i < n; i++) {
        STRBUF_Delete((struct U16Vec *)(*(int *)(p + i * 0xC + 0x780)));
    }
    ITEMMENU_UpdateSideButtons((int)p, 0);
}
