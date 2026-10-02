/*
 * function: func_021554A0
 * address: 0x021554A0
 * packet: pkt_ov009_021554A0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * func_02156C60 receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_0203D798 0x0203D798 arm
 *   func_02156C60 0x02156C60 thumb ov009
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 */
extern void *d_021A8264;
extern void *func_0203D798(void);
extern void func_02156C60(void *);
extern void func_0203D7FC(void *);
extern void func_02059F18(void);
void func_021554A0(void)
{
    if (d_021A8264) {
        func_02156C60(func_0203D798());
        func_0203D7FC(d_021A8264);
        d_021A8264 = 0;
    }
    func_02059F18();
}
