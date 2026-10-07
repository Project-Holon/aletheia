/*
 * file:     p_sta_oam_p34.c
 * unit:     yes
 * function: func_021DBA54, func_021DBA78, func_021DBA90
 * address:  0x021DBA54
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DC2B8 0x021DC2B8 data
 *   d_021DC2B9 0x021DC2B9 data
 *   func_0204B878  0x0204B878  arm
 *   func_02030734 0x02030734 arm
 *   d_021DC854 0x021DC854 data a1
 */
#include "../../matched/include/Obj14080.h"

struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct S { u32 f0; u16 f4; u16 pad; int f8[3]; };

extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021DBA54(unsigned char *p, unsigned short *o);
void func_021DBA78(u8 *p, int i);
struct S *func_021DBA90(u32 a, u32 b);
extern unsigned char d_021DC2B8[];
extern unsigned char d_021DC2B9[];
extern const char d_021DC854[];

void func_021DBA54(unsigned char *p, unsigned short *o) {
 o[0] = d_021DC2B8[*p * 2] << 3;
 o[1] = d_021DC2B9[*p * 2] << 3;
}


void func_021DBA78(u8 *p, int i)
{
    func_0204B878(((struct Obj14080 *)p)->f8, (u16)(p[0] + i * 5));
}

struct S *func_021DBA90(u32 a, u32 b) {
 struct S *p = func_02030734(a, 0x14, 1, d_021DC854, 0x5d);
 int i;
 p->f4 = a;
 p->f0 = b;
 for (i = 0; i < 3; i++) p->f8[i] = -1;
 return p;
}
