/*
 * function: func_0216E084
 * address: 0x0216E084
 * packet: pkt_ov010_0216E084
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0216E014 0x0216E014 thumb ov010
 */

typedef unsigned short u16;
extern void func_0216E014(void *, int *, int);
void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k) { int p[3]; p[0]=(x<<16)+0x8000; p[1]=y<<16; p[2]=(z<<16)+0x8000; func_0216E014(a,p,k); }
