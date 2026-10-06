/*
 * function: func_021B6934
 * address:  0x021B6934
 * packet:   pkt_ov070_021B6934
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B68E8  0x021B68E8  thumb  ov070
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6A14  0x021B6A14  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int   func_021B68E8(u16 id);
struct Big;
struct Blk38;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern u32 func_0200D58C(struct Blk38 *p);
extern u32   func_02020FE4(u16 a, u32 sel, u32 id);
extern void func_0200D55C(struct Blk38 *p, u8 v);
struct Obj;
extern void func_021B7D20(struct Obj *o, int x);
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BACF0(int p, int mode);
extern void  func_020061E4(u32 se);
extern void func_021B6100(char *p, int k);
extern void  func_021B6A14(u8 *p);

void func_021B6934(u8 *p)
{
    void *blk;
    u8 v;

    if (func_021B68E8(((struct Obj00002 *)p)->f84C)) {
        blk = func_0200D418(func_02012EBC(((struct Obj00002 *)p)->f0));
        if (func_0200D58C(blk)) {
            v = func_02020FE4(((struct Obj00002 *)p)->f84C, 2, ((struct Obj00002 *)p)->f544);
            func_0200D55C(blk, v);
            func_021B7D20((struct Obj *)p, 1);
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3F, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
            func_021B61F4(p, 1, ((struct Obj00002 *)p)->f84C);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BACF0((int)p, 1);
            func_020061E4(0x7CD);
        } else {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x40, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BACF0((int)p, 1);
        }
        func_021B6100((char *)p, (int)((void *)func_021B6A14));
    }
}
