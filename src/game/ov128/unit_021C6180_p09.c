/*
 * file:     unit_021C6180_p09.c
 * unit:     yes
 * function: func_021C8470, func_021C84E8, func_021C8548, func_021C8574, func_021C85A4, func_021C860C, func_021C867C, func_021C873C, func_021C875C, func_021C8784, func_021C87A0, func_021C87B0
 * address:  0x021C8470
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   d_021CA68C 0x021CA68C data a4
 *   func_021C8388 0x021C8388 thumb ov128
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C6B50 0x021C6B50 thumb ov128
 *   func_021C6E3C 0x021C6E3C thumb ov128
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021C88C0 0x021C88C0 thumb ov128
 *   func_021C899C 0x021C899C thumb ov128
 *   func_021CA2DC 0x021CA2DC thumb ov128
 *   func_021C8904 0x021C8904 thumb ov128
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   func_021C7600 0x021C7600 thumb ov128
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021CA42C 0x021CA42C thumb ov128
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   d_021CA6C8 0x021CA6C8 data a2
 */
#include "../../matched/include/Obj06478.h"
#include "../../matched/include/Obj23084.h"
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj14039.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj03811.h"
#include "../../matched/include/Obj23087.h"
#include "../../matched/include/Obj23088.h"
#include "../../matched/include/Obj14040.h"

struct TaskMenu;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
struct Actor;
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed short s16;

typedef unsigned long long u64;

typedef unsigned short u16;

typedef signed char s8;

typedef signed int s32;

typedef struct Point {s16 x,y;} Point;

typedef struct Entry {s16 x,y; s16 rest[3];} Entry;

extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern u8 func_020355C4(void);
extern unsigned long long func_021C8388(s16 *p, u8 *q);
extern void func_021C6BCC(u8 *p, u8 *q, int idx, unsigned heap);
extern void func_021C6B50(void **p, unsigned long long value);
extern void *func_021C6E3C(void *,void **,int,int);
extern void func_021CA40C(char *p, int n);
extern void func_021C88C0(s16 *, void *, u8 *);
extern void func_021C899C(char *p, char *q, void *r, void *s, int t, char *table, int page, u16 heap);
extern void func_021CA2DC(char *p);
extern void func_021C8904(char *p, char *q, void *r, void *s, int t, char *table, int page, u16 heap);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,int,int,void *,void *,void *,void *,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CA3E8(int);
extern int func_021C7600(void *,int *);
extern void func_0201F7A8(void *,u32);
extern void func_021CA42C(char *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_020061E4(u32 a);
int func_021C8470(u8 *p, int *a, void *b);
int func_021C84E8(u8 *p, u8 *a, u8 *b, int c);
void func_021C8548(s16 *p,u8 *q,u8 *r,u16 heap);
int func_021C8574(u8 *p,int *q,u8 *r,int heap);
void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c);
void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c);
void func_021C8660(void);
void func_021C8664(void);
void func_021C8668(u8 *p, u8 *a, int n);
void func_021C867C(u8 *p, u8 *a, int n, int heap);
int func_021C873C(void *p,int *state,u8 *q);
void func_021C875C(char *p,char *q);
void func_021C8784(char *p);
int func_021C87A0(s16 *p);
void func_021C87B0(u8 *p, u8 *a1);
extern const int d_021CA68C[][8];
extern const Entry d_021CA6C8[];

int func_021C8470(u8 *p, int *a, void *b)
{
    int n;
    int result;
    func_02027974(((struct Obj06478 *)p)->f194);
    if (func_020279E8(((struct Obj06478 *)p)->f194) == 1) {
        n = func_02027A04(*(u8 * *)&((struct Obj06478 *)p)->f194);
        func_02027858(((struct Obj06478 *)p)->f194);
    } else return 8;
    if (n == 3) {
        *a = func_020355C4();
        result = 2;
    } else {
        *a = func_020355C4();
        result = d_021CA68C[((struct Obj06478 *)p)->f198][n * 2];
    }
    if (result == 2) func_021C875C((char *)p, b);
    else if (result == 9 || result == 12) func_021C875C((char *)p, b);
    else func_021C8784((char *)p);
    return result;
}

int func_021C84E8(u8 *p, u8 *a, u8 *b, int c)
{
    u64 value = func_021C8388((s16 *)p, a);
    func_021C6BCC(b, a, (a + func_021C87A0((s16 *)p))[0x18], c);
    if (value != 0) {
        func_021C6B50((void **)b, value);
        func_021C867C(p, b, 0x3c, c);
    } else {
        func_021C867C(p, b, 0x44, c);
    }
    return 1;
}

void func_021C8548(s16 *p,u8 *q,u8 *r,u16 heap) {func_021C6BCC(r,q,*(u8 *)(q+24+func_021C87A0(p)),heap);func_021C867C((u8 *)p,r,57,heap);}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021C8574(u8 *p,int *q,u8 *r,int heap) {if(func_021C873C(p,q,r)==0)return 0;((struct Obj23084 *)p)->f194=func_021C6E3C(p+376,(void **)(p+400),0,heap);return 1;}

void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c)
{
    int offset;
    u8 *base;
    if (n == 0) {
        ((struct Obj00179 *)p)->f0 = x;
        ((struct Obj00179 *)p)->f4 = y;
        func_021CA40C((char *)p, x);
    }
    offset = n * 0x4c;
    base = p + 12;
    func_021C88C0((s16 *)(base + offset), b, b + 0x16c);
    func_021C899C((char *)(base + offset), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    func_021CA2DC((char *)p);
}

void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    ((struct Obj00179 *)p)->f4 = y;
    ((struct Obj00179 *)p)->f0 = x;
    func_021CA40C((char *)p, x);
    func_021C88C0((s16 *)(p + 12), b, b + 0x16c);
    func_021C8904((char *)(p + 12), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    func_021CA2DC((char *)p);
}

void func_021C8660(void) {}

void func_021C8664(void) {}

void func_021C8668(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    ((struct Obj14039 *)p)->f102 = n;
    ((struct Obj14039 *)p)->f100 = 0;
}

void func_021C867C(u8 *p, u8 *a, int n, int heap)
{
    void *text;
    void *q;
    if (((struct Obj00329 *)a)->f2C) {
        func_0201CE48(((struct Obj00329 *)a)->f2C);
        ((struct Obj00329 *)a)->f2C = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03811 *)p)->f108),15);
    text=func_020457B0(128,heap);
    func_02045CAC(((struct Obj00329 *)a)->f4,n,text);
    func_0201F250(((struct Obj00329 *)a)->f0,((struct Obj03811 *)p)->f110,text);
    ((struct Obj00329 *)a)->f2C=func_0201CCE4(((struct Obj03811 *)p)->f108,0,0,((struct Obj03811 *)p)->f110,((struct Obj00329 *)a)->f17C,(void *)func_02012FFC(),((struct Obj00329 *)a)->f28,10,((struct Obj00329 *)a)->f180,0);
    func_0201F73C(((struct Obj03811 *)p)->f108,2,70,11);
    q=((struct Obj03811 *)p)->f108;
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    func_02045808(text);
    func_021CA3E8(0);
}

int func_021C873C(void *p,int *state,u8 *q) {if(func_021C7600(((struct Obj23087 *)q)->f2C,(int *)(q+48))==0) {*state=0;return 1;}return 0;}

void func_021C875C(char *p,char *q) {func_0201F7A8(((struct Obj23088 *)p)->f108,1);func_021CA42C(q);func_021CA2DC(p);func_021CA3E8(1);}


/*
 * Addresses are Black-image addresses.
 */
void func_021C8784(char *p)
{
    func_02043B5C(func_02045770(((struct Obj14040 *)p)->f108), 0xf);
    func_02045334(((struct Obj14040 *)p)->f108);
}


int func_021C87A0(s16 *p)
{
    int a = p[0] * 8;

    return a + p[2];
}

static inline void Outside(int wnd,int effect)
{
    u32 tmp=(*(volatile u16 *)0x0400004A & ~0x3F) | wnd;
    if(effect) tmp |= 0x20;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}

/*
 * volatile: 021C8808, 021C8814 read WINOUT; 021C8828 reads DISPCNT.
 */
void func_021C87B0(u8 *p, u8 *a1)
{
    Point pos;
    func_0204B3DC(((struct Obj00179 *)p)->f1A0,1);
    func_0204B878(((struct Obj00179 *)p)->f1A0,1);
    func_0204B9A0(((struct Obj00179 *)p)->f1A0);
    *(int *)&((struct Obj00179 *)p)->f1A8=0;
    func_0204B92C(((struct Obj00179 *)p)->f1A0,1);
    pos.x=d_021CA6C8[*(s16 *)(p + 4)].x * 8;
    pos.y=d_021CA6C8[*(s16 *)(p + 4)].y * 8 - 4;
    func_0204B404(((struct Obj00179 *)p)->f1A0,(const struct Vec2 *)(&pos),0);
    *(volatile u16 *)0x0400004A=(u16)((*(volatile u16 *)0x0400004A & ~0x3F00) | 0x700);
    Outside(31,1);
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0xe000) | 0x8000;
    func_020061E4(0x668);
}
