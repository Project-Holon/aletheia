/*
 * function: func_021E8DF8
 * address:  0x021E8DF8
 * packet:   pkt_ov093_021E8DF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   func_021E8F08  0x021E8F08  thumb  ov093
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203D29C  0x0203D29C  arm
 */
extern char ov094_id[], ov095_id[], ov096_id[];
extern void func_021E8F08(void);
extern void func_02034A5C(void *id);
typedef unsigned int   u32;
extern u32 func_0203D29C(void);

void func_021E8DF8(void)
{
    func_021E8F08();
    func_02034A5C(ov094_id);
    func_02034A5C(ov095_id);
    if (func_0203D29C() == 0) {
        func_02034A5C(ov096_id);
    }
}
