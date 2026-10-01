/*
 * function: func_021C4CE4
 * address: 0x021C4CE4
 * packet: pkt_ov127_021C4CE4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: next larger wrapper starts at 0x021C4D34, its initial push
 *         is included by the stale label extent; filed separately.
 * symbols:
 *   func_021C4B7C 0x021C4B7C thumb ov127
 *   func_021C4B90 0x021C4B90 thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 */
typedef unsigned short u16;
struct pair { u16 a, b; };
extern void func_021C4B7C(char *, struct pair);
extern void func_021C4B90(char *, struct pair);
extern void func_021C4A00(void *, int, int);
void func_021C4CE4(char *p, struct pair v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 0);
}
