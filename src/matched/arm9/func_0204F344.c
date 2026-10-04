/*
 * function: func_0204F344
 * address:  0x0204F344
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../include/Obj16133.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec_0204F344 {
    u8  pad00[4];
    u16 hw;         /* +0x04 */
    u8  pad06[2];
    u8  x;          /* +0x08 */
    u8  y;          /* +0x09 */
    u8  pad0a[0xa];
    u32 f14;        /* +0x14 */
};

void func_0204F344(void *a0, int a1, int a2, int *out, int *in, u8 flag)
{
    struct Rec_0204F344 *p =
        (struct Rec_0204F344 *)(*(u8 * *)&((struct Obj16133 *)a0)->f4 + a1 * 0x28);
    int q;

    switch (p->f14) {
    case 3:
        *in = p->y * ((p->x << 5) / 8) / 8;
        break;
    case 1:
    case 4:
    case 6:
        *in = p->y * ((p->x << 6) / 8) / 8;
        break;
    case 2:
        *in = p->y * ((p->x << 4) / 8) / 8;
        break;
    }
    if (flag == 0) {
        *out = a2 * *in;
        return;
    }
    q = a2 / p->hw;
    *out = *in * q + p->x * (a2 % p->hw);
}
