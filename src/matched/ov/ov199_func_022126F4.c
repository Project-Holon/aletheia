/*
 * function: func_022126F4
 * address: 0x022126F4
 * packet: pkt_ov199_022126F4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02213754 0x02213754 thumb ov199
 *   func_02213800 0x02213800 thumb ov199
 *   func_0200F7B8 0x0200F7B8 thumb
 */
#include "../include/Obj08367.h"
struct S;
extern int func_02213754(struct S *s);
extern int func_02213800(char *p);
extern void func_0200F7B8(int);
int func_022126F4(int unused,int *state,int unused2,char *p)
{
    switch(*state) {
    case 0:
        if(func_02213754((struct S *)(((struct Obj08367 *)p)->f18))) *state=1;
        if(((struct Obj08367 *)p)->f1CC) --((struct Obj08367 *)p)->f1CC;
        {
            int x=func_02213800((char *)(((struct Obj08367 *)p)->f18));
            if(x==2 || x==0) func_0200F7B8(0);
        }
        break;
    case 1: return 1;
    }
    return 0;
}
