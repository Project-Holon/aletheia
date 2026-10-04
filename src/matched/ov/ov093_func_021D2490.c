/*
 * function: func_021D2490
 * address:  0x021D2490
 * packet:   pkt_ov093_021D2490
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
 */
#include "../include/Obj10019.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u16 a; u16 b; } Pair16;

extern void func_021EF9C0(void *w, u8 id, u16 v);
extern u32 func_021CD9E0(u8 *p);
extern void func_021F7998(u32 a);
extern int func_021F7EB4(void);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern Pair16 d_021EFFAE[5];

int func_021D2490(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(((struct Obj10019 *)p)->f34, id, c[1]);
        if (func_021CD9E0(p))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
