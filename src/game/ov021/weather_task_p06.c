/*
 * file:     weather_task_p06.c
 * unit:     yes
 * function: func_021A28CC, func_021A2924, func_021A2968, func_021A2970, func_021A2978, func_021A2994, func_021A29A8, func_021A29F4, func_021A2A18, func_021A2A68
 * address:  0x021A28CC
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
 *   func_02030734  0x02030734  arm
 *   func_021A2BD4  0x021A2BD4  thumb  ov021
 *   d_021DDE80     0x021DDE80  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_021A2C10  0x021A2C10  thumb  ov021
 *   func_021A2BB8  0x021A2BB8  thumb  ov021
 *   func_021A25CC  0x021A25CC  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021A1698  0x021A1698  thumb  ov021
 *   func_021A16D4  0x021A16D4  thumb  ov021
 *   func_021A16D8  0x021A16D8  thumb  ov021
 *   d_021EE710     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *   func_021A1680  0x021A1680  thumb  ov021
 */
#include "../../matched/include/Obj19755.h"
#include "../../matched/include/Obj12085.h"

typedef struct {
    char pad0[2];
    unsigned short n;
    char pad4[0x24];
    int f28;
} Hdr_021A28CC;

typedef struct {
    int f0;
    char pad4[0x18];
    int pad1c;
    Hdr_021A28CC *hdr;
    char pad24[4];
    char sub[0x14];
    int f3c;
} Obj_021A28CC;

typedef struct {
    char pad0[2];
    unsigned short n;
} Hdr_021A2924;

typedef struct {
    char pad0[0x20];
    Hdr_021A2924 *hdr;
    char pad24[0x18];
    void *f3c;
} Obj_021A2924;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    char pad8[8];
    int f10;
} Obj_021A29A8;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
} Src;

typedef struct {
    char pad0[8];
    unsigned char b8;
    char pad9[3];
} Buf;

typedef struct {
    char pad0[4];
    int f4;
    int f8[2];
    int f10;
} Obj;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
void func_021A2BD4(void *p, void *o, void *s, int a, int b);
unsigned int func_020307B0(void *p);
void func_021A2C10(u8 *p);
void func_021A2BB8(u32 a);
void func_021A25CC(u8 *p);
void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(u32 v);
int func_0204A6C8(int a, int b, int c, int d, int e);
int func_0204AC18(int a, int b, int c, int d, int e, int f, int g);
s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_0204A8D4(u32 i);
void func_0204ADA4(u32 i);
void func_0204AFD8(u32 i);
void func_02082D44(void *src, void *dst, int n);
int func_021A1698(unsigned int a, int b, void *c, int d);
void func_021A16D4(u8 *p, u32 v);
void func_021A16D8(u8 *p, u8 v);
void func_021A1680(u8 *p);
void func_021A28CC(Obj_021A28CC *o, int heap);
void func_021A2924(Obj_021A2924 *o);
void func_021A2968(u8 *p);
u8 func_021A2970(u8 *p);
void func_021A2978(u8 *p, u16 *q, u32 c, u32 a3);
void func_021A2994(u8 *p);
void func_021A29A8(Obj_021A29A8 *o, Src *s, int heap);
void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3);
void func_021A2A18(Obj *o, int idx, void *p, void *src, unsigned short x);
void func_021A2A68(u8 *p, int i, int x);
extern int d_021DDE80;
extern unsigned char d_021EE710[12];
extern unsigned char d_021EE710b[12];



void func_021A28CC(Obj_021A28CC *o, int heap)
{
    int i;

    o->f3c = (int)func_02030734(heap, o->hdr->f28, 1, (const char *)&d_021DDE80, 0x874);
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2BD4((char *)o + 0x74 + i * 0x38, o, o->sub, o->f0, heap);
        }
    }
}



void func_021A2924(Obj_021A2924 *o)
{
    int i;

    if (o->f3c != 0) {
        func_020307B0(o->f3c);
        o->f3c = 0;
    }
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2C10((u8 *)((char *)o + 0x74 + i * 0x38));
            func_021A2BB8((u32)((char *)o + 0x74 + i * 0x38));
        }
    }
    func_021A25CC((u8 *)o);
}



/*
 * Unlabelled leaf (listed as .word data): sets the byte at offset 0x27.
 * Called by func_021A1E08.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2968(u8 *p)
{
    p[0x27] = 1;
}



/*
 * Unlabelled leaf (listed as .word data): reads the byte at offset 0x27.
 * Called by func_021A1E08.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021A2970(u8 *p)
{
    return p[0x27];
}



void func_021A2978(u8 *p, u16 *q, u32 c, u32 a3)
{
    if (q[1] != 0 || q[2] != 0)
        ((struct Obj19755 *)p)->f10 = func_020490F4(q[0], c);
}



/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2994(u8 *p)
{
    u32 v = ((struct Obj12085 *)p)->f10;
    if (v != 0) {
        func_02049238(v);
        ((struct Obj12085 *)p)->f10 = 0;
    }
}



void func_021A29A8(Obj_021A29A8 *o, Src *s, int heap)
{
    if (s->f2 != 0) {
        o->f2 = func_0204A6C8(o->f10, s->f6, 0, 0, heap);
        o->f4 = func_0204AC18(o->f10, s->f8, 0, 0, 0, 1, heap);
        o->f6 = func_0204AF28((void *)o->f10, s->fa, s->fc, heap);
        o->f0 = 1;
    }
}



void func_021A29F4(u16 *p, u32 a1, u32 a2, u32 a3)
{
    if (p[0] != 0) {
        func_0204A8D4(p[1]);
        func_0204ADA4(p[2]);
        func_0204AFD8(p[3]);
        p[0] = 0;
    }
}



/*
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */
void func_021A2A18(Obj *o, int idx, void *p, void *src, unsigned short x)
{
    func_02082D44(src, d_021EE710, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    func_021A1698((unsigned int)p, o->f10, d_021EE710, x);
    func_021A16D4(p, 0);
    func_021A16D8(p, 0x20);
    o->f8[idx] = 1;
}



void func_021A2A68(u8 *p, int i, int x)
{
    u32 *s = (u32 *)(p + 8);

    if (s[i] != 0) {
        func_021A1680((u8 *)x);
        s[i] = 0;
    }
}
