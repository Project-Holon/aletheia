/*
 * function: MANUAL_COMMON_BuildListRects
 * address: 0x021BAFF8
 * packet: pkt_ov225_021BAFF8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void MANUAL_COMMON_BuildListRects(u8 *p) { u8 i; for(i=0;i<6;i++) { p[i*4]=i*24+12; p[i*4+1]=(i+1)*24+11; p[i*4+2]=16; p[i*4+3]=239; } p[24]=255; p[25]=0; p[26]=0; p[27]=0; }
