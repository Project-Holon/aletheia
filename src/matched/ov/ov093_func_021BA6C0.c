/*
 * function: func_021BA6C0
 * address:  0x021BA6C0
 * packet:   pkt_ov093_021BA6C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B90F8  0x021B90F8  thumb  ov093
 *   func_021CD924  0x021CD924  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 */
#include "../include/Obj00324.h"
#include "../include/Obj21018.h"
#include "../include/Obj21019.h"

typedef unsigned char u8;

struct T {
    int w[6];
};

typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_021B90F8(u8 *p);
extern u16 *func_021CD924(u8 *p, u32 *out);
extern void func_02082D44(void *, void *, int);

void func_021BA6C0(char *p)
{
    int n;
    void *src;

    if (func_021B90F8((u8 *)p)) {
        src = func_021CD924(*(void **)(p + (u8)p[0x46c] * 4 + 0x10), (u32 *)(&n));
        if (src) {
            func_02082D44(src, ((struct Obj21018 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f94, n);
            ((struct Obj21019 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f98 = n;
            *(struct T *)(*(char * *)&((struct Obj00324 *)p)->f0 + 0x9c) = *(struct T *)(p + 0x3f0);
        }
    }
}
