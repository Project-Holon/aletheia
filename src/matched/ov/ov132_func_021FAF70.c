/*
 * function: func_021FAF70
 * address: 0x021FAF70
 * packet: pkt_ov132_021FAF70
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB0DC 0x021FB0DC thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
#include "../include/Obj03289.h"
#include "../include/Obj10544.h"
#include "../include/Obj10545.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_021F9DFC(void *);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB0DC(void *unused, char *p);
int func_021FAF70(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct Obj10544 *)ctx)->f0;
    wait = func_0201134C(((struct Obj10544 *)ctx)->f4);
    p = func_02030734(((struct Obj10545 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1a4);
    *(char * *)&((struct Obj03289 *)p)->f10 = owner;
    ((struct Obj03289 *)p)->f0 = ((struct Obj10545 *)owner)->f34;
    ((struct Obj03289 *)p)->fE = 0;
    ((struct Obj03289 *)p)->f4 = func_021F9DFC(((struct Obj10545 *)owner)->f34);
    ((struct Obj03289 *)p)->f8 = 224;
    delta = 224 - ((struct Obj03289 *)p)->f4;
    if (delta < 0) delta = -delta;
    ((struct Obj03289 *)p)->fC = delta / 2;
    ((struct Obj03289 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    if (wait == 1) {
        ((struct Obj10544 *)ctx)->f14 = ((struct Obj03289 *)p)->fC;
        return 1;
    }
    return 0;
}
