/*
 * file:     intro_cmd_p04.c
 * unit:     yes
 * function: func_021BF030, func_021BF080, func_021BF094, func_021BF0A0, func_021BF1A4
 * address:  0x021BF030
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C09D8 0x021C09D8 data a4
 *   d_021C0AB8 0x021C0AB8 data a4
 *   site 0x021C0AE4 data a1
 *   func_02030734 0x02030734 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 *   func_0202EF60 0x0202EF60 thumb
 *   func_021BF580 0x021BF580 thumb ov204
 *   func_02028604 0x02028604 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj14620.h"
#include "../../matched/include/Obj01008.h"
#include "../../matched/include/Obj01292.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
struct S02031140;
struct Rec3;
struct PrintSys;
struct Rec;
typedef struct Command { unsigned tag; unsigned data[5]; } Command;

typedef struct Slot { unsigned data[3]; } Slot;

typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void *func_02028590(u32,u32,u32,u32);
extern struct Obj *func_0202EF60(u32 heap);
extern void func_021BF580(u8 *p);
extern int func_02028604(int);
extern void func_02045808(struct U16Vec *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_0201CE48(struct Rec3 *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_020307B0(void *p);
int func_021BF030(State *p);
void func_021BF080(char *p, u8 i);
void*func_021BF094(u32 n);
char *func_021BF0A0(u16 heap);
void func_021BF1A4(char *p);
extern const u32 d_021C0AB8[];
extern const char site[];

extern int (*const d_021C09D8[])(void *, Slot *, void *);

int func_021BF030(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!d_021C09D8[q->tag](p, &p->slots[i], q->data)) result = 1;
            else func_021BF080((char *)p, i);
        }
    }
    return result;
}


void func_021BF080(char *p, u8 i)
{
    char *q;

    *(int *)(p + i * 4 + 0x20) = 0;
    q = p + i * 0xC;
    ((struct Obj14620 *)q)->f40 = 0;
    ((struct Obj14620 *)q)->f44 = 0;
}

void*func_021BF094(u32 n){return *(void**)((u32)d_021C0AB8+n*4);}

char *func_021BF0A0(u16 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    ((struct Obj01008 *)p)->f0=heap;
    ((struct Obj01008 *)p)->f8=func_0201EC64(heap);
    ((struct Obj01008 *)p)->f4=(void *)func_0201C440((void *)heap);
    ((struct Obj01008 *)p)->f18=func_0203101C(((struct Obj01008 *)p)->f0,((struct Obj01008 *)p)->f0,2,0);
    func_02049B40(23,5,0,320,32,heap);
    func_0201F5BC(1,7,9,0,heap);
    func_0201F5BC(1,16,8,1,heap);
    ((struct Obj01008 *)p)->f10=func_0201D7EC(23,0,1,0,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f3C=func_020457B0(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f40=func_020457B0(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f38=(void *)func_020450F0(1,22,13,9,4,10,1);
    func_02043B5C(func_02045770(((struct Obj01008 *)p)->f38),0);
    obj=((struct Obj01008 *)p)->f38;
    func_02045334(obj);func_02045374(obj);func_02041B6C(func_02045730(obj));
    ((struct Obj01008 *)p)->f1C=(void *)func_020450F0(1,1,19,30,4,10,1);
    ((struct Obj01008 *)p)->f20=func_02028590(15,1,1,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f44=func_0202EF60(((struct Obj01008 *)p)->f0);
    return p;
}

void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    func_02028604(((struct Obj01292 *)p)->f20);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    func_0201D83C(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    func_02031140(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    func_0201C4C0(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        func_02045C04(((struct Obj01292 *)p)->fC);
    func_0201ED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}
