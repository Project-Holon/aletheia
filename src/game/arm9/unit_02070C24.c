/*
 * file:     unit_02070C24.c
 * function: func_02070C24
 * address:  0x02070C24
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bit `n` of a bitmap, written out through the caller's pointer. `n` is
 *  * (s->f0 >> 12) * b->h6 + idx -- the shift of f0 is the *arithmetic* form
 *  * (`asr ip, r3, #0xc`, so f0 is signed) while the shift of the summed index
 *  * is the *logical* one (`lsr r1, r2, #5`), which is the whole difference:
 *  * the local holding n has to be unsigned while the field it is built from
 *  * stays signed, and making the local signed too is one byte wrong.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp { u8 pad00[6]; u16 h6; };
struct S { int f0; u32 f4; struct Bmp *p8; };

void func_02070C24(u32 *out, struct S *s, int idx)
{
    struct Bmp *b = s->p8;
    u32 n = (s->f0 >> 12) * b->h6 + idx;

    *out = *(u32 *)((u8 *)b + ((n >> 5) * 4) + 0xc) & (1u << (n & 0x1f));
}
