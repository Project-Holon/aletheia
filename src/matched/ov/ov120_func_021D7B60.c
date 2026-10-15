/*
 * function: GTSNEGO_MSG_OpenMenu
 * address: 0x021D7B60
 * packet: pkt_ov120_021D7B60
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 */
#include "../include/Obj02174.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void STRBUF_Delete(struct U16Vec *vec);
void *GTSNEGO_MSG_OpenMenu(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct Obj02174 *)p)->fC8;
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=STRBUF_Create(100,((struct Obj02174 *)p)->fC8);
    ((struct Obj02174 *)p)->fA8=text;
    MSGDATA_ReadString(((struct Obj02174 *)p)->fC,25,text);
    ((struct Obj02174 *)p)->fAC=0x39e0;
    text=STRBUF_Create(100,((struct Obj02174 *)p)->fC8);
    ((struct Obj02174 *)p)->fB4=text;
    MSGDATA_ReadString(((struct Obj02174 *)p)->fC,26,text);
    ((struct Obj02174 *)p)->fB8=0x39e0;
    result=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config),((struct Obj02174 *)p)->fC0);
    STRBUF_Delete(((struct Obj02174 *)p)->fA8);
    STRBUF_Delete(((struct Obj02174 *)p)->fB4);
    return result;
}
