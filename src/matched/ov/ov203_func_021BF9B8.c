/*
 * function: DEMO3D_CMDSYS_Dispatch
 * address: 0x021BF9B8
 * packet: pkt_ov203_021BF9B8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3D00 0x021C3D00 data a4
 */
extern unsigned d_021C3D00[];
void DEMO3D_CMDSYS_Dispatch(unsigned a,unsigned b,char *p){(*(void (**)(unsigned,unsigned,char *))((unsigned)d_021C3D00+*(unsigned *)p*4))(a,b,p+8);}
