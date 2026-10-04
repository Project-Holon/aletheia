/*
 * function: func_0217403C
 * address:  0x0217403C
 * packet:   pkt_ov012_0217403C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02034714  0x02034714  arm
 *   func_02183FB8  0x02183FB8  thumb  ov022
 *   func_02184060  0x02184060  thumb  ov022
 */
#include "../include/Obj09365.h"

typedef unsigned char u8;

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int v);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183FB8(int o, void *p, u8 i, int y);
extern void func_02184060(u8 *s, int i);

void func_0217403C(int a, int x, int y, u8 *p)
{
    if (a != func_0203D1A4((int)func_020399A8())) {
        if (((struct Obj09365 *)p)->f3528 == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183FB8(((struct Obj09365 *)p)->f3528, p, (u8)a, y);
        func_02184060((u8 *)(((struct Obj09365 *)p)->f3528), (u8)a);
    }
}
