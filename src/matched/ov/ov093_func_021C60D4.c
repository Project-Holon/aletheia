/*
 * function: func_021C60D4
 * address: 0x021C60D4
 * packet: pkt_ov093_021C60D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
void func_021C60D4(u8 *p, u8 *a)
{
    func_021CD4B0(*(void **)(p + 12), 0x42, func_021D5440(a));
}
