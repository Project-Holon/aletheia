/*
 * function: func_021B699C
 * address: 0x021B699C
 * packet: pkt_ov071_021B699C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 */
struct S02021D50;
extern void func_0204A648(void);
extern void func_02021D50(struct S02021D50 *);
void func_021B699C(void *unused, struct S02021D50 **p)
{
    func_0204A648();
    func_02021D50(*p);
}
