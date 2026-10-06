/*
 * function: func_021B6D00
 * address:  0x021B6D00
 * packet:   pkt_ov070_021B6D00
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 *   func_021B7D20  0x021B7D20  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern u32 func_02028754(struct Obj *obj, u32 n);
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6100(char *p, int k);
extern void func_021B6AD8(int p);
extern void func_021B7D20(struct Obj *o, int x);

u32 func_021B6D00(u8 *p)
{
    if (func_02028754(((struct Obj00002 *)p)->fC, 4)) {
        ((struct Obj00002 *)p)->f844 = 0xF;
        func_021B6100((char *)p, 0);
        func_021B7D20((struct Obj *)p, 1);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}
