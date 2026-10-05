/*
 * function: func_021F9754,func_021F9770
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
 *   func_021FC4DC 0x021FC4DC thumb ov186
 * Extent includes empty follower func_021F9770; zeros at 021F976E and 021F9772 are alignment.
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021FC4DC(u8 *p);
void func_021F9754(int *out,int *source)
{
    out[2]=source[1];
    out[0]=source[3];
    out[3]=source[2];
    out[1]=func_021FC4DC((u8 *)source[0]);
}
void func_021F9770(void)
{
}
