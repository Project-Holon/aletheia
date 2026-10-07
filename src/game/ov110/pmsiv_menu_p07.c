/*
 * file:     pmsiv_menu_p07.c
 * unit:     yes
 * function: func_021BC93C, func_021BC964, func_021BC990, func_021BCA30
 * address:  0x021BC93C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_0207D658 0x0207D658 arm
 *   d_021C3C68 0x021C3C68 data
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_021BD194 0x021BD194 thumb ov110
 *   func_021BD044 0x021BD044 thumb ov110
 *   func_021BD114 0x021BD114 thumb ov110
 *   func_021BD2F0 0x021BD2F0 thumb ov110
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_021BD344 0x021BD344 thumb ov110
 *   func_021BD174 0x021BD174 thumb ov110
 *   func_021BD0D4 0x021BD0D4 thumb ov110
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj04448.h"
#include "../../matched/include/Obj08003.h"
#include "../../matched/include/Obj01249.h"
#include "../../matched/include/Obj00295.h"

struct Node;
struct MsgBank;
struct R;
struct Obj;
struct Rec;
struct TaskMenuState;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_02030EAC(struct Node *n);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_021BAC44(u8 *);
extern unsigned func_021BAC4C(u8 *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021BD194(u8 *);
extern void func_021BD044(u8 *);
extern void func_021BD114(u8 *);
extern void func_021BD2F0(u8 *);
extern void func_021BCAD8(u8 *);
extern void func_021BD344(u8 *);
extern void func_021BD174(u8 *);
extern void func_021BD0D4(u8 *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
int func_021BC93C(u8 *p);
void func_021BC964(void *unused,u8 *p);
u8 *func_021BC990(u8 *a,u8 *b,void *c);
void func_021BCA30(u8 *p);
extern const char d_021C3C68[];

int func_021BC93C(u8 *p)
{
    if (((struct Obj08003 *)p)->f18==0) {
        if (((struct Obj08003 *)p)->f14==0) {
            func_02030EAC(((struct Obj08003 *)p)->f1C);
            ++((struct Obj08003 *)p)->f18;
            return 1;
        }
    } else return 1;
    return 0;
}

/*
 * follower: callback func_021BC964 included in unit; function_starts seed.
 */
void func_021BC964(void *unused,u8 *p)
{
    int value;
    if (((struct Obj04448 *)p)->f14) {
        ((struct Obj04448 *)p)->f8+=((struct Obj04448 *)p)->f10;
        value=((struct Obj04448 *)p)->f8>>12;
        --((struct Obj04448 *)p)->f14;
    } else value=((struct Obj04448 *)p)->fC>>12;
    func_0207D658(0x4000050,((struct Obj04448 *)p)->f0,value);
}

u8 *func_021BC990(u8 *a,u8 *b,void *c)
{
    u8 *p;
    int i;
    unsigned x;
    p=func_02030734(42,188,1,d_021C3C68,309);
    *(u8 * *)&((struct Obj01249 *)p)->f0=a; *(u8 * *)&((struct Obj01249 *)p)->f4=b; ((struct Obj01249 *)p)->f8=c;
    *(u8 * *)&((struct Obj01249 *)p)->fC=func_021BF6D4(b);
    ((struct Obj01249 *)p)->f30=func_02045B38(0,2,146,42);
    for (i=0;i<3;i++) {
        x=func_021BAC44(*(u8 * *)&((struct Obj01249 *)p)->f0);
        *(void **)(p+0x34+i*4)=func_02027F60(0,8,x,func_021BAC4C(*(u8 * *)&((struct Obj01249 *)p)->f0),42);
    }
    func_02049B40(43,9,0,448,64,42);
    func_021BD194(p);func_021BD044(p);func_021BD114(p);func_021BD2F0(p);
    return p;
}

/*
 * extent: two bytes zero alignment padding after return.
 */
void func_021BCA30(u8 *p)
{
    int i;
    func_021BCAD8(p);
    func_0204B3B4(((struct Obj00295 *)p)->f28);
    func_0204ADA4((u32)(((struct Obj00295 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj00295 *)p)->f20));
    func_0204AFD8((u32)(((struct Obj00295 *)p)->f24));
    for (i=0;i<3;i++) func_02027FD8(*(void **)(p+0x34+i*4));
    func_021BD344(p); func_021BD174(p); func_021BD0D4(p);
    func_02045C04(((struct Obj00295 *)p)->f30);
    func_020307B0(p);
}
