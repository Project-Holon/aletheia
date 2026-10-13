/*
 * function: func_021DEB4C
 * address: 0x021DEB4C
 * packet: pkt_ov183_021DEB4C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021DF1DC 0x021DF1DC thumb ov183
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DED14 0x021DED14 thumb ov183
 *   d_021E3964 0x021E3964 data a1
 */
#include "../include/Obj00364.h"
#include "../include/Obj24587.h"
#include "../include/Obj24588.h"
#include "../include/Obj24589.h"
#include "../include/Obj24590.h"
#include "../include/Obj24591.h"
#include "../include/Obj24592.h"
#include "../include/Obj24593.h"
#include "../include/Obj24595.h"
#include "../include/Obj24596.h"
#include "../include/Obj24597.h"
#include "../include/Obj24598.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config {u16 left,right,top;u8 flag,pad;} Config;
typedef struct Triple {u32 a,b,c;} Triple;
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FD15C(void *,int);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *,u32,u32);
extern void MI_CpuFill8(void *,int,int);
extern int func_021FC124(void *,int,Triple *);
extern void func_02034714(const char *,u32,const char *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021DF1DC(char *,char *,char *,int,void *,void *,u16 *,u32);
extern int *func_021FD73C(int *p, int v);
extern void func_021DED14(int *a, int *state, char *p);
extern const char d_021E3964[];
void func_021DEB4C(int *task,int *state,char *p)
{
    int font,bank;
    Config config;
    Triple triple;
    font=func_021FC20C(*(char * *)&((struct Obj24587 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    bank=func_021FC214(*(char * *)&((struct Obj24588 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    if(((struct Obj00364 *)p)->f24) {
        func_021FD15C(((struct Obj00364 *)p)->f24,((struct Obj24589 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
        ((struct Obj00364 *)p)->f24=0;
    }
    func_021FB964((void *)(((struct Obj24590 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10),24,((struct Obj00364 *)p)->f18);
    func_021FBE54(*(char * *)&((struct Obj24591 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f104=1;
    MI_CpuFill8(&config,0,8);
    config.left=80;config.right=168;config.top=0;config.flag=1;
    if(!func_021FC124(((struct Obj24592 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,&triple))
        func_02034714(d_021E3964,0,d_021E3964);
    ((struct Obj00364 *)p)->f4=func_021FB378(&config,4,96,1,((struct Obj24593 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f0,font,bank,&triple,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f8=func_021FC6A4(4,11,6,10,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->f8,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    ((struct Obj00364 *)p)->fC=func_021FC6A4(1,3,3,26,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC868(((struct Obj00364 *)p)->fC,0,1,0);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->fC,(void *)bank,(void *)(**(int * *)&((struct Obj00364 *)p)->f108+0x57),(void *)font,0x3da0);
    func_021DF1DC(p+0x28,*(char * *)&((struct Obj24595 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f1C,*(char * *)&((struct Obj24596 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,((struct Obj24597 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f1C,((struct Obj00364 *)p)->f20,*(u16 * *)&((struct Obj24598 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f28,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f100=1;
    func_021FD73C(task,(int)func_021DED14);
}
