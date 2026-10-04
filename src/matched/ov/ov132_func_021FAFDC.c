/*
 * function: func_021FAFDC
 * address: 0x021FAFDC
 * packet: pkt_ov132_021FAFDC
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
 *   func_021F96D0 0x021F96D0 thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
#include "../include/Obj02850.h"
#include "../include/Obj08158.h"
#include "../include/Obj10546.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
extern int func_0201134C(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u16 func_021F9DFC(void *);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB0DC(void *unused, char *p);
extern void func_021F96D0(char *p);
int func_021FAFDC(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct Obj10546 *)ctx)->f0;
    wait = func_0201134C(((struct Obj10546 *)ctx)->f4);
    p = func_02030734(((struct Obj08158 *)owner)->f0, 0x18, 0, d_021FDD00, 0x1c1);
    *(char * *)&((struct Obj02850 *)p)->f10 = owner;
    ((struct Obj02850 *)p)->f0 = ((struct Obj08158 *)owner)->f34;
    ((struct Obj02850 *)p)->fE = 0;
    ((struct Obj02850 *)p)->f4 = func_021F9DFC(((struct Obj08158 *)owner)->f34);
    ((struct Obj02850 *)p)->f8 = 0;
    delta = ((struct Obj02850 *)p)->f8 - ((struct Obj02850 *)p)->f4;
    if (delta < 0) delta = -delta;
    ((struct Obj02850 *)p)->fC = delta / 2;
    ((struct Obj02850 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    func_021F96D0(((struct Obj08158 *)owner)->f34);
    if (wait == 1) {
        ((struct Obj10546 *)ctx)->f14 = ((struct Obj02850 *)p)->fC;
        return 1;
    }
    return 0;
}
