/*
 * function: func_021B6B38
 * address: 0x021B6B38
 * packet: pkt_ov071_021B6B38
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 */
struct Obj;
struct Grid;
struct Obj020437AC;
extern void func_0204B3B4(struct Obj *);
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
void func_021B6B38(void **p)
{
    func_0204B3B4(p[0]);
    func_0202570C(p[1]);
    func_020437AC(p[2]);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
