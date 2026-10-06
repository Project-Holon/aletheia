/*
 * function: func_021C62F0
 * address:  0x021C62F0
 * packet:   pkt_ov021_021C62F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAAB4     0x021DAAB4  data  a2
 *   func_02040588  0x02040588  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 */
#include "../include/Obj00458.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern const Pt d_021DAAB4;
typedef unsigned int   u32;
struct St021D3244;
struct St021D325C;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_021D325C(struct St021D325C *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021D3244(struct St021D3244 *p, int i, u8 v);

void func_021C62F0(u8 *p)
{
    Pt pt;

    pt = d_021DAAB4;
    func_02040588(p[0], 0);
    func_02040E78(p[0], &pt, 8, 0x20);
    func_02040C14(p[0], 1, 1, 0x100);
    func_02041300(p[0], 0x100, 0, 0, 0x20, 0x20, 1);
    func_020409B4(p[0]);
    func_021D325C(((struct Obj00458 *)p)->f4, 8, 0x37, p[1], 0x10 - p[1]);
    func_021D3244(((struct Obj00458 *)p)->f4, p[0], 1);
}
