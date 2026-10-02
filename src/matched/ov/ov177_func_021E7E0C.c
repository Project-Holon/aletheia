/*
 * function: func_021E7E0C
 * address: 0x021E7E0C
 * packet: pkt_ov177_021E7E0C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
extern void func_020061E4(unsigned se);
extern void func_020061F8(unsigned);
extern void func_0204B3DC(void *, int);
void func_021E7E0C(void **p, int on)
{
    if (on == 1) {
        func_020061E4(0x80D);
    } else {
        func_020061F8(2);
    }
    func_0204B3DC(p[0], on);
    func_0204B3DC(p[1], on);
}
