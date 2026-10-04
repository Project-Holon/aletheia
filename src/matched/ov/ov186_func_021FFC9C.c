/*
 * function: func_021FFC9C
 * address: 0x021FFC9C
 * packet: pkt_ov186_021FFC9C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022000F0 0x022000F0 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FFFCC 0x021FFFCC thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_02200188 0x02200188 thumb ov186
 *   func_021FFFF8 0x021FFFF8 thumb ov186
 *   func_022000D0 0x022000D0 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_021FFF28 0x021FFF28 thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   d_02200DAC 0x02200DAC data
 */
#include "../include/Obj00221.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern int func_022000F0(char *);
extern int func_02035D20(int *,int *);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(char *,u32,const Pair *);
extern void func_021FCD0C(char *);
extern int func_021FCDA8(char *),func_021FD938(char *),func_021FE7B0(int *);
extern void func_021FE784(int a, int b, int c, int d);
extern void func_021FFFCC(char *),func_022000D0(char *),func_021FFF28(char *),func_021FFFF8(char *);
extern u16 *func_02200188(void *,u32,u16 *,u32 *,u16);
extern void func_02034714(const char *,int,const char *),func_020307B0(void *);
extern unsigned func_021FFE34(char *p);
extern char d_02200DAC[];
int func_021FFC9C(char *p)
{
    if (((struct Obj00221 *)p)->f6C) {
        switch (((struct Obj00221 *)p)->f0) {
        case 0: (((struct Obj00221 *)p)->f0)++; break;
        case 1: ((struct Obj00221 *)p)->f0=2; break;
        case 2: {
            int x,y,held;
            Pair pair;
            ((struct Obj00221 *)p)->fC=func_022000F0(p);
            held=func_02035D20(&x,&y);
            if (func_021FB4B4(((struct Obj00221 *)p)->f2C,x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=1;
            } else if (((struct Obj00221 *)p)->fC!=9) {
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=3;
            }
            break;
        }
        case 3: {
            int x,y,held;
            Pair pair;
            func_021FCD0C(*(char * *)&((struct Obj00221 *)p)->f68);
            ((struct Obj00221 *)p)->f10=func_021FCDA8(*(char * *)&((struct Obj00221 *)p)->f68);
            held=func_02035D20(&x,&y);
            if (func_021FB4B4(((struct Obj00221 *)p)->f2C,x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char * *)&((struct Obj00221 *)p)->f78,1,&pair);
                *(int *)&((struct Obj00221 *)p)->f0=4; ((struct Obj00221 *)p)->f4=2;
            } else if (((struct Obj00221 *)p)->f10!=-1) {
                *(int *)&((struct Obj00221 *)p)->f0=8; ((struct Obj00221 *)p)->f8=2;
            }
            break;
        }
        case 4:
            if (func_021FD938(*(char * *)&((struct Obj00221 *)p)->f78)) {
                func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,1);
                (((struct Obj00221 *)p)->f0)++;
            }
            break;
        case 5:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) (((struct Obj00221 *)p)->f0)++;
            break;
        case 6:
            if (((struct Obj00221 *)p)->f4==3) {
                func_021FFFCC(p);
                if (((struct Obj00221 *)p)->f88) func_02034714(d_02200DAC,0,d_02200DAC);
                *(u16 * *)&((struct Obj00221 *)p)->f88=func_02200188(((struct Obj00221 *)p)->f7C,*(u32 *)&((struct Obj00221 *)p)->fC,*(u16 * *)&((struct Obj00221 *)p)->f80,(u32 *)(p+0x8c),((struct Obj00221 *)p)->f24);
                func_021FFFF8(p);
            } else {
                func_022000D0(p);
                if (((struct Obj00221 *)p)->f88) {
                    func_020307B0(((struct Obj00221 *)p)->f88);
                    ((struct Obj00221 *)p)->f88=0;
                }
                func_021FFF28(p);
            }
            func_021FE784((int)(((struct Obj00221 *)p)->f30),2,2,0);
            (((struct Obj00221 *)p)->f0)++;
            break;
        case 7:
            if (func_021FE7B0(*(int * *)&((struct Obj00221 *)p)->f30)) ((struct Obj00221 *)p)->f0=*(u32 *)&((struct Obj00221 *)p)->f4;
            break;
        case 8: (((struct Obj00221 *)p)->f0)++; break;
        case 9: (((struct Obj00221 *)p)->f0)++; break;
        case 10: ((struct Obj00221 *)p)->f20=1; break;
        }
    }
    return func_021FFE34(p);
}
