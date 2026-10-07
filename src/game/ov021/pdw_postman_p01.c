/*
 * file:     pdw_postman_p01.c
 * unit:     yes
 * function: func_021B7364, func_021B7390, func_021B73B8, func_021B7400, func_021B7494
 * address:  0x021B7364
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   d_021D99E8     0x021D99E8  data  a2
 *   d_021D99D4     0x021D99D4  data  a2
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021D99DE     0x021D99DE  data   ov021  a1
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   d_021DE288     0x021DE288  data   ov021  a1
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj04890.h"

struct Fx;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Obj;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02190728(void *a);
extern void func_02190788(u8 *p);
int func_021B7364(void *a, void *b);
int func_021B7390(u32 a, int b);
int func_021B73B8(u32 a, u32 b);
Obj *func_021B7400(u32 a, u32 b, int c);
int func_021B7494(void *a);
extern u16 d_021D99E8[];
extern u16 d_021D99D4[];
extern u8 d_021D99DE[];
extern u8 d_021DE288[];


int func_021B7364(void *a, void *b)
{
    u32 v;
    u16 *p;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    if (v >= 11) {
        v = 0;
    }
    *p = d_021D99E8[v];
    return 0;
}


int func_021B7390(u32 a, int b)
{
    u32 i;
    u16 k;

    k = (a << 8) | b;
    for (i = 0; i < 5; i++) {
        if (k == d_021D99D4[i]) {
            return 1;
        }
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B73B8(u32 a, u32 b)
{
    u16 *out;
    void *h;
    u32 x;
    int y;

    out = func_02159AE8((void *)a, (void *)b);
    h = func_0215A5E4((void *)b);
    x = func_021690D0((int)h);
    y = func_021690E0((int)h);
    if (func_021B7390(x, y) == 1)
        *out = 10;
    else
        *out = d_021D99DE[y % 10];
    return 0;
}


Obj *func_021B7400(u32 a, u32 b, int c)
{
    u32 heap;
    Obj *o;
    int line;
    int sz;

    heap = func_02188C84((u8 *)a);
    line = 0x73;
    o = func_02030734(heap, 0x28, 1, (const char *)d_021DE288, line);
    o->f0 = heap;
    o->f4 = a;
    o->f24 = b;
    o->f20 = c;
    line += 0xc8;
    o->f8 = (u32)func_02045B38(0, 3, line, heap);
    o->f14 = (u32)func_0201EC64(heap);
    o->f18 = (u32)func_020457B0(0x80, heap);
    o->f1C = (u32)func_020457B0(0x80, heap);
    sz = (c * 14 + 7) & ~7;
    o->fC = (u32)func_02190708((struct Fx *)func_02188C54((u8 *)a), o->f8, 1, 1, 0x15, (u16)(sz / 8));
    return o;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7494(void *a)
{
func_02190788((u8 *)(((struct Obj04890 *)((u8 *)(a)))->fC));
func_02190728((void *)(((struct Obj04890 *)((u8 *)(a)))->fC));
func_020409B4(1);
func_02045808((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f18));
func_02045808((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f1C));
func_0201ED04((struct WordSet *)(((struct Obj04890 *)((u8 *)(a)))->f14));
func_02045C04((struct Rec *)(((struct Obj04890 *)((u8 *)(a)))->f8));
return func_020307B0(a);
}
