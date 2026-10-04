/*
 * function: func_021E2910
 * address: 0x021E2910
 * packet: pkt_ov183_021E2910
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 * symbols:
 *   func_021E300C 0x021E300C thumb ov183
 *   func_021E2E30 0x021E2E30 thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021E2C2C 0x021E2C2C thumb ov183
 *   func_021E2AE0 0x021E2AE0 thumb ov183
 */
#include "../include/Obj01074.h"
#include "../include/Obj24678.h"
typedef unsigned int u32;
typedef struct { u32 a,b; } Pair;
extern void func_021E300C(Pair *);
extern void func_021E2E30(char *,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern u32 func_02035D20(u32 *,u32 *);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(int,int,Pair *);
extern void func_021E2E48(char *p, int a, int b);
extern void func_021FD73C(int *,int);
extern int func_021FD744(int);
extern void func_021E2C2C(void);
extern void func_021E2AE0(int *task, unsigned *state, char *p);
void func_021E2910(int task,int *state,char *p) {
    u32 x,y;
    Pair first,second,cb;
    int i;
    switch(*state) {
    case 0: {
        func_021E300C(&cb);
        *(Pair *)(p+0x4c)=cb;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct Obj01074 *)p)->f3C);
        *state=1; break;
    }
    case 1: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,0); *state=2; break;
    case 2: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=3; break;
    case 3: {
        if(func_02035D20(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(func_021FB4B4(*(int *)(p+i*4+0x14),x,y)) {
                    first.a=x; first.b=y;
                    func_021FD860(((struct Obj01074 *)p)->f34,1,&first);
                    ((struct Obj01074 *)p)->f10=i;
                    if(*(int *)((u32)*(char * *)&((struct Obj24678 *)(*(char * *)&((struct Obj01074 *)p)->f3C))->f18+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(func_021FB4B4(((struct Obj01074 *)p)->f20,x,y)) {
                second.a=x; second.b=y;
                func_021FD860(((struct Obj01074 *)p)->f34,1,&second); *state=10;
            }
        }
        break;
    }
    case 4: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); *state=5; break;
    case 5: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=6; break;
    case 6: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD73C(*(int * *)&((struct Obj01074 *)p)->fC,(int)func_021E2C2C); break;
    case 7: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); ++*state; break;
    case 8: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) ++*state; break;
    case 9: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD73C(*(int * *)&((struct Obj01074 *)p)->fC,(int)func_021E2AE0); break;
    case 10: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,1); *state=11; break;
    case 11: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=12; break;
    case 12: func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj01074 *)p)->f3C)); func_021FD744(task); break;
    }
}
