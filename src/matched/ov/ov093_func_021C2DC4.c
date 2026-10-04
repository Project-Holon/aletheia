/*
 * function: func_021C2DC4
 * address:  0x021C2DC4
 * packet:   pkt_ov093_021C2DC4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2E1C  0x021C2E1C  thumb  ov093
 *   func_021C2E2C  0x021C2E2C  thumb  ov093
 *   func_021C2E3C  0x021C2E3C  thumb  ov093
 *   func_021C2E64  0x021C2E64  thumb  ov093
 */
#include "../include/Obj21085.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

extern void func_021C2E1C(u32 c);
extern u32 func_021C2E2C(u32 c);
extern u32 func_021C2E3C(u32 c);
extern int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k);

void func_021C2DC4(u8 *p, u32 a, u32 b, u32 c)
{
    u32 t;
    func_021C2E1C(c);
    for (t = func_021C2E2C(c); t != 0; t = func_021C2E3C(c)) {
        if (func_021C2E64(p, (const u16 *)a, (u8 *)b, (u8 *)t, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj21085 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}
