/*
 * function: func_021D0504
 * address:  0x021D0504
 * packet:   pkt_ov021_021D0504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
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

extern int func_0216E1C4(u32 a, void *b);
extern void func_0219BF3C(int a, u32 v);

void func_021D0504(void *a, St021D04D8 *s)
{
    if (func_0216E1C4(s->f8, s->f10) == 1) {
        func_0219BF3C(s->f8, 0);
    }
}
