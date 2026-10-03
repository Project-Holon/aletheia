/*
 * function: func_021B6194
 * address: 0x021B6194
 * packet: pkt_ov180_021B6194
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data a4
 * volatile: SDK IRQ check buffer read/write at 021B61A4/021B61A8.
 */
typedef unsigned int u32;
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern void func_0204A648(void);
extern void func_0204EA64(void);
void func_021B6194(void)
{
    func_0204A648();
    func_0204EA64();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}
