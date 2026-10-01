/*
 * function: func_021C6854
 * address:  0x021C6854
 * packet:   pkt_ov021_021C6854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046FF8  0x02046FF8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8[8]; u8 f28; u8 f29; } S;
extern void func_02046FF8(u32 h);
void func_021C6854(S *s)
{
    s->f29 = 0; if (s->f4 != 0) func_02046FF8(s->f4); else func_02046FF8(s->f0); s->f29 = 1;
}
