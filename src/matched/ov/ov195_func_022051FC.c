/*
 * function: func_022051FC
 * address:  0x022051FC
 * packet:   pkt_022051FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00844.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Tcbl;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_02028590(int, int, int, u16);
extern void func_02040588(u32 which, u32 enable);

void func_022051FC(int a, char *b)
{
    u32 p;

    func_02049B40(0x17, 5, 0, 0x20, 0x20, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f70 = func_020450F0(1, 0, 0, 1, 1, 1, 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f70)), 0);
    func_02045334((struct Descriptor *)((struct Obj00844 *)b)->f70);
    ((struct Obj00844 *)b)->f6C = func_020450F0(1, 1, 0x13, 0x1e, 4, 1, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f6C)), 0);
    p = ((struct Obj00844 *)b)->f6C;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    ((struct Obj00844 *)b)->f74 = (u32)func_0201F5DC((void *)1, 2, 0, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f78 = (u32)func_02045B38(0, 2, 0xac, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f7C = (u32)func_02045B38(0, 2, 0xcc, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f68 = (u32)func_0203101C(((struct Obj00844 *)b)->f2, ((struct Obj00844 *)b)->f2, 1, 0);
    func_0201DD78(1, 2, 0xf);
    ((struct Obj00844 *)b)->f80 = 0;
    ((struct Obj00844 *)b)->f64 = 0;
    ((struct Obj00844 *)b)->f84 = func_02028590(0xf, 1, 1, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f88 = 0;
    func_02040588(1, 0);
    ((struct Obj00844 *)b)->f8C = 0;
}
