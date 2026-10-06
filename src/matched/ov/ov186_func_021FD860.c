/*
 * function: func_021FD860
 * address: 0x021FD860
 * packet: pkt_ov186_021FD860
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * follower: 021FD938 already filed separately; lead excludes that existing accessor.
 * symbols:
 *   func_021FD750 0x021FD750 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021FDE88 0x021FDE88 thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   func_021FD9A0 0x021FD9A0 thumb ov186
 *   func_021FDA7C 0x021FDA7C thumb ov186
 *   func_021FDBF4 0x021FDBF4 thumb ov186
 *   func_021FDF40 0x021FDF40 thumb ov186
 *   func_021FDFF0 0x021FDFF0 thumb ov186
 *   func_021FDFF4 0x021FDFF4 thumb ov186
 *   func_021FE1C4 0x021FE1C4 thumb ov186
 */
#include "../include/Obj02236.h"
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern int func_021FD750(int *,int);
extern int *func_021FD73C(int *p, int v);
extern void func_020061E4(u32 a);
typedef unsigned char  u8;
extern void func_021FDE88(void);
extern void func_021FD964(void *unused, int *state, u8 *p);
extern void func_021FD9A0(void);
extern void func_021FDA7C(void);
extern void func_021FDBF4(void);
extern void func_021FDF40(void);
extern void func_021FDFF0(void);
extern void func_021FDFF4(void);
extern void func_021FE1C4(int *task, int *state, char *p);
void func_021FD860(char *p,u32 mode,const Pair *pair)
{
    if(pair) {
        *(Pair *)p=*pair;
        *(const Pair * *)&((struct Obj02236 *)p)->f8=pair;
    }
    ((struct Obj02236 *)p)->f22C=0;
    if(mode==0 && func_021FD750(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88)) func_020061E4(0x701);
    switch(mode) {
    case 0: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD964);break;
    case 1: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD9A0);break;
    case 2: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDA7C);break;
    case 3: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDBF4);break;
    case 4: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88);break;
    case 5: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDF40);break;
    case 6: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF0);break;
    case 7: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF4);break;
    case 8: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FE1C4);break;
    }
}
