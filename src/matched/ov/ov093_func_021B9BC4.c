/*
 * function: func_021B9BC4
 * address: 0x021B9BC4
 * packet: pkt_ov093_021B9BC4
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
u8 func_021B9BC4(u8 *p,int i) {
    u32 n=0;
    for(;i<p[24];i++) if(BTL_POKEPARAM_IsAbleToBattle(*(void **)((u32)p+(u32)i*4))) n++;
    return n;
}
