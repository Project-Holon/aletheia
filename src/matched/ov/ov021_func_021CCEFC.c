/*
 * function: func_021CCEFC
 * address:  0x021CCEFC
 * packet:   pkt_ov021_021CCEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190938  0x02190938  thumb  ov021
 *   func_021CCF60  0x021CCF60  thumb  ov021
 *   func_021CCF7C  0x021CCF7C  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 */
#include "../include/Obj07588.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021DB414[];
extern u8 d_021DB42C[];
struct Handle;
struct Pair;
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
extern void func_021CCF60(void *a, u32 sel);
extern void func_021CCF7C(void *p, int k);

void func_021CCEFC(u8 *p)
{
    void *r;

    r = (void *)func_02190A28((const struct Pair *)d_021DB414, 3, ((struct Obj07588 *)p)->fA8, ((struct Obj07588 *)p)->fC);
    ((struct Obj07588 *)p)->fAC = func_02190938((u16 *)(((struct Obj07588 *)p)->fA4), d_021DB42C, (u32)r, 0, 0,
        (u32)func_021CCF60, (u32)func_021CCF7C, (u32)p);
}
