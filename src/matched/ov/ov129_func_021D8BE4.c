/*
 * function: func_021D8BE4
 * address: 0x021D8BE4
 * packet: pkt_ov129_021D8BE4
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA610 0x021DA610 thumb ov129
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021DA578 0x021DA578 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 */
#include "../include/Obj02843.h"

typedef unsigned int u32;

extern void func_021DA610(void *p, int sel, void *b, unsigned int c);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021DA578(void *p, int a, void *b, u32 c);
extern void func_021D8AF4(char *,int);
int func_021D8BE4(char *p)  {
    switch(((struct Obj02843 *)p)->f234)  {
        case 0: func_021DA610((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
        ((struct Obj02843 *)p)->f234+=1;
        break;
        case 1: if((func_020362DC() & 2) || (func_020362DC() & 1) || TOUCHPANEL_GetTrg())  {
            func_021DA578((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
            func_021D8AF4(p,1);
        }
        break;
    }
    return 0;
}
