/*
 * function: BTL_MAIN_GetTrainerItem
 * address: 0x021B9F84
 * packet: pkt_ov093_021B9F84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsTrainerSlotNpc 0x021B9F70 thumb ov093
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
u16 BTL_MAIN_GetTrainerItem(char *p,int i,unsigned int j) {
    char *q;
    if(BTL_MAIN_IsTrainerSlotNpc((u8 *)p,i)) {
        q=(char *)((u32)p+32+(u32)i*40);
        if(j<4) return *(u16 *)((u32)q+16+j*2);
    }
    return 0;
}
