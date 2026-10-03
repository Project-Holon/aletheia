/*
 * function: func_021A7508
 * address:  0x021A7508
 * packet:   pkt_ov021_021A7508
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDF7C  0x021DDF7C  data  a4
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *f4;
    u32 f8;
} S;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DDF7C[];

void func_021A7508(S *s, u32 b, int heap)
{
    s->f4 = func_02030734(heap, 0x80, 1, d_021DDF7C, 0x206);
    s->f8 = b;
}
