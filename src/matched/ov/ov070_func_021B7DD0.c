/*
 * function: func_021B7DD0
 * address: 0x021B7DD0
 * packet: pkt_ov070_021B7DD0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_0204B3DC 0x0204B3DC arm
 */

typedef unsigned char u8;
extern void func_020414EC(int v);
extern void func_0204B3DC(void *p, unsigned int v);
void func_021B7DD0(u8 *p) { func_020414EC(3); func_0204B3DC(*(void **)(p+0x724),0); func_0204B3DC(*(void **)(p+0x728),0); }
