/*
 * function: func_021CFADC
 * address:  0x021CFADC
 * packet:   pkt_ov093_021CFADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CF89C  0x021CF89C  thumb  ov093
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 */
#include "../include/Obj01894.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct QI;
struct Unk021D62A8;
extern int func_021CF89C(u8 *p, void *q);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D5814(void *m, int k);

int func_021CFADC(u8 *g, void *m)
{
    u32 a;

    a = func_021CF89C(g, m);
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) != 0)
        return 1;
    if (func_021D62C4(m, 0x1f) != 0)
        return 1;
    if (func_021D62C4(m, 0x15) != 0)
        return 1;
    if (a != 0 && func_021D5B40(m) == 0x116)
        return 1;
    if (func_021D59B4(m, 0x11) == 0x1a)
        return 0;
    if (func_021D5814(m, 2) != 0)
        return 0;
    if (func_021D62C4(m, 0x1e) != 0)
        return 0;
    if (func_021D62C4(m, 0x20) != 0)
        return 0;
    if (a != 0 && func_021D5B40(m) == 0x21d)
        return 0;
    return 1;
}
