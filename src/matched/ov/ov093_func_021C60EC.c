/*
 * function: func_021C60EC
 * address: 0x021C60EC
 * packet: pkt_ov093_021C60EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern void func_021CD4B0(void *, u32, ...);
extern void func_021D5FE4(void *, u32);
void func_021C60EC(u8 *p, u8 *a, u32 n)
{
    func_021D5FE4(a, n);
    func_021CD4B0(*(void **)(p + 12), 0x19, func_021D5440(a), n);
}
