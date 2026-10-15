/*
 * function: SYMBOL_MAP_StopBg2Scale
 * address: 0x02166B2C
 * packet: pkt_ov010_02166B2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MTX_Identity22_ 0x0207AD40 arm
 *   func_0207D59C 0x0207D59C arm
 */
extern void MTX_Identity22_(void *);
extern void func_0207D59C(void *, void *, int, int, int, int);
extern void func_0200566C(void);
void SYMBOL_MAP_StopBg2Scale(void) {
    int m[4];
    MTX_Identity22_(m);
    func_0207D59C((void *)0x04000020, m, 128, 92, 0, 0);
    func_0200566C();
}
