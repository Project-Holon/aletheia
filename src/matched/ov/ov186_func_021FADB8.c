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
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
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
extern int func_021FB7B0(void *, int);
extern void func_021FC124(void *, unsigned, void *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
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
    placement.animation = func_021FB7B0(((struct Obj00080 *)ctx)->fC, 4);
    placement.priority = priority;
    placement.attr = attr;
    func_021FC124(((struct Obj00080 *)ctx)->f30, ((struct Obj00080 *)ctx)->f28 + mode, &config);
    resource = func_021FC20C(((struct Obj00080 *)ctx)->f30);
    func_021FC214(*(char * *)&((struct Obj00080 *)ctx)->f30);
    func_021FB7B0(((struct Obj00080 *)ctx)->fC, 3);
    ((struct Obj00080 *)ctx)->f8 = func_021FB3BC(&placement, ((struct Obj00080 *)ctx)->f40, 160, mode, ((struct Obj00080 *)ctx)->f38, ((struct Obj00080 *)ctx)->f3C, resource, &config, ((struct Obj00080 *)ctx)->f34);
}
