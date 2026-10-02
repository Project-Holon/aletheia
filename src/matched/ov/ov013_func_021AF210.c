/*
 * function: func_021AF210
 * address: 0x021AF210
 * packet: pkt_ov013_021AF210
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_021B3064 0x021B3064 arm ov013
 */
extern void *d_021B3C80;
extern void func_021B3064(void *);
int func_021AF210(void)
{
    int a[4];
    if (d_021B3C80 != 0) {
        func_021B3064(a);
        if (a[1] > 2) return a[0];
    }
    return 0;
}
