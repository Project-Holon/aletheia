/*
 * function: func_021D7EAC
 * address: 0x021D7EAC
 * packet: pkt_ov131_021D7EAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041570 0x02041570 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */

extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(unsigned int);
extern void func_02041570(unsigned int, int);
extern void func_0204B3DC(void *, int);
extern void func_0204B878(void *, int);
void func_021D7EAC(unsigned char *p)
{
    func_02041300(1, 0, 0, 0, 19, 21, 16);
    func_02041B6C(1);
    func_02041570(4, 0);
    func_02041B6C(4);
    func_0204B3DC(*(void **)(p + 0x198), 0);
    func_0204B3DC(*(void **)(p + 0x19c), 0);
    func_0204B878(*(void **)(p + 0x178), 0);
}
