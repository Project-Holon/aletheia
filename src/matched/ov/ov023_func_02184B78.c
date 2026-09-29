/*
 * function: func_02184B78
 * address:  0x02184B78
 * packet:   pkt_ov023_02184B78
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 */

typedef unsigned char u8;

extern void func_02049B68(void *, int, int, int, int, int);
extern void func_02049B40(int, int, int, int, int, int);
extern void func_02049658(void *, int, int, int, int, int, int);
extern void func_020498F4(void *, int, int, int, int, int, int);
extern void func_0201F5BC(int, int, int, int, int);

void func_02184B78(u8 *p, void *h)
{
    func_02049B68(h, 0, 0, 0, 0x180, 0x28);
    func_02049B68(h, 1, 4, 0, 0x180, 0x28);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x28);
    func_02049B40(0x17, 5, 4, 0x1A0, 0x20, 0x28);
    func_02049658(h, 2, 2, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 6, 2, 0, 0x600, 0, 0x28);
    func_02049658(h, 4, 5, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 7, 5, 0, 0x600, 0, 0x28);
    func_0201F5BC(0, 1, 10, 0, 0x28);
    func_0201F5BC(0, 0x1F, 11, 0, 0x28);
}
