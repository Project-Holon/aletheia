/*
 * function: BTL_SLOT_Swap
 * address: 0x021B9C10
 * packet: pkt_ov093_021B9C10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 */
typedef unsigned int u32;
void BTL_SLOT_Swap(u32 *p, int a, int b) {
    u32 t=*(u32 *)((u32)p+(u32)a*4);
    *(u32 *)((u32)p+(u32)a*4)=*(u32 *)((u32)p+(u32)b*4);
    *(u32 *)((u32)p+(u32)b*4)=t;
}
