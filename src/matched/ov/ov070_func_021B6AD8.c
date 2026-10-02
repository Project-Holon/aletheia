/*
 * function: func_021B6AD8
 * address: 0x021B6AD8
 * packet: pkt_ov070_021B6AD8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BACF0 0x021BACF0 thumb ov070
 *   func_021B6100 0x021B6100 thumb ov070
 *   func_021B6A14 0x021B6A14 thumb ov070
 */

extern void func_021BACF0(int p, int mode);
extern void func_021B6100(void *p, void *fn);
extern void func_021B6A14(void *p);
void func_021B6AD8(int p) { func_021BACF0(p, 1); func_021B6100((void *)p, (void *)func_021B6A14); }
