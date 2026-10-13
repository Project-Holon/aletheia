/*
 * function: func_021B9CE8
 * address: 0x021B9CE8
 * packet: pkt_ov093_021B9CE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
void *func_021B9CE8(u8 *p) {
    int i;
    for(i=0;i<p[24];i++) if(BTL_POKEPARAM_IsAbleToBattle(*(void **)((u32)p+(u32)i*4))) return *(void **)((u32)p+(u32)i*4);
    return 0;
}
