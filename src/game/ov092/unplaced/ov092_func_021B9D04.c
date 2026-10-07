/*
 * function: func_021B9D04
 * address: 0x021B9D04
 * packet: pkt_ov092_021B9D04
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017F9C 0x02017F9C thumb
 * extent: code ends at 0x021B9D44; remaining handed extent is rodata.
 */
typedef unsigned int u32;
struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02017F9C(void *p, u32 v);
void func_021B9D04(void *p)
{
    u32 saved;
    u32 zero;
    saved = func_02017D30(p);
    zero = 0;
    if (func_02017E1C(p, 0x98, 0) == 14) {
        func_02017E40(p, 0xa0, func_02017E1C(p, 0xa1, zero));
        func_02017F9C(p, zero);
    }
    func_02017D70(p, saved);
}
