/*
 * function: func_021DCEE4
 * address: 0x021DCEE4
 * packet: pkt_ov183_021DCEE4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00730.h"
#include "../include/Obj03329.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u16 x,y,n;u8 flag,pad;} Desc;
typedef struct {int a,b,c;} Triple;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_RES_LoadSprite(char *,u32,u32);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetSprite(void *,int,Triple *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern void *BR_UTIL_Create(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,u16);
extern void MI_CpuFill8(void *,int,u32);
void func_021DCEE4(char *p,char *q)
{
    int a,b;
    if(!((struct Obj00730 *)p)->fD8) {
        ((struct Obj00730 *)p)->fD8=1;
        BR_RES_LoadBgGraphics((void *)(*(int *)&((struct Obj03329 *)q)->f10),5,((struct Obj00730 *)p)->fB4);
        BR_RES_LoadSprite(*(char * *)&((struct Obj03329 *)q)->f10,6,((struct Obj00730 *)p)->fB4);
        a=BR_RES_GetFont(*(char * *)&((struct Obj03329 *)q)->f10);
        b=BR_RES_GetMsgData(*(char * *)&((struct Obj03329 *)q)->f10);
        if(((struct Obj00730 *)p)->fCC) {
            Desc d;
            Triple t;
            MI_CpuFill8(&d,0,8);
            d.x=24;d.y=168;d.n=0;d.flag=1;
            BR_RES_GetSprite(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=BR_BTN_CreateFromMessage(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
            d.x=136;d.n=3;
            ((struct Obj00730 *)p)->f20=BR_BTN_CreateFromMessage(&d,84,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        } else {
            Desc d;
            Triple t;
            MI_CpuFill8(&d,0,8);
            d.x=80;d.y=168;d.n=0;d.flag=1;
            BR_RES_GetSprite(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=BR_BTN_CreateFromMessage(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        }
        ((struct Obj00730 *)p)->f28=BR_UTIL_Create(4,8,3,16,2,14,((struct Obj00730 *)p)->f4,((struct Obj00730 *)p)->fB4);
        if(((struct Obj00730 *)p)->fB0) BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}
