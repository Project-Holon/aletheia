/*
 * function: GSYNC_MESSAGE_OpenYesNoMenu
 * address: 0x021D5890
 * packet: pkt_ov123_021D5890
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 */
#include "../include/Obj01734.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void STRBUF_Delete(struct U16Vec *vec);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
int GSYNC_MESSAGE_OpenYesNoMenu(char *p,int mode)
{
    Config c;
    int result;
    c.size=((struct Obj01734 *)p)->fB0;
    c.flag=2;
    c.target=p+0x8c;
    switch (mode) {
    case 0: c.x=32; c.y=12; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    ((struct Obj01734 *)p)->f8C=STRBUF_Create(100,((struct Obj01734 *)p)->fB0);
    MSGDATA_ReadString(((struct Obj01734 *)p)->f20,4,((struct Obj01734 *)p)->f8C);
    ((struct Obj01734 *)p)->f90=0x39e0;
    ((struct Obj01734 *)p)->f98=STRBUF_Create(100,((struct Obj01734 *)p)->fB0);
    MSGDATA_ReadString(((struct Obj01734 *)p)->f20,5,((struct Obj01734 *)p)->f98);
    ((struct Obj01734 *)p)->f9C=0x39e0;
    result=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&c),((struct Obj01734 *)p)->fA4);
    STRBUF_Delete(((struct Obj01734 *)p)->f8C);
    STRBUF_Delete(((struct Obj01734 *)p)->f98);
    G2x_SetBlendBrightness_(0x04001050,9,-8);
    return result;
}
