/*
 * function: func_021D04D8
 * address:  0x021D04D8
 * packet:   pkt_ov021_021D04D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Blk021D04D8 {
    u32 w[4];
} Blk021D04D8;

typedef struct St021D04D8 {
    u8 *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10[2];
    u16 f18;
} St021D04D8;

extern Blk021D04D8 *func_021AC1AC(void *a);
extern void func_0216E1A4(u32 a, void *b);

void func_021D04D8(void *a, St021D04D8 *s)
{
    *(Blk021D04D8 *)s = *func_021AC1AC(a);
    func_0216E1A4(s->f8, s->f10);
    s->f18 = ((u16 *)(s->f0 + 8))[s->fC];
}
