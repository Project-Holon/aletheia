/*
 * function: func_021C6110
 * address: 0x021C6110
 * packet: pkt_ov093_021C6110
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
extern void func_021D6008(u8 *, unsigned int);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *, unsigned int, ...);
void func_021C6110(u8 *p, u8 *a, unsigned int n)
{
    func_021D6008(a, n);
    func_021CD4B0(*(void **)(p + 12), 0x1a, func_021D5440(a), n);
}
