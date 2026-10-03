/*
 * function: func_021E19A4
 * address: 0x021E19A4
 * packet: pkt_ov137_021E19A4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 * symbols:
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 */
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_02005DE4(void *);
int func_021E19A4(void) { if(func_02005F38()==0) { func_02005E9C();func_02005DE4(0);return 0; }return 1; }
