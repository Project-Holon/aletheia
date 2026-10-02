/*
 * function: func_02157910
 * address: 0x02157910
 * packet: pkt_ov010_02157910
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 22 bytes of code followed by 2-byte alignment padding.
 * symbols:
 *   func_02157724 0x02157724 thumb ov010
 *   func_02157818 0x02157818 thumb ov010
 */
typedef unsigned char u8;
extern int func_02157724(u8 *);
extern void func_02157818(u8 *);
int func_02157910(u8 *p) { int r; r = func_02157724(p); if (r) func_02157818(p); return r; }
