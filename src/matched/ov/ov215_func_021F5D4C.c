/*
 * function: func_021F5D4C
 * address: 0x021F5D4C
 * packet: pkt_ov215_021F5D4C
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049658(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_020498F4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049238(unsigned int);
extern void func_020409B4(unsigned char);

void func_021F5D4C(int unused, char *p)
{
    void *h = func_020490F4((void *)189, *(unsigned short *)p);
    func_02049B68(h, 3, 0, 0, 32, *(unsigned short *)p);
    func_02049658(h, 5, 2, 0, 0, 0, *(unsigned short *)p);
    func_020498F4(h, 4, 2, 0, 0, 0, *(unsigned short *)p);
    func_02049238(h);
    func_020409B4(2);
}
