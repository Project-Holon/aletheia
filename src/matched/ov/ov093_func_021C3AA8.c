/*
 * function: func_021C3AA8
 * address:  0x021C3AA8
 * packet:   pkt_ov093_021C3AA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C184  0x0201C184  thumb
 *   func_021C3C10  0x021C3C10  thumb  ov093
 *   func_021C3B68  0x021C3B68  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C3CCC  0x021C3CCC  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
#include "../include/Obj13330.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } Q;

extern u32 func_0201C184(int id);
extern u8 func_021C3C10(u8 *p, int k, u8 *a);
extern int func_021C3B68(u8 *p, int k, u8 v);
extern void func_021C5718(u8 *p, u8 *b, int c);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C3CCC(u8 *p, u8 *b, int c);
extern int func_021C88E4(u8 *p);
extern void func_021CC95C(void *lock, u32 v, int line);

void func_021C3AA8(u8 *p, u16 *a, u8 *b)
{
    u8 k = func_0201C184(*a);
    if (k) {
        int x = func_021C3C10(p, k, b);
        if (func_021C3B68(p, k, (u8)(x + 5))) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
            return;
        }
        func_021C5718(p, b, *a);
    } else {
        u32 s;
        int e;
        s = func_021CC8D8(p + 0x1d74, 0x22c8);
        func_021C3CCC(p, b, *a);
        e = (func_021C88E4(p) == 2);
        func_021CC95C(p + 0x1d74, s, 0x22cc);
        if (e) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else {
            func_021C5718(p, b, *a);
        }
    }
}
