/*
 * function: func_021DFCD4
 * address: 0x021DFCD4
 * packet: pkt_ov183_021DFCD4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 * symbols:
 *   func_021E04C8 0x021E04C8 thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021E04C8(void);
struct Sub0200852CObj;
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021FD860(int,int,int *);
extern void func_020061E4(u32 a);
extern void func_021E03B0(char *,char *,int);
extern void func_021FD170(char *p, char *q, void *text);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4B4(int,int,int);
extern int func_021FB4CC(int,int,int);
extern void func_021F9BA0(void *);
extern void func_021F9BF4(unsigned *,unsigned);
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f18=19;
        func_021E03B0(p,q,0);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)105);
        ((struct Obj00277 *)p)->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f14=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)106);
        ((struct Obj00277 *)p)->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=func_02012944(((struct Obj00351 *)q)->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        if(((struct Obj00351 *)q)->f16==255){((struct Obj00351 *)q)->f16=a;((struct Obj00351 *)q)->f17=b;}
        else{((struct Obj00351 *)q)->f16=255;((struct Obj00351 *)q)->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4(((struct Obj00277 *)p)->fC,x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                ((struct Obj00277 *)p)->f50=-1;
                func_021F9BA0(((struct Obj00351 *)q)->fC);
                return 1;
            }
            if(func_021FB4CC(((struct Obj00277 *)p)->f10,x,y)) {
                if(((struct Obj00351 *)q)->f14!=0xffff || ((struct Obj00351 *)q)->f17!=255 || ((struct Obj00351 *)q)->f18!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    func_020061E4(0x703);
                    func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                    ((struct Obj00277 *)p)->f50=-1;
                    func_021F9BF4(*(unsigned * *)&((struct Obj00351 *)q)->fC,5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)108);
            }
        }
    }
    return 0;
}
