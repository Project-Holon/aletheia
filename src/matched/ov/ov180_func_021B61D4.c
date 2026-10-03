/*
 * function: func_021B61D4
 * address: 0x021B61D4
 * packet: pkt_ov180_021B61D4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B8060 0x021B8060 data a4
 *   d_021B8090 0x021B8090 data a4
 */
typedef unsigned int u32;
struct DispVram;
extern const struct DispVram d_021B8060;
extern const struct DispVram d_021B8090;
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *);
void func_021B61D4(int flag)
{
    func_0204335C(0);
    if (flag == 0)
        func_020433E0(&d_021B8060);
    else
        func_020433E0(&d_021B8090);
}
