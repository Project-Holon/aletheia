/*
 * function: func_021C14E0
 * address:  0x021C14E0
 * packet:   pkt_ov093_021C14E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C156C  0x021C156C  thumb  ov093
 *   func_021C157C  0x021C157C  thumb  ov093
 *   func_021C6B5C  0x021C6B5C  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C6BB8  0x021C6BB8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C158C  0x021C158C  thumb  ov093
 *   func_021C159C  0x021C159C  thumb  ov093
 */
#include "../include/Obj21076.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C156C(u8 *c);
extern u8 *func_021C157C(u8 *c);
extern int func_021C6B5C(u8 *p, u8 *a, u8 *b, u8 *q);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C6BB8(u8 *p, u8 *a, u8 *r);
extern void func_021CC95C(void *lock, u32 v, int line);
extern void func_021C158C(u8 *c, u8 *r);
extern u8 *func_021C159C(u8 *c);

struct St { u8 pad[5]; u8 f : 1; };

void func_021C14E0(u8 *p, u8 *a, int b, u8 *c)
{
    u8 *r;
    u32 s;
    func_021C156C(c);
    r = func_021C157C(c);
    if (r != 0) {
        do {
            if (func_021C6B5C(p, a, r, (u8 *)b) != 0) {
                struct St *st = *(struct St * *)&((struct Obj21076 *)p)->f4A8;
                if (st->f == 0) st->f = 1;
                s = func_021CC8D8(p + 0x1d74, 0x197b);
                func_021C6BB8(p, a, r);
                func_021CC95C(p + 0x1d74, s, 0x197f);
                func_021C158C(c, r);
            }
            r = func_021C159C(c);
        } while (r != 0);
    }
}
