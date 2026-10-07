/*
 * file:     unit_021B7560_p03.c
 * unit:     yes
 * function: func_021B7C04, func_021B7C0C, func_021B7C14, func_021B7C1C, func_021B7C20, func_021B7C88, func_021B7CB0, func_021B7CBC, func_021B7CC0, func_021B7CC4, func_021B7CC8, func_021B7D38, func_021B7DA8, func_021B7DC4, func_021B7DFC, func_021B7E60
 * address:  0x021B7C04
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A600 0x0204A600 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C724 0x0201C724 thumb
 */
#include "../../matched/include/Obj07975.h"
#include "../../matched/include/Obj22143.h"
#include "../../matched/include/Obj22144.h"
#include "../../matched/include/Obj22145.h"
#include "../../matched/include/Obj22146.h"
#include "../../matched/include/Obj03230.h"
#include "../../matched/include/Obj13726.h"
#include "../../matched/include/Obj06365.h"
#include "../../matched/include/Obj22147.h"
#include "../../matched/include/Obj05269.h"
#include "../../matched/include/Obj02809.h"

struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct PrintSys;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct StrObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct {
    u32 win;     /* +0x00 */
    u32 win2;    /* +0x04 */
    u8  f8;      /* +0x08 */
    u8  pad9[3];
    u32 que;     /* +0x0C */
    u16 chr;     /* +0x10 */
} Rec;

extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_0201ED04(void *);
extern void func_02045C04(struct Rec *);
extern void func_0201C4C0(unsigned);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern int func_0201C6C4(int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021B7C04(void);
void func_021B7C0C(void *p);
u32 func_021B7C14(u8 *p, int i);
unsigned func_021B7C1C(unsigned *p);
void func_021B7C20(unsigned *p,u16 heap);
void func_021B7C88(void *p);
void func_021B7CB0(u8 *p);
int func_021B7CBC(void *p);
int func_021B7CC0(void *p);
int func_021B7CC4(void *p);
void func_021B7CC8(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap);
void func_021B7D38(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap);
void func_021B7DA8(void *p);
int func_021B7DC4(unsigned char *p,unsigned char *q);
void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y);
void func_021B7E60(u8 *p, void *q, int n);

 void func_021B7C04(void) { func_0204A600(); }

void func_021B7C0C(void *p) { func_0204A648(); }


u32 func_021B7C14(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0x10);
}

unsigned func_021B7C1C(unsigned *p) { return *p; }

void func_021B7C20(unsigned *p,u16 heap) {
 func_02082BCC(p,0,0x10);
 func_0201DD60();
 p[0]=(unsigned int)func_0201D7EC(0x17,0,0,0,heap);
 p[2]=func_0201C440((void *)heap);
 p[1]=(unsigned int)func_02045B38(0,2,0x31,heap);
 p[3]=(unsigned int)func_0201EC64(heap);
 func_02049B40(0x17,5,4,0,0x20,heap);
 func_02049B40(0x17,5,0,0,0x20,heap);
}

void func_021B7C88(void *p) { func_0201ED04(((struct Obj07975 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07975 *)p)->f4); func_0201C4C0(((struct Obj07975 *)p)->f8); func_0201D83C(((struct Obj07975 *)p)->f0); func_02082BCC(p,0,16); }

void func_021B7CB0(u8 *p) { func_0201C4E4((struct PrintSys *)(((struct Obj22143 *)p)->f8)); }


/*
 * three int getters at +0, +8, +4.
 */
int func_021B7CBC(void *p)
{
    return ((struct Obj22144 *)p)->f0;
}


int func_021B7CC0(void *p)
{
    return ((struct Obj22145 *)p)->f8;
}


int func_021B7CC4(void *p)
{
    return ((struct Obj22146 *)p)->f4;
}

/*
 * lever: sibling of func_021B7D38 (same window builder, slot 1, chr 0xF); narrow u8 c parameter places its reload immediately before the call.
 */
void func_021B7CC8(Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    p->chr = 0xF;
    p->win = func_020450F0(a, b, c, d, e, f, 1);
    p->que = (int)func_020457B0(255, heap);
    p->win2 = p->win;
    p->f8 = 0;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->win)), p->chr);
    win = p->win;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}

void func_021B7D38(u8 *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g, u8 h, u16 heap)
{
    int win;
    func_02082BCC(p, 0, 20);
    ((struct Obj03230 *)p)->f10 = g;
    ((struct Obj03230 *)p)->f0 = func_020450F0(a, b, c, d, e, f, h);
    ((struct Obj03230 *)p)->fC = (int)func_020457B0(255, heap);
    ((struct Obj03230 *)p)->f4 = ((struct Obj03230 *)p)->f0;
    p[8] = 0;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03230 *)p)->f0)), ((struct Obj03230 *)p)->f10);
    win = ((struct Obj03230 *)p)->f0;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}

void func_021B7DA8(void *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13726 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13726 *)p)->f0); func_02082BCC(p,0,20); }

int func_021B7DC4(unsigned char *p,unsigned char *q) { int a=((struct Obj22147 *)q)->f8; if (p[8]) { if (!func_0201C6C4(a,(int)func_02045770((struct Descriptor *)((struct Obj06365 *)p)->f4))) { func_02045334((struct Descriptor *)((struct Obj06365 *)p)->f4); p[8]=0; } } if (!p[8]) return 1; return 0; }

void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y)
{
    int a, b, c;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj05269 *)p)->f0)), ((struct Obj05269 *)p)->f10);
    func_02045CAC((struct MsgBank *)a, n, (void *)(((struct Obj05269 *)p)->fC));
    func_0201C6FC((struct PrintSys *)b, (int)func_02045770((struct Descriptor *)((struct Obj05269 *)p)->f4), (s16)x, (s16)y, (void *)(((struct Obj05269 *)p)->fC), (int)c);
    p[8] = 1;
}

void func_021B7E60(u8 *p, void *q, int n)
{
    int a, b, c;
    u16 x, y;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02809 *)p)->f0)), ((struct Obj02809 *)p)->f10);
    func_02045CAC((struct MsgBank *)a, n, (void *)(((struct Obj02809 *)p)->fC));
    x = func_02045738((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    y = func_02045740((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    x -= (u16)(func_0201D304((struct StrObj *)(((struct Obj02809 *)p)->fC), c, 0) >> 1);
    y -= (u16)(func_0201D42C((struct StrObj *)(((struct Obj02809 *)p)->fC), (void *)c) >> 1);
    func_0201C6EC((struct PrintSys *)b);
    func_0201C724((void *)b, (int)func_02045770((struct Descriptor *)((struct Obj02809 *)p)->f4), (s16)x, (s16)y, (int)(((struct Obj02809 *)p)->fC), (int)c, (int)0x3dc1);
    p[8] = 1;
}
