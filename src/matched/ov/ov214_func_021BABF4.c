/*
 * function: func_021BABF4
 * address: 0x021BABF4
 * packet: pkt_ov214_021BABF4
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 */

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049740(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049238(unsigned int);

void func_021BABF4(int unused, char *p)
{
    void *h = func_020490F4((void *)188, *(unsigned short *)p);
    func_02049B68(h, 0, 0, 0, 320, *(unsigned short *)p);
    *(unsigned int *)(p + 704) = func_02049740(h, 1, 2, 0, 0, *(unsigned short *)p);
    func_02049238(h);
}
