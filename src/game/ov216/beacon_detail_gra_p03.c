/*
 * file:     beacon_detail_gra_p03.c
 * unit:     yes
 * function: func_021BC454, func_021BC56C, func_021BC5C4, func_021BC614
 * address:  0x021BC454
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   configA 0x021BDB28 data a2
 *   configB 0x021BDB34 data a2
 *   func_0202DA04 0x0202DA04 thumb
 *   func_021BC3E4 0x021BC3E4 thumb ov216
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02062A00 0x02062A00 arm
 *   func_02049238 0x02049238 arm
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 *   func_021BC43C 0x021BC43C thumb ov216
 *   func_020307B0 0x020307B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B294 0x0204B294 arm
 */
#include "../../matched/include/Obj01783.h"
#include "../../matched/include/Obj10946.h"
#include "../../matched/include/Obj25771.h"
#include "../../matched/include/Obj14716.h"

struct ArcFile;
struct NitroFileHeader;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {unsigned char a,b,c,pad;u16 first,second,third;} Config;

typedef signed int     s32;

typedef struct { struct Descriptor *window; struct CharBuf *buffer; struct Descriptor *copy; unsigned char state; } Window;

typedef struct {short x,y,z;unsigned char a,b;} Position;

extern int func_0202DA04(int a0);
extern void func_021BC3E4(u16 *,int *,const Config *,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *,u32,u32);
extern int func_02062A98(struct NitroFileHeader *,void **);
extern int func_02062A00(struct NitroFileHeader *,void **);
extern void func_02049238(void *);
extern u32 func_0202DA48(u32,u32,u32,u32);
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_021BC43C(void *,char *);
extern u32 func_020307B0(void *p);
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *,unsigned char);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern unsigned char func_02045730(struct Descriptor *);
extern void func_020409B4(unsigned);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
void func_021BC454(char *p,u32 handle);
void func_021BC56C(char *p);
void func_021BC5C4(Window *p,unsigned layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height);
unsigned func_021BC614(unsigned short *p,unsigned manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag);
extern const Config configA,configB;

/*
 * lever: two Config locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 */
void func_021BC454(char *p,u32 handle)
{
    Config a,b;
    struct ArcFile *arc;
    int i;
    ((struct Obj01783 *)p)->f58=func_0202DA04(((struct Obj01783 *)p)->f0);
    a=configA;
    func_021BC3E4((u16 *)p,(int *)(p+92),&a,handle);
    b=configB;
    arc=func_020490F4(32,((struct Obj01783 *)p)->f2);
    func_021BC3E4((u16 *)p,(int *)(p+128),&b,(u32)arc);
    ((struct Obj01783 *)p)->f114=func_02049250(arc,0,((struct Obj01783 *)p)->f0);
    func_02062A98(*(struct NitroFileHeader * *)&((struct Obj01783 *)p)->f114,(void **)(p+268));
    ((struct Obj01783 *)p)->f110=((struct Obj25771 *)(*(char * *)&((struct Obj01783 *)p)->f10C))->fC;
    for(i=0;i<16;i++){
        *(void **)(p+i*8+144)=func_02049250(arc,i+49,((struct Obj01783 *)p)->f0);
        func_02062A00(*(struct NitroFileHeader **)(p+i*8+144),(void **)(p+140+i*8));
    }
    func_02049238(arc);
    for(i=0;i<2;i++){
        char *q=p+i*12;
        ((struct Obj10946 *)q)->f6C=func_0202DA48(((struct Obj01783 *)p)->f58,i+2,1,((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f68=(u32)func_0202DA18(((struct Obj01783 *)p)->f58,i+2,1,(u16)((i+8)<<5),((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f70=func_0202DA6C(i+2,0,1,((struct Obj01783 *)p)->f0);
    }
}

void func_021BC56C(char *p)
{
    int i;
    for(i=0;i<2;i++) func_021BC43C(p,p+0x68+i*12);
    for(i=0;i<16;i++) func_020307B0(*(void **)(p+0x90+i*8));
    func_020307B0(((struct Obj14716 *)p)->f114);
    func_021BC43C(p,p+0x80);
    func_021BC43C(p,p+0x5c);
    func_02049238(((struct Obj14716 *)p)->f58);
}

void func_021BC5C4(Window *p,unsigned layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height)
{
    struct Descriptor *window;
    p->window=(struct Descriptor *)func_020450F0(layer,x,y,width,height,palette,1);
    p->buffer=func_02045770(p->window);
    p->copy=p->window;
    p->state=0;
    func_02043B5C(p->buffer,3);
    window=p->window;
    func_02045334(window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730(window));
}

unsigned func_021BC614(unsigned short *p,unsigned manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag){Position pos;pos.x=x;pos.y=y;pos.z=z;pos.b=b;pos.a=a;return (unsigned)func_0204B294((void *)manager,r[1],r[0],r[2],&pos,flag,*p);}
