/*
 * function: func_021BA81C
 * address:  0x021BA81C
 * packet:   pkt_ov091_021BA81C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BED18     0x021BED18  data  ov091  a1
 *   d_021BEC74     0x021BEC74  data  ov091  a1
 *   d_021BEC75     0x021BEC75  data  ov091  a1
 */
#include "../include/Obj13247.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int w0;
    u8 b4;
    u8 pad5[15];
    int w14;
    int pad18;
    int w1c;
} S44;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32 id);
extern const char d_021BED18[];
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];

S44 *func_021BA81C(u8 *a, int k)
{
    S44 *p = func_02030734(((struct Obj13247 *)a)->f0, 0x44, 0, d_021BED18, 0xea);
    u8 *q = *(u8 * *)&((struct Obj13247 *)a)->f15C + 0xc;

    func_020410D0(2, (u8)(d_021BEC74[k * 2] + 0x10), d_021BEC75[k * 2], 0x10, 6,
                  (u32)q, 0, 0x13, 0x20, 0x20);
    p->b4 = k;
    p->w0 = 0;
    p->w14 = 1;
    p->w1c = 8;
    func_02041B6C(2);
    return p;
}
