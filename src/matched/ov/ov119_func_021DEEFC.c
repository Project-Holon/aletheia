/*
 * function: func_021DEEFC
 * address:  0x021DEEFC
 * packet:   pkt_ov119_021DEEFC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_02156ED0  0x02156ED0  thumb  ov009
 */

extern void func_021B9774(void *p);
extern void func_021B9838(void *p);
extern void func_02156ED0(void);

void func_021DEEFC(void **p)
{
    if (*p != 0) {
        func_021B9774(*p);
        func_021B9838(*p);
        *p = 0;
        func_02156ED0();
    }
}
