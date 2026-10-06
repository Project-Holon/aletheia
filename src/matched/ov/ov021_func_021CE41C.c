/*
 * function: func_021CE41C
 * address:  0x021CE41C
 * packet:   pkt_ov021_021CE41C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x104 base kept in r6 comes from w being assigned first; the slot
 * store is spelled through the row pointer ((u8 *)p + i * 0x2c)[0x70] while
 * the test indexes p directly.
 *
 * symbols:
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021CE36C  0x021CE36C  thumb  ov021
 *   func_021CE73C  0x021CE73C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 h;
    u32 pad4;
    u8  state;
} Sub;

struct Handle;
struct WordSet;
extern u32 func_02190EF0(u32 *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021CE9E4(u32 *p, int n);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(u32 a);
extern void func_021CE36C(u8 *p);
extern int func_021CE73C(u32 *p);

void func_021CE41C(u32 *p)
{
    Sub *q;
    u8 *w;
    u32 r;
    u8 i;
    u8 v;

    w = (u8 *)p + 0x104;
    q = (Sub *)((u8 *)p + 0x130);
    if (p[0x40] == 0) {
        return;
    }
    if (!func_02190EF0((u32 *)p[5])) {
        return;
    }
    switch (q->state) {
    case 0:
        func_0201F02C((struct WordSet *)p[1], 0, (void *)((int)w));
        func_021CE9E4(p, 10);
        q->state++;
        break;
    case 1:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        v = 4;
        if (r != 0) {
            v = 5;
        }
        for (i = 0; i < 4; i++) {
            if (((u8 *)p)[0x70 + i * 0x2c] == 3) {
                ((u8 *)p + i * 0x2c)[0x70] = v;
                if (v == 4) {
                    ((u8 *)p)[0x521] |= 1 << i;
                } else {
                    ((u8 *)p)[0x522] |= 1 << i;
                }
                break;
            }
        }
        func_021909BC(q->h);
        q->h = 0;
        q->state++;
        break;
    case 3:
        p[0x40] = 0;
        q->state = 0;
        func_021CE36C((u8 *)p);
        if (p[0x40] == 0) {
            if (func_021CE73C(p) > 1 && ((u8 *)p)[0x520] == 1) {
                ((struct Obj00011 *)p)->f574 = 9;
            } else {
                ((struct Obj00011 *)p)->f574 = 8;
            }
        }
        break;
    }
}
