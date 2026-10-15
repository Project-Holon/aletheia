/*
 * function: BR_BTN_SetMode
 * address: 0x021FADB8
 * packet: pkt_ov186_021FADB8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   memset 0x02082BCC arm
 *   BR_BTN_GetObjectPos 0x021FB548 thumb ov186
 *   BR_BTN_GetObjectDrawPriority 0x021FB594 thumb ov186
 *   BR_BTN_GetObjectBgPriority 0x021FB5B8 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_BTN_CreateObject 0x021FB3BC thumb ov186
 */
#include "../include/Obj00080.h"
typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;
typedef struct Config { int words[3]; } Config;
extern void *memset(void *, int, unsigned);
extern void BR_BTN_GetObjectPos(char *p, short *x, short *y);
extern int BR_BTN_GetObjectDrawPriority(char *p);
extern unsigned BR_BTN_GetObjectBgPriority(char *p);
extern void BR_BTN_DeleteObject(char *p);
extern int BR_BTN_DATA_GetRowField(void *, int);
extern void BR_RES_GetSprite(void *, unsigned, void *);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void *BR_BTN_CreateObject(void *, void *, int, int, int, int, int, void *, unsigned short);
void BR_BTN_SetMode(char *ctx, int mode)
{
    Config config;
    Placement placement;
    short x, y;
    int priority;
    int attr;
    int shift;
    unsigned resource;
    if (((struct Obj00080 *)ctx)->f4 == mode) return;
    ((struct Obj00080 *)ctx)->f4 = mode;
    BR_BTN_GetObjectPos(((struct Obj00080 *)ctx)->f8, &x, &y);
    priority = BR_BTN_GetObjectDrawPriority(((struct Obj00080 *)ctx)->f8);
    attr = BR_BTN_GetObjectBgPriority(((struct Obj00080 *)ctx)->f8);
    BR_BTN_DeleteObject(((struct Obj00080 *)ctx)->f8);
    ((struct Obj00080 *)ctx)->f2C = 0;
    shift = mode == 0 ? 512 : -512;
    memset(&placement, 0, sizeof(placement));
    placement.x = x;
    placement.y = y + shift;
    placement.animation = BR_BTN_DATA_GetRowField(((struct Obj00080 *)ctx)->fC, 4);
    placement.priority = priority;
    placement.attr = attr;
    BR_RES_GetSprite(((struct Obj00080 *)ctx)->f30, ((struct Obj00080 *)ctx)->f28 + mode, &config);
    resource = BR_RES_GetFont(((struct Obj00080 *)ctx)->f30);
    BR_RES_GetMsgData(*(char * *)&((struct Obj00080 *)ctx)->f30);
    BR_BTN_DATA_GetRowField(((struct Obj00080 *)ctx)->fC, 3);
    ((struct Obj00080 *)ctx)->f8 = BR_BTN_CreateObject(&placement, ((struct Obj00080 *)ctx)->f40, 160, mode, ((struct Obj00080 *)ctx)->f38, ((struct Obj00080 *)ctx)->f3C, resource, &config, ((struct Obj00080 *)ctx)->f34);
}
