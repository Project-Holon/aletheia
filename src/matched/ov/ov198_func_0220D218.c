/*
 * function: func_0220D218
 * address:  0x0220D218
 * packet:   pkt_0220D218
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 */
#include "../include/Obj02534.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void  func_0201C724(u32 a, u32 b, s16 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
struct StrObj;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 func_02045738(struct Descriptor *p);

void func_0220D218(char *p, int a1, u32 a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 <= 1) {
        u32 f;

        t = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w = (func_02045738((void *)handle) << 3) - w;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724(f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w, 0,
                      (u32)t, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3b);
        h = (u32)func_020457B0(8, *(u16 *)(((struct Obj02534 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02534 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02534 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w2 = (func_02045738((void *)handle) << 3) - w0;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724(f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), w2, 0,
                      h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t2);
        func_02045808((void *)h);
    }
}
