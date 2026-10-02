/*
 * function: func_021C5750
 * address: 0x021C5750
 * packet: pkt_ov093_021C5750
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern void func_021CD64C(void *, u8, ...);
void func_021C5750(u8 *p, u8 *a)
{
    func_021CD64C(*(void **)(p + 12), 0x5b, 210, func_021D5440(a), 0xffff0000);
}
