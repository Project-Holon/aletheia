/*
 * function: func_021D3294
 * address:  0x021D3294
 * packet:   pkt_ov021_021D3294
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf (a .word in ov021.s), blocker of ov032 func_021F0208.
 * Storing the u16 tag first is what makes the compiler save r3/r4 and keep
 * the constant in r4; the plain-pointer spelling gave a shorter body.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 p0[2]; u16 t; u8 p1[0x14]; u32 a, b, c, d; } S;

void func_021D3294(S *p, u32 a, u32 b, u32 c, u32 d)
{
    p->t = 2;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
