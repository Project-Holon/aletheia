/*
 * function: func_02157108
 * address:  0x02157108
 * packet:   pkt_ov009_02157108
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A1C8C  0x021A1C8C  data  ov009  a1
 *   func_02157048  0x02157048  thumb  ov009
 *   func_02059F6C  0x02059F6C  arm
 *   func_021570B8  0x021570B8  thumb  ov009
 *   func_02156F5C  0x02156F5C  thumb  ov009
 *   func_02156FDC  0x02156FDC  thumb  ov009
 */

#include "../include/G_Obj.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {
    u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; u16 f20;
} Obj;
extern struct Obj *d_021A8268;
extern char d_021A1C8C[];
extern void func_02157048(u32 a, u32 b);
extern int func_02059F6C(void *a, u32 b, void *c, void *d);
extern void func_021570B8(void);
extern u32 func_02156F5C(u32 a, u32 b, u32 c);
extern void func_02156FDC(u32 a, void *p, int b);
int func_02157108(u16 a)
{
    int r;
    func_02157048(a, 0x40000);
    r = func_02059F6C(d_021A1C8C, 0x4952414A, func_02156F5C, func_02156FDC);
    func_021570B8();
    return r;
}
