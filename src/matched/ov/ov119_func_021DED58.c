/*
 * function: func_021DED58
 * address:  0x021DED58
 * packet:   pkt_ov119_021DED58
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DECA0  0x021DECA0  thumb  ov119
 */

extern unsigned func_020221A4(void);
extern void func_021D8E84(void *p, int next);
extern void func_021DECA0(void *p);

void func_021DED58(void *p)
{
    if (func_020221A4() != 0) {
        func_021D8E84(p, (int)func_021DECA0);
    }
}
