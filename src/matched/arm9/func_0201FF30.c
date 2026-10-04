/*
 * function: func_0201FF30
 * address:  0x0201FF30
 * packet:   pkt_0201FF30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A7390     0x020A7390  data  a1
 */
#include "../include/Obj11266.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    void *arr;
    void *unk04;
    void *unk08;
    void *unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u8 pad1C[0x28 - 0x1C];
    void *f28;
    u8 pad2C[0x34 - 0x2C];
    u8 f34lo : 4;
    u8 f34hi : 4;
    u8 f35lo : 4;
    u8 f35hi : 4;
    u8 f36 : 6;
    u8 f36top : 2;
    u8 f37;
    u8 f38 : 7;
    u8 f38top : 1;
    u8 pad39[0x3C - 0x39];
    u32 f3C;
    u16 f40;
    u16 f42;
    u8 f44;
    u8 f45;
    u8 f46;
    u8 f47;
    u16 f48;
};

struct Src {
    u32 w[13];
};

extern char g_020A7390[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct CharBuf;
extern void *func_02020D18(u32 heap);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202055C(struct Obj *obj, u16 row, u16 col, u16 n, u32 flag);
extern void func_020206C0(struct Obj *o);
extern void func_02020A34(struct Obj *obj, void *arg1);

struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap)
{
    struct Obj *obj;
    int i;
    u32 *d;
    u32 *s;

    obj = (struct Obj *)func_02030734(heap, 0x50, 1, g_020A7390, 0x69);
    *(struct Src *)obj = *src;
    obj->f3C = (u32)func_02020D18(heap);
    obj->f40 = a;
    obj->f42 = b;
    obj->f44 = 0;
    obj->f45 = 0;
    obj->f46 = 0xFF;
    obj->f47 = 0;
    obj->f48 = (u16)heap;
    obj->f34lo = obj->f17hi;
    obj->f34hi = obj->f18lo;
    obj->f35lo = obj->f18hi;
    obj->f36 = (u8)obj->f1Alo;
    obj->f38 = (u8)obj->f1Amid2;
    obj->f38top = 0;
    if (obj->count < obj->rows) {
        obj->rows = obj->count;
    }
    while (*(u32 *)((u8 *)obj->arr + (obj->f40 + obj->f42) * 8 + 4) == (u32)-3) {
        obj->f42++;
    }
    {
        u8 *q = (u8 *)obj->f28;
        ((struct Obj11266 *)q)->f0 = (u32)obj->unk0C;
        q[4] = 0;
    }
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)obj->unk0C)), obj->f18lo);
    func_0202055C(obj, obj->f40, 0, obj->rows, 1);
    func_020206C0(obj);
    func_02020A34(obj, (void *)1);
    return obj;
}
