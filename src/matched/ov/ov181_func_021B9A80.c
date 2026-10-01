/*
 * function: func_021B9A80
 * address: 0x021B9A80
 * packet: pkt_ov181_021B9A80
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049238 0x02049238 arm
 *   func_02040EBC 0x02040EBC arm
 */
extern unsigned char *func_020490F4(int, int);
extern void func_02049B68(unsigned char *, int, int, int, int, int);
extern void func_02049238(unsigned char *);
extern void func_02040EBC(int, int);
void func_021B9A80(void *unused, int mode)
{
    unsigned char *h;
    if (mode == 1) {
        h = func_020490F4(0x1A, 0x808E);
        func_02049B68(h, 2, 0, 0, 0, 0x8E);
    } else {
        h = func_020490F4(0xDC, 0x808E);
        func_02049B68(h, 0xC, 0, 0x1E0, 0x20, 0x8E);
    }
    func_02049238(h);
    func_02040EBC(1, 0);
}
