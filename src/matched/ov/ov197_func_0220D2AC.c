/*
 * function: func_0220D2AC
 * address: 0x0220D2AC
 * packet: pkt_ov197_0220D2AC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_0220D8B0 0x0220D8B0 thumb ov197
 */
#include "../include/Obj03346.h"

typedef unsigned int u32;
struct Rec;
struct Rec3;
extern unsigned func_0201CE30(void *);
extern void func_0201CE5C(struct Rec *, int);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_0220D8B0(char **, int);
int func_0220D2AC(char *p)
{
    switch (func_0201CE30(*(struct Rec * *)&((struct Obj03346 *)p)->f1C)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (func_0203630C() & 3)) func_0201CE5C(*(struct Rec * *)&((struct Obj03346 *)p)->f1C, 0);
        ((struct Obj03346 *)p)->f20 = 0;
        break;
    case 1:
        if (!((struct Obj03346 *)p)->f20 && (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3))) {
            func_0220D8B0((char **)p, 0x547);
            func_0201CE38(*(struct Rec * *)&((struct Obj03346 *)p)->f1C);
            ((struct Obj03346 *)p)->f20 = 1;
        }
        break;
    case 2:
        func_0201CE48(*(struct Rec3 * *)&((struct Obj03346 *)p)->f1C);
        *(int *)&((struct Obj03346 *)p)->f1C = 0;
        ((struct Obj03346 *)p)->f20 = 0;
        return 15;
    }
    return 14;
}
