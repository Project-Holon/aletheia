/*
 * function: BTL_SLOT_CompactLiving
 * address: 0x021B9B60
 * packet: pkt_ov093_021B9B60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 * symbols:
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTL_SLOT_MoveToEnd 0x021B9C24 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern void BTL_SLOT_MoveToEnd(u8 *p, u8 i);
void BTL_SLOT_CompactLiving(u8 *p) {
    unsigned int j;
    int i;
    j=0;
    i=0;
    for(;j<p[24];j++) {
        if(BTL_POKEPARAM_IsAbleToBattle(*(void **)((u32)p+(u32)i*4))) i++;
        else BTL_SLOT_MoveToEnd(p,i);
    }
}
