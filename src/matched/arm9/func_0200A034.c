/*
 * function: func_0200A034
 * address:  0x0200A034
 * packet:   pkt_0200A034
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15579.h"

typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern u32 func_0200A400(struct Obj *obj);
extern void func_0200A49C(struct Obj *obj);
extern int func_02009F1C(void *p);
extern void *func_0200A43C(struct Obj *obj, u32 index);
extern u32 func_02009F0C(u32 a);
extern void func_0200A480(struct Obj *obj);
extern void func_02082D44(void *dst, void *src, int n);
int func_0200A034(void *p, void *arg)
{
    unsigned int i;
    int found = 0;
    unsigned int n = (unsigned int)func_0200A400(p);
    func_0200A49C(p);
    if (func_02009F1C(p) == 1) {
        for (i = 0; i < n; i++) {
            void *slot = func_0200A43C(p, i);
            if (func_02009F0C(((struct Obj15579 *)slot)->fB3) == 0) {
                func_02082D44(arg, slot, 0xcc);
                found = 1;
                break;
            }
        }
    }
    func_0200A480(p);
    return found;
}
