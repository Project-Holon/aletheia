/*
 * function: func_021BA2CC
 * address:  0x021BA2CC
 * packet:   pkt_ov071_021BA2CC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021BA528  0x021BA528  thumb  ov071
 *   func_021BA5D4  0x021BA5D4  thumb  ov071
 */
#include "../include/Obj06192.h"
#include "../include/Obj09900.h"
#include "../include/Obj13188.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_021BA528(void *a, void *b, void *c);
extern void func_021BA5D4(void *a, void *b, void *c);

int func_021BA2CC(int a, int *b, u8 *o, u8 *c)
{
    int i;
    u8 f[3];
    u32 t;
    u8 *e;

    if (o[0x2d] == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        t = (*(u32 **)(o + 4))[2];
        e = c + i * 8;
        if (e[0x10] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06192 *)e)->fC))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj06192 *)e)->fC);
                e[0x10] = 0;
            }
        }
        f[i] = e[0x10] == 0;
    }
    if (*b == 0) {
        if ((*(u8 **)(o + 8))[3] == 1 && f[1] == 1) {
            func_021BA528(o, ((struct Obj09900 *)o)->f4, c);
            (*(u8 **)(o + 8))[3] = 0;
        }
        if ((*(u8 **)(o + 8))[1] != ((struct Obj13188 *)c)->f24 && f[2] == 1) {
            func_021BA5D4(o, ((struct Obj09900 *)o)->f4, c);
            ((struct Obj13188 *)c)->f24 = (*(u8 **)(o + 8))[1];
        }
        return 0;
    }
    return 0;
}
