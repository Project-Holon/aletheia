/*
 * function: IRCBATTLEMENU_OpenYesNoMenu
 * address:  0x02197534
 * packet:   pkt_ov021_02197534
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_SetDisableKey  0x02027CD8  thumb
 *   STRBUF_Delete  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 w; u16 h; u16 pad; u32 z; } Ent;
typedef struct Obj {
    u8 pad0[0x10];
    u16 x10;
    u8 pad12[0x16];
    u32 x28;
    u8 pad2c[0x294];
    u32 x2c0;
    Ent e[2];
    u32 x2dc;
} Obj;
typedef struct {
    u32 x0;
    u8 x4;
    Ent *x8;
    u32 xc;
    u8 x10;
    u8 x11;
    u8 x12;
    u8 x13;
} Desc;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
extern void STRBUF_Delete(struct U16Vec *vec);

void IRCBATTLEMENU_OpenYesNoMenu(Obj *a)
{
    Desc d;

    d.x0 = a->x10;
    d.x4 = 2;
    d.x8 = a->e;
    d.xc = 1;
    d.x10 = 0x20;
    d.x11 = 0xE;
    d.x12 = 0xD;
    d.x13 = 3;
    a->e[0].w = (u32)STRBUF_Create(100, a->x10);
    MSGDATA_ReadString((struct MsgBank *)a->x28, 26, (void *)a->e[0].w);
    a->e[0].h = 0x39E3;
    a->e[1].w = (u32)STRBUF_Create(100, a->x10);
    MSGDATA_ReadString((struct MsgBank *)a->x28, 27, (void *)a->e[1].w);
    a->e[1].h = 0x39E3;
    a->e[0].z = 0;
    a->e[1].z = 0;
    a->x2c0 = (u32)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&d), (void *)a->x2dc);
    APP_TASKMENU_SetDisableKey(a->x2c0, 1);
    STRBUF_Delete((struct U16Vec *)a->e[0].w);
    STRBUF_Delete((struct U16Vec *)a->e[1].w);
}
