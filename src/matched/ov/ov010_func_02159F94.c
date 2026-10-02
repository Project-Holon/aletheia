/*
 * function: func_02159F94
 * address: 0x02159F94
 * packet: pkt_ov010_02159F94
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * addressing: getter result converted to unsigned; scale/add modulo 32 bits
 * preserves the original muls/add address without assuming a valid array index.
 * symbols:
 *   func_0215A064 0x0215A064 thumb ov010
 *   d_02170FF4 0x02170FF4 data a2
 */
typedef unsigned short u16;
extern int func_0215A064(int);
extern u16 d_02170FF4[][10];
u16 func_02159F94(int a) { return *(u16 *)((unsigned)d_02170FF4 + (unsigned)func_0215A064(a) * 20u); }
