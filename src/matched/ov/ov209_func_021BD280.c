/*
 * function: func_021BD280
 * address: 0x021BD280
 * packet: pkt_ov209_021BD280
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020216D4 0x020216D4 thumb
 *   func_021BC730 0x021BC730 thumb ov209
 */
struct PalAnmSlot;
extern void func_020216D4(struct PalAnmSlot *, unsigned, unsigned, unsigned);
extern void func_021BC730(char *, int, int);
void func_021BD280(char *p)
{
    func_020216D4(*(struct PalAnmSlot **)(p + 12), 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 12), 1, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 12), 2, 0, 512);
    func_020216D4(*(struct PalAnmSlot **)(p + 12), 3, 0, 512);
    func_021BC730(p, 16, 16);
}
