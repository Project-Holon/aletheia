/*
 * function: func_021B6A3C
 * address: 0x021B6A3C
 * packet: pkt_ov093_021B6A3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 */
extern void func_021EE644(void *, int, int);
typedef unsigned char  u8;
extern void func_021CD938(u8 *p, void *a);
void func_021B6A3C(unsigned char *p, unsigned char *q) { if(q[0x23]) { func_021EE644(p+0x2c8, *(int *)(q+0x94), *(int *)(q+0x98)); func_021CD938(*(void **)(p+0x10),p+0x2c8); func_021CD938(*(void **)(p+0x14),p+0x2c8); } }
