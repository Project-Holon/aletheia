/*
 * function: POKELIST_SetupBgPlanes
 * address: 0x021B6F0C
 * packet: pkt_ov091_021B6F0C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D4B0 0x0207D4B0 arm
 *   POKELIST_LoadBgPlane 0x021B7078 thumb ov091
 *   d_021BEB7C 0x021BEB7C data a4
 */
extern void func_0207D4B0(int,int,int);
extern void POKELIST_LoadBgPlane(const void *,unsigned,unsigned);
extern char d_021BEB7C[];
void POKELIST_SetupBgPlanes(void *p) { func_0207D4B0(1,0,0); POKELIST_LoadBgPlane(d_021BEB7C,0,0); }
