/*
 * function: func_021E0008
 * address:  0x021E0008
 * packet:   pkt_ov119_021E0008
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021DFD30  0x021DFD30  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E08E8  0x021E08E8  thumb  ov119
 */

typedef unsigned int u32;

extern void func_021DFD30(void *, u32);
extern void func_021D8E84(void *, int);
extern void func_021E08E8(char *p);

void func_021E0008(char *p)
{
    if (*(int *)(p + 0xf2c) >= 0x1a4) {
        func_021DFD30(p, 0);
        func_021D8E84(p, (int)func_021E08E8);
    }
}
