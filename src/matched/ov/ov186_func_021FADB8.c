/*
 * function: func_021FADB8
 * address: 0x021FADB8
 * packet: pkt_ov186_021FADB8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   memset 0x02082BCC arm
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB594 0x021FB594 thumb ov186
 *   func_021FB5B8 0x021FB5B8 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   func_021FB3BC 0x021FB3BC thumb ov186
 */
#include "../include/Obj00080.h"
typedef struct Placement { short x, y; unsigned short animation; unsigned char priority, attr; } Placement;
typedef struct Config { int words[3]; } Config;
extern void *memset(void *, int, unsigned);
extern void func_021FB548(char *p, short *x, short *y);
extern int func_021FB594(char *p);
extern unsigned func_021FB5B8(char *p);
extern void func_021FB494(char *p);
extern int BR_BTN_DATA_GetRowField(void *, int);
extern void BR_RES_GetSprite(void *, unsigned, void *);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void *func_021FB3BC(void *, void *, int, int, int, int, int, void *, unsigned short);
void func_021FADB8(char *ctx, int mode)
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
    func_021FB548(((struct Obj00080 *)ctx)->f8, &x, &y);
    priority = func_021FB594(((struct Obj00080 *)ctx)->f8);
    attr = func_021FB5B8(((struct Obj00080 *)ctx)->f8);
    func_021FB494(((struct Obj00080 *)ctx)->f8);
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
    ((struct Obj00080 *)ctx)->f8 = func_021FB3BC(&placement, ((struct Obj00080 *)ctx)->f40, 160, mode, ((struct Obj00080 *)ctx)->f38, ((struct Obj00080 *)ctx)->f3C, resource, &config, ((struct Obj00080 *)ctx)->f34);
}
