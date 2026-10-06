/*
 * function: func_021F86E4
 * address: 0x021F86E4
 * packet: pkt_ov185_021F86E4
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F8FC8 0x021F8FC8 thumb ov185
 *   func_021F9008 0x021F9008 thumb ov185
 *   func_021F9048 0x021F9048 thumb ov185
 *   func_021F8950 0x021F8950 thumb ov185
 *   func_021F8C30 0x021F8C30 thumb ov185
 *   func_021F8B5C 0x021F8B5C thumb ov185
 */
#include "../include/Obj02525.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(int,int,int *);
extern void func_021FD73C(int *p, int v);
extern int func_021F8FC8(int,int,int);
extern int func_021F9008(int,int,int);
extern int func_021F9048(char *p, unsigned x, unsigned y);
extern void func_021F8950(int *sys, int *state, char *p);
extern void func_021F8C30(int *task, int *state, char *p);
extern void func_021F8B5C(int *task, int *state, char *p);
void func_021F86E4(int a,int b,char *p)
{
    int x,y;
    if (func_02035D20((u32 *)(&x),(u32 *)(&y))) {
        if (func_021FB4B4(((struct Obj02525 *)p)->f18,x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(((struct Obj02525 *)p)->f3C,1,pair);
            func_021FD73C((int *)a,(int)func_021F8950);
        }
        if (func_021F8FC8((int)p,x,y)) func_021FD73C((int *)a,(int)func_021F8C30);
        if (func_021F9008((int)p,x,y)) {
            int index=((struct Obj02525 *)p)->fC-1;
            if (index<0) ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->f54-1;
            else ((struct Obj02525 *)p)->fC=index;
            func_021FD73C((int *)a,(int)func_021F8B5C);
        }
        if (func_021F9048((char *)((int)p),x,y)) {
            ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->fC+1;
            ((struct Obj02525 *)p)->fC=(int)((struct Obj02525 *)p)->fC % ((struct Obj02525 *)p)->f54;
            func_021FD73C((int *)a,(int)func_021F8B5C);
        }
    }
}
