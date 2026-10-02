/*
 * unit: yes
 * function: func_02177114, func_02177124, func_02177128, func_0217712C
 * address: 0x02177114
 * packet: pkt_ov014_02177114
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02177B58 0x02177B58 thumb ov014
 *   func_02177C08 0x02177C08 thumb ov014
 */
extern void *func_02177B58(int);
void *func_02177114(int index) { if (index >= 16) return 0; return func_02177B58(index); }
extern int func_02177C08(void);
int func_02177124(void) { return 1; }
int func_02177128(void) { return 1; }
int func_0217712C(void) { return func_02177C08(); }
