/*
 * function: BTL_SLOT_CountLiving
 * address: 0x021B9B98
 * packet: pkt_ov093_021B9B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 * symbols:
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
u8 BTL_SLOT_CountLiving(u8 *p) {
    int i;
    u32 n;
    i = 0;
    n = 0;
    for (; i < p[24]; i++) if (BTL_POKEPARAM_IsAbleToBattle(((void **)p)[i])) n++;
    return n;
}
