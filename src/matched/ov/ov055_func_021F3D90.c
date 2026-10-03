/*
 * function: func_021F3D90
 * address: 0x021F3D90
 * packet: pkt_ov055_021F3D90
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0216D5B8 0x0216D5B8 thumb ov010
 *   func_021F4124 0x021F4124 thumb ov055
 */
typedef unsigned short u16;
extern u16 func_0216D5B8(void *p);
extern void func_021F4124(unsigned char *);
void func_021F3D90(unsigned char *p) { if (p[0]==1 && p[2]==1 && func_0216D5B8(*(void **)(p+12))==2000) { p[2]=0; func_021F4124(p); } }
