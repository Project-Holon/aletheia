/*
 * function: BR_PROC_SYS_CopyRecord2,BR_PROC_SYS_NoopF
 * address: 0x021F9754
 * packet: pkt_ov186_021F9754
 * region: ov186
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 * Extent includes empty follower BR_PROC_SYS_NoopF; zeros at 021F976E and 021F9772 are alignment.
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
void BR_PROC_SYS_CopyRecord2(int *out,int *source)
{
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[2];
    out[1]=BR_GRAPHIC_GetActorUnit((u8 *)source[0]);
}
void BR_PROC_SYS_NoopF(void)
{
}
