/*
 * file:     btl_rec_sel_p02.c
 * unit:     yes
 * function: func_021B9EFC, func_021B9F10, func_021B9F18, func_021B9F24, func_021BA018, func_021BA058
 * address:  0x021B9EFC
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB0C4 0x021BB0C4 thumb ov214
 *   func_02030734 0x02030734 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   d_021BB658 0x021BB658 data a1
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02035630 0x02035630 arm
 */
#include "../../matched/include/Obj14698.h"
#include "../../matched/include/Obj00636.h"
#include "../../matched/include/Obj14699.h"

struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Rec3;
struct S02031140;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct C {u16 heap; u8 pad[0x66]; void *task,*win1,*win0,*font; u32 f78;};

struct Palette {u16 a,b,c;};

extern void func_021BB0C4(char *);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern void func_02040E78(u32,void*,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void *func_0201F5DC(void*,u32,u32,u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02031140(struct S02031140 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *);
extern u8 func_02035630(void);
void func_021B9EFC(int *out, int a, int b, int c, int d);
void func_021B9F10(int unused, char *b, int c, int d);
void func_021B9F18(void *unused, char *p);
void func_021B9F24(void *unused, struct C *p);
void func_021BA018(int unused,char*p);
void func_021BA058(int unused,char *p);
extern const char d_021BB658[];


void func_021B9EFC(int *out, int a, int b, int c, int d)
{
    *out = 4;
    func_021B9F10(a, (char *)b, c, d);
}


void func_021B9F10(int unused, char *b, int c, int d)
{
    ((struct Obj14698 *)b)->f40 = c;
    ((struct Obj14698 *)b)->f44 = d;
}

/*
 * blocker-leaf: sole callback blocker of ov214 021B95A0; no existing source/unit/shard, parent ownership cleared.
 */
void func_021B9F18(void *unused, char *p)
{
    func_021BB0C4(p);
}

static inline void init_palette(struct Palette *pal)
{
    pal->a=0x294b; pal->b=0x5694; pal->c=0x7fff;
}

void func_021B9F24(void *unused, struct C *p)
{
    struct Palette *pal = func_02030734(p->heap,6,1,d_021BB658,0x5e9);
    init_palette(pal);
    func_02040E78(2,pal,6,0x13a);
    func_020307B0(pal);
    func_02049B40(0x17,5,0,0x180,0x20,p->heap);
    p->win0=(void *)func_020450F0(1,0,0,1,1,9,0);
    func_02043B5C(func_02045770(p->win0),0);
    func_02045334(p->win0);
    p->win1=(void *)func_020450F0(1,1,0x13,0x1e,4,0xc,0);
    func_02043B5C(func_02045770(p->win1),0xf);
    func_02045334(p->win1);
    p->font=func_0201F5DC((void*)1,0xa,0,p->heap);
    p->task=func_0203101C(p->heap,p->heap,1,0);
    func_0201DD78(1,2,0xf);
    func_02041B6C(1);
    *(u32*)((u8*)p+0x5c)=0;
    *(u32*)((u8*)p+0x60)=0;
    *(u32*)((u8*)p+0x64)=0;
    p->f78=0;
}

void func_021BA018(int unused,char*p)
{
    if(*(void* *)&((struct Obj00636 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj00636 *)p)->f5C);
    if(*(void* *)&((struct Obj00636 *)p)->f78)func_02045808(*(void* *)&((struct Obj00636 *)p)->f78);
    func_02031140(*(void* *)&((struct Obj00636 *)p)->f68);
    func_0203FB44(1,(u16)(((struct Obj00636 *)p)->f74),(u16)(((struct Obj00636 *)p)->f74>>16));
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f6C);
    func_020452E8(*(void* *)&((struct Obj00636 *)p)->f70);
}

/*
 * Tail: two zero alignment bytes at 021BA072.
 */
void func_021BA058(int unused,char *p){func_020310C4(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);if(func_02035630()==30)func_020310C4(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);}
