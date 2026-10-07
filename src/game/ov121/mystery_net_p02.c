/*
 * file:     mystery_net_p02.c
 * unit:     yes
 * function: func_021DDD64, func_021DDF5C, func_021DDF84, func_021DE014, func_021DE024, func_021DE0AC
 * address:  0x021DDD64
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_02082A48 0x02082A48 arm
 *   func_0204B5F4 0x0204B5F4 arm
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021DDC30 0x021DDC30 arm ov121
 *   func_021DDC44 0x021DDC44 arm ov121
 *   func_02082A60 0x02082A60 arm
 *   func_021DDC58 0x021DDC58 thumb ov121
 *   func_021DDCF8 0x021DDCF8 thumb ov121
 *   func_021DA4A8 0x021DA4A8 thumb ov121
 *   func_021DA318 0x021DA318 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_020056A0 0x020056A0 thumb
 */
#include "../../matched/include/Obj10421.h"
#include "../../matched/include/Obj22908.h"
#include "../../matched/include/Obj01931.h"
#include "../../matched/include/Obj22910.h"
#include "../../matched/include/Obj22911.h"
#include "../../matched/include/Obj08098.h"

struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {s16 x,y;} Point;

extern void *func_021DBF10(void *,u16);
extern u32 func_021DBF40(void *);
extern int func_021DBF9C(void *);
extern u32 func_021DBF70(void *);
extern int func_021DC024(void *);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(void *,const Point *,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204ADEC(u32,void *,u32);
extern void func_02082A48(u32,void *,u32);
extern void func_0204B5F4(struct Actor *actor, u16 value);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0204B84C(void *,u8);
extern void func_021DDC30(int,int);
extern void func_021DDC44(int,int);
extern void func_02082A60(void *,const void *,int);
extern void func_021DDC58(const unsigned *,void *,u16);
extern void func_021DDCF8(unsigned *,void *,u16);
extern void func_021DA4A8(u8 *p);
extern void func_021DA318(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020056A0(u32,u32,u32);
void func_021DDD64(char *p,char *q,u16 heap);
void func_021DDF5C(u8 *p);
void func_021DDF84(char *p);
int func_021DE014(char *p);
void func_021DE024(void *unused,char *p);
void func_021DE0AC(u8 *p,u32 b);

static inline void *palette(u32 off, int mode)
{
    if (mode==0) return (void *)(off+0x05000200);
    else return (void *)(off+0x05000600);
}

/*
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 func_021DBF10 and matched caller func_021DE024: the earlier
 *   u32-heap owner gate does not apply.
 */
void func_021DDD64(char *p,char *q,u16 heap)
{
    void *arc;
    void *allocation;
    void *allocation2;
    void *res;
    void *res2;
    Point pt;
    u16 *dest;
    u32 offset;
    int i;
    arc=func_021DBF10(p,heap);
    allocation=func_02049F78(arc,(int)func_021DBF40(p),(u32)(&res),(u16)(*(u16 *)(p+0x118)));
    offset=*(u32 *)(q+0xb0)*32;
    func_02082D44(*(void **)((char *)res+12),palette(offset,*(u32 *)(q+0x98)),96);
    func_020307B0(allocation);
    allocation2=func_02049E74(arc,(int)func_021DBF9C(p),(int)0,(u32)(&res2),*(u16 *)(p+0x118));
    func_0204AA94(*(int *)(q+8),*(void **)((char *)res2+20),512,0,*(int *)(q+0x98));
    func_020307B0(allocation2);
    func_02049238(arc);
    pt.x=216; pt.y=22;
    if (func_021DC024(p)==2) {pt.x+=4;pt.y+=8;}
    func_0204B6F4(*(void **)(q+28),(u8)func_021DBF70(p),0);
    func_0204B404(*(void **)(q+28),&pt,*(u32 *)(q+0x98));
    func_0204B3DC(*(void **)(q+28),1);
    if (func_021DC024(p)==1) {
        func_0204ADEC(*(u32 *)(q+16),*(void **)(*(char **)(p+0x140)+12),1);
        func_02082D44(*(void **)(*(char **)(p+0x140)+12),q+0x64,32);
        func_02082A48(0,q+0x44,32);
        func_0204AA94(*(int *)(q+20),*(void **)(*(char **)(p+0x138)+20),0x1200,0,*(int *)(q+0x98));
        func_0204B5F4(*(void **)(q+32),0);
        func_0204B3DC(*(void **)(q+32),1);
        if (*(u32 *)(q+0xa0)<4) dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000200);
        else dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000600);
        for(i=0;i<16;i++) dest[i]=*(u16 *)(q+0x44+i*2);
        if (*(u32 *)(q+0xa0)<4)
            func_0207D63C((void *)0x04000050,0,(1<<(u8)*(u32 *)(q+0xa0))|(1<<(u8)*(u32 *)(q+0xa4)),2,12);
        else
            func_0207D63C((void *)0x04001050,0,(1<<(u8)(*(u32 *)(q+0xa0)-4))|(1<<(u8)(*(u32 *)(q+0xa4)-4)),2,12);
    } else func_0204B3DC(*(void **)(q+32),0);
}

void func_021DDF5C(u8 *p) { if(func_021DC024(p)==1 && ((struct Obj10421 *)p)->fDC==0) { ((struct Obj10421 *)p)->fDC=1; ((struct Obj10421 *)p)->fDE=0; } }

void func_021DDF84(char *p)
{
    char *palette;
    void (*blend)(int,int);
    if (func_021DC024(p)==1) {
        *(u16 *)(p+0xdc)=0;
        *(u16 *)(p+0xde)=0;
        func_0204B84C(*(void **)(*(char **)(p+0x11c)+0x20),*(unsigned *)(*(char **)(p+0x11c)+0x8c));
        if (*(int *)(*(char **)(p+0x11c)+0x84)) {
            palette=(char *)(func_0204AEF4((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000200);
            blend=func_021DDC30;
        } else {
            palette=(char *)(func_0204AEF4((u32)(*(void **)(*(char **)(p+0x11c)+0x10)),*(int *)(*(char **)(p+0x11c)+0x98))+0x05000600);
            blend=func_021DDC44;
        }
        blend(2,12);
        func_02082A48(0,*(char **)(p+0x11c)+0x44,32);
        func_02082A60(*(char **)(p+0x11c)+0x44,palette,32);
    }
}

int func_021DE014(char *p)
{
    if (((struct Obj22908 *)p)->fDC==0) return 1;
    return 0;
}

void func_021DE024(void *unused,char *p)
{
    if (((struct Obj01931 *)p)->f12C) return;
    ((struct Obj01931 *)p)->f12C=1;
    switch (((struct Obj01931 *)p)->f130) {
    case 0: func_021DDC58((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    case 1: func_021DDCF8((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    }
    func_021DDD64(p,((struct Obj01931 *)p)->f11C,((struct Obj01931 *)p)->f118);
    func_021DA4A8(((struct Obj01931 *)p)->f144);
    func_021DA318(**(void ** *)&((struct Obj01931 *)p)->f11C);
    func_02040588((u8)(((struct Obj22910 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f96),(int)1);
    func_02040588((u8)(((struct Obj22911 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f94),(int)1);
}

void func_021DE0AC(u8 *p,u32 b) { ((struct Obj08098 *)p)->f130=b; if(*(u32 *)&((struct Obj08098 *)p)->f128==0) ((struct Obj08098 *)p)->f128=func_020056A0((u32)func_021DE024,(u32)p,0); else ((struct Obj08098 *)p)->f12C=0; }
