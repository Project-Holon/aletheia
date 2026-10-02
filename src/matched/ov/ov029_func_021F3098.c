/*
 * function: func_021F3098
 * address: 0x021F3098
 * packet: pkt_ov029_021F3098
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2B9C 0x021F2B9C thumb ov029
 *   func_021EFF58 0x021EFF58 thumb ov029
 */
typedef unsigned char u8;
extern int func_021F2B9C(u8 *, int, int);
extern void func_021EFF58(u8 *, int, int);
void func_021F3098(u8 *p)
{
    p[0x414] = func_021F2B9C(p, p[0x452], p[0x453]);
    p[0x415] = 0;
    func_021EFF58(p, p[0x452], p[0x453]);
}
