/*
 * function: DEMO3D_DATA_FadeSeSlotParam1
 * address: 0x021BEC60
 * packet: pkt_ov203_021BEC60
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_CreateSeFade 0x021BECA8 thumb ov203
 */
typedef unsigned char u8;typedef unsigned short u16;
struct Owner;
extern void DEMO3D_DATA_CreateSeFade(struct Owner *,u8,u16,int,int,int,int);
void DEMO3D_DATA_FadeSeSlotParam1(struct Owner *p,int unused,int *v) {DEMO3D_DATA_CreateSeFade(p,1,(u16)v[0],v[1],v[2],v[3],v[4]);}
