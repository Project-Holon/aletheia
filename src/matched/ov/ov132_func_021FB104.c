/*
 * function: func_021FB104
 * address: 0x021FB104
 * packet: pkt_ov132_021FB104
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9E08 0x021F9E08 thumb ov132
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB190 0x021FB190 thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
#include "../include/Obj03820.h"
#include "../include/Obj06491.h"
#include "../include/Obj08160.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
extern int func_0201134C(void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
typedef unsigned char  u8;
extern u16 func_021F9E04(u8 *p);
extern void func_021F9E08(u8 *p, u16 v);
extern void *func_021FADA0(char *, u32, u32, u32);
extern void func_021FB190(void *unused, char *p);
int func_021FB104(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct Obj06491 *)ctx)->f0;
    time = func_0201134C(((struct Obj06491 *)ctx)->f4);
    target = func_0201134C(((struct Obj06491 *)ctx)->f4);
    wait = func_0201134C(((struct Obj06491 *)ctx)->f4);
    if (time == 0) {
        func_021F9E08(((struct Obj08160 *)owner)->f34, target);
    } else {
        p = func_02030734(((struct Obj08160 *)owner)->f0, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct Obj03820 *)p)->f10 = owner;
        ((struct Obj03820 *)p)->f0 = ((struct Obj08160 *)owner)->f34;
        ((struct Obj03820 *)p)->fE = 0;
        ((struct Obj03820 *)p)->f4 = func_021F9E04(((struct Obj08160 *)owner)->f34);
        ((struct Obj03820 *)p)->f8 = target;
        ((struct Obj03820 *)p)->fC = time;
        ((struct Obj03820 *)p)->f14 = func_021FADA0(owner, (u32)func_021FB190, (u32)p, 10);
        if (wait == 1) {
            ((struct Obj06491 *)ctx)->f14 = ((struct Obj03820 *)p)->fC;
            return 1;
        }
    }
    return 0;
}
