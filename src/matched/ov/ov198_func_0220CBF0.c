/*
 * function: func_0220CBF0
 * address:  0x0220CBF0
 * packet:   pkt_0220CBF0
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb
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
#include "../include/Obj01581.h"
#include "../include/Obj25154.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int   func_022110D4(u8 *p, int i);
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *a);
extern void  func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
struct StrObj;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 func_02045738(struct Descriptor *p);

void func_0220CBF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2e);
    x = ((struct Obj01581 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01581 *)p)->f1FF8);
    func_0201C724(x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01581 *)p)->f1FFC = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2f);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01581 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01581 *)p)->f1EA4, 0, ((struct Obj25154 *)elem)->fC, 3, 0, 1);
    func_0201F250(((struct Obj01581 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01581 *)p)->f1FB0) << 3) - b;
    d = ((struct Obj01581 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01581 *)p)->f1FB0);
    func_0201C724(d, e, c, 0, h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01581 *)p)->f1FB4 = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}
