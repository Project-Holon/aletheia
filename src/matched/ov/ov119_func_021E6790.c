/*
 * function: func_021E6790
 * address: 0x021E6790
 * packet: pkt_ov119_021E6790
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_0204B3DC(int, int);

void func_021E6790(void *p, int i, int a)
{
    func_0204B3DC(*(int *)((char *)p + i * 4 + 0x10bc), a);
}
