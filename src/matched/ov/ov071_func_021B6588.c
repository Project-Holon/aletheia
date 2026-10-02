/*
 * function: func_021B6588
 * address: 0x021B6588
 * packet: pkt_ov071_021B6588
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
typedef unsigned int u32;
struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *, u32);
extern void func_02021540(struct PalAnmSlot *);
void func_021B6588(struct PalAnmSlot **p)
{
    func_020215A0(*p, 2);
    func_020215A0(*p, 3);
    func_020215A0(*p, 0);
    func_020215A0(*p, 1);
    func_02021540(*p);
}
