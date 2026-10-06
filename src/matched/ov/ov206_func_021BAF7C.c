/*
 * function: func_021BAF7C
 * address: 0x021BAF7C
 * packet: pkt_ov206_021BAF7C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08388.h"
#include "../include/Obj25403.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct PrintSys;
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021BAF7C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj08388 *)slot)->f7C == 0 && func_0201C6C4((struct PrintSys *)(((struct Obj25403 *)p)->f2C), (void *)func_02045770((struct Descriptor *)((struct Obj08388 *)slot)->f6C)) == 0) {
            int window = ((struct Obj08388 *)slot)->f6C;
            func_02045334((struct Descriptor *)window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730((struct Descriptor *)window));
            ((struct Obj08388 *)slot)->f7C = 1;
        }
    }
}
