/*
 * file:     b_app_tool.c
 * unit:     yes
 * function: func_0220AF40, func_0220AF64, func_0220AF6C, func_0220AFC4, func_0220AFDC, func_0220B000, func_0220B07C, func_0220B094
 * address:  0x0220AF40
 * region:   ov196
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   d_0220B100 0x0220B100 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   sub_02045374 0x02045374 arm
 *   sub_02045730 0x02045730 arm
 *   sub_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj14539.h"
#include "../../matched/include/Obj24987.h"
#include "../../matched/include/Obj14540.h"

struct Obj;
struct Vec2;
struct Descriptor;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_0220AF40;

typedef unsigned int u32;

typedef struct {u16 x,y,z;u8 a,b;} Pos_0220AF6C;

typedef signed short   s16_0220AFC4;

typedef signed char    s8;

typedef struct {u16 x,y;} Pos_0220B000;

typedef short s16_0220B07C;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_0204B294(int, int, int, int, void *, int, u16);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void sub_02045374(struct Cfg *);
extern u8 sub_02045730(struct Descriptor *);
extern void sub_02041B6C(u32);
u8 *func_0220AF40(u16 v);
void func_0220AF64(void *p);
void func_0220AF6C(char *p, int a, int b, int c, int d);
void func_0220AFC4(u8 *p);
void func_0220AFDC(char *p, void *v);
void func_0220B000(int *p, u8 *q);
void func_0220B07C(void **p);
void func_0220B094(char *p, unsigned char *q);
extern const char d_0220B100[];

u8 *func_0220AF40(u16 v) { u8 *p; p=sub_02030734(v,24,0,d_0220B100,43); ((struct Obj14539 *)p)->f10=v; ((struct Obj14539 *)p)->f14=1; return p; }

/*
 * leaf: parent-cleared sole blocker of ov197 func_0220D3B0; eight-byte tail stub.
 */
void func_0220AF64(void *p)
{
    func_020307B0(p);
}

void func_0220AF6C(char *p, int a, int b, int c, int d)
{
    Pos_0220AF6C pos;
    unsigned i;
    pos.x=0;pos.y=0;pos.a=0;pos.b=1;
    for(i=0;i<4;i++) {
        pos.z=i;
        *(int *)(p+i*4)=func_0204B294(a,b,c,d,&pos,1,((struct Obj24987 *)p)->f10);
        func_0204B6F4((struct Obj *)(*(int *)(p+i*4)),0,1);
        func_0204B92C((struct Obj *)*(int *)(p+i*4),1);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0220AFC4(u8 *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4)));
    }
}


void func_0220AFDC(char *p, void *v)
{
    if (((struct Obj14540 *)p)->f14 != v)
    {
        unsigned int i;
        for (i = 0; i < 4; i++)
        {
            func_0204B3DC(*(void **)(p + i * 4), (unsigned int)v);
        }
        ((struct Obj14540 *)p)->f14 = v;
    }
}

void func_0220B000(int *p, u8 *q)
{
    Pos_0220B000 pos;
    u8 h=q[3]/2;
    u8 w=q[2]/2;
    pos.x=q[0]-w;pos.y=q[1]-h;func_0204B404((struct Obj *)p[0],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]-w;pos.y=q[1]+h;func_0204B404((struct Obj *)p[1],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]+w;pos.y=q[1]-h;func_0204B404((struct Obj *)p[2],(const struct Vec2 *)(&pos),1);
    pos.x=q[0]+w;pos.y=q[1]+h;func_0204B404((struct Obj *)p[3],(const struct Vec2 *)(&pos),1);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void func_0220B07C(void **p) { sub_02045374((struct Cfg *)*p); sub_02041B6C(sub_02045730((struct Descriptor *)*p)); }


void func_0220B094(char *p, unsigned char *q)
{
    int i = 0;
    for (;;) {
        unsigned char c = q[i];
        if (c == 0xff)
            break;
        func_0220B07C((void **)(p + (c << 3)));
        i++;
    }
}
