/*
 * function: CALENDER_FindZoneOffset
 * address: 0x021648A8
 * packet: pkt_ov010_021648A8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 CALENDER_FindZoneOffset(u8 *p,u32 n){int i;u32 out=0xffff;for(i=0;i<68;i++){if(n==*(u16 *)(p+12+i*4)){out=*(u16 *)(p+14+i*4);break;}}return out;}
