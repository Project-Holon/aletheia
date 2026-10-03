/*
 * function: func_021AB5F4
 * address:  0x021AB5F4
 * packet:   pkt_ov021_021AB5F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDFC8  0x021DDFC8  data  a4
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int pad8[3];
    int f14;
    int f18;
    int pad1c;
} S;

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
extern char d_021DDFC8[];

S *func_021AB5F4(int heap, int a, int b)
{
    S *p = func_02030734((u16)heap, 0x20, 1, d_021DDFC8, 0x51);
    p->f0 = a;
    p->f4 = b;
    p->f14 = -1;
    p->f18 = 1;
    return p;
}
