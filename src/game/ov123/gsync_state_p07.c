/*
 * file:     gsync_state_p07.c
 * unit:     yes
 * function: func_021D5BD4, func_021D5C0C, func_021D5C2C, func_021D5C64, func_021D5C9C, func_021D5CAC, func_021D5CF8, func_021D5D24, func_021D5D58, func_021D5D7C, func_021D5D8C, func_021D5D94, func_021D5E60, func_021D5E8C, func_021D5F4C
 * address:  0x021D5BD4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5928 0x021C5928 arm ov114
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021D5AC0 0x021D5AC0 thumb ov123
 *   func_021D5BA8 0x021D5BA8 thumb ov123
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 *   g_021DAC20 0x021DAC20 data ov123 a4
 *   OS_SNPrintf 0x0208D80C arm
 *   func_021C5C04 0x021C5C04 arm ov114
 *   d_021DAA74 0x021DAA74 data a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5B80 0x021C5B80 arm ov114
 *   func_021C5AB8  0x021C5AB8  arm  ov114
 *   ov067_id 0x00000043 data
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D614C 0x021D614C thumb ov123
 *   func_021D6CD8 0x021D6CD8 thumb ov123
 *   func_021D6D5C 0x021D6D5C thumb ov123
 *   func_021D60F8 0x021D60F8 thumb ov123
 *   d_021DAB68 0x021DAB68 data a1
 *   d_021DAA9C 0x021DAA9C data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DAA78 0x021DAA78 data a4
 *   func_0204A600 0x0204A600 arm
 *   func_021D6678 0x021D6678 thumb ov123
 *   func_021D6934 0x021D6934 thumb ov123
 *   func_021D63E4 0x021D63E4 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   d_021DA758 0x021DA758 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 */
#include "../../matched/include/Obj22944.h"
#include "../../matched/include/Obj22945.h"
#include "../../matched/include/Obj10438.h"
#include "../../matched/include/Obj22946.h"
#include "../../matched/include/Obj13975.h"
#include "../../matched/include/Obj06460.h"
#include "../../matched/include/Obj10439.h"
#include "../../matched/include/Obj06461.h"
#include "../../matched/include/Obj13976.h"
#include "../../matched/include/Obj22947.h"
#include "../../matched/include/Obj04498.h"
#include "../../matched/include/Obj03267.h"
#include "../../matched/include/Obj04499.h"

struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Obj;
struct Node;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef enum { C0 = 0 } Counter;

struct BgTemplate {
    u32 unk00, unk04, bufSize, unk0c;
    u8 unk10, unk11, unk12, unk13;
    u32 unk14;
    u8 unk18, unk19, unk1a, unk1b;
    u32 unk1c;
};

extern void func_021D5AC0(void *unused, u32 mode);
extern int func_021D5BA8(char *);
extern int func_021C5928(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern void func_02156DE0(int a, int b);
extern int OS_SNPrintf(char *,int,const char *,...);
extern int func_021C5C04(char *attr1, char *attr2, char *attr3);
extern int func_021C5DB4(void);
extern int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
extern int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
extern int func_021C5B80(void);
extern void func_021C5AB8(void);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32 swap);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021D614C(u8 *);
extern void func_021D6CD8(u8 *);
extern void func_021D6D5C(u8 *);
extern void func_021D60F8(void *,u8 *);
extern void *func_020056A0(void *,void *,int);
extern void func_0204A600(void);
extern void func_021D6678(u8 *);
extern void func_021D6934(struct Obj *);
extern void func_021D63E4(u8 *);
extern unsigned int func_020307B0(void *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203F9B4(void);
extern void func_02034A5C(int);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020409B4(u32);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_02041300(u32,u32,u32,u32,u8,u8,u8);
int func_021D5BD4(char *p);
int func_021D5C0C(char *p);
int func_021D5C2C(char *p);
int func_021D5C64(char *p,void *arg,int value);
void func_021D5C9C(char *p);
int func_021D5CAC(char *p);
int func_021D5CF8(char *p);
int func_021D5D24(char *p);
int func_021D5D58(char *p);
void func_021D5D7C(char *p);
void *func_021D5D8C(u8 *p);
u8 *func_021D5D94(u32 heap);
void func_021D5E60(u8 *p);
void func_021D5E8C(u8 *p);
void func_021D5F4C(u8 *p);
extern char d_021DAA58[],d_021DAA60[];
extern char *g_021DAC20;
extern const char d_021DAA74[],d_021DAA54[];
extern const char d_021DAB68[];
extern char ov067_id[];
extern const u32 d_021DAA9C[], d_020A1464[], d_021DAA78[];
extern unsigned char ov_id[];
extern const struct BgTemplate d_021DA758[7];

int func_021D5BD4(char *p){((struct Obj22944 *)p)->fB0=0;if(!func_021C5928((void (*)(int,  int,  int))func_021D5AC0,d_021DAA58,d_021DAA60))return 0;func_02156DE0((int)func_021D5BA8,(int)p);return 1;}

int func_021D5C0C(char *p){if(*(int *)(g_021DAC20+0xb0)){if(!((struct Obj22945 *)p)->fB4)return 1;}return 0;}

int func_021D5C2C(char *p){if(((struct Obj10438 *)p)->fD0&&((struct Obj10438 *)p)->fC8)return 1;if(*(int *)(g_021DAC20+0xb0)&&((struct Obj10438 *)p)->fB4)return 1;return 0;}

int func_021D5C64(char *p,void *arg,int value){char buf[20];int ok=0;((struct Obj22946 *)p)->fB0=0;OS_SNPrintf(buf,20,d_021DAA74,value);if(func_021C5C04(arg,buf,(char *)d_021DAA54))ok=1;return ok;}


void func_021D5C9C(char *p)
{
    ((struct Obj13975 *)p)->fCC = 0;
    ((struct Obj13975 *)p)->fD0 = 0;
}

int func_021D5CAC(char *p)
{
    if (((struct Obj06460 *)p)->fD0) return 0;
    if (((struct Obj06460 *)p)->fCC) {
        if (++((struct Obj06460 *)p)->fCC>3600) {
            ((struct Obj06460 *)p)->fD0=1;
            if (!func_021C5DB4()) ((struct Obj06460 *)p)->fC8=1;
            return 0;
        }
    }
    return 1;
}

int func_021D5CF8(char *p){int ok=1;((struct Obj10439 *)p)->fB0=0;((struct Obj10439 *)p)->fCC=1;((struct Obj10439 *)p)->fD0=0;if(!func_021C5C38(p,0,1))ok=0;return ok;}

int func_021D5D24(char *p){int ok=1;((struct Obj06461 *)p)->fB0=0;((struct Obj06461 *)p)->fCC=1;((struct Obj06461 *)p)->fD0=0;if(!func_021C5CFC(p,((struct Obj06461 *)p)->fB8,((struct Obj06461 *)p)->fBC+0x40))ok=0;return ok;}

int func_021D5D58(char *p){int ok;if(!((struct Obj13976 *)p)->fC4){ok=0;((struct Obj13976 *)p)->fB0=0;if(!func_021C5B80())return ok;}return 1;}


/*
 * Addresses are Black-image addresses.
 */
void func_021D5D7C(char *p)
{
    if (func_021D5CAC(p) != 0)
        func_021C5AB8();
}

void *func_021D5D8C(u8 *p){return ((struct Obj22947 *)p)->fAC;}

/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *func_021D5D94(u32 heap)
{
    u8 *p;
    p=func_02030734(heap,0x4568,1,d_021DAB68,0xfe);
    ((struct Obj04498 *)p)->f43C4=heap;
    func_02034AC4((int)ov067_id);
    func_02043534(0); func_020435F4(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj04498 *)p)->f43C4);
    func_0204A48C((const struct Cfg *)d_020A1464,(u32)d_021DAA9C,((struct Obj04498 *)p)->f43C4);
    ((struct Obj04498 *)p)->fC=func_0204B100(40,0,((struct Obj04498 *)p)->f43C4);
    func_020433E0((const struct DispVram *)d_021DAA9C); func_0203FC28((struct DispConfig *)d_021DAA78);
    func_021D5F4C(p); func_021D614C(p); func_021D6CD8(p); func_021D6D5C(p);
    ((struct Obj04498 *)p)->f10=func_020056A0(func_021D60F8,p,0);
    ((struct Obj04498 *)p)->f455C=200;
    func_020435F4(31); func_02043534(27);
    return p;
}

void func_021D5E60(u8 *p){(((struct Obj03267 *)p)->f43C6)++;if(((struct Obj03267 *)p)->f43C6>=192)((struct Obj03267 *)p)->f43C6=0;func_0204A600();func_021D6678(p);func_021D6934((struct Obj *)p);}

void func_021D5E8C(u8 *p)
{
    Counter i;
    func_021D63E4(p);
    func_020307B0(((struct Obj04499 *)p)->f1C);
    func_0204B3B4(((struct Obj04499 *)p)->fB4);
    func_0204B3B4(((struct Obj04499 *)p)->fB8);
    i=0;
    do { if(*(void **)(p+i*4+0x20)) func_0204ADA4((u32)(*(void **)(p+i*4+0x20))); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)(p+i*4+0x20)) func_0204A8D4((u32)(*(void **)(p+i*4+0x20)));
    for(;i<20;i++) if(*(void **)(p+i*4+0x20)) func_0204AFD8((u32)(*(void **)(p+i*4+0x20)));
    if(((struct Obj04499 *)p)->f14) func_02030EAC(((struct Obj04499 *)p)->f14);
    func_02030EAC(((struct Obj04499 *)p)->f10);
    func_0204B1CC(((struct Obj04499 *)p)->fC);
    func_0204A5AC();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}

void func_021D5F4C(u8 *p)
{
    struct BgTemplate b[7];
    b[6]=d_021DA758[0]; func_0203FCA0(0,&b[6],0); func_02040588(0,1); func_020409B4(0);
    b[5]=d_021DA758[1]; func_0203FCA0(1,&b[5],0); func_02040588(1,1); func_020409B4(1);
    b[4]=d_021DA758[2]; func_0203FCA0(3,&b[4],0); func_02040588(3,1); func_020409B4(3);
    b[3]=d_021DA758[3]; func_0203FCA0(4,&b[3],0); func_02040588(4,1); func_020409B4(4);
    b[2]=d_021DA758[4]; func_0203FCA0(5,&b[2],0);
    func_02040C14(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=d_021DA758[5]; func_0203FCA0(6,&b[1],0); func_02040588(6,1);
    func_02040C14(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=d_021DA758[6]; func_0203FCA0(7,&b[0],0); func_02040588(7,1); func_020409B4(7);
}
