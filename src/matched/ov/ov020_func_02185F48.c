/*
 * function: func_02185F48
 * address: 0x02185F48
 * packet: pkt_ov020_02185F48
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020127A4 0x020127A4 thumb
 *   func_02012B28 0x02012B28 thumb
 *   func_02012B2C 0x02012B2C thumb
 */
extern void *func_020127A4(void *);
extern int func_02012B28(void *);
extern void func_02012B2C(void *,int);
void func_02185F48(void *p) { void *q; q=func_020127A4(p); if (func_02012B28(q)!=3) func_02012B2C(q,0); else func_02012B2C(q,2); }
