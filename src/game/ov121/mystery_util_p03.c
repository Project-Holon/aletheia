/*
 * file:     mystery_util_p03.c
 * unit:     yes
 * function: func_021D98E0, func_021D98E8, func_021D98F4, func_021D9960, func_021D9974, func_021D9994, func_021D99A4, func_021D9A40, func_021D9A58, func_021D9A64, func_021D9AC8, func_021D9B28, func_021D9B2C, func_021D9B34, func_021D9B9C
 * address:  0x021D98E0
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
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021D9580 0x021D9580 thumb ov121
 *   d_021DF574 0x021DF574 data a4
 *   d_021DF58C 0x021DF58C data a4
 *   d_021DF580 0x021DF580 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02050BE8 0x02050BE8 arm
 *   func_02047970  0x02047970  arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   func_020452E8  0x020452E8  arm
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021D9BC0 0x021D9BC0 thumb ov121
 *   func_02045838 0x02045838 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj13948.h"
#include "../../matched/include/Obj10413.h"
#include "../../matched/include/Obj01929.h"
#include "../../matched/include/Obj13950.h"
#include "../../matched/include/Obj22875.h"
#include "../../matched/include/Obj01057.h"
#include "../../matched/include/Obj22876.h"
#include "../../matched/include/Obj02179.h"
#include "../../matched/include/Obj08092.h"

struct Light;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct MsgBank;
struct PrintSys;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short s16;

typedef struct { int x; int y; } Pair;

extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021D9580(void);
extern void func_02046440(int, int, int, int, int, u32, void (*)(void *));
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_02047964(void *);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02050BE8(void);
extern void func_02047970(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern void *func_020457B0(u32, u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_020456F8(struct Descriptor *d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D9BC0(void *, int, Pair *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02041B6C(unsigned);
void func_021D98E0(void *a0);
void func_021D98E8(void *a0);
unsigned func_021D98F0(unsigned *p);
void func_021D98F4(u32 *p, u32 heap);
void func_021D9960(char *p);
void func_021D9974(void **p);
void func_021D9994(void **p);
void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap);
void func_021D9A40(u8 *p);
void func_021D9A58(u8 *p);
void func_021D9A64(u8 *p, u16 a, int b, int c);
void func_021D9AC8(u8 *p, int a, int b);
void func_021D9B28(u8 *p,unsigned v);
void func_021D9B2C(char *p, u32 a, u32 b, int c);
int func_021D9B34(u8 *p);
void func_021D9B9C(u8 *p);
extern const u32 d_021DF574[];
extern const u32 d_021DF58C[];
extern const u32 d_021DF580[];
extern const char d_021DFBA0[];

void func_021D98E0(void *a0) { func_0204A600(); }

/*
 * note: tail wrapper plus unlabelled getter follower; seed 021D98F0.
 */
void func_021D98E8(void *a0) { func_0204A648(); }

unsigned func_021D98F0(unsigned *p) { return *p; }

void func_021D98F4(u32 *p, u32 heap)
{
    func_02046440(0, 1, 0, 1, 0, heap, (void (*)(void *))func_021D9580);
    p[0] = (u32)func_02048A24(2, 0x18000, -0x18000, -0x20000, 0x20000, 0x1000, 0x400000, 0,
                         d_021DF574, d_021DF58C, d_021DF580, heap);
    p[1] = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D9960(char *p)
{
    ((struct Obj13948 *)p)->f4 = 0;
    func_02048AC4(((struct Obj13948 *)p)->f0);
    func_02046788();
}

/*
 * note: two trailing zero alignment bytes.
 */
void func_021D9974(void **p) {
    if(((struct Obj10413 *)p)->f4) {
        func_02047964(((struct Obj10413 *)p)->f4);
        func_02048AD0(((struct Obj10413 *)p)->f0);
        func_020479D8();
        func_02050BE8();
    }
}


void func_021D9994(void **p)
{
    if (p[1])
        func_02047970();
}

void *func_021D99A4(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = func_02030734(heap, 0x28, 0, d_021DFBA0, 0x55);
    func_02082BCC(p, 0, 0x28);
    ((struct Obj01929 *)p)->f8 = h;
    ((struct Obj01929 *)p)->f14 = b;
    ((struct Obj01929 *)p)->f16 = 0x440;
    ((struct Obj01929 *)p)->f24 = a;
    ((struct Obj01929 *)p)->f10 = func_020457B0(0x200, heap);
    q = (void *)func_020450F0((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((struct Obj01929 *)p)->fC = q;
    ((struct Obj01929 *)p)->f0 = q;
    p[4] = 0;
    func_02043B5C(func_02045770(q), ((struct Obj01929 *)p)->f16 & 31);
    if (((struct Obj01929 *)p)->f24 == 0) {
        func_02045334(((struct Obj01929 *)p)->fC);
        func_02045374(((struct Obj01929 *)p)->fC);
        func_020409B4(func_02045730(((struct Obj01929 *)p)->fC));
    }
    return p;
}


void func_021D9A40(u8 *p)
{
    func_020452E8(((struct Obj13950 *)p)->fC);
    func_02045808(((struct Obj13950 *)p)->f10);
    func_020307B0(p);
}

void func_021D9A58(u8 *p) { func_020456F8(((struct Obj22875 *)p)->fC); }

/*
 * extent: two zero padding bytes at 0x021D9AC6.
 */
void func_021D9A64(u8 *p, u16 a, int b, int c)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045CAC((struct MsgBank *)a, b, ((struct Obj01057 *)p)->f10);
    func_021D9BC0(p, c, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), c, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}

/*
 * extent: two zero padding bytes at 0x021D9B26.
 */
void func_021D9AC8(u8 *p, int a, int b)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045838(((struct Obj01057 *)p)->f10, (struct U16Vec *)a);
    func_021D9BC0(p, b, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), b, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}

void func_021D9B28(u8 *p,unsigned v) { ((struct Obj22876 *)p)->f16=v; }


void func_021D9B2C(char *p, u32 a, u32 b, int c)
{
    *(u32 *)(p + 0x18) = a;
    *(u32 *)(p + 0x1c) = b;
    *(u32 *)(p + 0x20) = c;
}

int func_021D9B34(u8 *p)
{
    u32 q;
    if (((struct Obj02179 *)p)->f24 == 0) {
        q = ((struct Obj02179 *)p)->f8;
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj02179 *)p)->f0);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (func_0201C6C4((struct PrintSys *)(((struct Obj02179 *)p)->f8), (void *)((u32)func_02045770((struct Descriptor *)((struct Obj02179 *)p)->f0))) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}

void func_021D9B9C(u8 *p) {
    func_02045334(((struct Obj08092 *)p)->fC);
    if(((struct Obj08092 *)p)->f24==1) {
        func_02045374(((struct Obj08092 *)p)->fC);
        func_02041B6C(func_02045730(((struct Obj08092 *)p)->fC));
    }
}
