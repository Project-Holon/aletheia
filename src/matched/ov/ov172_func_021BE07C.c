/*
 * function: COMM_TVT_SYS_ApplyHalfRes
 * address: 0x021BE07C
 * packet: pkt_ov172_021BE07C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * symbols:
 *   CTVT_COMM_SendSlotHit 0x021B8720 thumb ov172
 * status: EXACT
 */
typedef unsigned int u32;
extern void CTVT_COMM_SendSlotHit(void *a0, u32 *a1, u32 a2);
void COMM_TVT_SYS_ApplyHalfRes(u32 *p, u32 v)
{
    CTVT_COMM_SendSlotHit(p, (u32 *)p[0x79], v);
}
