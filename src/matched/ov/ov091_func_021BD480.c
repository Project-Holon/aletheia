/*
 * function: func_021BD480
 * address:  0x021BD480
 * packet:   pkt_ov091_021BD480
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj09934.h"

struct PrintSys;
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
typedef unsigned char  u8;
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void func_021BD480(char *a, int *b)
{
    int q;
    if (b[0] == 1
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[1])) == 0
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[2])) == 0) {
        q = b[1];
        b[0] = 0;
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
        q = b[2];
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
    }
}
