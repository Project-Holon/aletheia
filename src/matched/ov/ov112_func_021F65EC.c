/*
 * function: MUSICAL_MCSS_SetupG3
 * address: 0x021F65EC
 * packet: pkt_ov112_021F65EC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Hardware register stores at listing 021F65F0,021F65F4,021F65FA.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void MUSICAL_MCSS_SetupG3(void) {*(volatile u32 *)0x040004c0=0x4210ffff;*(volatile u32 *)0x040004c4=0x4210;*(volatile u32 *)0x040004a4=0x001f00c0;}
