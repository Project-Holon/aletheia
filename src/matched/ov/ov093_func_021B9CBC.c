/*
 * function: BTL_SLOT_FindPokeId
 * address: 0x021B9CBC
 * packet: pkt_ov093_021B9CBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
int BTL_SLOT_FindPokeId(u8 *p, int v) {
    int i;
    for(i=0;i<p[24];i++) if(v==BTL_POKEPARAM_GetPokeId(*(void **)((u32)p+(u32)i*4))) return i;
    return -1;
}
