/*
 * function: func_02156ED0
 * address:  0x02156ED0
 * packet:   pkt_ov009_02156ED0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02156F14  0x02156F14  thumb  ov009
 */

#include "../include/G_Obj.h"

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern struct Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_02156F14(void);

void func_02156ED0(void)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f14 != 0) {
        func_0203C9AC(0, 0, 0, 0x3EE);
        d_021A8268->f1C = 1;
        return;
    }
    func_02156F14();
}
