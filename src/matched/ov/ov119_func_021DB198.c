/*
 * function: func_021DB198
 * address: 0x021DB198
 * packet: pkt_ov119_021DB198
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D658 0x0207D658 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB164 0x021DB164 thumb ov119
 */
typedef unsigned int   u32;
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021D8E84(void *,int);
extern void func_021DB164(char *p);
void func_021DB198(void *p) {
 func_0207D658((u32)((void *)0x04001050),27,-8);
 func_021D8E84(p,(int)func_021DB164);
}
