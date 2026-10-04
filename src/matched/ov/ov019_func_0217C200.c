/*
 * function: func_0217C200
 * address:  0x0217C200
 * packet:   pkt_ov019_0217C200
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_02173518  0x02173518  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_021735FC  0x021735FC  thumb  ov012
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173B4C  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 */
#include "../include/Obj05947.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_0217BB04(u8 *a);
extern void func_02173518(u8 *a);
typedef unsigned int   u32;
extern void func_021734A8(u8 *self, u32 id, u32 v);
struct Entry;
extern int func_021735FC(u8 *self, const struct Entry *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *a, u32 b, u32 c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern int func_02173B4C(u8 *a);
extern unsigned int func_02080D24(int a);

int func_0217C200(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (func_0217BB04(a) == 1)
        return 1;
    if (b[0x70] == 10) {
        ((struct Obj05947 *)b)->f6E = 1;
        return 1;
    }
    ((struct Obj05947 *)b)->f6E = 0;
    switch (*d) {
    case 0:
        func_02173518(b + 0x14);
        func_021734A8(a, 4, 1);
        func_021735FC(b + 0x14, (const struct Entry *)(((struct Obj05947 *)b)->f20));
        r = (int)func_020399A8();
        func_02039C68((struct Link *)r, 2, 0x14);
        (*d)++;
        break;
    case 1:
        r = (int)func_020399A8();
        if (func_02039CB4((struct Link *)r, 2, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (func_02173B4C(a) == 1)
            (*d)++;
        break;
    case 3:
        if (func_02080D24(b[0x5b]) > 1)
            return 1;
        break;
    }
    return 0;
}
