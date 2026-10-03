/*
 * function: func_021F6F24
 * address: 0x021F6F24
 * packet: pkt_ov097_021F6F24
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F6F50 0x021F6F50 thumb ov097
 *   func_021F6F88 0x021F6F88 thumb ov097
 *   func_021F714C 0x021F714C thumb ov097
 */
struct P;
extern void func_021F6F50(void);
extern void func_021F6F88(int);
extern void func_021F714C(struct P *);
void func_021F6F24(struct P *p)
{
    func_021F6F50();
    func_021F6F88((int)p);
    func_021F714C(p);
}
