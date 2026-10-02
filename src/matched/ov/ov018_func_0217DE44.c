/*
 * function: func_0217DE44
 * address: 0x0217DE44
 * packet: pkt_ov018_0217DE44
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 */
extern void func_0202570C(void *);
extern void func_020437AC(void *);
void func_0217DE44(void **p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_0202570C(p[0xc0 / 4 + i]);
        func_020437AC(p[0xb4 / 4 + i]);
    }
}
