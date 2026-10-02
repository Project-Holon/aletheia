/*
 * function: func_021F0F30
 * address: 0x021F0F30
 * packet: pkt_ov032_021F0F30
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0EDC 0x021F0EDC thumb ov032
 */
extern void func_021F0EDC(char *);
void func_021F0F30(char *p, int a, int b) { func_021F0EDC(p); p[1]=a; p[2]=b; }
