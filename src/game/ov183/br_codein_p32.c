/*
 * file:     br_codein_p32.c
 * unit:     yes
 * function: func_021E2910, func_021E2AE0
 * address:  0x021E2910
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   func_021E2E60 0x021E2E60 thumb ov183
 *   func_021E31E8 0x021E31E8 thumb ov183
 *   func_021E3228 0x021E3228 thumb ov183
 */
#include "../../matched/include/Obj01074.h"
#include "../../matched/include/Obj24678.h"
#include "../../matched/include/Obj03334.h"

typedef unsigned int u32;

typedef struct { u32 a,b; } Pair_021E2910;

typedef struct Pair_021E2AE0 {int a,b;} Pair_021E2AE0;

extern void func_021E300C(Pair_021E2910 *);
extern void func_021E2E30(char *,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern u32 func_02035D20(u32 *,u32 *);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,Pair_021E2910 *);
extern void func_021E2E48(char *p, int a, int b);
extern int *func_021FD73C(int *p, int v);
extern int func_021FD744(int *a);
extern void func_021E2C2C(int *task, unsigned *state, char *p);
extern void func_021E2E60(Pair_021E2AE0 *);
extern int func_021E31E8(char *,int,int),func_021E3228(char *,int,int);
void func_021E2910(int *task,int *state,char *p);
void func_021E2AE0(int *task,unsigned *state,char *p);

/*
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 */
void func_021E2910(int *task,int *state,char *p) {
    u32 x,y;
    Pair_021E2910 first,second,cb;
    int i;
    switch(*state) {
    case 0: {
        func_021E300C(&cb);
        *(Pair_021E2910 *)(p+0x4c)=cb;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct Obj01074 *)p)->f3C);
        *state=1; break;
    }
    case 1: func_021FE784(**(int * *)&((struct Obj01074 *)p)->f3C,2,3,0); *state=2; break;
    case 2: if(func_021FE7B0((int *)**(int * *)&((struct Obj01074 *)p)->f3C)) *state=3; break;
    case 3: {
        if(func_02035D20(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(func_021FB4B4((unsigned int *)(*(int *)(p+i*4+0x14)),x,y)) {
                    first.a=x; first.b=y;
                    func_021FD860(((struct Obj01074 *)p)->f34,1,&first);
                    ((struct Obj01074 *)p)->f10=i;
                    if(*(int *)((u32)*(char * *)&((struct Obj24678 *)(*(char * *)&((struct Obj01074 *)p)->f3C))->f18+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(func_021FB4B4((unsigned int *)(((struct Obj01074 *)p)->f20),x,y)) {
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

/*
 * lever: Declare scalar locals before Pair; assign the returned Pair as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 */
void func_021E2AE0(int *task,unsigned *state,char *p)
{
    unsigned x,y;
    Pair_021E2AE0 a;
    switch(*state) {
    case 0:
        func_021E2E60(&a);
        *(Pair_021E2AE0 *)(p+0x4c)=a;
        func_021E2E30(p+0x4c,(int)p,*(int *)&((struct Obj03334 *)p)->f3C);
        ++*state; break;
    case 1:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,0);
        ++*state; break;
    case 2:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 3:
        if(func_02035D20(&x,&y)) {
            if(func_021E31E8(p,x,y)) *state=4;
            if(func_021E3228(p,x,y)) *state=7;
        }
        break;
    case 4:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 5:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 6:
        func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        func_021FD73C(task,(int)func_021E2C2C); break;
    case 7:
        func_021FE784(**(int * *)&((struct Obj03334 *)p)->f3C,2,3,1);
        ++*state; break;
    case 8:
        if(func_021FE7B0(**(int ** *)&((struct Obj03334 *)p)->f3C)) ++*state;
        break;
    case 9:
        func_021E2E48(p+0x4c,(int)p,(int)(*(char * *)&((struct Obj03334 *)p)->f3C));
        func_021FD73C(task,(int)func_021E2910); break;
    }
}
