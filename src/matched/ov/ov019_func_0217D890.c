/*
 * function: func_0217D890
 * address:  0x0217D890
 * packet:   pkt_ov019_0217D890
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_02174F4C  0x02174F4C  thumb  ov012
 *   func_0217EC94  0x0217EC94  thumb  ov019
 *   func_0217EE34  0x0217EE34  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   d_021807E4     0x021807E4  data  a4
 */
#include "../include/Obj09414.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x5a - 0x2e];
    u8 b0 : 1;
    u8 b1 : 1;
} Obj;

extern int func_0217BB04(char *p);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern int func_02174F4C(int a, int b, int c, int d);
extern u16 func_0217EC94(int i);
extern u16 func_0217EE34(int i);
typedef unsigned int   u32;
extern void func_0217F210(u8 *p, u8 *a, u32 b);
extern u32 func_0217F1EC(u8 *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *a, u32 b, u32 c);
extern u32 func_02039CB4(struct Link *a, u32 b, u32 c);
extern void func_0217422C(u8 *a, int b, int c);
extern int func_02174268(u8 *a);
extern void func_0217BAF0(char *p, int x, unsigned int v);
extern int func_0217B8E4(char *p, char v);
extern u8 d_021807E4[];

int func_0217D890(u8 *a, Obj *b, u8 *c, u8 *d)
{
    int *p;
    if (*d < 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        if (b->b1 == 0)
            func_0217F210(a, c, func_0217EC94(b->f14->b3));
        else
            func_0217F210(a, c, func_0217EE34(b->f14->b3));
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1)
            (*d)++;
        break;
    case 2:
        if (b->b1 == 0)
            func_02039C68((struct Link *)func_020399A8(), 0xb, 0x14);
        (*d)++;
        break;
    case 3:
        if (b->b1 == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xb, 0x14) == 1)
                (*d)++;
        } else {
            (*d)++;
        }
        break;
    case 4:
        func_0217422C(a, b->f2d + 1, 0);
        (*d)++;
        break;
    case 5:
        if (func_02174268(a) == 0) {
            if (((struct Obj09414 *)a)->f355C != 0)
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
            p = *(int * *)&((struct Obj09414 *)a)->f0;
            ((struct Obj09414 *)a)->f355C = func_02174F4C(p[2], p[3], p[0], b->b1);
            func_0217BAF0((char *)a, (int)c, 1);
            func_0217B8E4((char *)a, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}
