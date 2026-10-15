/*
 * function: HALL_OF_FAME_InitGraphicsSystem
 * address: 0x021B6210
 * packet: pkt_ov180_021B6210
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 */
typedef unsigned short u16;
extern void BG_SYS_Create(u16);
void HALL_OF_FAME_InitGraphicsSystem(void) { BG_SYS_Create(141); }
