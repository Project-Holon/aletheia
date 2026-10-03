/*
 * function: func_021E1988
 * address: 0x021E1988
 * packet: pkt_ov137_021E1988
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: Legacy 02005E64 source lists four inputs, but its complete
 * body saves no entry input and starts with 02005FBC(void); omitted them.
 * symbols:
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 */
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern void func_02005D90(unsigned int,unsigned short);
void func_021E1988(unsigned int n) { func_02005DE4((void *)1);func_02005E64();func_02005D90(n,65535); }
